#include "User.h"
#include<iostream>
#include <string>
#include <fstream>
#include <vector>
#include "goods.h"
using namespace std;

User::User()            //不带参数构造
{
    ID = "N/A";         //不存在ID
    Password = "N/A";   //不存在密码
    UserName = "N/A";   //不存在用户名
}
User::User(string _ID, string _Password, string _UserName)  //带参数的构造
{
    ID = _ID;
    Password = _Password;
    UserName = _UserName;
}
User::User(const User& u) //拷贝构造
{
    ID = u.ID;
    Password = u.Password;
    UserName = u.UserName;
}
void User::Register()  //用户注册
{
    ofstream outFile;  //写入文件预备
    outFile.open("web1.txt", ios_base::out | ios_base::app);
    if (!outFile.is_open())                                //要是文件打不开
    {
        cout << "对不起，未连接服务器" << endl;
        cout << "程序正在退出... ... ... ... ... ..." << endl;
        cin.get();
        exit(EXIT_FAILURE);
    }
    string name, code;                 //
    cin.get();        //吃空字符
    getline(cin, name);
    outFile << name << endl;           //姓名写入文本
    cout << "请输入密码" << endl;
    getline(cin, code);
    outFile << code << endl;          //密码写入文本
    cout << "注册成功";
    outFile.close();
}

bool User::Login()      //登录
{
    {
        cin.get();
        ifstream inFile;//定义ifstream对象
        inFile.open("web1.txt");//读取web1.txt文件中的注册资料
        if (!inFile.is_open())//如果文件没有成功打开
        {
            cout << "很遗憾，连接不上服务器";
            exit(EXIT_FAILURE);
        }
        string name;
        string code;
        string temp;

        cout << "请输入用户名名称: ";
        getline(cin, name);

        while (getline(inFile, temp))//匹配用户名
        {
            if (temp == name)//如果匹配用户名成功
            {
                cout << "请输入密码: ";//请输入密码
                getline(cin, code);//code
                getline(inFile, temp);//匹配code
                if (temp == code)//如果密码正确，登录成功
                {
                    cout << "登录成功";
                    return true;
                }
                else
                {
                    cout << "密码错误";
                    return false;
                }
            }
        }
    }
}

void Search(User& s, string goods)
{
    map<string, GOODS>::iterator it;
    it = s.good.lower_bound(goods);
    if (it->first == goods)
    {
        cout << it->second << endl;
        it->second.displaydiscuss();
    }

    else
    {
        cout << "can't find" << endl;
    }


}

string User::get_name() {
    return UserName;
}

string User::getId() {
    return ID;
}

void User::addAdd() {
    string add;
    cout << "set your address: ";
    cin >> add;

    Address = add;
}


bool User::checkPassword() {
    string cip;
    cout << "enter your password: ";
    cin >> cip;
    if (cip == Password)
        return true;
    else
        return false;
}
