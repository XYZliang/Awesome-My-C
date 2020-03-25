//
//  main.m
//  3作业
//
//  Created by 张亮 on 2019/8/25.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>

int main()
{
    // insert code here...
    int a,h,m;
    scanf("%d",&a);
    h=a/100;
    m=a-100*h;
    h=h-8;
    
    if(h>=0)
    {
        a=100*h+m;
    }
    else
    {
        a=(24+h)*100+m;
    }
    printf("%d\n",a);
    
    return 0;
}

