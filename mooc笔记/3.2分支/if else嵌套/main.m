//
//  main.m
//  3.2分支/1/if else嵌套
//
//  Created by 张亮 on 2019/8/21.
//  Copyright © 2019 张亮. All rights reserved.
//                 >>>>>>>>>>>>比较三个数大小<<<<<<<<<<<<<<

#include <stdio.h>

int main()
{
    int a,b,c,max;
    scanf("%d%d%d",&a,&b,&c);
    
    if(a>b)             //if(条件不成立)>>>>if(0)
    {
        if(a>c)         //if(条件成立)>>>>>if(1)
            max=a;
        else
            max=c;
    }
    else  if(b>c)       //2⃣️本该与18行最近的if匹配，由于{ }分割，故与16行if匹配
        max=b;
    else               //1⃣️else一般情况下与上方最近的if匹配，此处匹配23行if
        max=c;
        
    printf("最大的输为%d\n",max);
    return 0;
}
