#include <iostream>
using namespace std;
int sumDay=730120;
//int sumDay;
//int year=2000,month=1,day=1;
int year,month,day;
int returnSumDay()
{
    int n=sumDay;
    int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(year=1;;year++)//算出年份
    {
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            if(n<=366)
                break;
            else
                n-=366;
        }
        else
        {
            if(n<=365)
                break;
            else
                n-=365;
        }
        
    }
    if((year%4==0&&year%100!=0)||year%400==0)
        m[2]++;
    for(month=1;month<=12;month++)
    {
        if(n>m[month])
        {
            n-=m[month];
            continue;
        }
        else
        {
            day=n;
            break;
        }
    }
    return 0;
}

int returnSumDayy()
{
    int n=sumDay;
    int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    year=1;
    if(n>=731635)
    {
        n-=731635;
        year=2000;
    }
    for(;;year++)//算出年份
    {
        if((year%4==0&&year%100!=0)||year%400==0)
        {
            if(n<=366)
                break;
            else
                n-=366;
        }
        else
        {
            if(n<=365)
                break;
            else
                n-=365;
        }
        
    }
    if((year%4==0&&year%100!=0)||year%400==0)
        m[2]++;
    for(month=1;month<=12;month++)
    {
        if(n>m[month])
        {
            n-=m[month];
            continue;
        }
        else
        {
            day=n;
            break;
        }
    }
    return 0;
}

int getSumDay()
{
    int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if((year%4==0&&year%100!=0)||year%400==0)
        m[2]++;
    int sum = 0;
    for(int i = 1;i < year;i++)
    {
        sum += 365;
        if((i%4==0&&i%100!=0)||i%400==0)
            sum ++;
    }
    for(int i = 1;i < month;i++)
    {
        sum += m[i];
    }
    sum += day;
    sumDay=sum;
    return sum;
}

int main()
{
    returnSumDay();
    cout<<year<<month<<day;
//    getSumDay();
//    cout<<sumDay;
    return 0;
}
