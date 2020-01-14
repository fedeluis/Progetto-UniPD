//Pagotto Francesco 1195886

#include <iostream>
#include <fstream>
#include "Component.cpp"

using namespace std;

Component getComponent(int cId){
	int id,delivery,price;
	string name,reader;
	
	ifstream file{"components_info.dat"}; //apro il file
	id=file.get()-48; //leggo l'id della prima riga
	
	while(id!=cId){
		getline(file,reader); //passo alla riga successiva e leggo l'id finche non trovo quello richiesto
		id=file.get()-48;
	}
	
	file>>name;
	file>>reader;
	delivery=stoi(reader);
	file>>reader;
	price=stoi(reader);
	file.close();
	
	return Component{id,name,delivery,price};
}

int main(){
	getComponent(2).print();
	getComponent(6).print();
	return 0;
}
