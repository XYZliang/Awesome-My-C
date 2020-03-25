//
//  计算.c
//  ZL's C-Project
//
//  Created by 张亮 on 2020/1/31.
//  Copyright © 2020 张亮. All rights reserved.
//
//ps:全局变量可在多个.c之间共享
//静态本地变量只可在当前.c中
#include <stdio.h> 
#include "我的头文件.h"
int plus(int a,int b)
{
    printf("all=%d\n",all);
    return (a+b);
}
