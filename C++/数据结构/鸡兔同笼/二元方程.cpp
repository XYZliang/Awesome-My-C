//
//  二元方程.cpp
//  鸡兔同笼
//
//  Created by 张亮 on 2020/2/16.
//  Copyright © 2020 张亮. All rights reserved.
//

#include "1.hpp"
void 二元方程法(int head,int jio)
{
    start = clock();
    for (int i=1; i<=cycletimes;i++)
    {
        int key=1;
        for (int ra=0,ch=0;(ra+ch<=head)&&(key==1);ra++)
        {
            for(;ra+ch<=head;ch++)
                if(ra+ch==head)
                {
                    rabbit=ra;
                    chicken=ch;
                    key=0;
                    break;
                }
        }
    }
    stop = clock();
    cout <<  __FUNCTION__ << "运行" << cycletimes << "次花费" << (stop-start)/ (1.0*CLOCKS_PER_SEC) << "秒" << endl;
}
