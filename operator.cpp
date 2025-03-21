#include<iostream>
using namespace std;
class person
{
    public:
    //1.成员函数重载+号
    // person operator+ (person &p)
    // {
    //     person t;
    //     t.a=this->a+p.a;
    //     t.b=this->b+p.b;
    //     return t;
    // }
    int a;
    int b;

};
//2.全局函数重载+号
person operator+ (person &p1,person&p2)
{
    person t;
    t.a=p1.a+p2.a;
    t.b=p1.b+p2.b;
    return t;
}
person operator+ (person &p1,int num)
{
    person t;
    t.a=p1.a+num;
    t.b=p1.b+num;
    return t;
}
ostream &operator <<(ostream &out ,person&p)
{
    out<<"a="<<p.a<<"b="<<p.b;
    return out;
}
void test01()
{
    person p1;
    p1.a=10;
    p1.b=10;
    person p2;
    p2.a=10;
    p2.b=10;
    person p3=p1+p2;
    //成员：person p3=p1.opertor+(p2)
    //全局：person p3=opertor+(p1,p2)
    cout<<p3.a<<endl;
    cout<<p3.b<<endl;
    cout<<p3<<endl;
}
int main()
{
    test01();
}
