#include<iostream>
using namespace std;
class person
{
    public:
    static int a;
    static void func()
    {
        
    }
    static int b;
};
int person::a=100;
int person::b=0;
void test01()
{
    person p;
    cout<<p.a<<endl;
    cout<<p.func<<endl;
    cout<<person::func<<endl;
    cout<<person::a<<endl;
    
}
int main()
{

    test01();
}