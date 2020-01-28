#include "Orders.h"
#include <fstream>
Orders::Orders() : time_stamp{-1}, model_id{}, quantity{}
{
}

Orders::Orders(int TS, int id, int qt) : time_stamp{TS}, model_id{id}, quantity{qt}
{
}
void Orders::set_ts(int ts)
{
	if (ts < 0)
		throw Orders::InvalidTSException();
	this->time_stamp = ts;
}
void Orders::set_id(int id)
{
	if (id < 0)
		throw Orders::InvalidIdException();
	this->model_id = id;
}
void Orders::set_quantity(int qt)
{
	if (qt < 0)
		throw Orders::InvalidQuantityException();
	quantity = qt;
}
int Orders::get_ts()
{
	return this->time_stamp;
}
int Orders::get_id()
{

	return this->model_id;
}

int Orders::get_quantity()
{
	return this->quantity;
}
