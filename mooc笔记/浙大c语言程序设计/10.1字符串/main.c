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
    char c="HELLO!";//字符串,自动在尾部加入\0
    printf("%d %d",sizeof(a),sizeof(b));
    return 0;
}
