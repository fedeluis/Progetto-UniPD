#include <iostream>

class Componente{
	private:
		int component_id; //id del componente
		std::string component_name; //nome del componente
		int delivery_time; //tempo di spedizione
		//double component_price; //prezzo del componente
		
	public:
		Componente(int id,std::string name,int time/*,double price*/); //costruttore
		
		void print(); //stampa componente
		
		int getComponent_id(); //ritorna l'id del componente
		std::string getComponent_name(); //ritorna il nome del componente
		int getDelivery_time(); //ritorna il tempo di spedizione del componente
		//double getComponent_price(); //ritorna il prezzo del componente
};
