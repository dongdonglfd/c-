#include<iostream>
#include<string>
using namespace std;
class student//类
{
    public:
    student()
    {
        cout<<"构造函数"<<endl;
    }
    student(int a)
    {
        age=a;
        cout<<"有参构造函数"<<endl;
    }
    student (const student &p)
    {
        age=p.age;
        cout<<"拷贝构造函数"<<endl;
    }

    public:
    string name;
    int id;
    int age;
    protected:
    string car;
    private:
    int password;
    void show()
    {
        cout<<name<<id<<endl;
    }
    void set(string n)
    {
        name=n;
    }
    public:
    ~student()
    {
        cout<<"析构函数"<<endl;
    }
};
void test()
{
    student p1;
    student p2(10);
    student p3(p2);
    cout<<"age="<<p2.age<<endl;
    cout<<"age="<<p3.age<<endl;
    student p4=student (10);
    student p5=10;//student p5=student (10);
    student p6=p5;
    

}

int main()
{
    test();
    // student p;
    // student s;
    // s.name="张三";
    // //s,set("张三")；
    // s.id=1;
    // s.show();
    return 0;
}