#include<iostream>
using namespace std;

void Swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}
int main()
{
    int a = 100;
    int b = 200;
    //printf("交换前：a = %d, b = %d", a, b);
    cout << "交换前：a = " << a << ", b = " << b << endl;
    Swap(a, b);
    //printf("交换后：a = %d, b = %d", a, b);
    cout << "交换后：a = " << a << ", b = " << b << endl;

    return 0;
}