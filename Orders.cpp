#include <iostream>

using namespace std;

Orders::Orders():id{-1}, name{""}, comp{}
  {}

Orders::Orders(int TS, int id, int qt):time_stamp{TS}, id{model_id}, quantity{qt}
  {}
void Orders::add_order(int ts,int id,int quantity);
	{    if(qt<1)
   	     throw InvalidQuantityException();
     	 //creo variabile
   		 component n = {cid,cname,q};
         //aggiungo in coda
  		  comp.push_back(n);
	}
void set_ts(int ts)
{
	if(ts<0)
	 thorw InvalidTSException();
	this->time_stamp=ts;		
}
void set_id(int id)
{ 
    if(id<0)
	 thorw InvalidIdException();
	this->model_id=id;			
}
void set_quantity(int qt)
{
	if(quantity<0)
	 thorw InvalidQuantityException();
	this->quantity=qt;		
}
int get_ts()
{
	return this->time_stamp;
}
int get_id()
{

	return this->model_id;
}
