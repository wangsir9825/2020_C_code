#include<iostream>
using namespace std;

//函数模板示例，把类型当做参数进行传递
//template<class Type>
//void Swap(Type & a, Type & b)
//{
//    cout << "Type" << typeid(Type).name() << endl;
//    Type tmp = a;
//    a = b;
//    b = tmp;
//}
//函数模板
template<typename Type>//新版c++标准使用关键字typename，
void Swap(Type& a, Type& b)
{
    cout << "Type" << typeid(Type).name() << endl;
    Type tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    char ch1 = 'a';
    char ch2 = 'b';
    printf("交换前:");
    cout << ch1 << " " << ch2 << endl;
    Swap(ch1, ch2);
    printf("交换后:");
    cout << ch1 << " " << ch2 << endl;
    int a = 100, b = 200;
    printf("交换前:");
    cout << a << " " << b << endl;
    Swap(a, b);
    printf("交换后:");
    cout << a << " " << b << endl;
    return 0;
}