//Pagotto Francesco 1195886

#include <fstream>
#include "Component.h"

Component::Component():component_id{-1},component_name{""},delivery_time{-1},component_price1{-1},component_price2{-1},component_price3{-1}{} //costruttori

Component::Component(int id){
	if(id<0 || id>9) throw Component::invalidId();

	string reader;
	ifstream file{"files/components_info.dat"}; //apro il file
	
	if(!file) throw Component::invalidId(); //file valido?
	
	getline(file,reader);
	
	file>>reader;
	component_id=stoi(reader); //leggo l'id
	
	while(component_id!=id && file){
		getline(file,reader); //passo alla riga successiva e leggo l'id finche non trovo quello richiesto
		file>>reader;
		component_id=stoi(reader); 
	}
		
	if(!file) throw Component::invalidId();
	
	//leggo i dati del componente
	file>>component_name;
	
	file>>reader;
	delivery_time=stoi(reader);
	
	file>>reader;
	component_price1=stod(reader);
	
	file>>reader;
	component_price2=stod(reader);
	
	file>>reader;
	component_price3=stod(reader);
	
	file.close();
}

Component::Component(int id,string name,int time,double price1,double price2,double price3):component_id{id},component_name{name},delivery_time{time},component_price1{price1},component_price2{price2},component_price3{price3}{}

void Component::print(){ //stampa componente
	cout<<"Component "<<component_id<<":\n\n";
	cout<<"\tId: "<<component_id<<"\n";
	cout<<"\tName: "<<component_name<<"\n";
	cout<<"\tDelivery time: "<<delivery_time<<"\n";
	cout<<"\tPrice 1: "<<component_price1<<" euro\n";
	cout<<"\tPrice 2: "<<component_price2<<" euro\n";
	cout<<"\tPrice 3: "<<component_price3<<" euro\n\n";

}

int Component::getComponent_id(){return component_id;} //ritorna l'id del componente
string Component::getComponent_name(){return component_name;} //ritorna il nome del componente
int Component::getDelivery_time(){return delivery_time;} //ritorna il tempo di spedizione del componente
double Component::getComponent_price1(){return component_price1;} //ritorna il prezzo1 del componente 1-10
double Component::getComponent_price2(){return component_price2;} //ritorna il prezzo2 del componente 11-50
double Component::getComponent_price3(){return component_price3;} //ritorna il prezzo3 del componente 51+
