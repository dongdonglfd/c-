#include<iostream>
using namespace std;
class person
{
    public:
    person()
    {
        cout<<"person 的默认构造函数的调用"<<endl;
    }
    person(int age,int height)
    {
        m_age=age;
        m_height=new int (height);
        cout<<"person 的有参构造函数的调用"<<endl;
    }
    person(const person &p)
    {
        cout<<"拷贝函数"<<endl;
        m_age=p.m_age;
        //m_height=p.m_height编译器默认
        m_height=new int (*p.m_height);
    }
    ~person()
    {
        if(m_height!=NULL)
        {
            delete m_height;
            m_height=NULL;
        }
        cout<<"person 的析构函数的调用"<<endl;
    }
    int m_age;
    int *m_height;
};
void test01()
{
    person p1(18,18);
    cout<<"p1年龄"<<p1.m_age<<"身高"<<*p1.m_height<<endl;
    person p2(p1);
    cout<<"p2年龄"<<p2.m_age<<endl;
}
int main()
{
    test01();
}