//
//  main.cpp
//  顺序栈v0.2
//
//  Created by 张亮 on 2020/3/23.
//  Copyright © 2020 张亮. All rights reserved.
//

//v0.2:尝试将数据导入文本/将文本中数据导入栈（liunx、macos需要root权限，windows需要管理员权限）
//将子菜单输出内容放入各函数，减少主函数内容
//将主菜单功能另做函数

#include <iostream>
#include <string>
#define STACKSIZE 200
//最大容量
using namespace std;
struct sqstack
{
    int *base;//栈底
    int *top;//栈顶
};
class Sqstack
{
private:
    sqstack S;//定义栈基本结构
public:
    void initStart();             //顺序栈的初始化函数
    void pushData(int e);         //顺序栈单数据入栈函数
    int popData();                //顺序栈单数据出栈函数
    int getTopdata();             //顺序栈取栈顶函数
    int functionDisplay();        //顺序表功能打印输出函数
    void pushLotsdata(int);   //顺序表多数据入栈函数
    void popLotsdata();           //顺序表的数据顺序出栈函数
    void storeDatafile();         //顺序表的数据存储至文本文件函数
    void createSqstackfromfile(); //导入文本文件数据创建顺序栈函数
    void Destroy(int);//销毁顺序栈
};

void Sqstack::initStart() //顺序栈的初始化函数
{
    cout << "执行顺序栈的初始化功能" << endl;
    S.base = new int[STACKSIZE];//申请空间
    S.top = S.base;//同步信息
}

void Sqstack::pushData(int e) //顺序栈单个数据入栈函数
{
    cout << "执行顺序栈单个数据入栈功能" << endl;
    if (S.top - S.base == STACKSIZE)//判断是否满栈
    {
        cout << "顺序栈满" << endl;
        return;
    }
    *S.top++ = e;//入栈，并调整栈顶
}

int Sqstack::popData() //顺序栈单个数据出栈函数
{
    cout << "执行顺序栈单个数据出栈功能" << endl;
    if (S.top == S.base)//判空
    {
        cout << "顺序栈空" << endl;
        return 0;
    }
    return (*--S.top);//出栈，并调整栈顶
}

int Sqstack::getTopdata() //顺序栈取栈顶函数
{
    cout << "执行顺序栈取栈顶数据功能" << endl;
    if (S.top == S.base)//判空
    {
        cout << "顺序栈空" << endl;
        return 0;
    }
    int *p = S.top;//取顶栈数据地址
    return *--p;//返回
}

int Sqstack::functionDisplay()//顺序表功能打印输出函数
{
    int menu;
    system("cls"); //清屏
    cout << endl
         << endl;
    cout << "------------------------------------------------------\n";
    cout << "          顺      序      表      菜      单            \n";
    cout << "------------------------------------------------------\n";
    cout << "          1. 初始化顺序栈     6. 多数据入栈               \n";
    cout << "          2. 数据入栈         7. 数据顺序出栈             \n";
    cout << "          3. 数据出栈         8. 数据存储至文件           \n";
    cout << "          4. 取栈顶数据       9. 导入文件数据创建顺序栈     \n";
    cout << "          0. 退出程序                                  \n";
    cout << "\n    请选择你的操作[0~9]:";
    cin >> menu;
    cout << "------------------------------------------------------\n";
    if((S.top==nullptr||S.base==nullptr)&&menu!=1&&menu!=0)
    {
        cout<<"还没有初始化顺序栈或者顺序栈被销毁，请先初始化！";
        return functionDisplay();
    }
    return menu;
}

void Sqstack::pushLotsdata(int num)//顺序表多数据入栈函数
{
    cout << "执行多数据入栈功能" << endl;
    initStart();//先初始化
    int i;
    for (i = 0; i < num; i++)
    {
        printf("请输入第%d个入栈数据:", i + 1);//依次输入
        cin >> *S.top;//入栈
        S.top++;//栈顶更新
    }
}

//顺序表的数据顺序出栈函数
void Sqstack::popLotsdata()
{
    cout << "执行多数据出栈功能" << endl;
    if (S.top == S.base)//判空栈
    {
        cout << "栈空" << endl;
        return;
    }
    int i = 1;
    while (S.top != S.base)
    {
        cout<<"第"<<i<<"个出栈数据:"<<(*--S.top)<<endl;//一个个输出
        i++;
    }
}
//顺序表的数据存储至文本文件函数
void Sqstack::storeDatafile()
{
    cout << "执行顺序表的数据存储至文本文件功能" << endl;
    FILE *fp = fopen("Sqstack.txt", "w");//W打开文件，存在即覆盖。
    if (!fp)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    int i = 0;
    int *p = S.base;
    int *q = S.top;
    while (p != q)
    {
        i++;
        fprintf(fp, "顺序栈第%d个数据:%d\n", i, *p++);//依次写入
    }
    fclose(fp);//关闭文件
}
//导入文本文件数据创建顺序栈函数
void Sqstack::createSqstackfromfile()
{
    cout << "执行导入文本文件数据创建顺序栈功能" << endl;
    initStart();//初始化，等待入栈
    FILE *fp = fopen("Sqstack.txt", "r");//R打开文件
    if (!fp)
    {
        cout << "文件打开失败" << endl;
        return;
    }
    int i;
    while (!feof(fp))
    {
        fscanf(fp, "顺序栈第%d个数据:%d\n", &i, S.top++);//读入，入栈
    }
    fclose(fp);//关闭文件
}

void Sqstack::Destroy(int key=666)
{
    if(S.base)//如果被初始化了才销毁
    {
    delete (S.base);
    cout<<"顺序栈销毁完毕！\n";
    if(key)
        cout<<"如需继续使用请初始化顺序栈！\n";
    }
}

int main()
{
    Sqstack S;
    int menu = 666666;
    while (menu)
    {
        switch (menu = S.functionDisplay())
        {
        case 0:
            break;
        case 1:
            S.initStart();
            break;
        case 2:
        {
            int e;
            cout << "请输入入栈数据e:";
            cin >> e;
            S.pushData(e);
        }
        break;
        case 3:
            printf("顺序栈单个出栈数据:%d\n", S.popData());
            break;
        case 4:
            printf("顺序栈取栈顶数据:%d\n", S.getTopdata());
            break;
        case 6:
        {
            int num;
            cout << "请输入入栈数据总数num:";
            cin >> num;
            S.pushLotsdata(num);
        }
        break;
        case 7:
            S.popLotsdata();
            break;
        case 8:
            S.storeDatafile();
            break;
        case 9:
            S.createSqstackfromfile();
            break;
        default:
            cout << "不存在此功能,请确认后重新输入!" << endl;
        }
        if(menu)
        {
        cout << "按任意键返回菜单！\n" << endl;
        fflush(stdin); //清空输入缓存区
        system("pause");
        }
    }
    S.Destroy(0);
    cout<<"    _    _            _     _\n   | |  | |          | |   | |\n   | |__| |    ___   | |   | |    ___\n   |  __  |   / _ \\  | |   | |   / _ \\\n   | |  | |  |  __/  | |   | |  | (_) |\n   |_|  |_|   \\___|  |_|   |_|   \\___/\n    __  __           __     __           _\n   |  \\/  |          \\ \\   / /          | |\n   | \\  / |_ __       \\ \\_/ /_ _ _ __   | |\n   | |\\/| | '__|       \\   / _` | '_ \\  | |\n   | |  | | |     _     | | (_| | | | | |_|\n   |_|  |_|_|    (_)    |_|\\__,_|_| |_| (_)\n";
    cout << "欢迎下次再使用本系统！\n";
    return 0;
}
