/*
 * Created by 致命之猫 on 2024-03-10 17:52
 * 双向链表的实现
 * 双向链表一般都是带头结点的双向循环链表
 */
#include <stdio.h>
#include <stdlib.h>
//1 定义数据类型
typedef int dataType;
//2 定义结构体和头结点指针
typedef struct node{
    dataType data;
    struct node *prior;
    struct node *next;
}DLNode,*DLList;

void showHeadStart(DLList head){
    DLNode *p = head->next;
    printf("[");
    while (p != head) {
        printf("%d",p->data);
        if(p->next != head){
            printf(",");
        }
        p = p->next;
    }
    printf("]\n");
}

void showTailStart(DLList head){
    DLNode *p = head->prior;
    printf("[");
    while (p != head) {
        printf("%d",p->data);
        if(p->prior != head){
            printf(",");
        }
        p = p->prior;
    }
    printf("]\n");
}

//3 双向链表的运算，头插法，尾插法，插入，删除，按值查找，按位置查找
DLList insertHead(){
    DLList head = (DLList)malloc(sizeof(DLNode));
    DLNode *p;
    head->prior = head;
    head->next = head;
    int i;
    // 头插法插入10个元素
    // TODO 错误点 1 忘记使用前指针 2 head->next 不可能为空，因为是循环链表
    for (i = 0; i < 10; ++i) {
        p = (DLNode*)malloc(sizeof(DLNode));
        p->data = (i+1)*100;
        p->next = head->next;
        p->prior = head;
        head->next->prior = p;
        head->next = p;
    }
    return head;
}

DLList insertTail(){
    // 声明指针表示当前元素 和 尾结点
    DLNode *p,*tail;
    // 初始化头结点
    DLList head = (DLList)malloc(sizeof(DLNode));
    head->prior = head;
    head->next = head;
    // 尾插法插入10个元素
    int i;
    for (i = 0; i < 10; ++i) {
        p = (DLNode*)malloc(sizeof(DLNode));
        p->data = (i+1)*100;
        p->next = head;
        p->prior = head->prior;
        head->prior->next = p;
        head->prior = p;
    }
    return head;
}

void insert(DLList head,int index,dataType data){
    DLNode *s,*p = head;
    if(index < 1) {
        printf("位置错误");
        return;
    }
    int i = 0;
    /*
    while (p->next != head && i < index){
        p = p->next;
        i++;
    }
    // 如果不是通过 i < index 退出循环的，那将插在尾结点后，也就是头结点前
    // 如果不将head赋值给p，那么index大于链表长度时，将永远插入在尾结点之前的位置，这显然不符合逻辑
    if(i < index) p = head;
    s = (DLNode *)malloc(sizeof(DLNode));
    s->data =data;
    s->next = p;
    s->prior = p->prior;
    p->prior->next = s;
    p->prior = s;
    */
    // 找到前一个结点，然后插入到这个结点之后
    while (p->next != head && i < index-1){
        p = p->next;
        i++;
    }
    s = (DLNode *)malloc(sizeof(DLNode));
    s->data =data;
    s->next = p->next;
    s->prior = p;
    p->next->prior = s;
    p->next = s;
}

DLNode* getNode(DLList head,int index){
    DLNode* p = head->next;
    int i = 1;
    while (p != head && i < index){
        p = p->next;
        i++;
    }
    if(i == index) return p;
    return NULL;
}

// 找到第一个值为data的结点
DLNode* locateNode(DLList head,dataType data){
    DLNode* p = head->next;
    while (p != head){
        if(p->data == data) return p;
        p = p->next;
    }
    //return p;
    return NULL;
}

//删除
dataType deleteNode(DLList head,int index){
    DLNode *s,*p=head;
    dataType data = -1;
    int i = 0;
    while (p->next != head && i < index){
        p = p->next;
        i++;
    }
    if(p == head) {
        printf("删除失败，位置错误");
    }else{
        //if(i == index)
        s = p;
        data = s->data;
        // TODO 这里我也写错过，竟然写的是修改p的前驱了，应该是前驱的后驱等于p的后驱
        p->next->prior = p->prior;
        p->prior->next = p->next;
        free(s);
    }
    return data;
}

//4 尾结点来表示双向链表的运算，头插法，尾插法，插入，按值查找，按位置查找
/*
 * TODO 我又搞错了，双向循环链表头插法尾插法就不用输入尾结点了，因为头结点的前一个结点就是尾结点
 * TODO 所以头插法和尾插法一样容易，并不需要特意用尾结点
 */


int main(){
    //DLList head = insertHead();
    //showHeadStart(head);
    //showTailStart(head);
    //free(head);
    DLList head = insertTail();
    showHeadStart(head);
    //showTailStart(head);
    insert(head,12,111);
    //insert(head,110,222);
    //insert(head,110,333);
    //insert(head,1,333);
    //insert(head,1,444);
    //insert(head,1,555);
    showHeadStart(head);
    DLNode *p = getNode(head,1);
    if(p != NULL){
        printf("获取第1个元素 %d\n",p->data);
    }
    DLNode *p1 = locateNode(head,1000);
    if(p != NULL){
        //因为带头结点，头结点为0
        //加了一个判断是否是头结点的情况，如果是就跳到下一个结点，如果不是直接输出
        printf("获取值为 1000 的结点的前驱: %d,后驱: %d\n",
               p1->prior == head?p1->prior->prior->data:p1->prior->data,
               p1->next == head?p1->next->next->data:p1->next->data);
    }
    printf("删除第 10 个结点 返回值: %d\n",deleteNode(head,10));
    showHeadStart(head);
    return 0;
}
