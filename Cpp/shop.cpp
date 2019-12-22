#include "shop.h"
using namespace std;

SHOP::SHOP() {
	cipher = "123456";
	keep_name = shop_name = ads = phonenum = college = "";
	sale_vol = shop_credit = 0;
	order_num = cnum = gnum = 0;
}

SHOP::SHOP(bool flag) {
	cipher = "123456";
	string cip, _cip;

	cout << "Register your shop." << endl;
	cout << "Shop name: ";
	cin >> shop_name;
	cout << "Your name: ";
	cin >> keep_name;
	cout << "Set your nickname: ";
	cin >> college;
	cout << "Phone number: ";
	cin >> phonenum;
	cout << "Set your cipher: ";
	cin >> cip;
	cout << "Confirm your cipher: ";
	cin >> _cip;

	if (cip != _cip) {
		cout << "Inconsistent" << endl;
		do {
			cout << "Set your cipher: ";
			cin >> cip;
			cout << "Confirm your cipher: ";
			cin >> _cip;
		} while (cip != _cip);
	}

	cipher = cip;
	order_num = cnum = gnum = 0;
	sale_vol = shop_credit = 0;

}

SHOP::SHOP(const SHOP& s) {
	cipher = s.cipher;
	keep_name = s.keep_name;


	g_list = s.g_list;

	complaint_list = s.complaint_list;
	order_list = s.order_list;
	order_num = s.order_num;
	cnum = s.cnum;
	gnum = s.gnum;

	shop_name = s.shop_name;
	sale_vol = s.sale_vol;
	shop_credit = s.shop_credit;
	ads = s.ads;
	phonenum = s.phonenum;
	college = s.college;
}

SHOP::~SHOP() {
	;
}

/*ostream& operator<<(ostream& os, SHOP& shop)
{

	os << shop.shop_name << endl;
	os << "shop keeper: " << shop.college << endl;
	os << "sale volume: " << shop.sale_vol << endl;
	os << "credit: " << shop.shop_credit << endl;
	os << "address: " << shop.ads << endl;
	os << "shop keeper phone number: " << shop.phonenum << endl;

	return os;
}*/

void SHOP::searchItem() {
	string iname;
	int cnt = 0;
	cout << "what do you want to buy: ";
	cin >> iname;

	multimap<string, GOODS>::iterator it;
	for (it = g_list.begin(); it != g_list.end(); it++)
		if (it->second.Getname() == iname) {
			cnt++;
			cout << "Item name: " << it->second.Getname() << endl;
			cout << "Price: " << it->second.Getprice() << endl;
			cout << "Sale Volume: " << it->second.Getsales() << endl;
			cout << "Surplus: " << it->second.Getsurplus();
		}


	if (cnt == 0)
		cout << "no item found." << endl;

}

void SHOP::saleItem(string iname) {
	order_num++;
	struct order tmp;
	tmp.num = order_num;
	tmp.iname = iname;
	tmp.status = false;
	order_list.push_back(tmp);
}

void SHOP::deleteItem(string iname) {
	multimap<string, GOODS>::iterator it;
	for (it = g_list.begin(); it != g_list.end(); it++)
		if (it->second.Getname() == iname) {
			g_list.erase(it);
			break;
		}

	if (it == g_list.end())
		cout << "no item found." << endl;
}

void SHOP::setInfo() {
	cout << "Register your shop." << endl;
	cout << "Shop name: ";
	cin >> shop_name;
	cout << "Your name: ";
	cin >> keep_name;
	cout << "Set your nickname: ";
	cin >> college;
	cout << "Phone number: ";
	cin >> phonenum;
}

void SHOP::setCipher() {
	int cnt = 0;
	string cip, _cip;
	cout << "enter your previous password: ";
	cin >> cip;
	cnt++;

	if (cip != cipher) {
		while (cip != cipher && cnt < 3) {
			cout << "enter your previous password: ";
			cin >> cip;
			cnt++;
		}
		cout << "修改成功" << endl;
	}

	if (cnt >= 3)
		return;

	cout << "Set your cipher: ";
	cin >> cip;
	cout << "Confirm your cipher: ";
	cin >> _cip;

	if (cip != _cip) {
		cout << "Inconsistent" << endl;
		do {
			cout << "Set your cipher: ";
			cin >> cip;
			cout << "Confirm your cipher: ";
			cin >> _cip;
		} while (cip != _cip);
	}

	cipher = cip;
}

int SHOP::numOfGoods() {
	return g_list.size();
}

int SHOP::showSaleVol() {
	return sale_vol;
}

int SHOP::showCredit() {
	return shop_credit;
}

string SHOP::getAds() {
	return ads;
}

string SHOP::getNick() {
	return college;
}

int SHOP::showComplainNum() {
	return complaint_list.size();
}


void SHOP::showAllItems() {
	multimap<string, GOODS>::iterator it;
	for (it = g_list.begin(); it != g_list.end(); it++) {
		cout << it->second << endl;
	}
}

bool SHOP::checkPassword() const {
	string cip;
	cout << "Please enter the password: ";
	cin >> cip;
	if (cip == this->cipher)
		return true;
	return false;
}

void SHOP::addItem() {
	string iname;
	double price;
	int surplus;

	cout << "Enter item's name: ";
	cin >> iname;
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the surplus of item: ";
	cin >> surplus;

	GOODS g(iname, price, 0, surplus);
	g_list.insert(pair<string, GOODS>(g.Getname(), g));
}
