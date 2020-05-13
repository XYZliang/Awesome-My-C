//
//  main.cpp
//  循环队列
//
//  Created by 张亮 on 2020/4/03.
//  Copyright © 2020 张亮. All rights reserved.
//

//取消初始化和销毁函数的菜单入口，改为运行程序/退出程序时自动运行
//v0.2:使用更骚的outstream/ofstream来储存/读取文件

#include <iostream>
#include <string>
#include <fstream>
#define MAX 200
using namespace std;

#pragma warning(disable:4996)
//允许vs使用sscanf

struct cirsequeue
{
    int *base;//存储队列元素指针
    int front;//头
    int rear;//尾
};
class Cirsequeue
{
private:
    cirsequeue C;//定义循环队列基本结构
public:
    void initStart();             //循环顺序队列初始化函数
    void pushLotdata(int);    //循环顺序队列多数据入队函数
    void popLotdata();            //循环顺序队列总数据出队函数
    void pushData(int);         //循环顺序队列单数据入队函数
    int popData();                //循环顺序队列单数据出队函数
    void storeDatatofile(); //循环顺序队列数据存储至文本文件函数
    void getDatafromfile();       //导入文本文件数据创建循环顺序队列函数
    int displayFunction();       //循环队列功能打印输出函数
    void Destroy();
};

void Cirsequeue::initStart()//循环顺序队列初始化函数
{
    cout << "执行顺序队列的初始化功能" << endl;
    C.base = new int[MAX];//申请空间
    if (!C.base)
    {
        cerr << "动态申请空间失败" << endl;
        return;
    }
    C.rear = C.front = 0;//同步信息
}

void Cirsequeue::pushLotdata(int num)//循环队列多数据入队函数
{
    cout << "执行循环顺序队列多数据入队功能" << endl;
    initStart();//先初始化下
    for (int i = 0; i < num; i++)
    {
        printf("请输入第%d个入队数据:", i + 1);
        cin >> C.base[C.rear];//依次入队，移动尾指针
        C.rear = (C.rear + 1) % MAX;
    }
}

void Cirsequeue::popLotdata()//循环队列总数据出队函数
{
    cout << "执行循环顺序队列总数据顺序出队功能" << endl;
    if (C.rear == C.front)//判断是否为空
    {
        cerr << "循环队列空" << endl;
        return;
    }
    int i = 0;
    do
    {
        i++;
        cout<<"第"<<i<<"个出队数据:"<<(C.base[C.front])<<endl;
        C.front = (C.front + 1) % MAX;//依次输出,并移动头指针
    } while (C.front != C.rear);
}

void Cirsequeue::pushData(int e)//循环顺序队列单数据入队函数
{
    cout << "执行循环顺序队列单数据入队功能" << endl;
    if ((C.rear + 1) % MAX == C.front)//判断是否满队
    {
        cerr << "循环队列满" << endl;
        return;
    }
    C.base[C.rear] = e;
    C.rear = (C.rear + 1) % MAX;//入队,并移动尾指针
}

int Cirsequeue::popData()//循环顺序队列单数据出队函数
{
    cout << "执行循环顺序队列单数据出队功能" << endl;
    if (C.rear == C.front)//判空
    {
        cerr << "循环队列为空" << endl;
        return NULL;
    }
    int e = C.base[C.front];
    C.front = (C.front + 1) % MAX;//入队,并移动头指针
    return e;
}

void Cirsequeue::storeDatatofile()//循环顺序队列数据存储至文本文件函数
{
    cout << "执行循环顺序队列数据存储至文本文件功能" << endl;
    if (C.rear == C.front)//判空
    {
        cerr << "循环队列为空" << endl;
        return;
    }
    ofstream outfile;//输出文件流
    outfile.open("Data.txt", ios::out);
    if (!outfile)
    {
        cerr << "文件打开失败" << endl;
        return;
    }
    int front_tmp = C.front;//记录头指针
    int i = 0;
    while (front_tmp != C.rear)
    {
        i++;
        outfile << "第" << i << "个入队数据:" << C.base[front_tmp++] << endl;
    }//写入文件，移动“头”指针
    outfile.close();//关闭输出流
}

void Cirsequeue::getDatafromfile()//导入文本文件数据创建循环顺序队列函数
{
    cout << "执行导入文本文件数据创建循环顺序队列功能" << endl;
    initStart();//初始化
    ifstream infile;//打开输入流
    infile.open("Data.txt", ios::in);
    if (!infile)
    {
        cerr << "文件打开失败" << endl;
        return;
    }
    int i, data;
    char str[MAX];
    while (infile.peek() != EOF)//一直读取到完全结束
    {
        infile.getline(str, sizeof(str));
        sscanf(str, "第%d个入队数据:%d\n", &i, &data);
        C.base[C.rear] = data;
        C.rear = (C.rear + 1) % MAX;
    }//读入，移动尾指针
    infile.close();//关闭输入流
}

int Cirsequeue::displayFunction()//循环队列功能打印输出函数
{
    int menu;
    system("cls");
    cout << endl
         << endl;
    cout << "------------------------------------------------------\n";
    cout << "          顺      序      表      菜      单            \n";
    cout << "------------------------------------------------------\n";
    cout << "          1. 多数据入队         5. 数据存储至文件          \n";
    cout << "          2. 全数据出队         6. 导入文件数据创建顺序栈   \n";
    cout << "          3. 单数据入队         0. 退出程序               \n";
    cout << "          4. 单数据出队                                 \n";
    cout << "\n    请选择你的操作[0~6]:";
    cin >> menu;
    cout << "------------------------------------------------------\n";
    return menu;
}
void Cirsequeue::Destroy()
{
    if (C.base)//如果被初始化过，才进行销毁
    {
    delete C.base;
    cout<<"顺序栈销毁完毕！\n";
    }
}
int main()
{
    Cirsequeue C;
    int menu=888888;
    while(menu)
    {
        switch (menu=C.displayFunction())
        {
                case 0:
                break;
        case 1:
            {
                int num;
            cout << "请输入入队数据总数num:";
            cin >> num;
            C.pushLotdata(num);
            }
            break;
        case 2:
            C.popLotdata();
            break;
        case 3:
            {
                int e;
            cout << "请输入单个入队数据e:";
            cin >> e;
            C.pushData(e);
            }
            break;
        case 4:
            printf("单个出队数据:%d\n", C.popData());
            break;
        case 5:
            C.storeDatatofile();
            break;
        case 6:
            C.getDatafromfile();
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
    };
    C.Destroy();
    cout<<"  .------..------..------.\n  |1.--. ||9.--. ||2.--. |\n  | :/\\: || :/\\: || (\\/) |\n  | (__) || (__) || :\\/: |\n  | '--'1|| '--'9|| '--'2|\n  `------'`------'`------'\n";
    cout << "欢迎下次再使用本系统！\n";
    return 0;
}
