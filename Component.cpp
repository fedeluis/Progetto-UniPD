#include "Component.h"

using namespace std;

Component::Component():component_id{-1},component_name{""},delivery_time{-1},component_price{-1}{} //costruttore
Component::Component(int id,string name,int time,int price):component_id{id},component_name{name},delivery_time{time},component_price{price}{} //costruttore

void Component::print(){ //stampa componente
	cout<<"Component "<<component_id<<":\n\n";
	cout<<"\tId: "<<component_id<<"\n";
	cout<<"\tName: "<<component_name<<"\n";
	cout<<"\tDelivery time: "<<delivery_time<<"\n";
	cout<<"\tPrice: "<<component_price<<" euro\n\n";
	
}

int Component::getComponent_id(){return component_id;} //ritorna l'id del componente
string Component::getComponent_name(){return component_name;} //ritorna il nome del componente
int Component::getDelivery_time(){return delivery_time;} //ritorna il tempo di spedizione del componente
int Component::getComponent_price(){return component_price;} //ritorna il prezzo del componente
