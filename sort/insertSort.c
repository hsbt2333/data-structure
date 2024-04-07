/*
 * Created by 致命之猫 on 2024-03-17 0:41
 */
#include <stdio.h>

void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert_sort(int a[], int n) {
    print_array(a, n);
    int i;
    for (i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            int temp = a[i];
            int j;
            for (j = i - 1; j >= 0 && temp < a[j]; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
        print_array(a, n);
    }
}

// 带哨兵，下标0位置不使用，用来做哨兵
void insert_sort2(int a[], int n) {
    print_array(a, n+1);
    int i, j;
    for (i = 2; i <= n; i++) {
        if (a[i] < a[i - 1]) {
            a[0] = a[i];
            for (j = i - 1; a[0] < a[j]; j--) {
                a[j + 1] = a[j];
            }
            a[j + 1] = a[0];
        }
        print_array(a, n+1);
    }
}

int main() {
    int a[9] = {46,39,17,23,28,55,18,46};
    int b[9] = {0, 46,39,17,23,28,55,18,46};
    insert_sort(a,8);
    printf("\n");
    insert_sort2(b, 8);
    return 0;
}