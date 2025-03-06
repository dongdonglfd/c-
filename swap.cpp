#include<iostream>
using namespace std;
void swap(int &a,int &b)
{
    int t=a;
    a=b;
    b=t;
}
int &test()
{
    static int a=10;
    return a;
}
int main()
{
    int a=10;
    int b=20;
    swap(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    int &r=test();
    cout<<"r="<<r<<endl;
    test()=1000;//函数做左值
    cout<<"r="<<r<<endl;
}