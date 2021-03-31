#include<iostream>
using namespace std;
int& Count()
{
    static int n = 0; // n 是静态局部变量
    n++;
    return n;
}
int main()
{
    int num = Count(); //利用变量num接收函数返回值
    for (int i = 9; i > 0; --i)
        Count();
    cout << "num = " << num << endl;
    return 0;
}