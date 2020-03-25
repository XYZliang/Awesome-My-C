//
//  main.c
//  12.3.1一个程序多个源代码
//
//  Created by 张亮 on 2020/1/31.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <stdio.h>
void main1(void);
int main(int argc, const char * argv[])
{
    printf("当前文件%s\nmain.c执行成功!\n",__FILE__);
    main1();
    return 0;
}
//只要建立在同一个工程下(xcode是targe),编译时就能自动链接
