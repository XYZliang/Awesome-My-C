#include <iostream>
#include <cstring>
using namespace std;

#pragma warning(disable : 4996)

class Data
{ //日期类
public:
    Data() {}                     //无参构造
    Data(int yy, int mm, int dd); //有参构造
    Data(Data &ap);               //拷贝复制
    int get_year();               //获取年份
    int get_month();              //获取月份
    int get_day();                //获取日子
    void set_year(int y);         //设置年份
    void set_month(int m);        //设置月份
    void set_day(int d);          //设置日子
private:
    int year;
    int month;
    int day;
};
Data::Data(int yy, int mm, int dd)
{
    year = yy;
    month = mm;
    day = dd;
}
Data::Data(Data &ap)
{
    year = ap.year;
    month = ap.month;
    day = ap.day;
}
inline int Data::get_day()
{
    return day;
}
inline int Data::get_month()
{
    return month;
}
inline int Data::get_year()
{
    return year;
}
inline void Data::set_day(int d)
{
    day = d;
}
inline void Data::set_month(int m)
{
    month = m;
}
inline void Data::set_year(int y)
{
    year = y;
}

class People
{
public:
    People(int num, string se, Data birthd, string iid); //序号、性别、生日、id（身份证、学号、教师号等）
    People(People &tp);
    People() {}
    People get_People();
    ~People() {}
    void set_number(int num)
    {
        number = num;
    }
    void set_sex(string se)
    {
        sex = se;
    }
    void set_birthday(Data birth)
    {
        birthday = birth;
    }
    void set_id(string iidd)
    {
        id = iidd;
    }
    int get_number();//获取序号
    string get_sex();//获取性别
    Data get_birthday();//获取出生年月
    string get_id();//获取id
    void details();//获取详情（输出）

private:
    int number;
    string sex;
    Data birthday;
    string id;
};
inline int People::get_number()
{ //反正短，做内联函数
    return number;
}
inline string People::get_sex()
{
    return sex;
}
inline string People::get_id()
{
    return id;
}
inline Data People::get_birthday()
{
    return birthday;
}
void People::details()
{
    cout << "序号:" << number << endl;
    cout << "性别:" << sex << endl;
    cout << "生日:" << birthday.get_year() << "/" << birthday.get_month() << "/" << birthday.get_day() << endl;
    cout << "ID:" << id << endl;
}
People::People(int num, string se, Data birth, string iid) : birthday(birth)
{
    number = num;
    sex = se;
    id = iid;
}
People People::get_People()
{
    int num, yy, mm, dd;
    string ID, se;
    cout << "请输入序号:";
    cin >> num;
    cout << "请输入性别(male 或 female):";
    cin >> se;
    cout << "请输入生日(比如2020 01 01):" << endl;
    cin >> yy >> mm >> dd;
    cout << "请输入ID:";
    cin >> ID;
    Data birth(yy, mm, dd);
    id = ID;
    number = num;
    sex = se;
    birthday = birth;
    return *this;
}
People::People(People &tp)
{
    number = tp.get_number();
    sex = tp.get_sex();
    id = tp.get_id();
    birthday = tp.get_birthday();
}
class Student : virtual public People
{ //学生类，继承people类
public:
    char classNo[7];
    Student(int num, string se, Data birthd, string iid, const char a[7]) : People(num, se, birthd, iid)
    {
        strcpy(classNo, a);
    }
    ~Student(){};
    void Show_Student()
    {
        cout << "这是学生:" << endl;
        cout << "班级 :" << classNo << endl;
    }
};
class Teacher : virtual public People
{ //老师类，继承people类
public:
    char principalship[11];
    char department[21];
    Teacher(int num, string se, Data birthd, string iid, const char a[11], const char b[21]) : People(num, se, birthd, iid)
    {
        strcpy(principalship, a);
        strcpy(department, b);
    }
    Teacher() {}
    void Show_Teacher()
    {
        cout << "这是老师:" << endl;
        cout << "职务 :" << principalship << endl;
        cout << "科目 :" << department << endl;
    }
};
class Graduate : virtual public Student
{ //研究生类，从学生类继承
public:
    char subject[21];
    Teacher adviser;
    Graduate(int num, string se, Data birthd, string iid, const char a[7], const char c[21], Teacher vt) : People(num, se, birthd, iid), Student(num, se, birthd, iid, a)
    {
        strcpy(subject, c);
        adviser = vt;
    }
    ~Graduate() {}
    void Show_Graduate()
    {
        cout << "这是研究生:" << endl;
        cout << "学科 :" << subject << endl;
        cout << "～导师信息～:" << endl;
        cout << "职务 :" << adviser.principalship << endl;
        cout << "科目 :" << adviser.department << endl;
        cout << endl;
    }
};

int main()
{
    People xyz;
    xyz.get_People();
    cout << endl
         << "☻☻☻☻☻☻☻☻☻a成员☻☻☻☻☻☻☻☻☻" << endl;
    xyz.details();
    Data a(2001, 3, 21);
    Student b(18, "male", a, "0194240", "软件192");
    cout << endl
         << "☻☻☻☻☻☻☻☻☻b成员☻☻☻☻☻☻☻☻☻" << endl;
    b.Show_Student();
    Data a1(1900, 3, 22);
    Teacher c(25, "male", a1, "1614", "班主任", "c++程序设计");
    cout << endl
         << "☻☻☻☻☻☻☻☻☻c成员☻☻☻☻☻☻☻☻☻" << endl;
    c.Show_Teacher();
    Data a2(1995, 3, 23);
    Graduate d(22, "female", a2, "0192334", "软件001", "软件", c);
    cout << endl
         << "☻☻☻☻☻☻☻☻☻d成员☻☻☻☻☻☻☻☻☻" << endl;
    d.Show_Graduate();
    return 0;
}
