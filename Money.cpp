//Pagotto Francesco 1195886

#include <fstream>
#include "Money.h"
#include "Component.h"
#include "Model.h"

using namespace std;

Money::Money():money{0}{}
Money::Money(double m):money{m}{}

int Money::getMoney(){return money;}

void Money::buyComponent(int id,int quantity){
	
}

void Money::sellModel(int id,int quantity){
	
}
