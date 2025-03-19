#include<iostream>
#include<string.h>
using namespace std;
class phone
{
    public:
    phone(string d)
    {
        p=d;
    }
    string p;
};
class person
{
    public:
    // person(int a,int b,int c)
    // {
    //     ma=a;
    //     mb=b;
    //     mc=c;

    // }
    //初始化列表初始化属性
    person(int a,int b,int c,string d):ma(a),mb(b),mc(c),md(d)
    {

    }
    int ma;
    int mb;
    int mc;
    phone md;
};
void test01()
{
    // person p(10,20,30);
    person p(30,20,10,"1");
    cout<<p.ma<<p.mb<<p.mc<<endl;
}
int main()
{
    test01();

}