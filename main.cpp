#include <iostream>
#include "System.h"
#include "Money.h"
#include "Orders.h"
#include "Model.h"
#include "Component.h"
using namespace std;
Orders ScrollOrders(list<Orders> & NewOrders)
{
	Orders	ord;
	ord = NewOrders.front();
	NewOrders.pop_front();
	return ord;
}
Component SearchComponentById(int id, list<Component> comp)
 {
	for(int i=0;comp.front().getComponent_id != id&&i<comp.size; i++)
	{
		comp.push_back(comp.front);
		comp.pop_front();
	}
	return comp.front();
 }

Model SearchModelById(int id, list<Model> mod)
{
	int size=mod.size();
	for (int i = 0;mod.front().get_m_id != id && i < size; i++)
	{
		mod.push_back(mod.front());
		mod.pop_front();
	}
	return mod.front();
}
void OrdsByMonth(list<Component> & comp, const int size)
{
	Component *vet=new Component [size];
	for (int i = 0;i < size;i++)
	{
		vet[i] = comp.front();
		comp.pop_front();
	}
	Component temp;
	for (int i = 0;i < size - 1;i++)
		for (int j = 1;j < size;j++)
			if (vet[i].getDelivery_time() < vet[j].getDelivery_time)
			{
				temp = vet[i];
				vet[i] = vet[j];
				vet[j] = temp;
			}
	for (int i = 0;i < size;i++)
	{
		comp.push_front(vet[i]);
	}
	delete vet;
}
bool HasArrived(Component comp)
{
	
}
int main()
{
	System sy;
	Money mon ;
	Model currentModel;
	list<Orders> OrdersInProcess;
	list<Orders> NewOrders;
	list<Component> allComponents;
	list<Component> components;
	list <Model> models;
	Component  currentComponent;
	Orders temp;
	int length;
	bool completo=false;
	int c;
	while (NewOrders.size>0)
	{
		cout<<"ordine 1\n";
		OrdersInProcess.push_back(ScrollOrders(NewOrders));
		currentModel = SearchModelById(OrdersInProcess.back().get_id(), models );
		for (int i = 0;i < currentModel.get_num_c();i++)
		{
			components.push_back(SearchComponentById(currentModel.get_c_id(i),allComponents));
		}
		OrdsByMonth(components,components.size());
		length = components.size();
       
	   c=0;
	   while(c<length)
	   {
		    if(sy.catch_from_stock(components.front().getComponent_id,OrdersInProcess.back().get_quantity()*currentModel.get_c_qnt(OrdersInProcess.back().get_id())))
		      {
				  completo=true;
				  c++;
				  components.push_back(components.front());
				  components.pop_front();
			  }
			  else
			     {
					 sy.add_month();
					 completo=false;
				 }
	   }
	  	    mon.sellModel(currentModel, OrdersInProcess.back().get_quantity());
        	sy.add_m_sold(currentModel.get_m_name(), OrdersInProcess.back().get_quantity());
   			sy.print_current_status();
	}
	cout<<"tutti gli ordini sono stati consegnati!";
	 return 0;
}