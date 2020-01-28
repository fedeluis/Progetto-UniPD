//Pagotto Francesco 1195886

#include "Money.h"

int main(){
	Money m{5000};
	cout<<m.getMoney();
	Component c{3};
	m.buyComponent(c,13);
	cout<<m.getMoney();
	return 0;
}
