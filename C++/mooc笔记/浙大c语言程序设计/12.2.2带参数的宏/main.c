//
//  main.c
//  12.2.2带参数的宏
//
//  Created by 张亮 on 2020/1/31.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
#define 三次方x ((x)*(x)*(x))//像函数
int main(int argc, const char * argv[]) {
    int x=2;
    printf("2的三次方为%d\n",三次方x);
    return 0;
}
//因为宏定义都是单纯的文本替换,替换过去后一定要注意运算顺序是否有问题
//所以整个值都需要括号,参数出现的地方需要括号
//宏的时间效率比函数快,但是宏不会进行检查
