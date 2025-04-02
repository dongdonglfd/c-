#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;
void printdeque(const deque<int>&d)
{
    for(deque<int>::const_iterator it=d.begin();it!=d.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void test01()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    deque<int>d2=d1;
    printdeque(d2);
    deque<int>d3;
    d3.assign(d1.begin(),d1.end());
    printdeque(d3);
    deque<int>d4;
    d4.assign(10,100);
    printdeque(d4);
}
void test02()
{
    deque<int>d1;
    for(int i=0;i<10;i++)
    {
        d1.push_back(i);
    }
    printdeque(d1);
    if(d1.empty())
    {
        cout<<"1"<<endl;
    }
    else
    {
        cout<<"2"<<endl;
        cout<<d1.size()<<endl;

    }
    d1.resize(15,1);
    printdeque(d1);
}
void test03()
{
    deque<int>d;
    d.push_back(10);
    d.push_back(20);
    d.push_back(30);
    d.push_front(100);
    d.push_front(200);
    d.push_front(300);
    sort(d.begin(),d.end());
    printdeque(d);


}
int main()
{
    test03();

}