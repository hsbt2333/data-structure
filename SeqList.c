/*
 * Created by 致命之猫 on 2024-03-09 23:49
 * 顺序表
 * 插入 删除 按位置查找 按值查找 初始化 求表长
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 100
typedef int dataType;
typedef struct {
    dataType data[MAX_LENGTH];
    int length;
} SeqList;

SeqList *init() {
    SeqList *p = malloc(sizeof(SeqList));
    p->length = 0;
    return p;
}

void insert(SeqList *list, int index, dataType data) {
    if (list->length == MAX_LENGTH) {
        printf("顺序表已满");
        return;
    }
    if (index < 1 || index > list->length + 1) {
        printf("位置错误");
        return;
    }
    int i;
    for (i = list->length - 1; i >= index - 1; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index - 1] = data;
    list->length++;
}

dataType delete(SeqList *list, int index) {
    if (list->length == 0) {
        printf("顺序表为空");
        exit(0);
    }
    if (index < 1 || index > list->length) {
        printf("位置错误");
        exit(0);
    }
    list->length--;
    return list->data[index - 1];
}

dataType getNode(SeqList *list, int index) {
    if (index < 1 || index > list->length) {
        printf("位置错误");
        exit(0);
    }
    return list->data[index - 1];
}

int locateNode(SeqList *list, dataType data) {
    int i;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] == data) {
            return i + 1;
        }
    }
    return 0;
}

int getLength(SeqList *list) {
    return list->length;
}

void show(SeqList *list) {
    int i;
    printf("[");
    for (i = 0; i < list->length; i++) {
        printf("%d", list->data[i]);
        if(i < list->length-1){
            printf(",");
        }
    }
    printf("]\n");
}

int main() {
    SeqList *list = init();
    insert(list, 1, 10);
    insert(list, 2, 20);
    insert(list, 3, 30);
    insert(list, 4, 40);
    insert(list, 5, 50);
    printf("插入5个元素后顺序表长度: %d\n", getLength(list));
    show(list);
    delete(list, 5);
    delete(list, 4);
    printf("删除位置5和4后顺序表长度: %d\n", getLength(list));
    show(list);

    printf("第一个元素: %d\n", getNode(list, 1));
    printf("值20的位置: %d\n", locateNode(list, 20));
    free(list);
    return 0;
}
