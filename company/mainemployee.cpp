#include <iostream>
#include <string>
using namespace std;

//为了省时间，直接用define
#define 提成比例 0.3
#define 公司人员数 6
#define 时薪 13.0
#define 月薪 10000

class employee
{
private:
    string employeeID;
    string name;
    double wage;

public:
    void setName(string name);
    string getName();
    void setemployeeID(string employeeID);
    string getemployeeID();
    double getWage();
};

class technician : public employee
{
private:
    int hour;
    double hourWage;

public:
    void setHour(int hour);
    void setHourWage(double hourWage);
    double getWage(int hour, double hourWage);
};

class salesman :virtual public employee
{
private:
    double salesVolume;
    double proportion;

public:
    void setSalesVolume(double salesVolume);
    void setProportion(double proportion);
    double getWage(double salesVolume, double proportion);
};

class manager :virtual public employee
{
private:
    double monthlySalary;

public:
    void setMonthlySalary(double monthlySalary);
    double getWage(double monthlySalary);
};


class salsemanager : public salesman, public manager//多继承子类
{
public:
    double getWage(double monthlySalary, double salesVolume, double proportion);
};

//基类函数
void employee::setName(string name)
{
    this->name = name;
}

void employee::setemployeeID(string employeeID)
{
    this->employeeID = employeeID;
}

string employee::getName()
{
    return name;
}

string employee::getemployeeID()
{
    return employeeID;
}

//设置技术员时间
void technician::setHour(int hour)
{
    this->hour = hour;
}
//设置技术员时薪
void technician::setHourWage(double hourWage)
{
    this->hourWage = hourWage;
}
//设置销售员销量
void salesman::setSalesVolume(double salesVolume)
{
    this->salesVolume = salesVolume;
}
//设置销售员分红比例
void salesman::setProportion(double proportion)
{
    this->proportion = proportion;
}
//设置经理月薪
void manager::setMonthlySalary(double monthlySalary)
{
    this->monthlySalary = monthlySalary;
}

//实现technician收入计算方法
double technician::getWage(int hour, double hourWage)
{
    return hour * hourWage;
}
//实现salesman收入计算方法
double salesman::getWage(double salesVolume, double proportion)
{
    return salesVolume * proportion;
}
//实现manager收入计算方法
double manager::getWage(double monthlySalary)
{
    return monthlySalary;
}
//实现salsemanager收入计算方法
double salsemanager::getWage(double monthlySalary, double salesVolume, double proportion)
{
    return monthlySalary + salesVolume * proportion;
}

int main()
{

    employee *p[公司人员数];
    technician t1, t2;
    salesman s1, s2;
    manager m;
    salsemanager sm;

    p[0] = &t1;
    p[1] = &t2;
    p[2] = &s1;
    p[3] = &s2;
    p[4] = &m;
    p[5] = &sm;
    string str;

    cout << "请输入技术员1的姓名:" ;

    cin >> str;
    p[0]->setName(str);
    p[0]->setemployeeID("1001");
    cout << "姓名: " << p[0]->getName() << endl;
    cout << "员工号: " << p[0]->getemployeeID() << endl;
    cout << "工资: " << t1.getWage(200, 时薪) << endl;

    cout << "请输入技术员2的姓名:" ;

    cin >> str;
    p[1]->setName(str);
    p[1]->setemployeeID("1002");
    cout << "姓名: " << p[1]->getName() << endl;
    cout << "员工号: " << p[1]->getemployeeID() << endl;
    cout << "工资: " << t2.getWage(240, 时薪) << endl;

    cout << "请输入销售员1的姓名:" ;
    cin >> str;
    p[2]->setName(str);
    p[2]->setemployeeID("2001");
    cout << "姓名" << p[2]->getName() << endl;
    cout << "员工号" << p[2]->getemployeeID() << endl;
    cout << "工资: " << s1.getWage(12345, 提成比例) << endl;

    cout << "请输入销售员2的姓名:" ;
    cin >> str;
    p[3]->setName(str);
    p[3]->setemployeeID("2002");
    cout << "姓名" << p[3]->getName() << endl;
    cout << "员工号" << p[3]->getemployeeID() << endl;
    cout << "工资: " << s2.getWage(24680, 提成比例) << endl;

    cout << "请输入经理的姓名:" ;
    cin >> str;
    p[4]->setName(str);
    p[4]->setemployeeID("3001");
    cout << "姓名" << p[4]->getName() << endl;
    cout << "员工号" << p[4]->getemployeeID() << endl;
    cout << "工资: " << m.getWage(月薪) << endl;

    cout << "请输入销售经理的姓名:" ;
    cin >> str;
    p[5]->setName(str);
    p[5]->setemployeeID("4001");
    cout << "姓名" << p[5]->getName() << endl;
    cout << "员工号" << p[5]->getemployeeID() << endl;
    cout << "工资: " << sm.getWage(月薪, (12345+24680), 提成比例) << endl;

    return 0;
}
