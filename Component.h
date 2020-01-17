//Pagotto Francesco 1195886

#include <iostream>

using namespace std;

class Component{
		
	public:
		class invalidId{}; //id errato
		class invalidDeliveryTime{}; //delivery_time errato
		class invalidPrice{}; //prezzo errato
		
		Component();
		Component(int id,string name,int time,int price); //costruttore
		
		void print(); //stampa componente
		
		int getComponent_id(); //ritorna l'id del componente
		string getComponent_name(); //ritorna il nome del componente
		int getDelivery_time(); //ritorna il tempo di spedizione del componente
		int getComponent_price(); //ritorna il prezzo del componente
		
	private:
		int component_id; //id del componente
		string component_name; //nome del componente
		int delivery_time; //tempo di spedizione
		int component_price; //prezzo del componente
};
