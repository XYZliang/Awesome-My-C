#include<iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "-------------------------------" << endl;
    cout << setiosflags(ios::left) <<"  "<< setw(7) << "日" << setw(7) << "一" << setw(7) << "二" << setw(7) << "三" << setw(7) << "四" << setw(7) << "五" << setw(7) << "六" << resetiosflags(ios::left)
         << resetiosflags(ios::right) << endl;
    cout << "-------------------------------" << endl;
    
    cout << "-------------------------------" << endl;
}
