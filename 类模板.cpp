#include<iostream>
#include<string>
using namespace std;
template <class nametype, class agetype=int>
class person
{
    public:
    person(nametype name,agetype age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    void show()
    {
        cout<<"1"<<endl;
    }
    nametype m_name;
    agetype m_age;


};
void printperson1(person<string,int>&p)
{
    p.show();
}
template<class T1,class T2>
void printperson2(person<T1,T2>&p)
{
    p.show();
    cout<<typeid(T1).name()<<endl;
}

void test01()
{
    person<string ,int> p1("孙悟空",999);
    printperson1(p1);

}
void test02()
{
    person<string ,int> p2("孙",999);
    printperson2(p2);

}
//类模板的继承
template <class T>
class base
{

    T m;
};
class son:public base<int>
{

};
template<class t1,class t2>
class son2 :public base<t2>
{
    t1 obj;
};
int main()
{
    test01();
}