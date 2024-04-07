/*
 * Created by 致命之猫 on 2024-03-31 23:58
 */

#include <stdio.h>
#include <stdlib.h>
void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void sift(int arr[],int n,int i){
    int index = i;
    int lChild = 2*index + 1;
    int rChild = 2*index + 2;
    if(lChild < n && arr[index] < arr[lChild]){
        index = lChild;
    }
    if(rChild < n && arr[index] < arr[rChild]){
        index = rChild;
    }
    if(index != i){
        int temp = arr[index];
        arr[index] = arr[i];
        arr[i] = temp;
        sift(arr,n,index);
    }
}

void heapSort(int arr[],int n){
    // 建堆
    int i;
    for(i = n/2-1;i>=0;i--){
        sift(arr,n,i);
    }
    printf("建堆：\n");
    print_array(arr,n);
    int j,temp;
    for(j=n-1;j>0;j--){
        temp = arr[j];
        arr[j] = arr[0];
        arr[0] = temp;
        sift(arr,j,0);
        print_array(arr,n);
    }
}

int main(){
    int a[10] = {10,9,8,7,6,5,4,3,2,1};
    int b[10] = {1,2,3,4,5,6,7,8,9,10};
    //int b[9] = {0, 46,39,17,23,28,55,18,46};
    print_array(a,10);
    heapSort(a,10);
    print_array(a,10);

    printf("\n");
    print_array(b,10);
    heapSort(b,10);
    print_array(b,10);
    return 0;
}