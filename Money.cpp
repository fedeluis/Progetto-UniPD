//Pagotto Fr ancesco 1195886

#include "Money.h"
#include "Component.cpp"
#include "Model.h"

using namespace std;

Money::Money():money{0}{}
Money::Money(double m):money{m}{}

double Money::getMoney(){return money;}

bool Money::buyComponent(int id,int quantity){
	if(id<0) throw Component::invalidId();
	if(quantity<1) throw invalidQuantity();
	
	Component c{id};
	double price,totPrice;
	
	if(quantity<11) price=c.getComponent_price1();
	else if(quantity<51) price=c.getComponent_price2();
	else price=c.getComponent_price3();
	
	totPrice=price*quantity;
	
	if(totPrice>money) throw notEnoughMoney();
	
	money-=totPrice;
	
	return true;
}

bool Money::sellModel(int id,int quantity){
	if(id<0) throw Model::invalid_id();
	if(quantity<1) throw invalidQuantity();
	
	//money+=Model{id}.getPrice()*quantity;
	
	return true;
}
