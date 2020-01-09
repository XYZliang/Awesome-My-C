//
//  main.c
//  7.2指针动态分配
//
//  Created by 张亮 on 2020/1/8.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>//free所包含的头文件

int main()
{
    char *p=0;//最好初始化
    char *q=0;
    long GB = 0;
    while((p=(char*)malloc(1024*1024*1000)))//malloc有返回值.当申请空间失败时,返回0或者NIULL.申请的大小是以字节为单位
        GB++;                         //malloc申请的类型是(void*),要转换成你需要的
    printf("分配了%ldG空间\n",GB);
    free(p);//空间还回去.如果不还,运行内存x减少大程序容易炸,n可能留下内存漏洞,内存垃圾
    free(q);//相当于free(null),啥也不干,防止你忘记了给q分配空间.
    //free(GB);(只能还你前面申请的空间,
    //free(p+1);而且地址不能更改)不然系统都会崩
    free(p);//free已经还过的空间可能会崩
    return 0;
    //c99后可以用变量名定义数组大小,c99前只能用malloc
}
