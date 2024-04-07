/*
 * Created by 致命之猫 on 2024-03-05 20:27
 * 顺序表
 */
#include <stdio.h>
#include <stdlib.h>

typedef int element_type;

typedef struct {
    element_type data[10];
    int length;
} seq_list;

// 1 初始化循序表
seq_list *init_list();

// 2 求表长
int size(seq_list *list);

// 3 查找某个元素
element_type query_index(seq_list *list, int index);

// 4 按值查找
int query_element(seq_list *list, element_type e);

// 5 插入元素到某个位置
void insert(seq_list *list, int index, element_type e);

// 6 删除元素某个元素
element_type delete(seq_list *list, int index);

// 7 输出顺序表
void print(seq_list *list);

// 添加元素到顺序表最后一个位置
void add(seq_list *list, element_type e);

// 删除顺序表最后一个位置
element_type delete_list(seq_list *list);

// 顺序表逆置
void reverse(seq_list *list);

// 找出最大值和最小值
void query_max_min(seq_list *list, element_type *max, element_type *min);

int main() {
    seq_list *list = init_list();
    int i;
    for (i = 1; i < 9; i++) {
        add(list, i * 200);
    }
    print(list);
    reverse(list);
    print(list);

    element_type *max = malloc(sizeof(element_type));
    element_type *min = malloc(sizeof(element_type));
    query_max_min(list, max, min);
    printf("max:%d,min:%d\n", *max, *min);
    free(max);
    free(min);
    free(list);
    /*printf("表的长度: %d\n", size(list));

    element_type insert_e = 10;
    insert(list, 1, insert_e);
    printf("表的长度: %d\n", size(list));
    print(list);

    element_type delete_e = delete(list, 2);
    printf("删除第2个元素: %d\n", delete_e);
    printf("表的长度: %d\n", size(list));
    print(list);
    element_type query_e;
    query_e = query_index(list, 5);
    printf("表中第1个元素: %d\n", query_e);

    add(list, 10);
    add(list, 20);
    delete_list(list);
    int query_index;
    element_type query_ten = 10;
    query_index = query_element(list, query_ten);
    printf("表中最后一个值等于10的位置: %d\n", query_index);

    print(list);*/
    return 0;
}

// 如果要向形参指针赋值，使用两个*
seq_list *init_list() {
    seq_list *list = (seq_list *) malloc(sizeof(seq_list));
    list->length = 0;
    return list;
}

int size(seq_list *list) {
    return list->length;
}

element_type query_index(seq_list *list, int index) {
    if (index < 1 || index > list->length) {
        printf("位置错误");
        exit(0);
    }
    return list->data[index - 1];
}

int query_element(seq_list *list, element_type e) {
    int result;
    int i;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] == e) {
            result = i + 1;
        }
    }
    if (result > list->length) {
        return -1;
    }
    return result;
}

void insert(seq_list *list, int index, element_type e) {
    if (list->length == 10) {
        printf("顺序表已满");
        exit(0);
    }
    if (index < 1 || index > list->length) {
        printf("位置错误");
        exit(0);
    }
    int i;
    for (i = list->length - 1; i >= index - 1; i--) {
        list->data[i + 1] = list->data[i];
    }
    list->data[index - 1] = e;
    list->length++;
}

element_type delete(seq_list *list, int index) {
    if (index < 1 || index > list->length) {
        printf("位置错误");
        exit(0);
    }
    element_type result = list->data[index - 1];
    int i;
    for (i = index; i < list->length; i++) {
        list->data[i - 1] = list->data[i];
    }
    list->length--;
    return result;
}

void print(seq_list *list) {
    int i;
    printf("[");
    for (i = 0; i < list->length; i++) {
        printf("%d", list->data[i]);
        if (i != list->length - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void add(seq_list *list, element_type e) {
    if (list->length == 10) {
        printf("顺序表已满");
    } else {
        list->data[list->length++] = e;
    }
}

element_type delete_list(seq_list *list) {
    return list->data[--list->length];
}

void reverse(seq_list *list) {
    element_type temp;
    int i;
    for (i = 0; i < list->length / 2; i++) {
        temp = list->data[i];
        list->data[i] = list->data[list->length - 1 - i];
        list->data[list->length - 1 - i] = temp;
    }
}

// *max=xx,将xx的值赋给指针max的位置
// max=&xx,将max指向xx的地址
void query_max_min(seq_list *list, element_type *max, element_type *min) {
    *max = list->data[0];
    *min = list->data[0];
    int i;
    for (i = 0; i < list->length; i++) {
        if (list->data[i] > *max) {
            *max = list->data[i];
        } else if (list->data[i] < *min) {
            *min = list->data[i];
        }
    }
}
