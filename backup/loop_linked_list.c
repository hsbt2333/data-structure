/*
 * Created by 致命之猫 on 2024-03-05 22:10
 * 循环链表 不带头节点 插入删除都要返回链表指针，很麻烦
 * 循环打印元素用do while，头不为空时将头赋值给p，do执行一次打印元素，再将p->next赋值给p，
 * while判断p不为空且p不等于头，因为p已经被赋值为p->next了，所以是判断 p != 头。
 * 用while，先将头赋值给p，while判断p不为空，不为空开始循环，循环体里再判断p->next等不等于头，等于就跳出循环，
 * 不等于就将p->next赋值给p，再开始下一次循环
 */
#include <stdio.h>
#include <stdlib.h>

typedef int data_type;

typedef struct node {
    data_type data;
    struct node *next;
} linked_node, *linked_list;

//初始化 判空 链表长度 插入 删除 按位置查找 按值查找 显示
void show(linked_list head);

linked_node init();

linked_list create(data_type data);

int isEmpty(linked_list head);

int getLength(linked_list head);

linked_list insert(linked_list head, int index, data_type data);

linked_list insertHead(linked_list head, data_type data);

linked_list insertRear(linked_list head, data_type data);

linked_list insertTail(linked_list tail, data_type data);

linked_list insertHeadReturnTail(linked_list tail, data_type data);

int main() {
    // 不带头节点
    //linked_list head = NULL;
    /* 头插法返回头 */
    /*head = insertHead(head,50);
    head = insertHead(head,40);
    head = insertHead(head,30);
    head = insertHead(head,20);
    head = insertHead(head,10);*/

    // 尾插法返回头
    /*head = insertRear(head,10);
    head = insertRear(head,20);
    head = insertRear(head,30);
    head = insertRear(head,40);
    head = insertRear(head,50);
    head = insertRear(head,50);*/
    //show(head);
    // 尾插法 返回尾
    //linked_list tail = NULL;
    /*tail = insertTail(tail,10);
    tail = insertTail(tail,20);
    tail = insertTail(tail,30);
    tail = insertTail(tail,40);*/

    /*tail = insertHeadReturnTail(tail,10);
    tail = insertHeadReturnTail(tail,20);
    tail = insertHeadReturnTail(tail,30);
    tail = insertHeadReturnTail(tail,40);
    tail = insertHeadReturnTail(tail,50);*/
    //show(tail->next);

    linked_list head = NULL;
    head = insert(head,1,10);
    head = insert(head,1,20);
    head = insert(head,1,30);
    head = insert(head,1,40);
    head = insert(head,1,50);
    /*head = insert(head,2,22);
    head = insert(head,3,33);
    head = insert(head,2,22);
    head = insert(head,20,2200);
    head = insert(head,100,2300);
    head = insert(head,14,2400);
    head = insert(head,18,2500);
    head = insert(head,1,2600);*/
    /*insert(&head,getLength(head),60);
    insert(&head,getLength(head),70);
    insert(&head,getLength(head),80);
    insert(&head,getLength(head),90);
    insert(&head,getLength(head),100);*/
    show(head);
    show(head->next);
    printf("%d\n", getLength(head));
    return 0;
}

// while实现
void show(linked_list head) {
    printf("[");
    linked_node *p = head;
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != head) {
            printf(",");
        }
        if(p->next == head) break;
        p = p->next;
    }
    printf("]\n");
}

// 不带头节点的初始化
linked_node init() {
    linked_node result;
    return result;
}

// 创建链表并插入1个元素
linked_list create(data_type d) {
    linked_list head = malloc(sizeof(linked_list));
    head->data = d;
    head->next = head;
    return head;
}

int isEmpty(linked_list head) {
    return head == NULL;
}

// do while 实现
int getLength(linked_list head) {
    int length = 0;
    if(head != NULL){
        linked_node *p = head;
        do{
            length++;
            p = p->next;
        }while (p != NULL && p != head);
    }
    return length;
}

// 头插法
linked_list insertHead(linked_list head, data_type data) {
    linked_node *p = malloc(sizeof(linked_list)), *s;
    p->data = data;
    if (head != NULL) {
        s = head;
        while (s && s->next != head) {
            s = s->next;
        }
        s->next = p;
        p->next = head;
        head = p;
    } else {
        head = p;
        head->next = head;
    }
    return head;
}

linked_list insertRear(linked_list head, data_type data) {
    linked_node *p = head,*s;
    while (p && p->next !=head){
        p = p->next;
    }
    s = malloc(sizeof(linked_list));
    s->data = data;
    if(p == NULL) p = s;
    s->next = p->next;
    p->next = s;
    return s->next;
}

linked_list insertHeadReturnTail(linked_list tail, data_type data) {
    linked_node *p = malloc(sizeof(linked_list));
    p->data = data;
    if(tail == NULL) {
        tail = p;
        tail->next = tail;
    } else{
        p->next = tail->next;
        tail->next = p;
    }
    return tail;
}

linked_list insertTail(linked_list tail, data_type data) {
    linked_node *p = malloc(sizeof(linked_list));
    if(tail == NULL) tail = p;
    p->data = data;
    p->next = tail->next;
    tail->next = p;
    tail = p;
    return tail;
}

linked_list insert(linked_list head, int index, data_type data){
    if(head != NULL && index > 1){
        linked_node *p = malloc(sizeof(linked_list)),*s = head;
        p->data = data;
        int i;
        for(i=0;i<index-1&&s->next!=head;i++){
            s = s->next;
        }
        p->next = s->next;
        s->next = p;
        return head;
    } else{
        return insertHead(head,data);
    }
}
