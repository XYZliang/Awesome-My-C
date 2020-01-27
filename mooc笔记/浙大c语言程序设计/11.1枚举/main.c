//枚举是一种类型，通过它可以定义枚举变量
//比如：enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun }
//
//枚举和宏其实非常类似：宏在预处理阶段将名字替换成对应的值，枚举在编译阶段将名字替换成对应的值。我们可以将枚举理解为编译阶段的宏。
//
//枚举列表中的 Mon、Tues、Wed 这些元素相当于变量，不能再定义与它们名字相同的变量。
//
//Mon、Tues、Wed 等都是常量，不能对它们赋值，只能将它们的值赋给其他的变量。
//enum　枚举名　{枚举元素1,枚举元素2,……},枚举变量;

//枚举,不常用.适用于排比的,有意义的,比const int方便(整形常量)
#include <stdio.h>

void main1(void);
void main2(void);
void main3(void);
int main()
{
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun };
    //枚举值默认从 0 开始，往后逐个加 1（递增）,也可以如上，指定从1开始
    //也可以这样enum week{ Mon = 1, Tues, Wed, Thurs=10, Fri, Sat, Sun };
    //        对应为    {     1      2    3       10     11   12   13
    
    /*枚举是一种类型，通过它可以定义枚举变量：
    enum week a, b, c;
    也可以在定义枚举类型的同时定义变量：
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } a, b, c;
    有了枚举变量，就可以把列表中的值赋给它：
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun };
    enum week a = Mon, b = Wed, c = Sat;
    或者：
    enum week{ Mon = 1, Tues, Wed, Thurs, Fri, Sat, Sun } a = Mon, b = Wed, c = Sat;*/
    
    int day=5;
    
    switch(day){
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }
    
    main1();
    main2();
    main3();
    return 0;
}
//宏定义
#include <stdio.h>
#define Mon 1
#define Tues 2
#define Wed 3
#define Thurs 4
#define Fri 5
#define Sat 6
#define Sun 7
void main1(){
    int day=5;
    switch(day){
        case Mon: puts("Monday"); break;
        case Tues: puts("Tuesday"); break;
        case Wed: puts("Wednesday"); break;
        case Thurs: puts("Thursday"); break;
        case Fri: puts("Friday"); break;
        case Sat: puts("Saturday"); break;
        case Sun: puts("Sunday"); break;
        default: puts("Error!");
    }
}
//#define命令虽然能解决问题，但也带来了不小的副作用，导致宏名过多，代码松散，看起来总有点不舒服。
 //C语言提供了一种枚举（Enum）类型，能够列出所有可能的取值，并给它们取一个名字。


//将整数转换为枚举,需要类型站换
void main2()
{
 
    enum week
    {
        saturday,
        sunday,
        monday,
        tuesday,
        wednesday,
        thursday,
        friday
    } weekend;
 
    int a = 1;
    weekend = ( enum week ) a;  //类型转换
    //weekend = a; //错误
    printf("weekend:%d\n",weekend);
}

//小技巧
//设置枚举变量时,常在最后放一个元素,来统计元素量的总个数
void main3()
{
    enum week{Monday,Tuesday,Wednesday,Thursday,Friday,Saturday,Sunday,days };
    printf("weekend:%d\n",days);
}
