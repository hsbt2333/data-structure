/*
 * Created by 致命之猫 on 2024-03-09 23:51
 * 顺序栈
 */
#include "SeqStack.h"

int main() {
    SeqStack *stack = init();
    push(stack, 10);
    push(stack, 2);
    push(stack, 33);
    push(stack, 44);
    push(stack, 55);
    push(stack, 66);
    push(stack, 77);
    push(stack, 88);
    push(stack, 99);
    push(stack, 100);
    push(stack, 101);
    //printf("%d\n", stack->top);
    //printf("%lu,%lu\n", sizeof(SeqStack),sizeof(SeqStack*));
    show(stack);
    printf("栈顶元素 %d\n", getTop(stack));
    int i;
    for (i = 0; i < 12; ++i) {
        if (i == 1) {
            printf("入栈 10000\n");
            push(stack, 10000);
        }
        printf("出栈 %d\t", pop(stack));
        printf("\t栈长度 %d", getSize(stack));
        printf("\t\t栈是否空 %s\n", isEmpty(stack) ? "true" : "false");
        show(stack);
    }
    printf("入栈 101\n");
    push(stack, 101);
    show(stack);
    return 0;
}
