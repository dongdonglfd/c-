#include<iostream>
#include<algorithm>
int main()
{
    std::string a="hello";
    std::transform(a.begin(),a.end(),a.begin(),::toupper);
    std::cout<<a<<std::endl;
}