#ifndef GOODS_H
#define GOODS_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class GOODS
{
protected:
	string name;//商品名称
	double price;//价格
	int sales;//销售量
	int surplus;//剩余量
	vector<string> discuss;//评论
	int discusssum;//评论个数

public:
	GOODS();//goods不带参数构造
	GOODS(char* na, double pri, int sale, int sur);//goods带参数构造
	GOODS(GOODS& l);//goods拷贝构造
	~GOODS(){};
	void diplaygoods();
	void Insert(char* na, double pri, int sale, int sur);//输入商品信息
	void Changename(char* na);//更改名称
	void Changeprice(double pri);//更改价格
	void Changesales(int sale);//更改销售量
	void Changesurplus(int sur);//更改剩余量
	string Getname();//提取名称
	double Getprice();//提取价格
	int Getsales();//提取销售量
	int Getsurplus();//提取剩余量
	void Insertdiscuss(char* dis);//写入评论char*
	void Insertdiscuss(string dis);//写入评论string
	void displaydiscuss();//打印评论
};

class Meat:public GOODS//肉类
{};

class Fish:public GOODS//鱼类
{};

class Vegetable:public GOODS//蔬菜类
{};

#endif
