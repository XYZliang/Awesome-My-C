//
//  main.m
//  3.2分支/3/switch case多路分支
//
//  Created by 张亮 on 2019/8/24.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>

int main()
{
    
    printf("请输入月份：");
    int month;
    scanf("%d", &month);
    
    
    printf("在case中有break的情况下输出如下:");
    switch ( month )                                //系统直接跳转至相应的case，而不是像级联的if else那样去判断
    {
            
        case 1: printf("%d是January\n",month);
            break;                                  //如果没有break，程序会继续运行下一个case的情况，直到遇到break跳出switch
        case 2: printf("%d是February\n",month);
            break;                                  //或者运行完后面全部的case
        case 3: printf("%d是March\n",month);
            break;
        case 4: printf("%d是April\n",month);
            break;
        case 5: printf("%d是May\n",month);
            break;
        case 6: printf("v%d是June\n",month);
            break;
        case 7: printf("%d是July\n",month);
            break;
        case 8: printf("%d是August\n",month);
            break;
        case 9: printf("%d是September\n",month);
            break;
        case 10:printf("%d是October\n",month);
            break;
        case 11:printf("%d是November\n",month);
            break;
        case 12:printf("%d是December\n",month);
            break;

        default:
            printf("请输入正确的月数\n");
            break;                                  //可以不加break。default本来就是最后的语句
            
    }
    
    printf("请再次输入月份：");
    scanf("%d", &month);
    printf("在case中无break的情况下输出如下:");

    switch ( month )
    {
            
        case 1: printf("%d是January\n",month);
        case 2: printf("%d是February\n",month);
        case 3: printf("%d是March\n",month);
        case 4: printf("%d是April\n",month);
        case 5: printf("%d是May\n",month);
        case 6: printf("%d是June\n",month);
        case 7: printf("%d是July\n",month);
        case 8: printf("%d是August\n",month);
        case 9: printf("%d是September\n",month);
        case 10:printf("%d是October\n",month);
        case 11:printf("%d是November\n",month);
        case 12:printf("%d是December\n",month);      //如果没有break，甚至连default都会运行
    
        default:
            printf("请输入正确的月数\n");
            
    }
    return 0;
}

