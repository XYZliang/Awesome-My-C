//
//  main.c
//  10.2字符串函数
//
//  Created by 张亮 on 2020/1/19.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main()
{
    //输出
    char a[30]="abcdefghijklmnopqrstuvwxyz";
    char b='1';
    int aa=printf("%s\n",a);
    printf("printf的返回值为%d,为其输出的字符个数.不输出\\0,也不算入返回值\n",aa);
    printf("sizeof为%lu,strlen为%lu\n",sizeof(a),strlen(a));
    int bb=putchar(b);
    printf("\nputchar的返回值为%d,为其输出的字符的asc2\n",bb);
    //输入
    int c,cc=scanf("%30s %d",&a,&c);//%30s防止溢出数组
    printf("scandf的返回值为%d,为成功读取的项的个数\n",cc);
    getchar();//吞掉回车
    int dd=b=getchar();
    printf("putchar的返回值为%d,为输入的字符的asc2\n输入任意值或回车以继续\n",dd);
    getchar();//吞去回车
    getchar();//停顿
    
    printf("PS:printf()、scanf()、getchar()、putchar()这四个函数\n如果遇到错误或者检测到文件结尾（在不同的系统下会有所不同）,\n都会返回EOF.EOF是一个值，一般情况下都是被定义为-1，\n也正是因为EOF是一个负值，所有这四个函数的返回值为int类型\n输入任意值或回车以继续\n");
    
    printf("mac xcode,EOF为control+d\n");
    printf("vs,EOF为control+c\n");
    printf("windows终端,EOF为control+z\n");
    printf("linus/unix,EOF为control+d/control+c\n");
    printf("进入测试循环:\n");
    while(scanf("%d",&c)!=EOF)
        continue;
    printf("成功读取EOF,退出循环\n");
    return 0;
}
