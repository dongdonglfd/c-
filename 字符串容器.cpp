#include<iostream>
#include<string>
using namespace std;
void test01()
{
    string str1="1";
    str1+="23";
    cout<<str1<<endl;
    string str2="hello";
    str1 +=str2;
    cout<<str1<<endl;
    string str3="1";
    str3.append("23");
    cout<<str3<<endl;
    str3.append("game abcd",4);
    cout<<str3<<endl;
    str3.append(str2);
    cout<<str3<<endl;
    str3.append(str2,0,1);
}
void test02()
{
    string str1 ="abcd";
    int pos=str1.find("cd");
    //pos=str1.rfind("cd");//从右往左查找
    cout<<pos<<endl;
}
void test03()
{
    string str1="abcdef";
    str1.replace(1,3,"1111");
    cout<<str1<<endl;
}
void test04()
{
    string str1="xello";
    string str2="hello";
    if(str1.compare(str2)==0)
    {
        cout<<"1"<<endl;
    }
    else if(str1.compare(str2)>0)
    {
        cout<<"2"<<endl;
    }
    else{
        cout<<"3"<<endl;
    }

}
void test05()
{
    string str="hello";
    for(int i=0;i<str.size();i++)
    {
        cout<<str[i]<<endl;
    }
    // for(int i=0;i<str.size();i++)
    // {
    //     cout<<str.at(i)<<endl;
    // }
    str[0]='x';
    str.at(1)='x';
    cout<<str<<endl;
}
void test06()
{
    string str="hello";
    str.insert(1,"111");
    cout<<str<<endl;
    str.erase(1,3);
    cout<<str<<endl;

}
void test07()
{
    string str="abcdef";
    string substr=str.substr(1,3);
    cout<<substr<<endl;
}
void test08()
{
    string email="zhangsan@com";
    int pos=email.find("@");
    string username=email.substr(0,pos);
    cout<<username<<endl;
}
int main()
{
    test08();

}