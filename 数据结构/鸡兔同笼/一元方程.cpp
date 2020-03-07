//
//  一元方程.c
//  鸡兔同笼
//
//  Created by 张亮 on 2020/2/16.
//  Copyright © 2020 张亮. All rights reserved.
//

#include "1.hpp"
void 一元方程法(int head,int jio)
{
    start = clock();
    for (int i=1; i<=cycletimes;i++)
    {
        for (int ra=0;ra<=head;ra++)
        {
            if(4*ra+2*(head-ra)==jio)
            {
                rabbit=ra;
                chicken=35-ra;
                break;
            }
        }
    }
    stop = clock();
    cout <<  __FUNCTION__ << "运行" << cycletimes << "次花费" << (stop-start)/ (1.0*CLOCKS_PER_SEC) << "秒" << endl;
}
