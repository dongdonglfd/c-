#include<iostream>
using namespace std;
int main()
{
    int *p=new int(10);
    delete p;
    int *s=new int [10];
    delete [] s;     

}