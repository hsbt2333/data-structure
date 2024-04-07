/*
 * Created by 致命之猫 on 2024-03-09 23:50
 * 带头结点的单链表
 * 插入 删除 按位置查找 按值查找 初始化 求表长
 */
#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct node {
    dataType data;
    struct node *next;
} LinkedNode, *LinkedList;

void show(LinkedList head) {
    LinkedNode *p = head->next;
    printf("[");
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) {
            printf(",");
        }
        p = p->next;
    }
    printf("]\n");
}

// 带头结点的链表 插入位置 index 前一个位置判断为 i < index - 1，
// 需要两个指针变量，一个表示插入位置前一个结点，一个表示需要插入的结点
// 如果插入位置前一个结点为空，则说明位置输入错误
// 当链表为空并且插入位置合法时，p不会等于空，可以正常插入
void insert(LinkedList head, int index, dataType data) {
    if(index < 1){
        printf("[%d] 插入位置错误\n",index);
        return;
    }
    LinkedNode *p, *s;
    int i = 0;
    p = head;
    while (p != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("[%d] 插入位置错误\n",index);
    } else {
        s = (LinkedNode *) malloc(sizeof(LinkedNode));
        s->data = data;
        s->next = p->next;
        p->next = s;
    }
}

dataType delete(LinkedList head, int index) {
    LinkedNode *p, *s;
    dataType x;
    int i = 0;
    p = head;
    while (p != NULL && i < index - 1) {
        p = p->next;
        i++;
    }
    if (p == NULL || p->next == NULL) {
        printf("删除位置错误\n");
        return -1;
    } else {
        s = p->next;
        p->next = s->next;
        x = s->data;
        free(s);
        return x;
    }
}

LinkedNode *getNode(LinkedList head, int index) {
    LinkedNode *p = head->next;
    int i = 1;
    while (p && i < index) {
        p = p->next;
        i++;
    }
    if (i == index) {
        return p;
    }
    return NULL;
}

LinkedNode *locateNode(LinkedList head, dataType data) {
    LinkedNode *p = head->next;
    while (p && p->data != data) {
        p = p->next;
    }
    return p;
}

void insertHead(LinkedList head) {
    LinkedNode *p;
    int i;
    for (i = 0; i < 10; i++) {
        p = (LinkedNode *) malloc(sizeof(LinkedNode));
        p->data = (i + 1) * 100;
        p->next = head->next;
        head->next = p;// 一定要注意 不要写错
    }
}

void insertRear(LinkedList head) {
    LinkedNode *p,*r = head->next;
    int i;
    while(r->next != NULL){
        r = r->next;
    }
    for (i = 0; i < 10; i++) {
        p = (LinkedNode *) malloc(sizeof(LinkedNode));
        p->data = (i + 1) * 100;
        r->next = p;
        r = p;
    }
}

void f34(LinkedList L){
    LinkedNode *p = L,*s;
    if(p->next != NULL){
        int min = p->next->data;
        s = p;
        while(p->next != NULL){
            if(min > p->next->data){
                s = p;
                min = p->next->data;
            }
            p = p->next;
        }
        p = s->next;
        s->next = p->next;
        free(p);
    }
}


int main() {
    LinkedList head = (LinkedNode *) malloc(sizeof(LinkedNode));
    head->next = NULL;
    //insertHead(head);
    //show(head);
    //insertRear(head);
    //show(head);

    insert(head,1,111);
    insert(head,1,2);
    insert(head,1,333);
    insert(head,1,444);
    //insert(head,0,0);
    //insert(head,100,0);
    insert(head,5,555);
    insert(head,6,666);
    insert(head,7,777);
    //insert(head,9,999);
    insert(head,8,888);
    show(head);
    /*printf("删除位置 10，返回值: %d\n",delete(head,10));
    printf("删除位置 9，返回值: %d\n",delete(head,9));
    //delete(head,9);
    printf("删除位置 8，返回值: %d\n",delete(head,8));
    printf("删除位置 7，返回值: %d\n",delete(head,7));
    show(head);
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    show(head);
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    show(head);
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    show(head);
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    printf("删除位置 1，返回值: %d\n",delete(head,1));
    printf("删除位置 1，返回值: %d\n",delete(head,1));*/
    f34(head);
    show(head);
    free(head);
    return 0;
}
/**
 * 202210
CDAAB
CDBBD
ADDCD
二叉树转森林 森林一定唯一
16 逻辑
17 开始元素
18 顺序栈
19 (a,b)
20 根节点
21 邻接点
22 0
23 基准
24 大根堆
25 散列函数或哈希函数
			A
	B				C
D		E 		F		G
	  H				  I

30
(1) 55
(2) 求前两项的和

31 -1，1
二分查找

32
min[i] > A[i][j]
max[j] = a[i][j]
min[n] == max[m]

33
R[j-1]=R[0]
NoSwap = 1
i++

34
void f34(LinkList L){
	ListNode *p = head,*s;
	if(p->next != NULL){
		int min = p->next->data;
		s = p;
		while(p->next != NULL){
			if(min > p->next->data){
				s = p;
				min = p->next->data;
			}
			p = p->next;
		}
		p = s->next;
		s->next = p->next;
		free(p);
	}
}
*/