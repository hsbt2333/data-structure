/*
 * Created by 致命之猫 on 2024-03-12 23:26
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef DATA_STRUCTURE_SEQSTACK_H
#define DATA_STRUCTURE_SEQSTACK_H

#endif //DATA_STRUCTURE_SEQSTACK_H
#define MAX_LENGTH 10
typedef int dataType;

typedef struct {
    dataType data[MAX_LENGTH];
    int top;
} SeqStack;

SeqStack *init() {
    // TODO malloc必须初始化结构体的别名，不能初始化指针，初始化的指针只有8字节
    // TODO 而整个结构体应该占44字节，int占4字节，数组10个元素int类型 占40字节。
    SeqStack *stack = (SeqStack *) malloc(sizeof(SeqStack));
    stack->top = -1;
    return stack;
}

void push(SeqStack *stack, dataType data) {
    if (stack->top == MAX_LENGTH - 1) {
        printf("---栈已满---\n");
        return;
    }
    stack->data[++stack->top] = data;
}

dataType pop(SeqStack *stack) {
    if (stack->top == -1) {
        printf("---栈空---\n");
        return -1;
    }
    return stack->data[stack->top--];
}

int isEmpty(SeqStack *stack) {
    return stack->top == -1;
}

dataType getTop(SeqStack *stack) {
    if (stack->top == -1) {
        printf("栈空\n");
        return -1;
    }
    return stack->data[stack->top];
}

int getSize(SeqStack *stack) {
    return stack->top + 1;
}

void show(SeqStack *stack) {
    printf("栈顶到栈底: [");
    int i;
    for (i = stack->top; i >= 0; i--) {
        printf("%d", stack->data[i]);
        if (i != 0) {
            printf(",");
        }
    }
    printf("]\n");
}