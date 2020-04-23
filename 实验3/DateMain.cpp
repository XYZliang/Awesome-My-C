#include <iostream>
using namespace std;
#include "DateClass.h"

int main()
{
    DateType test2(2020,04,10);
    DateType graduation(2023,07,01);
    cout<<"距离本科毕业还有："<<(graduation-test2).getSumDay()<<"天！"<<endl;
    return 0;
}
