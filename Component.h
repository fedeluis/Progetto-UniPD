//Pagotto Francesco 1195886

#include <iostream>

using namespace std;

class Component{
	public:
		class invalidId{}; //id errato
		
		Component(); //costruttore
		Component(int); //costruttore
		
		int getComponent_id(); //ritorna l'id del componente
		string getComponent_name(); //ritorna il nome del componente
		int getDelivery_time(); //ritorna il tempo di spedizione del componente
		double getComponent_price1(); //ritorna il prezzo1 del componente 1-10
		double getComponent_price2(); //ritorna il prezzo2 del componente 11-50
		double getComponent_price3(); //ritorna il prezzo3 del componente 51+
		
		void print(); //stampa componente
		
	private:
		int component_id; //id del componente
		string component_name; //nome del componente
		int delivery_time; //tempo di spedizione
		double component_price1; //prezzo1 del componente 1-10
		double component_price2; //prezzo2 del componente 11-50
		double component_price3; //prezzo3 del componente 51+
};
