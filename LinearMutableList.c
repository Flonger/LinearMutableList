//
//  LinearMutableList.c
//  LinearMutableList
//
//  Created by 薛飞龙 on 2017/7/28.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

typedef void * LinearMutableListNodeValue;
//线性表
typedef struct {
    int capacity;                         //容量
    int count;                            //长度
    LinearMutableListNodeValue * value;   //节点数据的指针
}LinearMutableList;

#define LINEARMUTABLELIST_STRUCT




#include "LinearMutableList.h"
#include <stdlib.h>
#include <string.h>

LinearMutableList * creatList(int capacity){
    if (capacity < 0) {
        return NULL;
    }
    LinearMutableList * list = malloc(sizeof(LinearMutableList));
    if (list) {
        list -> capacity = capacity;
        list -> count = 0;
        list->value = capacity ? malloc(capacity * sizeof(LinearMutableListNodeValue)) : NULL;
    }
    return list;
}


void printList(LinearMutableList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    
    printf("list{\n");
    printf("\tcount = %d;\n",list -> count);
    printf("\tcapacity = %d;\n",list -> capacity);
    printf("\tvalue = [");
    for (int i = 0; i < list -> count; i++) {
        printf("%p",list -> value[i]);
        if (i < list -> count -1) {
            printf(",");
        }
    }
    printf("];\n}\n\n");
    
}

void releasaList(LinearMutableList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    
    free(list -> value);
    free(list);
}


void clearList(LinearMutableList * list){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    list -> count = 0;
    
}

int getListCount(LinearMutableList * list){
    if (list == NULL) {
        printf("list is NULL");
        return 0;
    }
    return list -> count;
}

LinearMutableListNodeValue getValueWithCount(LinearMutableList * list,int index){
    if (list == NULL) {
        printf("list is NULL");
        return 0;
    }
    return list -> value[index];
}

void insertValue(LinearMutableList * list, int index, LinearMutableListNodeValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index > list -> count) {
        return;
    }
    
    //判断是否需要扩容
    if (list->count == list->capacity) {//扩容!
        //分配新的空间
        int newCapacity = list->capacity + 10;
        LinearMutableListNodeValue * newValue = malloc(sizeof(LinearMutableListNodeValue) * newCapacity);
        if(newValue == NULL) return;
        //将旧数据复制到新空间
        //利用for循环
        /*
         for (int i = 0; i < list->capacity; i++) {
         newValue[i] = list->value[i];
         }*/
        //利用系统提供的宏
        //1.目标  2.来源  3.字节
        memcpy(newValue, list->value,sizeof(LinearMutableListNodeValue)*list->capacity);
        //释放旧空间
        free(list->value);
        list->value = newValue;
        //修改capacity
        list->capacity = newCapacity;
    }
    
    //从index开始后面所有的数据挪动
    for (int i = list->count - 1; i >= index; i--) {
        list->value[i+1] = list->value[i];
    }
    //设置新值到index位置
    list->value[index] = value;
    //数量增加
    list->count++;

}

void addValue(LinearMutableList * list, LinearMutableListNodeValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    insertValue(list, list -> count, value);
}

void setValue(LinearMutableList * list, int index, LinearMutableListNodeValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index >= list -> count) {
        return;
    }
    list -> value[index] = value;
}

void deleteIndex(LinearMutableList * list, int index){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    if (index < 0 || index >= list -> count) {
        return;
    }
    
    for (int i = index + 1; i < list -> count; i++) {
        list -> value[i-1] = list -> value[i];
    }
    //数量减少
    list -> count --;
}


void deleteValue(LinearMutableList * list, LinearMutableListNodeValue value){
    if (list == NULL) {
        printf("list is NULL");
        return;
    }
    //定义一个初始记录
    int removeCount = 0;
    //遍历所有元素
    for (int i = 0; i < list -> count; i++) {
        if (list -> value[i] == value) {
            //删除记录加1
            removeCount ++;
        }else{
            //挪动
            list -> value[i - removeCount] = list -> value[i];
        }
    }
    //个数减去删除的个数
    list -> count -= removeCount;
    
    
}
