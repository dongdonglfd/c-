#include<iostream>
using namespace std;
class abstractdrinking
{
    public:
    virtual void boil()=0;
    virtual void brew()=0;
    void makedrink()
    {
        boil();
        brew();
    }
};
class coffee: public abstractdrinking
{
    public:
    virtual void boil()
    {
        cout<<"1"<<endl;
    }
    virtual void brew()
    {
        cout<<"2"<<endl;
    }
};
void work(abstractdrinking *abs)
{
    abs->makedrink();
    delete abs;
}
void test01()
{
    work(new coffee);
}
int main()
{
    test01();

}