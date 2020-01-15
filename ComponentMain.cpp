//Pagotto Francesco 1195886

#include <iostream>
#include <fstream>
#include "Component.cpp"

using namespace std;

Component readComponent(int cId){
	if(cId<0) throw Component::invalidId();

	int id,delivery,price;
	string name,reader;

	ifstream file{"files/components_info.dat"}; //apro il file
	
	if(!file) throw Component::invalidId(); //file valido?
	
	getline(file,reader);
	
	file>>reader;
	id=reader.at(1)-48; //leggo l'id
	while(id!=cId && file){
		getline(file,reader); //passo alla riga successiva e leggo l'id finche non trovo quello richiesto
		file>>reader;
		id=reader.at(1)-48; 
	}
		
	if(!file) throw Component::invalidId();
	
	//leggo i dati del componente
	file>>reader;
	name=reader.substr(1,reader.size()-2);
	file>>reader;
	delivery=stoi(reader.substr(1,reader.size()-2));
	file>>reader;
	price=stoi(reader.substr(1,reader.size()-2));
	file.close();

	return Component{id,name,delivery,price};
}

void readAll(){
	string s;
	ifstream f{"files/components_info.dat"};
	while(f){
		getline(f,s);
		cout<<s;
	}
}

int main(){
	Component c=readComponent(8);
	c.print();
	return 0;
}
