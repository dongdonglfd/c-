#include<iostream>
#include<fstream>
using namespace std;
void test01()
{
    ofstream ofs;
    ofs.open("test.txt",ios::out);
    ofs<<"1"<<endl;
    ofs.close();
}
void test02()
{
    ifstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return ;
    }
    //1
    // char buf[1024]={0};
    // while(ifs>>buf)
    // {
    //     cout<<buf<<endl;
    // }
    //2
    // char buf[1024]={0};
    // while(ifs.getline(buf,sizeof(buf)))
    // {
    //     cout<<buf<<endl;

    // }
    //3
    // string buf;
    // while(getline(ifs,buf))
    // {
    //     cout<<buf<<endl;
    // }
    //4
    char c;
    while((c=ifs.get())!=EOF)
    {
        cout<<c;
    }
    ifs.close();


}
int main()
{
    // test01();
    test02();

}