#include "TimeClass.h"
#include <iostream>

int main()
{
    TimeType test9(12,34,56);
    TimeType test10(1,2,3);
    TimeType test11(23,12,10);
    (test9+test10).display();
    (test11-test10).display();
    return 0;
}
