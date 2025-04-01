#include<iostream>
#include<string>
using namespace std;
void test01()
{
    string s1;
    const char *str="hello world";
    string s2(str);
    cout<<s2<<endl;
    string s3(s2);
    cout<<s3<<endl;
    string s4(10,'1');
    cout<<s4<<endl;
    string str5;
    str5.assign("c++");
    cout<<str5<<endl;
    string str6;
    str6.assign("hello c++",5);
    cout<<str6<<endl;
}
int main()
{
    test01();
}