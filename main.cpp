//Alessandro Leonardi 1188704
#include <iostream>
#include <vector>
#include <fstream>
#include "System.h"
#include "Money.h"
#include "Orders.h"
#include "Model.h"
#include "Component.h"
using namespace std;

//soldi che abbiamo all'inizio
extern double init_money;

//funzione che legge i componenti
list<Component> scan_comp_file()
{
	list<Component> output; //contiene tutti i componenti

	/**
	 * lettura file
	 */
	string reader;
	ifstream file{"files/components_info.dat"}; //apre file components_info.dat

	if (!file)
		throw Component::invalidFile();

	//legge ogni riga e la salva
	do
	{
		int id, del_time;
		double cp1, cp2, cp3;
		string name;

		//id
		file >> reader;
		id = stoi(reader);
		//name
		file >> reader;
		name = reader;
		//delivery time
		file >> reader;
		del_time = stoi(reader);
		//price 1
		file >> reader;
		cp1 = stod(reader);
		//price 2
		file >> reader;
		cp2 = stod(reader);
		//price 3
		file >> reader;
		cp3 = stod(reader);

		Component tmp{id, name, del_time, cp1, cp2, cp3};
		output.push_back(tmp);

	} while (file);

	// chiude il file models.dat
	file.close();

	return output;
}
//funzione per leggere ordini
list<Orders> scan_ord_file()
{
	list<Orders> output; //contiene tutti gli ordini

	/**
	 * lettura file
	 */
	string reader;
	ifstream file{"files/orders.dat"}; //apre file orders.dat

	if (!file)
		throw Orders::InvalidFiles();

	//leggo soldi iniziali
	file >> reader;
	init_money = stoi(reader);

	//legge ogni riga e la salva
	do
	{
		Orders tmp; //ordine temporaneo da salvare in lista
		getline(file, reader);

		//time_stamp
		file >> reader;
		tmp.set_ts(stoi(reader));
		//time_stamp
		file >> reader;
		tmp.set_id(stoi(reader));
		//time_stamp
		file >> reader;
		tmp.set_quantity(stoi(reader));

		output.push_back(tmp); //salvo ordine in lista
	} while (file);

	// chiude il file models.dat
	file.close();

	return output;
}
//funzione per leggere model
list<Model> scan_model_files()
{
	list<Model> output;  //contiene tutti gli elettrodomestici
	vector<string> nomi; //contiene nomi file
	/**
     * lettura file
     */
	string reader;
	ifstream file{"files/models.dat"}; //apre il file models.dat

	if (!file)
		throw Model::invalid_file();

	//legge ogni riga e la salva
	do
	{
		file >> reader;
		nomi.push_back("files/" + reader);
		getline(file, reader);
	} while (file);

	// chiude il file models.dat
	file.close();

	/**
     * leggo ed inserisco modelli
     */
	for (int index = 0; index < nomi.size(); index++)
	{
		Model mod;
		int id, qnt; //componente
		string name; //componente
		/**
        * lettura file
        */
		ifstream file{nomi[index]}; //apre il file salvato in nomi[]

		if (!file)
			throw Model::invalid_file();

		bool first_row = true; //differenzia lettura righe

		/* legge e stampa ogni riga */

		do
		{
			//id
			file >> reader;
			if (first_row)
				mod.set_id(stoi(reader));
			else
				id = stoi(reader);

			//name
			file >> reader;
			if (first_row)
				mod.set_name(reader);
			else
				name = reader;

			//price or quantity needed
			file >> reader;
			if (first_row)
				mod.set_price(stoi(reader));
			else
				qnt = stoi(reader);

			if (first_row) //dopo una lettura first_row=false
				first_row = false;
			else //da seconda riga inserisco componenti
				mod.add_component(id, name, qnt);

			getline(file, reader);
		} while (file);

		// chiudo il file di indice index
		file.close();

		//inserisco nella lista modello letto
		output.push_back(mod);
	}

	return output;
}
//scrolla gli ordini
Orders ScrollOrders(list<Orders> &NewOrders)
{
	Orders ord;
	ord = NewOrders.front();
	NewOrders.pop_front();
	return ord;
}
//cerca i componenti in base all'id
Component SearchComponentById(int id, list<Component> comp)
{
	for (int i = 0; comp.front().getComponent_id != id && i < comp.size; i++)
	{
		comp.push_back(comp.front);
		comp.pop_front();
	}
	return comp.front();
}
//cerca un modello in base all'id
Model SearchModelById(int id, list<Model> mod)
{
	int size = mod.size();
	for (int i = 0; mod.front().get_m_id != id && i < size; i++)
	{
		mod.push_back(mod.front());
		mod.pop_front();
	}
	return mod.front();
}
//ordina i componenti in modo decrescente in base al mese
void OrdsByMonth(list<Component> &comp, const int size)
{
	Component *vet = new Component[size];
	for (int i = 0; i < size; i++)
	{
		vet[i] = comp.front();
		comp.pop_front();
	}
	Component temp;
	for (int i = 0; i < size - 1; i++)
		for (int j = 1; j < size; j++)
			if (vet[i].getDelivery_time() < vet[j].getDelivery_time)
			{
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
			}
	for (int i = 0; i < size; i++)
	{
		comp.push_front(vet[i]);
	}
	delete vet;
}
//metodo che cerca se ci sono ordini che arrivano
list<Orders> SearchForArrivedOrders(int ts, list<Orders>& listOrders) {
	list<Orders> output;
	int size = listOrders.size();
	for(int i=0; i<size; i++) {
		if(listOrders.front().get_ts() <= ts) {	//mese ordine minore di mese corrente
			output.push_back(listOrders.front());
			listOrders.pop_front();
		}
		else {
			listOrders.push_back(listOrders.front());
			listOrders.pop_front();
		}
	}
	return output;
}

int main()
{
	System sy;
	//salvadanaio aziendale
	Money mon{init_money};
	int capitale = mon.getMoney();
	//serve per indicare il modello che stiamo considerando
	Model currentModel;
	//lista degli ordini che si stanno processando
	list<Orders> OrdersInProcess;
	//lsita degli ordini da processare
	list<Orders> OrdersToProcess;
	//lista degli ordini pronti ad essere costruiti
	list<Orders>OrdersReady;
	//lista degli ordini finiti e consegnati
	list<Orders>OrdersDone;
	//lista di tutti gli ordini, man mano che vengono processati verranno rimossi da questa lista
	list<Orders> NewOrders = scan_ord_file();
	//lista contenente tutti i componenti
	list<Component> allComponents = scan_comp_file();
	//lista contenente i componenti utili ad un ordine
	list<Component> components;
	//lista contenente tutti gli elettrodomestici
	list<Model> models = scan_model_files();
	//Rappresenta il componente su cui stiamo lavorando al momento
	Component currentComponent;
	//numero di componenti per l'ordine
	int componentLength;
	//contatore
	int count;
	//quantità di elettrodomestici
	int modelquantity;
	//quantita di componenti
	int componentquantity;
	//contatore di mesi
	int monthcount = 0;
	//numero di ordini in arrivo
	int ArrivingOrdersCount;
	int ordersreadysize;
	bool ordineOk;
	while (NewOrders.size() > 0)
	{
		while (SearchForArrivedOrders(monthcount, NewOrders).size() > 0)
		{
			OrdersToProcess = SearchForArrivedOrders(monthcount, NewOrders);
			capitale += (SearchModelById(OrdersToProcess.back().get_id(), models).get_m_price * OrdersToProcess.back().get_quantity()) / 2;

			while (OrdersToProcess.size() > 0)
			{
				for (int i = 0; i < SearchModelById(OrdersToProcess.back().get_id(), models).get_num_c(); i++)
					components.push_back(SearchComponentById(SearchModelById(OrdersToProcess.back().get_id(), models).get_c_id(i), allComponents));
				componentLength = components.size();
				OrdsByMonth(components, componentLength);
				for (int i = 0; i < componentLength; i++)
				{
					if (mon.buyComponent(components.front(), SearchModelById(OrdersToProcess.front().get_id(), models).get_c_qnt(components.front().getComponent_id()) * OrdersToProcess.front().get_quantity()))
					{
						sy.add_c_shop(components.front().getComponent_id, SearchModelById(OrdersToProcess.front().get_id(), models).get_c_qnt(components.front().getComponent_id()) * OrdersToProcess.front().get_quantity(), components.front().getDelivery_time - monthcount);
						sy.add_month();
						monthcount++;
						components.pop_front();
					}
					else
					{
						components.push_back(components.front());
						components.pop_front();
					}
				}
				OrdersInProcess.push_back(OrdersToProcess.front());
				OrdersToProcess.pop_front();
			}
			ordineOk = false;
			for (int i = 0; i < OrdersInProcess.size(); i++)
			{
				for (int j = 0; j < SearchModelById(OrdersInProcess.front().get_id(), models).get_num_c(); j++)
					if (sy.catch_from_stock(SearchComponentById(SearchModelById(OrdersInProcess.front().get_id(), models).get_c_id(j), allComponents).getComponent_id(), SearchModelById(OrdersInProcess.front().get_id(), models).get_c_qnt(j) * OrdersInProcess.front().get_quantity()))
						ordineOk = true;
			   if(ordineOk)
			     {
					 OrdersReady.push_back(OrdersInProcess.front());
				 	 OrdersReady.back().set_ts(monthcount);
					 OrdersInProcess.pop_front();
				 }
			}
			ordersreadysize=OrdersReady.size();
			for(int i=0;i<ordersreadysize;i++)
			 if(monthcount>OrdersReady.front().get_ts())
			  {mon.sellModel(SearchModelById(OrdersReady.front().get_id(),models),OrdersReady.front().get_quantity());
			   sy.add_m_sold(SearchModelById( OrdersReady.front().get_id(),models).get_m_name(),OrdersReady.front().get_quantity();
			   sy.print_current_status();
			   OrdersReady.pop_front();
			  }
		}
	}
	return 0;
}
