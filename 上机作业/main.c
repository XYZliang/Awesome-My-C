//
//  main.c
//  上机作业
//
//  Created by 张亮 on 2019/10/23.
//  Copyright © 2019 张亮. All rights reserved.
//
#include<stdio.h>

int main()
{
    int N,U,D,h;
    int t=0;
    scanf("%d %d %d",&N,&U,&D);
    for(h=0;h<N;)
    {
        h+=U;
        t++;
        if(h<N)
        {
            h-=D;
            t++;
        }

    }
    printf("%d",t);
return 0;
}


