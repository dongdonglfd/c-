#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//设计联系人结构体
struct person
{
    string name;
    int sex;
    int age;
    string phone;
    string addr;
};
struct addressbooks
{
    struct person people[MAX];
    int size;
};
//菜单
void showmenu()
{
    cout<<"1,添加联系人"<<endl;
    cout<<"2,显示联系人"<<endl;
    cout<<"3,删除联系人"<<endl;
    cout<<"4,查找联系人"<<endl;
    cout<<"5,修改联系人"<<endl;
    cout<<"6,清空联系人"<<endl;
    cout<<"0,退出通讯录"<<endl;

}
//添加联系人
void addperson(addressbooks * abs)
{
    if(abs->size==MAX)
    {
        cout<<"通讯录已满，无法添加！"<<endl;
        return;
    }
    else
    {
        string name;
        cout<<"请输入姓名"<<endl;
        cin>>name;
        abs->people[abs->size].name=name;
        cout<<"请输入性别"<<endl;
        cout<<"1---男"<<endl;
        cout<<"2---女"<<endl;
        int sex=0;
        while(true)
        {
            cin>>sex;
            if(sex==1||sex==2)
            {
                abs->people[abs->size].sex=sex;
                break;
            }
            cout<<"输入有误"<<endl;
        }
        cout<<"请输入年龄"<<endl;
        int age=0;
        cin>>age;
        abs->people[abs->size].age=age;
        cout<<"请输入联系电话"<<endl;
        string phone;
        cin>>phone;
        abs->people[abs->size].phone=phone;
        cout<<"请输入家庭住址"<<endl;
        string address;
        cin>>address;
        abs->people[abs->size].addr=address;
        abs->size++;
        cout<<"添加成功"<<endl;
        // system("pause");//请按任意键继续
        // system("cls");//清屏

    }
}
//显示联系人
void showperson(addressbooks * abs)
{
    if(abs->size==0)
    {
        cout<<"当前记录为空"<<endl;
    }
    else
    {
        for(int i=0;i<abs->size;i++)
        {
            cout<<"姓名： "<<abs->people[i].name<<"\t";
            cout<<"性别： "<<(abs->people[i].sex==1?"男":"女")<<"\t";
            cout<<"年龄： "<<abs->people[i].age<<"\t";
            cout<<"电话： "<<abs->people[i].phone<<"\t";
            cout<<"住址： "<<abs->people[i].addr<<endl;
        }

    }
    // system("pause");//请按任意键继续
    // system("cls");//清屏
}
int main()
{
    addressbooks abs;
    abs.size=0;
    int select=0;
    while(true)
    {   showmenu();
        cin>>select;
        switch(select)
        {
            case 1://1,添加联系人
                addperson(&abs);
                break;
            case 2://2,显示联系人
                showperson(&abs);
                break;
            case 3://3,删除联系人
                
                break;
            case 4://4,查找联系人
                break;
            case 5://5,修改联系人
                break;
            case 6://6,清空联系人
                break;
            case 0://0,退出通讯录
                cout<<"欢迎下次使用"<<endl;
                // system("pause");
                return 0;
                break;
    }
    }
    // system("pause");
    return 0;
}