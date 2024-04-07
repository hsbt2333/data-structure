/*
 * Created by 致命之猫 on 2024-03-10 23:39
 */
#include "LinkStack.h"

int main() {
    LinkStack top = init();
    printf("栈是否空 %s\n", isEmpty(top) ? "true" : "false");
    push(top, 10);
    push(top, 2);
    push(top, 33);
    push(top, 44);
    push(top, 55);
    push(top, 66);
    push(top, 77);
    push(top, 88);
    push(top, 99);
    push(top, 100);
    push(top, 101);
    //printf("%d\n", top->top);
    //printf("%lu,%lu\n", sizeof(SeqStack),sizeof(SeqStack*));
    show(top);
    printf("栈长度 %d\n", getSize(top));
    printf("栈顶元素 %d\n", getTop(top));
    int i;
    for (i = 0; i < 12; ++i) {
        if (i == 1) {
            printf("入栈 10000\n");
            push(top, 10000);
        }
        printf("出栈 %d\t", pop(top));
        printf("\t栈长度 %d", getSize(top));
        printf("\t\t栈是否空 %s\n", isEmpty(top) ? "true" : "false");
        show(top);
    }
    printf("入栈 101\n");
    push(top, 101);
    printf("栈长度 %d\n", getSize(top));
    printf("栈顶元素 %d\n", getTop(top));
    show(top);
    return 0;
}