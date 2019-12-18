#ifndef SHOP_H
#define SHOP_H

#include <iostream>
#include <vector>
#include <string>
#include "goods.h"

struct complaint{
	string reason;		//理由
	string iname;		//物品名称
};

struct order{
	int num;		//订单号
	string iname;
	bool status;
};

class SHOP{
private:
	string cipher;		//密码
	string keep_name;					//店主名
protected:
	vector<Meat> meat_list;		//商品列表meat
	vector<Fish> fish_list;		//商品列表fish
	vector<Vegetable> veg_list;	//商品列表vegetable

	int order_num;

	vector<complaint> complaint_list;		//投诉列表
	vector<order> order_list;		//订单列表

	string shop_name;					//商店名称
	int sale_vol;						//销量
	int shop_credit;					//信用
	string ads;							//地址
	string phonenum;					//店主电话
	string nickname;					//昵称

public:
	SHOP();
	SHOP(bool);
	SHOP(const SHOP& s);
	~SHOP();
	
	friend ostream& operator<<(ostream& os, SHOP shop);	//输出商店信息
	void searchItem();		//搜索物品
	void saleItem(string iname);		//卖出物品
	void deleteItem(string iname);		//删除物品
	void setInfo();			//设置店铺信息
	void setCipher();		//修改密码
	int numOfGoods();		//统计商品个数
	int showSaleVol();		//获取销量
	int showCredit();		//获取信用
	string getAds();		//获取地址
	string getNick();		//获取店主昵称

};




#endif
