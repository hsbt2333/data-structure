/*
 * Created by 致命之猫 on 2024-03-18 20:30
 */

#include <stdio.h>

void print_array(int a[], int n) {
    int i;
    printf("[");
    for (i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i != n - 1) {
            printf(",");
        }
    }
    printf("]\n");
}

void bubbleSort(int a[], int n) {
    print_array(a,n);
    int i,j,temp,flag;
    for(i = 0;i < n;i++){
        flag = 0;
        for(j=n-1;j>i;j--){
            if(a[j] < a[j-1]){
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
                flag = 1;
            }
        }
        print_array(a,n);
        if(flag == 0) return;
    }
}

void twoWayBubbleSort(int a[],int n){
    print_array(a,n);
    int i = 0,j,temp,flag = 1;
    while(flag){
        flag = 0;
        for(j = n-i-1;j>i;j--){
            if(a[j] < a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = 1;
            }
        }
        printf("找出最小：%d--",a[i]);
        print_array(a,n);
        for(j=i;j<n-i-1;j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
            }
        }
        printf("找出最大：%d--",a[n-i-1]);
        print_array(a,n);
        i++;
    }
}

int main() {
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    int b[8] = {36,28,45,13,67,36,18,56};
    bubbleSort(a,10);
    printf("\n");
    bubbleSort(b,8);
    printf("\n");

    int c[10] = {10,9,8,7,6,5,4,3,2,1};
    int d[8] = {36,28,45,13,67,36,18,56};
    twoWayBubbleSort(c,10);
    printf("\n");
    twoWayBubbleSort(d,8);
    return 0;
}