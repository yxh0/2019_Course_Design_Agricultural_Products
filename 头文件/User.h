#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

class User     //用户类
{
protected:
	string ID;            //用户登录ID
	string Password;      //用户密码
	string UserName;      //用户名
	double User_Blance;   //用户钱包
public:
	User();               //不带参数的构造
	User(string _ID, string _Password, string _UserName, double _User_Blance);  //带参数的构造
	User(User& u);        //拷贝构造
	~User() {};           //析构函数
	void Register();      //用户注册
	void Enter();         //用户注册


};

#endif
