#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class person
{
    public:
    person() {
        m_name[0] = '\0';
        m_age = 0;
    }
    person (const char name[],int age)
    {
        strcpy(m_name,name);
        m_age=age;
    }
    char m_name[64];
    int m_age;

};
void test01()
{
    ofstream ofs;
    ofs.open("person.txt",ios::out | ios::binary);
    person p("张三",18);
    ofs.write((const char *)&p,sizeof(person));
    ofs.close();
}
void test02()
{
    ifstream ifs;
    ifs.open("person.txt",ios::in |ios ::binary);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return;
    }
    person n;
    ifs.read((char *)&n,sizeof(n));
    cout<<n.m_name<<n.m_age<<endl;
    ifs.close();
}
int main()
{
    test01();
    test02();
}