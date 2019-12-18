#include "shop.h"
#include <windows.h>
using namespace std;

SHOP::SHOP(){
	cipher = "123456";
	keep_name = shop_name = ads = phonenum = nickname = "";
	sale_vol = shop_credit = 0;
}

SHOP::SHOP(bool flag){
	cipher = "123456";
	string cip, _cip;

	cout << "Register your shop." << endl;
	cout << "Shop name: " ;
	cin >> shop_name;
	cout << "Your name: ";
	cin >> keep_name;
	cout << "Set your nickname: ";
	cin >> nickname;
	cout << "Phone number: ";
	cin >> phonenum;
	cout << "Set your cipher: ";
	cin >> cip;
	cout << "Confirm your cipher: ";
	cin >> _cip;

	if(cip != _cip){
		cout << "Inconsistent" << endl;
		do{
			cout << "Set your cipher: ";
			cin >> cip;
			cout << "Confirm your cipher: ";
			cin >> _cip;
		}
		while(cip != _cip);
	}

	cipher = cip;

}

SHOP::SHOP(const SHOP& s){
	cipher = s.cipher;
	keep_name = s.keep_name;


	meat_list = s.meat_list;
	fish_list = s.fish_list;
	veg_list = s.veg_list;

	complaint_list = s.complaint_list;
	order_list = s.order_list;

	shop_name = s.shop_name;
	sale_vol = s.sale_vol;
	shop_credit = s.shop_credit;
	ads = s.ads;
	phonenum = s.phonenum;
	nickname = s.nickname;
}

SHOP::~SHOP(){
	;
}

ostream& operator<<(ostream& os, SHOP shop){

	os << shop.shop_name << endl;
	os << "shop keeper: " << shop.nickname << endl;
	os << "sale volume: " << shop.sale_vol << endl;
	os << "credit: " << shop.shop_credit << endl;
	os << "address: " << shop.ads << endl;
	os << "shop keeper phone number: " << shop.phonenum << endl;
	
	return os;
}

/*void SHOP::searchItem(){
	string iname;
	int cnt = 0;
	cout << "what do you want to buy: ";
	cin >> iname;

	vector<GOODS>::iterator it;
	for(it = g_list.begin(); it != g_list.end(); it++)
		if(it->Getname() == iname){
			cnt++;
			cout << "Item name: " << it->Getname() << endl;
			cout << "Price: " << it->Getprice() << endl;
			cout << "Sale Volume: " << it->Getsales() << endl;
			cout << "Surplus: " << it->Getsurplus();
		}


	if(cnt == 0)
		cout << "no item found." << endl;

}*/

void SHOP::saleItem(string iname){
	order_num++;
	struct order tmp;
	tmp.num = order_num;
	tmp.iname = iname;
	tmp.status = false;
	order_list.push_back(tmp);
}

/*void SHOP::deleteItem(string iname){
	vector<GOODS>::iterator it;
	for(it = g_list.begin(); it != g_list.end(); it++)
		if(it->Getname() == iname){
			g_list.erase(it);
			break;
		}

	if(it == g_list.end())
		cout << "no item found." << endl;
}*/

void SHOP::setInfo(){
	cout << "Register your shop." << endl;
	cout << "Shop name: " ;
	cin >> shop_name;
	cout << "Your name: ";
	cin >> keep_name;
	cout << "Set your nickname: ";
	cin >> nickname;
	cout << "Phone number: ";
	cin >> phonenum;
}

void SHOP::setCipher(){
	int cnt = 0;
	string cip, _cip;
	cout << "enter your previous password: ";
	cin >> cip;
	cnt++;

	if(cip != cipher){
		while(cip != cipher && cnt < 3){
			cout << "enter your previous password: ";
			cin >> cip;
			cnt++;
		}
	}

	if(cnt >= 3)
		return;

	cout << "Set your cipher: ";
	cin >> cip;
	cout << "Confirm your cipher: ";
	cin >> _cip;

	if(cip != _cip){
		cout << "Inconsistent" << endl;
		do{
			cout << "Set your cipher: ";
			cin >> cip;
			cout << "Confirm your cipher: ";
			cin >> _cip;
		}
		while(cip != _cip);
	}

	cipher = cip;
}
