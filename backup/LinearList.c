/*
 * Created by 致命之猫 on 2024-03-09 16:50
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 10
typedef int DataType;

typedef struct {
    DataType data[MAX_CAPACITY];
    int length;
} LinearList;

LinearList* InitList();

int ListLength(LinearList* list);

DataType GetNode(LinearList* list, int index);

int LocateNode(LinearList* list, DataType data);

void InsertList(LinearList* list, int index, DataType data);

DataType DeleteList(LinearList* list, int index);

int main() {

    return 0;
}

LinearList* InitList() {
    LinearList* list = malloc(sizeof(LinearList));
    list->length = 0;
    return list;
}

int ListLength(LinearList* list) {
    return list->length;
}

DataType GetNode(LinearList* list, int index) {
    return list->data[index-1];
}

int LocateNode(LinearList* list, DataType data) {
    int i;
    for(i=0;i<list->length;i++){
        if(list->data[i] == data){
            return i+1;
        }
    }
    return 0;
}

void InsertList(LinearList* list, int index, DataType data) {
    if(index > 0 && list->length < MAX_CAPACITY){
        int i;
        for(i = list->length-1;i>=index-1;i--){
            list->data[i+1] = list->data[i];
        }
        list->data[index-1] = data;
        list->length++;
    }
}

DataType DeleteList(LinearList* list, int index) {
    DataType data = -1;
    if(list->length > 0){
        data = list->data[index-1];
        int i;
        for (i = index; i < list->length; ++i) {
            list->data[i-1] = list->data[i];
        }
        list->length--;
    }
    return data;
}

void show(LinearList* list){
    int i;
    for (i = 0; i < list->length; ++i) {
        printf("%d",list->data[i]);
        if(i != list->length-1){
            printf(",");
        }
    }
}