/*
 * Created by 致命之猫 on 2024-03-18 21:08
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

void quickSort(int a[],int n){

}

int main(){
    return 0;
}