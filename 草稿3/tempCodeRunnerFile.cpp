#include <iostream>
#include <iomanip>
using namespace std;
class Matrix
{
private:
    int row, col, *element; //定义矩阵行列、存储空间
public:
    Matrix(int m = 0, int n = 0, int key = 0); //缺省构造函数
    Matrix(const Matrix &src);                 //拷贝构造函数
    void input(int, int);                      //矩阵值修改

    //矩阵的基本运算
    Matrix operator+(Matrix);          //矩阵加法
    Matrix operator-(Matrix);          //矩阵减法
    Matrix operator*(Matrix);          //矩阵乘法
    Matrix operator*(int);             //矩阵数乘
    Matrix operator~();                //矩阵转置
    Matrix &operator=(const Matrix &); //矩阵赋值

    friend ostream &operator<<(ostream &os, const Matrix &c); //重载输出运算符
    //因为没有办法修改 ostream 类和 istream 类，所以只能将<<重载为全局函数的形式。
    //由于这两个函数需要访问 Complex 类的私有成员，因此在 Complex 类定义中将它们声明为友元。

    ~Matrix();
};

Matrix::Matrix(const Matrix &src) //拷贝构造函数
{
    row = src.row;
    col = src.col;
    element = new int[row * col + 1];
    memcpy(element, src.element, (row * col + 1) * 4);
}

Matrix::Matrix(int m, int n, int key)
{
    row = m;
    col = n;
    element = new int[m * n + 1];
    memset(element, 0, (m * n + 1) * 4);
    if (!key) //如果是计算模式，则无需用户输入，直接退出
        return;
    if (m * n)
    {
        cout << "请输入" << m << "×" << n << "矩阵:" << endl;
        for (int i = 1; i <= row; i++)
            for (int ii = 1; ii <= col; ii++)
            {
                int x;
                cin >> x;
                input(ii + (i - 1) * col, x);
            }
    }
}

void Matrix::input(int ele, int num)
{
    element[ele] = num;
}

Matrix Matrix::operator+(Matrix plus)
{
    if (row != plus.row || col != plus.col)
    {
        Matrix error(0, 0);
        error.input(0, -1); //用闲置的0号位来返回错误信息
        return error;
    }
    Matrix results(row, col);
    for (int i = 1; i <= row * col; i++)
        results.input(i, element[i] + plus.element[i]);
    return results;
}

Matrix Matrix::operator-(Matrix sub)
{
    if (row != sub.row || col != sub.col)
    {
        Matrix error(0, 0);
        error.input(0, -1); //用闲置的0号位来返回错误信息
        return error;
    }
    Matrix results(row, col);
    for (int i = 1; i <= row * col; i++)
        results.input(i, element[i] - sub.element[i]);
    return results;
}

Matrix Matrix::operator*(Matrix mul)
{
    if (col != mul.row)
    {
        Matrix error(0, 0);
        error.input(0, -2); //用闲置的0号位来返回错误信息1
        return error;
    }
    Matrix results(row, mul.col);
    for (int newrow = 0; newrow < row; newrow++)
        for (int newcol = 0; newcol < mul.col; newcol++)
            for (int i = 0; i < col; i++)
                results.element[newrow * mul.col + newcol + 1] += element[newrow * col + i + 1] * mul.element[i * mul.col + newcol + 1];
    return results;
}

Matrix Matrix::operator*(int num)
{
    Matrix results(row, col);
    for (int i = 1; i <= row * col; i++)
        results.input(i, element[i] * num);
    return results;
}

Matrix Matrix::operator~()
{
    Matrix results(col, row); //row行，col列交换
    for (int i = 1; i <= col; i++)
        for (int ii = 1; ii <= row; ii++)
            results.input((i - 1) * row + ii, element[(ii - 1) * col + i]);
    return results;
}

Matrix &Matrix::operator=(const Matrix &src) //不能直接等于，否则只是表面上的数据“相同”
{
    delete element;
    row = src.row;
    col = src.col;
    element = new int(row * col + 1);
    memcpy(element, src.element, row * col + 1);
    return *this;
}

ostream &operator<<(ostream &os, const Matrix &c)
{
    int max = c.row * c.col, row = 0;
    if (!max)
    {
        if (c.element[0] == -1)
            os << "矩阵运算失败！有且仅有同型矩阵（行列数相同）之间才可以进行加减法。" << endl;
        else if (c.element[0] == -2)
            os << "矩阵乘法失败！两个矩阵的乘法仅当第一个矩阵A的列数和另一个矩阵B的行数相等时才能定义。" << endl;
        else
            os << "[   ]" << endl
               << "该矩阵为空!" << endl;
    }
    else if (c.row == 1)
    {
        int i = 1;
        os << "[ ";
        for (; i <= c.col; i++)
            os << c.element[i] << " ";
        os << "]" << endl;
    }
    else
    {
        while (++row <= c.row)
        {
            int i = 1;
            if (row == 1)
            {
                os << "┏";
                for (; i <= c.col; i++)
                    os << setw(5) << c.element[i] << "  ";
                os << "  ┓" << endl;
            }
            else if (row == c.row)
            {
                os << "┗";
                for (; i <= c.col; i++)
                    os << setw(5) << c.element[((row)-1) * c.col + i] << "  ";
                os << "  ┛" << endl;
            }
            else
            {
                os << "┃";
                for (; i <= c.col; i++)
                    os << setw(5) << c.element[((row)-1) * c.col + i] << "  ";
                os << "  ┃" << endl;
            }
        }
    }
    return os;
}

Matrix::~Matrix() //析构函数
{
    if (element)
        delete element;
}

int main()
{
    cout << "请输入第一个矩阵A的行列数m n:";
    int row, col;
    cin >> row >> col;
    Matrix A(row, col, 1);

    cout << "请输入第二个矩阵B的行列数m n:";
    cin >> row >> col;
    Matrix B(row, col, 1);

    cout << endl
         << "☲☲☲☲输☲☲☲☲出☲☲☲☲结☲☲☲☲果☲☲☲☲" << endl;
    
    cout << "A*3得到矩阵:" << endl
         << A * 3;

    cout << endl
         << "A转置得到矩阵:" << endl
         << ~A << endl;

    cout << endl
         << "A+B得到矩阵:" << endl
         << A + B << endl;

    cout << endl
         << "A-B得到矩阵:" << endl
         << A - B << endl;

    cout << endl
         << "A*B得到矩阵:" << endl
         << A * B << endl;
    return 0;
}
