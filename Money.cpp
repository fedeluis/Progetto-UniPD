//Pagotto Francesco 1195886

#include "Money.h"

using namespace std;

Money::Money():money{0}{}
Money::Money(double m):money{m}{}

double Money::getMoney(){return money;}

bool Money::buyComponent(Component c,int quantity){
	if(quantity<1) throw invalidQuantity();
	double price,totPrice;
	
	if(quantity<11) price=c.getComponent_price1();
	else if(quantity<51) price=c.getComponent_price2();
	else price=c.getComponent_price3();
	
	totPrice=price*quantity;
	
	if(totPrice>money) throw notEnoughMoney();
	
	money-=totPrice;
	
	return true;
}

bool Money::sellModel(Model m,int quantity){
	if(quantity<1) throw invalidQuantity();
	
	money+=m.get_m_price()*quantity;
	
	return true;
}
