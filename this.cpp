#include<iostream>
using namespace std;
class person
{
    public:
    person(int age)
    {
        this->age=age;
    }
    person & personadd( person &p)
    {
        this->age+=p.age;
        return *this;
    }
    int age;
};
void test01()
{
    person p(10);
    cout<<p.age<<endl;
    person p2(10);
    p2.personadd(p).personadd(p).personadd(p);
    cout<<p2.age<<endl;
}
int main()
{
    test01();
}