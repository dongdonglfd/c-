#include<iostream>
#include<stdio.h>
using namespace std;
// #define FAT 28
int main()
{
    // int age=2;
    // string name="小明";
    // cout<<"hello"<<endl;
    // cout<<FAT<<endl;
    // cout<<"输出你好"<<endl;
    // cout<<"age="<<age<<endl;
    // cout<<name<<endl;
    // cout<<age-2<<endl;
    // cout<<sizeof(age);
    // float s=12345;
    // cout<<fixed; //设置为小数显示
    // cout.width(20);//设置最大宽度
    // cout<<s<<endl;
    // printf("%f",s);
    // string name="小明";
    // int age=21;
    // double height=172.50;
    // //to_string转换为字符串类型
    // string msg="我是： "+name+",身高： "+to_string(height)+"cm,年龄： "+to_string(age)+"岁。";
    // cout<<msg<<endl;
    // bool flag=true;
    // cout<<flag<<endl;
    // int age=0;
    // cout<<"请输入一个整数"<<endl;
    // cin>>age;
    // cout<<age<<endl;
    // string a="a";
    // string b="b";
    // cout<<(a<b)<<endl;
    //枚举
    enum color
    {
        red,//默认0
        yellow,//1
        blue//2
    };
    int num;
    cin>>num;
    switch(num)
    {
        case red:
        cout<<"red";
        break;
        case yellow:
        cout<<"yellow";
        break;
        case blue:
        cout<<"blue";
        break;
    }
    return 0;
}