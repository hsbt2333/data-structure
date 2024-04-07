/*
 * Created by 致命之猫 on 2024-03-10 23:39
 * 算了不写了，带头结点，不带头结点，带头结点的循环队列，不带头结点的循环队列，真的麻烦。
 */
#include <stdio.h>
#include <stdlib.h>

typedef int dataType;
typedef struct node {
    dataType data;
    struct node *next;
} LinkNode;

typedef struct {
    LinkNode *front;
    LinkNode *rear;
} Queue, *LinkQueue;

// 不带头结点
LinkQueue init() {
    LinkQueue queue = (Queue *) malloc(sizeof(Queue));
    queue->front = queue->rear = NULL;
    return queue;
}

int isEmpty(LinkQueue queue){
    return queue->front == NULL;
}

void enqueue(LinkQueue queue, dataType data) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    p->data = data;
    if(queue->rear == NULL) {
        queue->front = p;
        queue->rear = p;
        queue->front->next = queue->rear;
    }else{
        queue->rear->next = p;
        queue->rear = p;
    }
}

dataType dequeue(LinkQueue queue) {
    dataType x = -1;
    if(queue->front == NULL){
        printf("出队失败！队为空\n");
        return x;
    }
    LinkNode *p = queue->front;
    queue->front = p->next;
    x = p->data;
    free(p);
    return x;
}

dataType getFront(LinkQueue queue){
    if(queue->front == queue->rear) return -1;
    return queue->front->data;
}

void show(LinkQueue queue){
    printf("队列从头到尾: [");
    LinkNode *p = queue->front;
    while (p != NULL) {
        printf("%d",p->data);
        if(p->next != NULL){
            printf(",");
        }
        p = p->next;
    }
    printf("]\n");
}

int main() {
    LinkQueue queue = init();
    show(queue);
    int i;
    for (i = 0; i < 9; ++i) {
        enqueue(queue, 10);
        printf("队头: %d\t", getFront(queue));
        printf("出队元素: %d\t", dequeue(queue));
        printf("front: %d\t", queue->front->data);
        printf("rear:%d\n", queue->rear->data);
    }
    for (i = 0; i < 9; ++i) {
        enqueue(queue, (i + 1) * 10);
    }
    show(queue);
    enqueue(queue, 100);
    show(queue);
    printf("front: %d\t", queue->front->data);
    printf("rear:%d\n", queue->rear->data);

    for (i = 0; i < 9; ++i) {
        if (i == 5) {
            printf("\n999入队\n");
            enqueue(queue, 999);
        }
        printf("\t出队元素: %d", dequeue(queue));
    }
    printf("\n");
    show(queue);
    return 0;
}