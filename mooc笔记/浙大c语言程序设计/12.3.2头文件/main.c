//
//  main.c
//  12.3.2头文件
//
//  Created by 张亮 on 2020/1/31.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h> // < >指让编译器在指定的地方查找
//包含printf这些函数的  原 型 声 明.用于正确调用函数.如果没有,有可能出错
//include并不是引入标准库。现代c语言编译器会默认映入所有标准库。
#include "我的头文件.h"//" "指现在当前目录查找,若没有再在指定的地方查找
//#include是编译预处理指令,和宏一样
//他会把所调用的文件的全部内容原封不动插入调用它的地方
//所以#include并不一定在开头
int all=1;
int main()
{
    int a=1;
    int b=2;
    printf("%d+%d=%d\n",a,b,plus(a,b));
    return 0;
}
