#include<iostream>
#include<queue>
#include<string>
using namespace std;
class person
{
    public:
    person(string name)
    {
        this->m_name=name;
    }
    string m_name;
};
void test01()
{
    queue<person>q;
    person p1("1");
    person p2("2");
    person p3("3");
    q.push(p1);
    q.push(p2);
    q.push(p3);
    while(!q.empty())
    {
        cout<<q.front().m_name<<endl;
        cout<<q.back().m_name<<endl;
        q.pop();

    }

}

int main()
{
    test01();
}