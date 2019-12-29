//
//  main.c
//  5.3循环应用/3/计算两个数的最大公约数
//
//  Created by 张亮 on 2019/9/30.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>
 
int main()
{
    float a,b,c;
    
    printf("请输入三个数,以逗号分隔：");
    scanf("%f,%f,%f",&a,&b,&c);
    
    if(a+b>c&&a+c>b&&b+c>a)
        printf("这三个数能够组成三角形哦。\n");
    else
        printf("这三个数不能组成三角形嗷！\n");
    
    return 0;
}
