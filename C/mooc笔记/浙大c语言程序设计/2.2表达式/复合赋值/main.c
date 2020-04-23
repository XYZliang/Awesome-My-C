//
//  main.c
//  2.2表达式/1/复合赋值
//
//  Created by 张亮 on 2019/8/13.
//  Copyright © 2019 张亮. All rights reserved.
//

#include <stdio.h>
int main()
{
    int a,b,c;
    a=5;
    c=b=0;
    
    b=-a;  //将a取反值
    printf("此时b的值为%d\n",b);
    
    b=0;
    b+=a+2; //等同于 b=b+（a+2）
    printf("此时b的值为%d\n",b);
    
    a=5;
    b=0;
    b*=a+2; //等同于 b=b*（a+2）
    printf("此时b的值为%d\n",b);
    
    a=5;
    c=a++;  //等同于先将a赋值给c，然后把a自身递增1
    printf("此时a c的值分别为%d，%d\n",a,c);
    
    a=5;
    c=0;
    c=++a;  //等同于先把a自身递增1，再把a赋值给c
    printf("此时a c的值分别为%d，%d\n",a,c);
    
    return 0;
    
}
