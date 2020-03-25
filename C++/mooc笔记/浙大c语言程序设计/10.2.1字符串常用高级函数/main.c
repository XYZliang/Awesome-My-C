//
//  main.c
//  10.2.1字符串常用高级函数
//
//  Created by 张亮 on 2020/1/20.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
    //strcmp 字符串比较函数
    char a[]="hello word!";
    char b[]="hello word?";
    char c[]="hello word!";
    if(strcmp(a, b))//一位一位比对,直到出现'\0'或者不一样的,输出其asc2之差(a-b),也可比较数组
        printf("a b字符串不相同,strcmp返回值为%d\n",strcmp(a, b));
    else
        printf("a b字符串相同,strcmp返回值为%d\n",strcmp(a, b));
    if(strcmp(a, c))
        printf("a c字符串不相同,strcmp返回值为%d\n",strcmp(a, c));
    else
        printf("a c字符串相同,strcmp返回值为%d\n",strcmp(a, c));
    
    //不安全⬇️
    //strcpy 字符串复制函数 多核函数,效率高
    //方法一:
    char d[100];
    strcpy(d, a);//复制到的字符串长度要足够,防止缓冲溢出.strcpy(新,原).
                 //两个字符串内存不可重合.返回值为目标数组的地址(d)
    puts(d);
    //方法二(推荐):
    char *new=(char*)malloc(strlen(b)+1);//strlen不计算\0,故新串要多分配一个空间来复制\0
    strcpy(new, b);
    puts(new);
    free(new);//用完释放
    
    //strcat 字符串拼接函数
    char Forwards[20]="heihei";//原函数必须要足够大
    char After[]="!";
    strcat(Forwards, After);//两个函数所指内存区域不可以重叠.返回值为目标数组的地址(Forwards)
    puts(Forwards);
    
    //安全方法:使用strncpy/strncat
    //strncpy(新,原,最大长度)
    //strncat(原,接在原上的串,最大长度)  同样,两个函数所指内存区域不可以重叠,返回值意义相同
    
    //同样,strcmp也有plus版本,strncmp返回值意义相同
    //strncmp(a,b,比较前n个字符)
    
    
    //strchr/strrchr 字符串从左/从右搜索某个字符函数
    printf("%p,%s\n",strchr(a, 'l'),strchr(a, 'l'));//返回该字符以及其后面的字符
    printf("%p,%s\n",strrchr(a, 'l'),strrchr(a, 'l'));
    printf("%p,%s\n",strchr(a, 'H'),strchr(a, 'H'));//如果没找到,返回空指针(即NULL)
    //寻找第2/n个指定字符
    char *p=strchr(a, 'l');//先找出第一个的地址,存入p
    printf("%p,%s\n",strchr(p+1, 'l'),strchr(p+1, 'l'));//从p+1地址且属于字符串的地址开始继续寻找l
    //复制某个字符前/后的字符串到新数组
    //后:
    //找到地址存下地址,直接strcpy malloc复制到新数组
    //前:
    //找到地址存下地址,将该位改为\0再strcpy malloc复制到新数组,最后恢复该位字符
    
    //strstr/strcasestr 字符串从左/从右搜索某个字符串,区分/不区分大小写,返回值及用法和strchr基本相同
    return 0;
}
