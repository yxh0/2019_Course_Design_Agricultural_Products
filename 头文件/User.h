#pragma once
#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <map>
#include "goods.h"
using namespace std;

class User     //用户类
{
protected:
	string ID;            //用户登录ID
	string Password;      //用户密码
	string UserName;      //用户名
	string Address;       //用户地址
	map<string, GOODS> good;
public:
	User();               //不带参数的构造
	User(string _ID, string _Password, string _UserName);  //带参数的构造
	User(const User& u);        //拷贝构造
	~User() {};           //析构函数
	void Register();      //用户注册
	bool Login();         //用户登录
	friend void Search(User& s, string goods);
	string getId();
	void addAdd();
	string get_name();
	bool checkPassword();
};



#endif
