#ifndef UI_H
#define UI_H

#include "shop.h"
#include "goods.h"
#include "User.h"
#include <windows.h>
#include <map>


class MAINCLASS {
protected:
	SHOP* shops;
	vector<User> users;
	vector<User>::iterator uit;
public:
	MAINCLASS();
	void shopLogin();		//登录
	void Register();		//用户注册
	void shopOperator();	//商店操作
	void userLogin();
	void userOperator();
	void mainOperator();

	int shop_getOp();
	int user_getOp();
	int main_getOp();
	void main_ui();
	void shop_ui();
	void user_ui();

};






#endif
