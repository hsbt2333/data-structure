/*
 * Created by 致命之猫 on 2024-03-13 0:27
 */
#include <stdio.h>
#include <stdlib.h>
#ifndef DATA_STRUCTURE_LINKSTACK_H
#define DATA_STRUCTURE_LINKSTACK_H

#endif //DATA_STRUCTURE_LINKSTACK_H

typedef int dataType;

typedef struct node {
    dataType data;
    struct node *next;
} LinkNode, *LinkStack;

LinkStack init(){
    LinkNode* top = (LinkNode*)malloc(sizeof(LinkNode));
    top->next = NULL;
    return top;
}

void push(LinkStack top,dataType data){
    LinkNode *p = (LinkNode*)malloc(sizeof(LinkNode));
    p->data = data;
    p->next = top->next;
    top->next = p;
}

dataType pop(LinkStack top){
    LinkNode *p = top->next;
    dataType x = p->data;
    top->next = p->next;
    free(p);
    return x;
}

int isEmpty(LinkStack top){
    return top->next == NULL;
}

dataType getTop(LinkStack top){
    return top->next->data;
}

int getSize(LinkStack top){
    LinkNode *p = top;
    int length = 0;
    while (p->next != NULL){
        p = p->next;
        length++;
    }
    return length;
}

void show(LinkStack top){
    printf("栈顶到栈底: [");
    LinkNode *p = top->next;
    while (p != NULL){
        printf("%d", p->data);
        if(p->next != NULL) printf(",");
        p = p->next;
    }
    printf("]\n");
}