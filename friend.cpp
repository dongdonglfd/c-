// #include<iostream>
// #include<string.h>
// using namespace std;
// class building
// {
//     friend void goodgay(building *building); //类的好朋友
//     public:
//     building()
//     {
//         sitingroom="客厅";
//         bedroom="卧室";
//     }
//     public:
//     string sitingroom;
//     private:
//     string bedroom;
// };
// void goodgay(building *building)//全局函数做友元
// {
//     cout<<building->sitingroom<<endl;
//     cout<<building->bedroom<<endl;

// }
// void test01()
// {
//     building building;
//     goodgay(&building);
// }
// int main()
// {
//     test01();
// }
#include<iostream>
#include<string.h>
using namespace std;
class building;
class goodgay
{
public:
    void visit();
    goodgay();
private:
    building *b;
};
class building
{
    friend class goodgay;
public:
    building();
public:
    string sitingroom;
private:
    string bedroom;

};
building::building()
{
    sitingroom="客厅";
    bedroom="卧室";
}
goodgay ::goodgay()
{
    b=new building;
}
void goodgay:: visit()
{
    cout<<b->sitingroom<<endl;
    cout<<b->bedroom<<endl;
}
void test01()
{
    goodgay gg;
    gg.visit();
}
int main()
{
    test01();

}