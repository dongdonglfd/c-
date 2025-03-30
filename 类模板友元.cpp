#include<iostream>
#include<string>
using namespace std;
template <class T1,class T2>
class person;
template <class T1,class T2>
void print2(person<T1,T2> P)
{
    cout<<"2"<<endl;
}
template <class T1,class T2>
class person
{
    //全局函数 类内实现
    friend void print(person<T1,T2> p)
    {
        cout<<"1"<<endl;
    }
    //类外实现
    friend void print2<>(person<T1,T2> p);
    public:
    person(T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    private:
    T1 m_name;
    T2 m_age;

};

void test01()
{
    person<string ,int> p("tom",100);
    print2(p);
}
int main()
{
    test01();
}