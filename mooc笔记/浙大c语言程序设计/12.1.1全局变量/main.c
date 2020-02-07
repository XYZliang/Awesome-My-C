//
//  main.c
//  12.1.1全局变量
//
//  Created by 张亮 on 2020/1/30.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>

int a;
int *b;
//int c=main();     全局变量初始化的值必须在编译时刻就已经存在
//int d=a;    同上
/*
 const int e
 int f=e;//在某些编译器里这是允许的,但是不推荐.全局变量最好不要和另一个全局变量有关系
         //在大程序中,存在多个源文件,初始化顺序可能不一样.
*/
int main()
{
    printf("%d,%p\n",a,b);
    int a=1;
    printf("%d\n",a);
    //局部变量优先级大于全局
    return 0;
}
//没有初始化的全局变量自动初始化为0
//没有初始化的指针会初始化为NULL
