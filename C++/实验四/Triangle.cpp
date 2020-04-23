#include <iostream>
#include <math.h>
using namespace std;
class Point //点类
{
    friend class Triangle;

private:
    double x, y;

public:
    Point(double x0 = 0, double y0 = 0)
    {
        x = x0;
        y = y0;
    };                           //初始化横纵坐标
    void display();              //输出函数
    void move(double, double);   //移动函数
    Point operator+(Point pt2);  //两坐标相加
    double operator^(Point pt2); //两坐标距离
    double ODistance();          //坐标与原点之间的距离
} O(0, 0);

class Triangle //三角形类
{
private:
    Point axy, bxy, cxy; //三点坐标
    double a, b, c;      //三点边长
    double A, B, C;      //三点角度(弧度制)
    int isLegal();       //数据是否合法
public:
    Triangle(Point Pa = O, Point Pb = O, Point Pc = O);
    double getSideLength(); //求边长
    double getArea();       //求面积
    Point getCenter(int);   //求三角形三心：内心，外心，重心
    //void getLine(char,int);获取三角形指定边的中线，角平分线，垂线。懒得做了。。。。。
};

void Point::display()
{
    cout << "（" << x << "," << y << "）" << endl;
}
void Point::move(double deltaX, double deltaY)
{
    x += deltaX;
    y += deltaY;
}
Point Point::operator+(Point plus)
{
    Point sum(x + plus.x, y + plus.y);
    return sum;
}
double Point::operator^(Point pt2)
{
    return sqrt(pow((x - pt2.x), 2) + pow((y - pt2.y), 2));
}
double Point::ODistance()
{
    return sqrt(pow(x, 2) + pow(y, 2));
}
Triangle::Triangle(Point Pa, Point Pb, Point Pc)
{
    axy = Pa;
    bxy = Pb;
    cxy = Pc;
    a = bxy ^ cxy;
    b = axy ^ cxy;
    c = axy ^ bxy;
    if (isLegal())
    {
        A = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / 2 / b / c);
        B = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / 2 / a / c);
        C = acos((pow(b, 2) + pow(a, 2) - pow(c, 2)) / 2 / b / a);
    }
    else
        cout << "数据非法，无法围成三角形。请确定数据!";
}
int Triangle::isLegal()
{
    return (a + b > c && a + c > b && b + c > a) ? 1 : 0;
}
double Triangle::getSideLength()
{
    return a + b + c;
}
double Triangle::getArea()
{
    double C = getSideLength();
    return sqrt(C / 2 * (C / 2 - a) * (C / 2 - b) * (C / 2 - c));
}
Point Triangle::getCenter(int model)
{
    switch (model)
    {
    case 1: //重心
        return Point(((axy.x + bxy.x + cxy.x) / 3), ((axy.y + bxy.y + cxy.y) / 3));
    case 2: //内心
        return Point(((a * axy.x + b * bxy.x + c * cxy.x) / getSideLength()), ((a * axy.y + b * bxy.y + c * cxy.y) / getSideLength()));
    case 3: //外心
    {
        double x1 = axy.x, y1 = axy.y;
        double x2 = bxy.x, y2 = bxy.y;
        double x3 = cxy.x, y3 = cxy.y;

        double a1 = 2 * (x2 - x1);
        double b1 = 2 * (y2 - y1);
        double c1 = x2 * x2 + y2 * y2 - x1 * x1 - y1 * y1;

        double a2 = 2 * (x3 - x2);
        double b2 = 2 * (y3 - y2);
        double c2 = x3 * x3 + y3 * y3 - x2 * x2 - y2 * y2;

        double x = (c1 * b2 - c2 * b1) / (a1 * b2 - a2 * b1);
        double y = (a1 * c2 - a2 * c1) / (a1 * b2 - a2 * b1);

        return Point(x, y);
    }
    case 4: //垂心
    {
        cout << "暂时不支持！";
    } //暂时无法从三点坐标直接得出垂心，必须用老办法；任意两垂线相交，代码肯定较多。方程的话，代码少，但误差和耗时嘛。。
    default:
        cout << "参数错误，请检查";
        break;
    }
    return NULL;
}

int main()
{
    Point test1(1, 1);
    Point test2(2, 2);
    Point test3(3, 1);
    Triangle test(test1, test2, test3);
    test.getCenter(4).display();
}
