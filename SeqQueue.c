/*
 * Created by 致命之猫 on 2024-03-09 23:51
 * 顺序循环队列
 */
#include "SeqQueue.h"

int main() {
    SeqQueue *queue = init();
    show(queue);
    int i;
    for (i = 0; i < 9; ++i) {
        enqueue(queue, 10);
        printf("队头: %d\t", getFront(queue));
        printf("出队元素: %d\t", dequeue(queue));
        printf("front: %d\t", queue->front);
        printf("rear:%d\n", queue->rear);
    }
    for (i = 0; i < 9; ++i) {
        enqueue(queue, (i + 1) * 10);
    }
    show(queue);
    enqueue(queue, 100);
    show(queue);
    printf("front: %d\t", queue->front);
    printf("rear:%d\n", queue->rear);

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