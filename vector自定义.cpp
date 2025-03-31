#include<iostream>
#include<vector>
#include<string>
using namespace std;
class person
{
    public:
    person(string name,int age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    string m_name;
    int m_age;
};
void test01()
{
    vector<person> v;
    person p1("1",10);
    person p2("2",20);
    person p3("3",30);
    person p4("4",40);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    for(vector<person>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it).m_name<<(*it).m_age<<endl;
        // cout<<it->m_name<<it ->m_age<<endl;
    }
}
void test02()
{
    vector<person*> v;
    person p1("1",10);
    person p2("2",20);
    person p3("3",30);
    person p4("4",40);
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    for(vector<person*>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<(*it)->m_name<<(*it)->m_age<<endl;
    }
}
int main()
{
    test02();
}