/*
 * Created by 致命之猫 on 2024-03-17 2:05
 */
#include <stdio.h>

void print_array(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void shell_sort(int a[],int n){
    print_array(a,n);
    int i,j,inc,temp;
    for(inc = n/2;inc > 0;inc/=2){
        for(i = inc;i<n;i++){
            if(a[i] < a[i-inc]){
                temp = a[i];
                for(j = i;j >= inc && temp < a[j-inc];j-=inc){
                    a[j] = a[j-inc];
                }
                a[j] = temp;
            }
        }
        print_array(a,n);
    }
}

int main() {
    int a[10] = {36,25,48,27,65,25,43,58,76,32};
    int b[9] = {0, 46,39,17,23,28,55,18,46};
    shell_sort(a,10);
    return 0;
}