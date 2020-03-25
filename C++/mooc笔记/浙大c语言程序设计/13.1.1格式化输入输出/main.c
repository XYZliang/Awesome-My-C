//
//  main.c
//  13.1.1格式化输入输出
//
//  Created by 张亮 on 2020/2/1.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
//格式化输出
int main()
{
    printf("%%[flags][width][.prec][hIL]type\n");
    //flage:
    //  -         +       (空格)     0
    //左对齐  在前面加+或-  正数留空   0填充
    printf("%10d|\n",123);
    printf("%-10d|\n",123);
    printf("%+10d|\n",123);
    printf("%-+10d|\n",-123);
    printf("%010d|\n",-123);
    //width/.prec:
    //  数字        .数字           *                 .*
    //最小字符数  保留的小数位数  参数为最小字符数  参数为保留的小数位数
    printf("%10.2f\n",1.1);
    printf("%*.*f\n",10,2,1.1);
    //hIL类型修饰
    //  hh       h      l       ll          L
    //单个字节  short  long    longlong  long double
    //type
    //  i/d        u            o       x        X          f/F          e/E
    //  int   unsigned int    八进制  十六进制 大写的十六进制   float(6位)     指数
    //  g/G         a/A         c       s       p        n
    //  float   十六进制浮点数   char    字符串   指针  读入/写出的个数
    int a;
    printf("%d5678%n\n",1234,&a);//把这次输出的字符个数赋值给a;
    printf("%d\n",a);
    
//格式化输入
    //scanf(%[flag]type)
    //flag:
    //   *      数字      hh      h        l            ll         L
    //  跳过  最大字符数   char   short  long,double  long long  long double
    //  type
    //   d              i                 u        o       x     a,e,f,g
    //  int  整数(可为十\八\十六进制)  unsigned int  八进制  十六进制    float
    //      s           [....]    p
    //  字符串(纯字母)  所允许的字符  指针
    
    /*除了转换修饰符 s 以外，也可以使用“扫描集”（scanset）修饰符来读取字符串，
     它由方括号所包含的一串无序字符组成（[scanset]）。
     scanf（）函数接着读取所有字符，然后将它们存储为一个字符串（带有字符串终止符），
     直到遇到不匹配扫描集中任一字符时才停止。例如：
     char strNumber[32];
     scanf( "%[0123456789]", strNumber );

     如果用户输入 345X67，那么 scanf（）会把 345\0 字符串存储到数组 strNumber 中。
     字符 X 以及后续字符则仍然留在输入缓冲区中。

     逆向使用转换扫描集（也就是说，除扫描集中的字符外，其他都符合），
     做法是在扫描集的左括号后面加上一个插入号（^）。
     下面的 scanf（）调用读取所有字符（包括空白符），
     直到句子结束的标点符号，然后再读入标点符号本身：
     char ch, sentence[512];
     scanf( "%511[^.!?]%c", sentence, &ch );

     下面的 scanf（）调用读取并丢弃所有字符，一直到当前行结束：
     scanf( "%*[^\n]%*c" );
     */
    
    
    
    //在要求严格的大程序h中,应每次判断scanf和printf的返回值以确保没有问题
    return 0;
}
