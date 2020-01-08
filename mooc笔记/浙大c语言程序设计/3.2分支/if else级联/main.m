//
//  main.m
//  3.2分支/2/if else级联
//
//  Created by 张亮 on 2019/8/24.
//  Copyright © 2019 张亮. All rights reserved.
//
//
//>>>>>>>级联if else适合做类似于分段函数的程序<<<<<<<<<<

#include <stdio.h>

int main()
{
    int input,output;                     //方法一
    
    printf("请输入一个数:");
    scanf("%d",&input);
    
    if(input<0)
    {
        output=-input;
        printf("这个数的绝对值为%d\n",output);
    }
    
    else if(input==0)
    {
        output=0;
        printf("这个数的绝对值为%d\n",output);
    }
    
    else if(input>0)
    {
        output=input;
        printf("这个数的绝对值为%d\n",output);
    }
    
    
    input=output=0;                     //方法二
    
    printf("请在输入一个数:");
    scanf("%d",&input);
    
    if(input<0)                         //if后别带 ";" 计算机会直接结束这一if语句
    {                                   //if语句尽量后面直接跟上{}
        output=-input;
    }
    
    else if(input==0)
    {
        output=0;
    }
    
    else if(input>0)
    {
        output=input;
    }                                   //方法二更好，因为只有（一个出口），而且更简洁
    

    
    printf("这个数的绝对值为%d\n",output);
   
    
    return 0;
    

}
