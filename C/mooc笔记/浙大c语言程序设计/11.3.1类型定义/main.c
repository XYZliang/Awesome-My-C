//
//  main.c
//  11.3.1类型定义
//
//  Created by 张亮 on 2020/1/30.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>

int main()
{
    typedef int 整形;
    整形 a=0;
    typedef char* 字符串;
    字符串 b="abcdefgh";
    typedef char 十个字符;
    typedef struct ccnustu{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } 华中师范学生信息;
    华中师范学生信息 lyy={"Li yu ying", 1, 18, 'C', 90.0};
    //或
    struct jxufestu{
        char *name;  //姓名
        int num;  //学号
        int age;  //年龄
        char group;  //所在小组
        float score;  //成绩
    } ;
    typedef struct jxufestu 江西财经学生信息;
    江西财经学生信息 zl={"Zhang liang", 1, 18, 'C', 87.9};
    //原:
    struct jxufestu jeff={"Chen ji fu", 1, 18, 'C', 87.9};
    return 0;
}
/*
 typedef和define都是替一个对象取一个别名，以此增强程序的可读性，区别如下：

 （1）原理不同

 #define是C语言中定义的语法，是预处理指令，在预处理时进行简单而机械的字符串替换，不作正确性检查，只有在编译已被展开的源程序时才会发现可能的错误并报错。

 typedef是关键字，在编译时处理，有类型检查功能。它在自己的作用域内给一个已经存在的类型一个别名，但不能在一个函数定义里面使用typedef。用typedef定义数组、指针、结构等类型会带来很大的方便，不仅使程序书写简单，也使意义明确，增强可读性。

 （2）功能不同

 typedef用来定义类型的别名，起到类型易于记忆的功能。

 #define不只是可以为类型取别名，还可以定义常量、变量、编译开关等。

 （3）作用域不同

 #define没有作用域的限制，只要是之前预定义过的宏，在以后的程序中都可以使用，而typedef有自己的作用域。

 （4）对指针的操作不同

 #define INTPTR1 int*

 typedef int* INTPTR2;

 INTPTR1 p1, p2;

 INTPTR2 p3, p4;

 含义分别为，

 声明一个指针变量p1和一个整型变量p2

 声明两个指针变量p3、p4

 #define INTPTR1 int*

 typedef int* INTPTR2;

 int a = 1;

 int b = 2;

 int c = 3;

 const INTPTR1 p1 = &a;

 const INTPTR2 p2 = &b;

 INTPTR2 const p3 = &c;

 上述代码中，

 const INTPTR1 p1是一个常量指针，即不可以通过p1去修改p1指向的内容，但是p1可以指向其他内容。

 const INTPTR2 p2是一个指针常量，不可使p2再指向其他内容。因为INTPTR2表示一个指针类型，因此用const限定，表示封锁了这个指针类型。

 INTPTR2 const p3是一个指针常量
