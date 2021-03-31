#include<iostream>
using namespace std;

int& Add(int a, int b) {
    int c = a + b;
    return c;
}
int main()
{
    int x1 = Add(1,2); //利用变量接收函数的返回值
    int x2 = Add(3,4);
    cout << "x1 = " << x1 << endl; //输出变量x1的值
    cout << "x2 = " << x2 << endl; //输出变量x2的值

    return 0;
}