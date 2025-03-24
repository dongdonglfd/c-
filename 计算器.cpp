#include<iostream>
using namespace std;
class abstractcalculator
{
    public:
    virtual int getresult()
    {
        return 0;
    }
    int num1;
    int num2;
        
    
};
class addcalculator:public abstractcalculator
{
    public:
    int getresult()
    {
        return num1+num2;
    }
};
void test01()
{
    abstractcalculator *abc=new addcalculator;
    abc->num1=100;
    abc->num2=100;
    cout<<abc->getresult()<<endl;
    delete abc;
}

int main()
{
    test01();
}