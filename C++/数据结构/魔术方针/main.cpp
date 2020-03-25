//
//  main.cpp
//  魔术方针
//
//  Created by 张亮 on 2020/2/20.
//  Copyright © 2020 张亮. All rights reserved.
//
#include <stdio.h>
using namespace std;
#define Max_Size 22

int main(void)
{
    int i , j , row ,column , size , count ;
    printf("输入矩阵大小：");
    scanf("%d" , &size);
    
        int **square = new int *[size];
        for (int i = 0; i < size; i++)
        {
            square[i] = new int[size];
        }

    for(i = 0 ; i < size ; i ++)
    {
        for(j = 0 ; j < size ; j ++)
        {
            square[i][j] = 0 ;

            square[0][(size - 1)/2] = 1 ;

            i = 0 ;
            j = (size - 1)/2;

            for(count = 2 ; count <= size * size ; count++)
            {
                row = (i - 1 < 0)?(size - 1):(i - 1);
                column = (j - 1 < 0)?(size - 1):(j - 1);

                if(square[row][column])
                {
                    i = (++i)%size;
                }
                else
                {
                    i = row ;
                    j = (j - 1 < 0)?(size - 1): --j;
                }
                square[i][j] = count ;
            }

            printf("\n大小为%d的魔术矩阵为:\n" , size);

            for(i = 0 ; i < size ; i++)
            {
                for(j = 0 ; j < size ; j++)
                {
                    printf("%d\t" , square[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
