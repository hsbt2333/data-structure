/*
 * Created by 致命之猫 on 2024-03-11 20:26
 */
#include <stdio.h>
#include <stdlib.h>
typedef char dataType1;

typedef struct treeNode{
    dataType1 data;
    struct treeNode *lChild,*rChild;
}BinNode,*BinTree;

typedef BinNode* dataType;

typedef struct node {
    BinNode* data;
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

// ABC DE FG
// 将广义表插入二叉树
// (A(B(,D(E,F)),C))
BinTree init1(const char *str){
    // 用栈保存根结点
    BinNode *stack[20];
    // 用p表示当前新增的结点
    BinNode *p = NULL;
    // 用b表示第一个根节点，也是返回结点
    BinNode *b = NULL;
    // 初始化栈顶
    int top = -1;
    // 字符串下标
    int strIndex = 0;
    // 判断左右结点，,
    int k;
    char ch = str[strIndex];
    while(ch != '\0'){
        switch (ch) {
            case '(':
                top++;
                stack[top] = p;
                k = 1;
                break;
            case ')':
                top--;
                break;
            case ',':
                k=2;
                break;
            default:
                p = (BinNode *)malloc(sizeof(BinNode));
                p->data = ch;
                p->lChild = NULL;
                p->rChild = NULL;
                if(b == NULL){
                    b = p;
                }else{
                    switch (k) {
                        case 1:
                            stack[top]->lChild = p;
                            break;
                        case 2:
                            stack[top]->rChild = p;
                            break;
                        default:
                            break;
                    }
                }
                break;
        }

        strIndex++;
        ch = str[strIndex];
    }
    // 不需要释放stack和p，因为p指向的是树中的节点，而stack是栈上数组
    // free(stack);
    // free(p);
    return b;
}

// 递归遍历真的好简单啊
void recursionDLR(BinTree tree){
    if(tree != NULL){
        printf("%c",tree->data);
        recursionDLR(tree->lChild);
        recursionDLR(tree->rChild);
    }
}

void recursionLDR(BinTree tree){
    if(tree != NULL){
        recursionLDR(tree->lChild);
        printf("%c",tree->data);
        recursionLDR(tree->rChild);
    }
}

void recursionLRD(BinTree tree){
    if(tree != NULL){
        recursionLRD(tree->lChild);
        recursionLRD(tree->rChild);
        printf("%c",tree->data);
    }
}

BinTree init2(){
    BinNode *queue[20];
    BinNode *p = NULL;
    BinNode *b = NULL;
    char ch;
    int front = 1,rear = 0;
    ch = getchar();
    while (ch != '#'){
        p = NULL;
        if(ch != '@'){
            p = (BinNode*)malloc(sizeof(BinNode));
            p->data = ch;
            p->lChild = p->rChild = NULL;
        }
        rear++;
        queue[rear] = p;
        if(rear == 1){
            b = p;
        }else{
            if(p != NULL && queue[front] != NULL){
                if(rear % 2 == 0){
                    queue[front]->lChild = p;
                }else{
                    queue[front]->rChild = p;
                }
            }
            if(rear % 2 != 0){
                front++;
            }
        }
        ch = getchar();
    }
    return b;
}

// 利用栈前序遍历二叉树
void inorderDLR(BinTree tree){
    LinkStack stack = init();
    BinNode *p;
    push(stack,tree);
    while(!isEmpty(stack)){
        p = pop(stack);
        printf("%c",p->data);
        if(p->rChild != NULL){
            push(stack,p->rChild);
        }
        if(p->lChild != NULL){
            push(stack,p->lChild);
        }
    }
    free(stack);
}

// 利用栈中序遍历二叉树
void inorderLDR(BinTree tree){
    LinkStack stack = init();
    BinNode *p;
    push(stack,tree);
    while(!isEmpty(stack)){
        while (getTop(stack)){
            push(stack,getTop(stack)->lChild);
        }
        pop(stack); // 上面栈顶为空退出循环，这里弹出空元素
        if(!isEmpty(stack)){
            printf("%c",getTop(stack)->data);
            p = pop(stack);
            push(stack,p->rChild);
        }
    }
    free(stack);
}

// 利用栈后序遍历二叉树 TODO 真写不出来
void inorderLRD(BinTree tree){
    LinkStack stack = init();
    BinNode *p = tree,*pre;
    while(p != NULL && !isEmpty(stack)){
        while(p != NULL){
            push(stack,p);
            p = p->lChild;
        }
        p = pop(stack);
        if(p->rChild == NULL){
            pre = p;
            printf("%c",p->data);
            p = p->rChild;
        } else if(p->rChild == pre){
            pre = p;
            printf("%c",p->data);
            p = NULL;
        }else{
            push(stack,p);
            p = p->rChild;
        }
    }
    free(stack);
}

void destroy(BinTree tree){
    if(tree != NULL){
        destroy(tree->lChild);
        destroy(tree->rChild);
        free(tree);
    }
}

int main(){
    BinTree tree = init1("(A(B(,D(E,F)),C))");
    recursionLRD(tree);
    printf("\n");

    // "(A(B(,D(E,F)),C))" ABC@D@@@@EF#
    // ABC,A的左右结点，@D B的左右结点，@@ C的左右结点，@@ @的左右结点 EF D的左右结点
    // ABE@CFG@@D@@H#
    BinTree tree2 = init2();
    recursionLRD(tree2);
    printf("\n");
    // TODO 原来这就是二叉树啊
    //BinTree tree2 = init("(A(B(C(D(E,F),G),H(,I)),J(,K(,L(,M(,N))))))");
    //recursionDLR(tree2);

    inorderLRD(tree);
    printf("\n");
    inorderLRD(tree2);

    destroy(tree);
    destroy(tree2);
    //free(tree);
    //free(tree2);
    return 0;
}
