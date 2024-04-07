/*
 * Created by 致命之猫 on 2024-03-12 23:22
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef DATA_STRUCTURE_SEQQUEUE_H
#define DATA_STRUCTURE_SEQQUEUE_H

#endif //DATA_STRUCTURE_SEQQUEUE_H
#define MAX_LENGTH 10
typedef int dataType;
typedef struct {
    dataType data[MAX_LENGTH];
    int front, rear;
} SeqQueue;

SeqQueue *init() {
    SeqQueue *queue = (SeqQueue *) malloc(sizeof(SeqQueue));
    queue->front = queue->rear = 0;
    return queue;
}

int isEmpty(SeqQueue *queue) {
    return queue->front == queue->rear;
}

// 少用一个空间表示队满 rear永远指向队列的下一个位置
int isFull(SeqQueue *queue) {
    return (queue->rear + 1) % MAX_LENGTH == queue->front;
}

void enqueue(SeqQueue *queue, dataType data) {
    if (isFull(queue)) {
        printf("队列已满\n");
        return;
    }
    queue->data[queue->rear] = data;
    queue->rear = (queue->rear + 1) % MAX_LENGTH;
}

dataType dequeue(SeqQueue *queue) {
    dataType data = -1;
    if (isEmpty(queue)) {
        printf("空队列\n");
        return data;
    }
    data = queue->data[queue->front];
    queue->front = (queue->front + 1) % MAX_LENGTH;
    return data;
}

dataType getFront(SeqQueue *queue) {
    if (isEmpty(queue)) {
        printf("空队列\n");
        return -1;
    }
    return queue->data[queue->front];
}

void show(SeqQueue *queue) {
    printf("队列从头到尾: [");
    int i;
    for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_LENGTH) {
        printf("%d", queue->data[i]);
        if (i != queue->rear - 1) {
            printf(",");
        }
    }
    printf("]\n");
}