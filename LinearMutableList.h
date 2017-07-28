//
//  LinearMutableList.h
//  LinearMutableList
//
//  Created by 薛飞龙 on 2017/7/28.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

#ifndef LinearMutableList_h
#define LinearMutableList_h

#include <stdio.h>

#ifndef LINEARMUTABLELIST_STRUCT
typedef void * LinearMutableListNodeValue;

//线性表
typedef void LinearMutableList;

#endif

/**
 打印线性表
 */
void printList(LinearMutableList * list);
/**
 创建一个线性表
 */
LinearMutableList * creatList(int capacity);

/**
 销毁线性表
 */
void releasaList(LinearMutableList * list);

/**
 清空线性表
 */
void clearList(LinearMutableList * list);

/**
 获取线性表的长度
 */
int getListCount(LinearMutableList * list);

/**
 获取index的值
 */
LinearMutableListNodeValue getValueWithCount(LinearMutableList * list,int index);

/**
 插入数据
 */
void insertValue(LinearMutableList * list, int index, LinearMutableListNodeValue value);

/**
 添加数据
 */
void addValue(LinearMutableList * list, LinearMutableListNodeValue value);

/**
 设置数据
 */
void setValue(LinearMutableList * list, int index, LinearMutableListNodeValue value);

/**
 删除索引的数据
 */
void deleteIndex(LinearMutableList * list, int index);


/**
 删除所有值得数据
 */
void deleteValue(LinearMutableList * list, LinearMutableListNodeValue value);





#endif /* LinearMutableList_h */
