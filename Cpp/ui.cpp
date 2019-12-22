#include "ui.h"
using namespace std;

MAINCLASS::MAINCLASS() {
	shops = new SHOP(true);
}

void MAINCLASS::Register() {
	string nickname;
	string pass;
	string name;
	User* u;

	cout << "set your nickname: ";
	cin >> nickname;
	cout << "set your password: ";
	cin >> pass;
	cout << "set your name: ";
	cin >> name;

	u = new User(nickname, pass, name);
	users.push_back(*u);
	cout << "用户注册成功" << endl;
	system("pause");

}
/******************************user*********************************/
void MAINCLASS::userLogin() {
	int cnt = 0;
	string cip;
	string name;

	cout << "your nickname: ";
	cin >> name;
	for (uit = users.begin(); uit != users.end(); uit++)
		if (uit->get_name() == name)
			break;
	while (cnt < 3) {
		cnt++;
		if (uit->checkPassword() == true) {
			break;
		}
	}
	if (cnt >= 3)
		return;
	else {
		cout << "login succellful." << endl;
		Sleep(500);
		userOperator();
	}
}

int MAINCLASS::user_getOp() {
	int tmp;
	cin >> tmp;
	while (tmp < 0 || tmp > 10) {
		cout << "wrong selection." << endl;
		cin >> tmp;
	}


	return tmp;
}

void MAINCLASS::userOperator() {
	int op;

	while (true)
	{
		system("cls");
		user_ui();
		cout << "enter the operation: ";
		cin >> op;
		switch (op) {
		case 0:
			return;
		case 1:
			shops->searchItem();
			break;
		}
	}
}

void MAINCLASS::user_ui() {
	//	cout << "0. exit" << endl;
	//	cout << "1.search item" << endl;
	cout << "╔══════════════════════════════════╗" << endl;
	cout << "║         用户选项                 ║" << endl;
	cout << "╠══════════════════════════════════╣" << endl;
	cout << "║       1.搜索商品                 ║" << endl;
	cout << "║       0.退出                     ║" << endl;
	cout << "║                                  ║" << endl;
	cout << "╚══════════════════════════════════╝" << endl;

}
/******************************shop*********************************/
void MAINCLASS::shopLogin() {
	int cnt = 0;
	string cip;

	while (cnt < 3) {
		if (shops->checkPassword() == true)
			break;
		cnt++;
	}
	if (cnt >= 3)
		return;
	else {
		cout << "login succellful." << endl;
		Sleep(500);
		shopOperator();
	}
}

void MAINCLASS::shopOperator() {
	int op;

	while (true)
	{
		system("cls");
		shop_ui();
		cout << "enter the operation: ";
		op = shop_getOp();
		switch (op) {
		case 0:			//返回
			return;
		case 1:
			shops->setCipher();
			system("pause");
			break;
		case 2:
			shops->addItem();
			system("pause");
			break;
		case 3:
			cout << shops->numOfGoods() << endl;
			system("pause");
			break;
		case 4:
			cout << *shops;
			system("pause");
			break;
		case 5:
			shops->searchItem();
			system("pause");
			break;
		default:
			break;
		}
	}
}

int MAINCLASS::shop_getOp() {
	int tmp;
	cin >> tmp;
	while (tmp < 0 || tmp > 10) {
		cout << "wrong selection." << endl;
		cin >> tmp;
	}


	return tmp;
}

void MAINCLASS::shop_ui() {
	/*	cout << "0. exit" << endl;
		cout << "1.add item" << endl;
		cout << "2.num of goods" << endl;
		cout << "3.show info" << endl;
		cout << "4. search item" << endl;*/
	cout << "╔══════════════════════════════════╗" << endl;
	cout << "║         用户选项                 ║" << endl;
	cout << "╠══════════════════════════════════╣" << endl;
	cout << "║       1.修改密码                 ║" << endl;
	cout << "║       2.增加商品                 ║" << endl;
	cout << "║       3.商品个数                 ║" << endl;
	cout << "║       4.打印商品信息             ║" << endl;
	cout << "║       5.搜索商品                 ║" << endl;
	cout << "║       0.退出                     ║" << endl;
	cout << "║                                  ║" << endl;
	cout << "╚══════════════════════════════════╝" << endl;

}
/******************************main*********************************/
void MAINCLASS::main_ui() {
	/*	cout << "0. exit" << endl;
		cout << "1.user login" << endl;
		cout << "2.shop login" << endl;
		cout << "3.user register" << endl;*/
	cout << "╔══════════════════════════════════╗" << endl;
	cout << "║       欢迎使用浙农小宝           ║" << endl;
	cout << "╠══════════════════════════════════╣" << endl;
	cout << "║       1.用户登录                 ║" << endl;
	cout << "║       2.店铺登录                 ║" << endl;
	cout << "║       3.用户注册                 ║" << endl;
	cout << "║       0.退出                     ║" << endl;
	cout << "║                                  ║" << endl;
	cout << "╚══════════════════════════════════╝" << endl;
}

int MAINCLASS::main_getOp() {
	int tmp;
	cin >> tmp;
	while (tmp < 0 || tmp > 3) {
		cout << "wrong selection." << endl;
		cin >> tmp;
	}

	return tmp;
}

void MAINCLASS::mainOperator() {
	int op;

	while (true)
	{
		system("cls");
		main_ui();
		cout << "enter the operation: ";
		op = shop_getOp();
		switch (op) {
		case 0:
			cout << "谢谢使用，再见！" << endl;
			return;
		case 1:
			userLogin();
			break;
		case 2:
			shopLogin();
			break;
		case 3:
			Register();
			break;
		default:
			break;
		}
	}
}
