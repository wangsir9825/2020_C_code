#include<iostream>
using namespace std;
int& Count()
{
    static int n = 0;
        n++;
    return n;
}
int main()
{
    int num = 0;
    int i = 9;
    while(i--)
        Count();
    num = Count();
    cout << "num = " << num << endl;
    return 0;
}