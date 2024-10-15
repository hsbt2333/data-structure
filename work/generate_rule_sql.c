//
// Created by 致命之猫 on 24-10-11.
// 传入两个参数，IO文件路径，SQL导出目录
// 扫描文件，按行读取，分割字段的各项属性
// 拼接sql，写入文件
//
#include <stdio.h>// fprintf
#include <stdlib.h>// exit(1)
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#include <string.h>
#include <errno.h>
// 读取文件夹
// 读文件
// SQL组装
// 创建文件写文件

#define IS_DIRECTORY 1
#define IS_FILE 2

struct line {
    char *column_name;
    char *column_type;
    int column_length;
    int decimal_length;
    char is_primary_key;
};

// 判断是否是文件夹
int is_dir_or_file(const char *io_file_path) {
    struct stat stat_buf;
    // 文件无法打开
    if (stat(io_file_path, &stat_buf) == -1) {
        fprintf(stderr, "Get stat on %s Error: %s\n", io_file_path, strerror(errno));
        return -1;
    }
    // 判断文件夹
    if (S_ISDIR(stat_buf.st_mode)) {
        return 1;
    }
        // 判断文件
    else if (S_ISREG(stat_buf.st_mode)) {
        return 2;
    }
    return 0;
}

void read_file(const char *io_file, const char *sql_file) {
    if (is_dir_or_file(io_file) == IS_FILE) {
        printf("%s\n", io_file);
        FILE *ioFile = fopen(io_file, "r");
        FILE *sqlFile = fopen(sql_file, "w");
        if (ioFile == NULL || sqlFile == NULL) {
            printf("cannot open file\n");
            exit(1);
        }
        /*char content[128];
        while (fgets(content, 128, ioFile) != NULL) {
            //printf("c:  %s\n",content);
            //memset(content,0, sizeof(content));
            fputs(content, sqlFile);
        }*/

        char *str = NULL;
        size_t len = 0;
        ssize_t read;
        while ((read = getline(&str, &len, ioFile)) != -1) {
            if (strncmp(str, "#", 1) == 0 || strcmp(str, "\n") == 0 || strcmp(str, "\r\n") == 0) {
                printf("空行或者以#开头的行\n");
                continue;
            }
            char *str_arr[5];
            int str_len = 0;
            char *temp = strtok(str, "|");
            while (temp) {
                //printf("%s\n",temp);
                //fprintf(sqlFile,"%s\n",temp);
                str_arr[str_len++] = temp;
                temp = strtok(NULL, "|");
                if (temp) {
                    size_t temp_len = strlen(temp);
                    // windows
                    if (temp_len > 2 && temp[temp_len - 2] == '\r' && temp[temp_len - 1] == '\n') {
                        temp[temp_len - 2] = '\0';
                    }
                    // linux
                    if (temp_len > 1 && temp[temp_len - 1] == '\n') {
                        temp[temp_len - 1] = '\0';
                    }
                }
            }
            fprintf(sqlFile, "insert into file_rule(a,b,c,d,e) values(%s,%s,%s,%s,%s)\n", str_arr[0], str_arr[1],
                    str_arr[2], str_arr[3], str_arr[4]);
            //fprintf(sqlFile,"%s\n",str);
        }
        free(str);
        fclose(ioFile);
        fclose(sqlFile);
    }
}

void read_directory(const char *io_file_path, const char *sql_file_path) {
    DIR *dir_p;
    struct dirent *dirent_p;
    if (is_dir_or_file(io_file_path) != IS_DIRECTORY) {
        fprintf(stderr, "%s not a directory\n", io_file_path);
        exit(1);
    }
    if ((dir_p = opendir(io_file_path)) == NULL) {
        printf("open directory %s Error: %s\n", io_file_path, strerror(errno));
        exit(1);
    }
    while ((dirent_p = readdir(dir_p)) != NULL) {
        if (strcmp(dirent_p->d_name, ".") == 0 || strcmp(dirent_p->d_name, "..") == 0) {
            continue;
        }
        char io_file[128], sql_file[128];
        memset(io_file, 0, sizeof(io_file));
        strcpy(io_file, io_file_path);
        strcat(io_file, "/");//TODO Linux /
        strcat(io_file, dirent_p->d_name);

        memset(sql_file, 0, sizeof(io_file));
        strcpy(sql_file, sql_file_path);
        strcat(sql_file, "/");//TODO Linux /
        strcat(sql_file, dirent_p->d_name);
        strcat(sql_file, "_insert.sql");

        read_file(io_file, sql_file);
    }

    closedir(dir_p);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "please enter the IO file path and export SQL path\n");
        exit(1);
    }
    const char *io_file_path = argv[1];
    const char *sql_file_path = argv[2];

    //printf("%s\n%s\n",io_file_path,sql_file_path);
    read_directory(io_file_path, sql_file_path);
    return 0;
}