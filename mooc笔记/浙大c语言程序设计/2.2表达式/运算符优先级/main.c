//
//  main.c
//  2.2表达式/2/运算符优先级
//
//  Created by 张亮 on 2019/8/18.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a;
    
    //优先级1 + -（单目运算符，前者不变，后者取负）<<<<<<<<<<<<<<<<<<<<<
    //优先级2 + / %
    
    a=2*-3;
    printf("2*-3=%d\n",a);
    
    
    //优先级3 + -（普通加减）
    //优先级4 =（赋值符号）
    
    
    return 0;
}
