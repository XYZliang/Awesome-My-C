//
//  main.c
//  10.1字符串
//
//  Created by 张亮 on 2020/1/9.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#include <string.h>//包含很多字符串函数

int main()
{
    char a[]={'H','E','L','L','O','!'};//单纯的字符数组,不可用字符串的操作
    char b[]={'H','E','L','L','O','!','\0'};//字符串
    char *c="HELLO!";//字符串,自动在尾部加入\0
    char d[100]="";//空
    char e[]="";//空
    printf("sizeof(a)=%lu (b)=%lu (c)=%lu (e)=%lu\n",sizeof(a),sizeof(b),sizeof(*c),sizeof(*e));
    //sizeof(c) 即字符指针变量的长度,linux和macos为8,windows为4
    printf("%c %c %c\n",c[0],d[0],e[0]);//d[0],e[0]均为/0,c可当作字符数组用
    //X c[0]='a'  c为指针,初始化为字符串常量,所指向的字符串储存在只读部分,不可修改,char*~~const char*/const char[]
    printf("%p %p %p %p\n",a,b,&c,c);
    //X char *f; scanf("%s",f); char*是字符串指针,必须先初始化才能用,可能出错.
    char **g;
    //X char h[][]必须指定部分长度
    char h[][2]={"a","b","c","dec"};//这样定义分配的为连续空间,不可超出
    char *i[]={"a","b","c","dec"};//i[0]对应着一串空间,储存着a;i[1]对应着一串空间,储存着b……
    printf("%s %s\n",h[3],i[3]);
    return 0;
}
