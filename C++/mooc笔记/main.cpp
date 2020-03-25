//
//  main.cpp
//  c>>c++准备
//
//  Created by 张亮 on 2020/2/5.
//  Copyright © 2020 张亮. All rights reserved.
//

#include <iostream>//标准输入输出流头文件
using namespace std;//声明命名空间std,若不写则需要在cout cin前加std::
//std::    是个名称空间标示符，C++标准库中的函数或者对象都是在命名空间std中定义的，
//所以我们要使用标准函数库中的函数或对象都要使用std来限定。
//对象count是标准函数库所提供的对象，而标准库在名字空间中被指定为std，所以在使用cout的时候要加上std：：
//这样编译器就会明白我们调用的cout是名字空间std中的cout。
//using namespace std 告诉编辑器我们将要使用空间std中的函数或者对象。
#include <stdio.h>
#include <cstdio>//在c++中,stdio.h升级为cstdio
void swap(int &cc,int &dd);
void multiply(int a,int b=0);
void xixi(void);
void MemoryAllocation(void);

int main(int argc, const char * argv[]) {
    // 1.输入输出
    int a;
    printf("请输入一个数:");
    cin >> a;//用cin输入流替代scanf等输出函数,cin代表键盘
    cout << "Hello!你刚刚输入了一个 " << a << " !\n";//用cout输出流替代printf等输出函数,cout代表显示器
    char b;
    cin >> a >> b ;//一条输入可以输入多个数据,以空格/Tab分开,回车结束
    cout << a << b <<endl;//中间无分隔,endl表示换行

    // 2.变量初始化 常量
    int c(66666666),d(88888888);//在c中 int c=66666666;
    const double Pi=3.141592;//#define Pi=3.141592
    //使用const定义常量,不可再次改变,必须初始化

    //3.引用访问,引用传递
    //在c++中,出了直接用变量名访问变量,指针间接访问变量,还可以给变量取别名,通过别名间接访问
    int &C=c;//他们共用一段空间 &又叫引用说明符
    int e,&E=e,&D=d;//可在一条中定义
    swap(c,d);
    cout << c << endl << d << endl;
    multiply(C,D);
    multiply(E);
    xixi();
    return 0;
}
void swap(int &cc,int &dd)//将形参定义为引用变量
{
    int t;
    t=cc;cc=dd;dd=t;//将被调函数的形参定义为主调函数的实参变量的引用,使得被调函数通过这个引用可以访问主调函数中的变量
    //使用b引用传递时,实参必须为变量
    //好处:不需额外定义,节省内存;实现了数据双向传递
}

//4.1带默认形参值的函数
void multiply(int a,int b)//见声明:void multiply(int a,int b=0);如果b没有给值的话,就默认为0
{
    cout << a*b << endl;
}
//ps:s带默认值的形参必须放在后面
//void multiply(int a,int b=0);√
//void multiply(int a=0,int b=0);√
//void multiply(int a=0,int b);X


//4.2重载函数
//在c语言中,函数不能重名
//在c++中, 只要c函数的形参个数不同或者类型不同,就可以重名.重名函数称为重载函数.
//void multiply(int a,int b);
//void multiply(double a,double b);

//4.3内联函数
//在>定义<前加上inline,只放在声明前没用,一般在声明和定义前都加上inline
//当编译器发现某段代码在调用一个内联函数时，它不是去调用该函数，而是将该函数的代码，整段插入到当前位置。
//优点:省去了调用的过程，加快程序运行速度。
//缺点:由于每当代码调用到内联函数，就需要在调用处直接插入一段该函数的代码，所以程序的体积将增大。
//ps:内联函数应该简洁，只有几个语句，且调用次数多.如果语句较多，或者只调用几次,则不适合于定义为内联函数。
//内联函数体中，不能有循环语句、if语句或switch语句，
//否则，函数定义时即使有inline关键字，编译器也会把该函数作为非内联函数处理。

//5.1创建命名空间
namespace Zliang
{
char name[]="zhangliang";
int old=18;
char school[]="JXUFE";
char lover[]="Liyuying";
//void fun1() {......};
}
//5.2访问命名空间元素
void xixi(void)
{
    Zliang::old=19;//直接访问

    using Zliang::name;
    name[0]='Z';//先声明后访问,用啥声明啥

    using namespace Zliang;
    cout << name << " love " << lover << endl;//直接全部声明,就可以省略命名空间
    /*
     因为标准库非常的庞大，所程序员在选择的类的名称或函数名时就很有可能和标准库中的某个名字相同。
     所以为了避免这种情况所造成的名字冲突，就把标准库中的一切都被放在名字空间std中。但这又会带来了一个新问题。
     无数原有的C++代码都依赖于使用了多年的伪标准库中的功能，他们都是在全局空间下的。
     所以就有了<iostream.h>和<iostream>等等这样的头文件，一个是为了兼容以前的C++代码，一个是为了支持新的标准。
     命名空间std封装的是标准库的名称，标准库为了和以前的头文件区别，一般不加".h"

     C++语言是从C语言发展起来的，因此有很多借鉴的地方。
     当C++语言推出但尚未标准化以前（98年才标准化），市场上已经有了很多版本的程序库了，
     导致互相应用时出现了一个很难调和的难题，那就是命名冲突，又称名空间泛滥。比如某个库写了个函数line(int x,int y);
     不巧另外一个库又写了个类class line;这下编译器该匹配哪个呢？只好取决于哪个库文件先被引用到文件中，并且把另外一个完全屏蔽掉。
     这显然不是一个好的方法。在标准库的产生过程中，这个问题被提了出来。
     为此，标准库组织决定在标准库中引入名空间的概念，所有标准库的组件都在名空间std中定义，由用户手动引入到程序中，
     这样就让编译器知道，当遇到一个可能冲突的名称时，以标准库中定义的名称为主，如果想用标准库外定义的名称，
     那程序员需要自己注明另外的名空间，从而达到消除名空间泛滥的目的。
     using namespace std；的写法引入了名空间的所有内容，这是一种简单但不保险的做法，是标准库组织不推荐这么做的。
     因为这样引入了所有的组件函数名，相当于重新引发了名字空间泛滥的问题。为此，好的做法应该是第二种分别引入。
     */
}

//6动态内存分配
void MemoryAllocation()
{
    int *a,*b;
    a=(int*)malloc(sizeof(int)*8);
    free(a);//c
    b=new int;
    delete b;
    
    a=new int(10);
    delete a;//同时初始化为10
    
    b=new int[10];
    delete []b;//10个int长度空间,并整个释放
    //c++
}
