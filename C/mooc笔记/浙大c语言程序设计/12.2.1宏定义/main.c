//
//  main.c
//  12.2.1宏定义
//
//  Created by 张亮 on 2020/1/31.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#define PI 3.1415926
#define 宏的名字 宏的值//定义一个宏
//在程序运行前会编译,而编译前会先预处理.预处理时会把程序中的宏替换成宏的值
//结尾无分号,因为他不是c的语句
//名字必须为一个词,值可以是任意的东西
//宏的值里有其他宏d,也会被替换
//如果宏的值超过一行,则要在换行行末加\
//如果宏的值里有注视,则注释会被省略
int main(int argc, const char * argv[])
{
    printf("PI=%lf\n",PI);
    //系统定义的宏
    printf("行号:%d\n",__LINE__);
    printf("文件:%s\n",__FILE__);
    printf("编译日期:%s\n",__DATE__);
    printf("编译时间:%s\n",__TIME__);
    printf("当要求程序严格遵循ANSIC标准时该标识符被赋值为:%d\n常用来判断该文件是不是标准C程序\n",__STDC__);
    return 0;
}

