#include<iostream>
using namespace std;
class base
{
    public:
    int a=10;
    void head()
    {
        cout<<"1"<<endl;
    }
};
class java:public base
{
    public:
    int a=20;
    void head()
    {
        cout<<"3"<<endl;
    }
    void content()
    {
        cout<<"2"<<endl;
    }
};
void test01()
{
    java p;
    p.head();
    p.base::head();
    p.content();
    cout<<p.a<<endl;
    cout<<p.base::a<<endl;
}
int main()
{
    test01();
    return 0;

}