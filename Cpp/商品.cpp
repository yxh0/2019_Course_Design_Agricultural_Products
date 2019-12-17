#include "goods.h"

GOODS::GOODS()//goods不带参数构造
{
	name = "";
	price = sales = surplus = -1;
	discusssum = 0;
}

GOODS::GOODS(char* na, double pri, int sale, int sur)//goods带参数构造
{
	name = na;
	price = pri;
	sales = sale;
	surplus = sur;
}

GOODS::GOODS(GOODS& l)//goods拷贝构造
{
	name = l.name;
	price = l.price;
	sales = l.sales;
	surplus = l.surplus;
}

void GOODS::diplaygoods()
{
	cout<<"名称: "<<name<<", 价格: "<<price<<", 销售量: "<<sales<<", 剩余量: "<<surplus<<endl;
}

void GOODS::Insert(char* na, double pri, int sale, int sur)//输入商品信息
{
	name = na;
	price = pri;
	sales = sale;
	surplus = sur;
}

void GOODS::Changename(char* na)//更改名称
{name = na;}

void GOODS::Changeprice(double pri)//更改价格
{price = pri;}

void GOODS::Changesales(int sale)//更改销售量
{sales = sale;}

void GOODS::Changesurplus(int sur)//更改剩余量
{surplus = sur;}

string GOODS::Getname()//提取名称
{return name;}

double GOODS::Getprice()//提取价格
{return price;}

int GOODS::Getsales()//提取销售量
{return sales;}

int GOODS::Getsurplus()//提取剩余量
{return surplus;}

void GOODS::Insertdiscuss(char* dis)//写入评论char*
{
	discuss.push_back(dis);
	++discusssum;
}

void GOODS::Insertdiscuss(string dis)//写入评论string
{
	discuss.push_back(dis);
	++discusssum;
}

void GOODS::displaydiscuss()//打印评论
{
	for (int i = 0;i < discusssum;++i)
		cout<<discuss[i]<<endl;
}
/////////////////////////////////////////////////////

void main()
{
//	goods a("大面筋", 4.5, 2, 200);
//	a.diplaygoods();

	Meat b;
	b.Insert("羊肉", 23.75, 56, 20);
	b.diplaygoods();
	b.Changename("猪肉");
	b.Changeprice(10.25);
	b.Changesales(15);
	b.Changesurplus(99);
	b.diplaygoods();
	cout<<b.Getname()<<endl;
	cout<<b.Getprice()<<endl;
	cout<<b.Getsales()<<endl;
	cout<<b.Getsurplus()<<endl;
	b.Insertdiscuss("很好");
	b.Insertdiscuss("一般");
	b.Insertdiscuss("很差，不建议购买");
	b.displaydiscuss();
}
