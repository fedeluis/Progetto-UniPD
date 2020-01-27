//Pagotto Francesco 1195886

#include "Component.h"
#include "Model.cpp"

class Money{
	public:
		class notEnoughMoney{};
		class invalidQuantity{};
		
		Money();
		Money(double); //soldi iniziali
		
		double getMoney(); //ritorna quanti fondi sono disponibili
		
		bool buyComponent(Component&,int); //viene passato l'id del componente e la quantità, se i fondi sono disponibili acquista il componente e vengono scalati i soldi
		bool sellModel(Model&,int); //viene passato l'id del model e la quantità che vengono venduti e viene guadagnato il prezzo di vendita 
	
	private:
		double money;
};
