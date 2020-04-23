//
//  main.c
//  3.1判断/1/判断关系的运算
//
//  Created by 张亮 on 2019/8/18.
//  Copyright © 2019 张亮. All rights reserved.
//


//判断关系若成立则输出1，不成立则输出0<<<<<<<<<<<<<<<<<<<<<<


#include <stdio.h>

int main()
{
    int a,b,c,d;
    a=5>4;
    b=5<4;
    c=5==4;//（==为等号，优先级大于=赋值号）
    d=5!=4;//（！一般为不的意思,如!< !> !=）
    
    
    printf("%d\n",a);
    printf("%d\n",b);
    printf("%d\n",c);
    printf("%d\n",d);
    
    
    
    return 0;
}
