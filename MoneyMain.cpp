#include "Money.cpp"

int main(){
	Money m{5000};
	cout<<m.getMoney();
	m.buyComponent(2,13);
	cout<<m.getMoney();
	m.sellModel(3,5);
	cout<<m.getMoney();
	return 0;
}
