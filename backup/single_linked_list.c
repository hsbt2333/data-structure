/*
 * Created by 致命之猫 on 2024-03-05 22:10
 * 单链表 带头节点
 */
#include <stdio.h>
#include <stdlib.h>

typedef int elem_type;
typedef struct node {
    elem_type data;
    struct node *next;
} single_linked_node, *single_linked_list;

single_linked_list create();

single_linked_list create_head();

single_linked_list create_tail();

void insert(single_linked_node *head, int index, elem_type elemType);

void insert_head(single_linked_node *head, elem_type elemType);

void insert_tail(single_linked_node *head, elem_type elemType);

elem_type delete(single_linked_node *head, int index);

elem_type delete_head(single_linked_node *head);

elem_type delete_tail(single_linked_node *head);

int get_size(single_linked_node *head);

int is_empty(single_linked_node *head);

single_linked_node *query(single_linked_node *head, int index);

single_linked_node *query_elem(single_linked_node *head, elem_type elemType);

void linked_list_print(single_linked_node *head);

/* 201910 算法设计题 */
/* 在带头结点的单链表L中删除数值在指定范围内的结点 */
void f34(single_linked_list L, int x, int y);

int main() {
    //single_linked_list head = create_head();
    //single_linked_list head = create_tail();
    //single_linked_list head = create();
    /*insert(head,1,10);
    insert(head,1,20);
    insert(head,2,30);
    insert(head,1,40);*/

    /*insert_head(head,10);
    insert_head(head,20);
    insert_head(head,30);
    insert_head(head,40);*/

    /*insert_tail(head, 11);
    insert_tail(head, 22);
    insert_tail(head, 33);
    insert_tail(head, 44);
    insert_tail(head, 55);
    insert_tail(head, 66);
    linked_list_print(head);
    printf("链表长度: %d\n", get_size(head));*/
    // delete(head,4);

    /*delete_head(head);
    linked_list_print(head);

    delete_head(head);
    linked_list_print(head);*/

    /*printf("删除尾结点的值: %d\n", delete_tail(head));
    linked_list_print(head);
    printf("链表长度: %d\n", get_size(head));

    printf("删除尾结点的值: %d\n", delete_tail(head));
    linked_list_print(head);
    printf("链表长度: %d\n", get_size(head));

    single_linked_node *p = query(head, 3);
    printf("查询的值: %d\n", p->data);

    p = query_elem(head, 44);
    printf("查询的值: %d\n", p->data);*/

    single_linked_list head = create();
    insert_tail(head, 430);
    insert_tail(head, 105);
    linked_list_print(head);
    f34(head,100,200);
    linked_list_print(head);
    return 0;
}

void linked_list_print(single_linked_node *head) {
    if (is_empty(head)) {
        printf("[]\n");
    } else {
        printf("[");
        single_linked_node *p = head->next;
        while (p != NULL) {
            printf("%d", p->data);
            if (p->next != NULL) {
                printf(",");
            }
            p = p->next;
        }
        printf("]\n");
    }
}

int is_empty(single_linked_node *head) {
    return head->next == NULL;
}

// 创建一个空的头节点
single_linked_list create() {
    single_linked_list head = (single_linked_list) malloc(sizeof(single_linked_node));
    head->next = NULL;
    return head;
}

// 创建输入若干数据的单链表 在头结点后插入
single_linked_list create_head() {
    single_linked_list head = (single_linked_list) malloc(sizeof(single_linked_node));
    single_linked_node *p;
    char ch = getchar();
    while (ch != '\n') {
        p = (single_linked_node *) malloc(sizeof(single_linked_node));
        p->data = ch;
        p->next = head->next;
        head->next = p;
        // 不带头节点
        //p->next = head;
        //head = p;
        ch = getchar();
    }
    return head;
}

// 创建输入若干数据的单链表 在尾结点后插入
single_linked_list create_tail() {
    single_linked_list head = (single_linked_list) malloc(sizeof(single_linked_node));
    single_linked_node *p, *tail;
    elem_type e = getchar();
    while (e != '\n') {
        printf("%d", e);
        p = (single_linked_node *) malloc(sizeof(single_linked_node));
        p->data = e;
        tail->next = p;
        tail = p;
        e = getchar();
    }
    return head;
}

void insert(single_linked_node *head, int index, elem_type elemType) {
    single_linked_node *p = head;
    int i = 0;
    while (i < index - 1 && p != NULL) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("%d 插入位置错误\n", index);
    } else {
        single_linked_node *s = (single_linked_node *) malloc(sizeof(single_linked_node));
        s->data = elemType;
        s->next = p->next;
        p->next = s;
    }
}

void insert_head(single_linked_node *head, elem_type elemType) {
    single_linked_node *p = (single_linked_node *) malloc(sizeof(single_linked_node));
    p->data = elemType;
    p->next = head->next;
    head->next = p;
}

void insert_tail(single_linked_node *head, elem_type elemType) {
    single_linked_node *tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }
    single_linked_node *p = (single_linked_node *) malloc(sizeof(single_linked_node));
    p->data = elemType;
    tail->next = p;
}

elem_type delete(single_linked_node *head, int index) {
    if (is_empty(head)) {
        printf("链表为空，删除错误");
        exit(0);
    }
    single_linked_node *p = head;
    int i;
    for (i = 0; i < index - 1 && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL || p->next == NULL) {
        printf("删除错误，未找到位置");
        exit(0);
    }
    single_linked_node *s = p->next;
    elem_type e = s->data;
    p->next = s->next;
    free(s);
    return e;
}

elem_type delete_head(single_linked_node *head) {
    if (is_empty(head)) {
        printf("链表为空，删除错误");
        exit(0);
    }
    single_linked_node *p = head->next;
    head->next = p->next;
    elem_type e = p->data;
    free(p);
    return e;
}

elem_type delete_tail(single_linked_node *head) {
    if (is_empty(head)) {
        printf("链表为空，删除错误");
        exit(0);
    }
    single_linked_node *p = head->next;
    while (p->next != NULL && p->next->next != NULL) {
        p = p->next;
    }
    single_linked_node *s = p->next;
    elem_type e = s->data;
    free(s);
    p->next = NULL;
    return e;
}

int get_size(single_linked_node *head) {
    single_linked_node *tail = head;
    int i;
    for (i = 0; tail->next != NULL; i++) {
        tail = tail->next;
    }
    return i;
}

single_linked_node *query(single_linked_node *head, int index) {
    single_linked_node *p = head->next;
    int i;
    for (i = 1; i < index && p != NULL; i++) {
        p = p->next;
    }
    if (p == NULL) {
        printf("查询位置错误");
        exit(0);
    }
    // 也可以判断 i == index 返回 p，否则返回NULL
    return p;
}

single_linked_node *query_elem(single_linked_node *head, elem_type elemType) {
    single_linked_node *p = head->next;
    while (p != NULL && p->data != elemType) {
        p = p->next;
    }
    return p;
}

void f34(single_linked_list L, int x, int y) {
    single_linked_node *p = L, *s;
    while (p != NULL && p->next != NULL) {
        s = p->next;
        if (x <= s->data && s->data <= y) {
            p->next = s->next;
            free(s);
        } else{
            p = p->next;
        }
    }
}


