//
//  main.cpp
//  顺序表v0.3
//
//  Created by 张亮 on 2020/2/15 in Xcode.
//  Copyright © 2020 张亮. All rights reserved.
//

//v0.2加入菜单
//v0.3优化逻辑问题

#include <iostream>
using namespace std;

#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LISTINCREMENT 10   // 线性表存储空间的分配增量

class SqList // 顺序表（顺序结构）的定义
{
private:
    int *elem;    // 存储空间基址
    int listsize; // 当前分配的存储容量（以sizeof(int)为单位）
public:
    int length;                           // 当前长度
    void IntiaList();                     //初始化链表
    void DestroyList();                   //顺序表销毁
    void ClearList();                     //顺序表清空
    int ListEmpty();                      //顺序表判空
    int ListLength();                     //顺序表长度
    int GetElem(int i, int &e);           //定位元素
    int LocateElem(int e);                //定位值
    int PriorElem(int cur_e, int &pre_e); //前驱元素
    int NextElem(int cur_e, int &next_e); //下一个元素
    int ListInsert(int i, int e);         //顺序表插入
    int show();                           //顺序表输出
    int ListDelete(int i, int &e);        //退出程序
};

void SqList::IntiaList()
{
    elem = new int[LIST_INIT_SIZE]; //初始化分配
    length = 0;                     //初始化元素个数
    listsize = LIST_INIT_SIZE;      //初始化链表被分配长度
}

void SqList::DestroyList()
{
    delete elem; //删除所分配空间
}

void SqList::ClearList()
{
    length = 0; //直接令元素长度为0
}

int SqList::ListEmpty()
{
    return length ? 0 : 1; //有长度就返回0，没有就是1
}

int SqList::ListLength()
{
    return length;
}

int SqList::GetElem(int i, int &e)
{
    if ((i < 1) || (i > length)) //判断输入是否合法
        return 0;
    e = elem[i - 1]; //返回值
    return 1;
}

int SqList::LocateElem(int e)
{
    int i = 0;
    while (i < length)
        if (elem[i++] == e)
            return (i); //找到制定值的元素项
    return 0;
}

int SqList::PriorElem(int cur_e, int &pre_e)
{
    int i;
    i = LocateElem(cur_e); //先定位当前
    if (i == 0 || i == 1)  //不存在、已经是第一个元素，返回0
        return 0;
    pre_e = elem[i - 2]; //返回前驱
    return 1;
}

int SqList::NextElem(int cur_e, int &next_e)
{
    int i;
    i = LocateElem(cur_e);     //先定位当前
    if (i == 0 || i == length) //不存在、已经是最后一个元素返回0
        return 0;
    next_e = elem[i]; //返回后继
    return 1;
}

int SqList::ListInsert(int i, int e)
{
    if ((i < 1) || (i > length + 1)) //判断数据合法
    {
        cout << "数据非法，超过当前的长度/数据需为正整数";
        return 0;
    }
    int *newelem, *q, *p;
    if (length >= listsize)
    {                                                                             // 当前存储空间已满，增加分配
        newelem = (int *)realloc(elem, (listsize + LISTINCREMENT) * sizeof(int)); //重新分配空间
        if (!newelem)
            return 0;
        elem = newelem;
        listsize += LISTINCREMENT; //增加顺序表长度
    }
    q = &(elem[i - 1]);
    for (p = &(elem[length - 1]); p >= q; --p)
        *(p + 1) = *p; //移动元素
    *q = e;            //插入
    ++length;          //增加元素个数
    return 1;
}

int SqList::ListDelete(int i, int &e)
{
    int *q, *p;
    if ((i < 1) || (i > length)) //判断合法
        return 0;
    p = &(elem[i - 1]);
    e = *p;
    q = elem + length - 1;
    for (++p; p <= q; ++p) //移动元素
        *(p - 1) = *p;
    --length; //减少元素个数
    return 1;
}

int SqList::show()
{
    int i;
    for (i = 0; i < length - 1; i++) //输出n-1个元素
        cout << elem[i] << "--";
    cout << elem[i] << endl; //输出第n个
    return length;
}

int main(void)
{
    SqList L;      //定义一个顺序表
    L.IntiaList(); //初始化
    int menu = 1;
    while (menu)
    {
        system("cls"); //清屏
        cout << endl
             << endl;
        cout << "------------------------------------------------------\n";
        cout << "          顺      序      表      菜      单            \n";
        cout << "------------------------------------------------------\n";
        cout << "          1. 初始化顺序表      7. 定位值\n";
        cout << "          2. 顺序表销毁        8. 前驱元素\n";
        cout << "          3. 顺序表清空        9. 后继元素\n";
        cout << "          4. 顺序表判空       10. 顺序表插入\n";
        cout << "          5. 顺序表长度       12. 顺序表输出\n";
        cout << "          6. 定位元素          0. 退出程序\n";
        cout << "\n    请选择你的操作[0~14]:";
        cin >> menu;
        cout << "------------------------------------------------------\n";
        switch (menu)
        {
        case 1:
        {
            if (L.length == 0) //如果没有元素，则初始化
            {
                int n = LIST_INIT_SIZE;
                cout << "请输入初始化的元素个数n：";
                cin >> n;
                cout << "请输入初始化的" << n << "个元素，以空格分开： \n";
                for (int i = 1; i <= n; i++)
                {
                    int m;
                    cin >> m;
                    L.ListInsert(i, m); //一个个插入
                }
                cout << "初始化完毕!";
            }
            else
                cout << "已经初始化过了！";
        }
        break;
        case 2:
        {
            L.DestroyList();
            cout << "线性表销毁成功！\n";
        }
        break;
        case 3:
        {
            L.ClearList();
            cout << "线性表清空成功！\n";
        }
        break;
        case 4:
        {
            if (L.ListEmpty())
                cout << "该表为空表！\n";
            else
                cout << "该表不为空！\n";
        }
        break;
        case 5:
            cout << "该表的长度为" << L.ListLength() << endl;
            break;
        case 6:
        {
            int i = 0;
            int e = 0;
            cout << "请输入你想知道第几个元素的值：\n";
            cin >> i;
            if (i > L.length || i <= 0)
            {
                L.GetElem(i, e);
                cout << "该表中第" << i << "个元素为" << e << endl;
            }
            else
                cout << "数据非法，链表没有那么长或者不可为负数！\n";
        }
        break;
        case 7:
        {
            int x = 0;
            cout << "请输入你想查找的元素：\n";
            cin >> x;
            int i = L.LocateElem(x);
            if (i != 0)
                cout << "该元素存在，且在该表中为第" << i << "位！\n";
            else
                cout << "该元素在此表中不存在！\n";
        }
        break;
        case 8:
        {
            int pre_e = 0, cur_e = 0;
            cout << "请输入你想要获得前驱的元素：\n";
            cin >> cur_e;
            if (L.PriorElem(cur_e, pre_e) == 1)
                cout << "前驱元素为" << pre_e << endl;
            else
                cout << "请重新输入！\n";
        }
        break;
        case 9:
        {
            int cur_e = 0, next_e = 0;
            cout << "请输入你想要获得后继的元素：\n";
            cin >> cur_e;
            if (L.NextElem(cur_e, next_e) == 1)
                cout << "后继元素为" << next_e << endl;
            else
                cout << "请重新输入！\n";
        }
        break;
        case 10:
        {
            int i = 0;
            int e = 0;
            cout << "请输入你想要插入元素的位置：\n";
            cin >> i;
            cout << "请输入你想要插入的元素：\n";
            cin >> e;
            if (L.ListInsert(i, e) == 1)
                cout << "插入成功！\n";
            else
                cout << "插入失败！\n";
        }
        break;
        case 11:
        {
            if (L.length != 0)
            {
                int i = 0;
                int e = 0;
                cout << "请输入你想要删除的元素的位置：\n";
                cin >> i;
                if (L.ListDelete(i, e) == 1)
                    cout << "删除成功，且删除的元素为" << e << endl;
                else
                    cout << "删除失败！\n";
            }
            else
                cout << "该表为空表！\n";
        }
        break;
        case 12:
        {
            if (!L.show())
                cout << "线性表是空表！\n";
        }
        break;
        case 0:
            break;
        default:
            cout << "不存在此功能,请确认后重新输入!\n";
            break;
        }
        cout << "按任意键返回菜单！" << endl;
        fflush(stdin); //清空输入缓存区
        system("pause");
    }
    L.DestroyList(); //销毁顺序表
    cout << "欢迎下次再使用本系统！\n";
}
