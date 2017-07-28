//
//  main.m
//  LinearMutableList
//
//  Created by 薛飞龙 on 2017/7/28.
//  Copyright © 2017年 薛飞龙. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LinearMutableList.h"
int main(int argc, const char * argv[]) {
    @autoreleasepool {
        // insert code here...
        NSLog(@"Hello, World!");
        
        
        //返回一个结构体!
        LinearMutableList * list = creatList(5);
        //添加数据
        for (int i = 0; i < 20; i++) {
            addValue(list, (LinearMutableListNodeValue)i);
            NSLog(@"长度:%d,首元素地址:%p",getListCount(list),*((void **)list + 1));
        }
        //打印数据
        printList(list);
        
        //销毁
        releasaList(list);
        
    }
    return 0;
}
