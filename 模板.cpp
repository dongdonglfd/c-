#include<iostream>
using namespace std;
template<typename T>
void swap1(T &a,T &b)
{
    T temp =a;
    a=b;
    b=temp;
}
void my_print(int a,int b)
{
    cout<<"普通函数的调用"<<endl;
}
template<class T>
void my_print(T a,T b)
{
    cout<<"调用的模板"<<endl;
}
void test01()
{
    int a=10;
    int b=20;
    swap1<int>(a,b);
    cout<<a<<b<<endl;
}
void test02()
{
    int a=10;
    int b=20;
    my_print(a,b);
    my_print<>(a,b);
}
int main()
{
    // test01();
    test02();
}