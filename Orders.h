#include <iostream>

using namespace std;

class Orders
{
public:
	class InvalidQuantityException
	{
	};
	class InvalidTSException
	{
	};
	class InvalidIdException
	{
	};
	class InvalidFiles
	{	
	};
	Orders();
	Orders(int TS, int id, int quantity);
	void set_ts(int ts);
	void set_id(int id);
	void set_quantity(int quantity);
	int get_ts();
	int get_id();
	int get_quantity();

private:
	int time_stamp;
	int model_id;
	int quantity;
};