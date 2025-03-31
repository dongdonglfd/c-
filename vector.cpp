#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printvector(vector<int>&v)
{
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
void myprint(int val)
{
    cout<<val<<endl;
}
void test01()
{
    vector<int> v;
    //向容器中插入数据
    v.push_back(10);
    v.push_back(20);v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(30);
    //通过迭代器访问容器中的数据
    vector<int>::iterator itbegin=v.begin();//起始迭代器，容器中的第一个数据
    vector<int>::iterator itend=v.end();//结束迭代器，指向容器中最后一个元素的下一个位置
    //遍历
    //1
    while(itbegin!=itend)
    {
        cout<<*itbegin<<endl;
        itbegin++;
    }
    //2
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    //3
    for_each(v.begin(),v.end(),myprint);
}
void test02()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int> v2(v1.begin(),v1.end());
    printvector(v2);
    vector<int>v3(10,100);
    printvector(v3);
    vector<int>v4(v3);
    printvector(v4);
}
void test03()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int>v2=v1;
    printvector(v2);
    vector<int>v3;
    v3.assign(v1.begin(),v1.end());
    printvector(v3);
    vector<int>v4;
    v4.assign(10,100);
    printvector(v4);
}
void test04()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    if(v1.empty())
    {
        cout<<"为空"<<endl;
    }
    else
    {
        cout<<"不为空"<<endl;
        cout<<v1.capacity()<<endl;
        cout<<v1.size()<<endl;
        v1.resize(15,100);
        printvector(v1);
        v1.resize(5);
        printvector(v1);

    }
}
void test05()
{
    vector<int> v1;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printvector(v1);
    v1.pop_back();
    printvector(v1);
    v1.insert(v1.begin(),100);
    printvector(v1);
    v1.insert(v1.begin(),2,1000);
    printvector(v1);
    v1.erase(v1.begin());
    printvector(v1);
    v1.erase(v1.begin(),v1.end());
    //v1.clear();
    printvector(v1);
}
void test06()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
        //cout<<v1.at(i)<<" ";
    }
    cout<<endl;
    cout<<v1.front()<<endl;
    cout<<v1.back()<<endl;
}
void test07()
{
    vector<int> v1;
    for(int i=0;i<10;i++)
    {
        v1.push_back(i);
    }
    printvector(v1);
    vector<int>v2;
    for(int i=10;i>0;i--)
    {
        v2.push_back(i);
    }
    printvector(v2);
    v1.swap(v2);
    printvector(v1);
    printvector(v2);
}
void test08()
{
    vector<int>v;
    for(int i=0;i<100000;i++)
    {
        v.push_back(i);
    }
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    v.resize(3);
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
    vector<int>(v).swap(v);
    cout<<v.capacity()<<endl;
    cout<<v.size()<<endl;
}
void test09()
{
    vector<int> v;
    v.reserve(10000);
    cout<<v.capacity()<<endl;
}
int main()
{
    test09();
}
