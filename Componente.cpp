#include "Componente.h"

Componente::Componente(int id,std::string name,int time/*,double price*/):component_id{id},component_name{name},delivery_time{time}/*,component_price{price}*/{} //costruttore

void Componente::print(){std::cout<<"["<<component_id<<"] ["<<component_name<<"] ["<<delivery_time/*<<"] ["<<component_price*/<<"]\n";} //stampa componente

int Componente::getComponent_id(){return component_id;} //ritorna l'id del componente
std::string Componente::getComponent_name(){return component_name;} //ritorna il nome del componente
int Componente::getDelivery_time(){return delivery_time;} //ritorna il tempo di spedizione del componente
//double Componente::getComponent_price(){return component_price;} //ritorna il prezzo del componente
