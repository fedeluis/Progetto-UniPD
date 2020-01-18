//Pagotto Francesco 1195886

#include <iostream>

class Money{
	public:
		class notEnoughMoney();
		
		Money();
		Money(int); //soldi iniziali
		
		int getMoney(); //ritorna quanti fondi sono disponibili
		void buyComponent(int); //viene passato l'id del componente e se i fondi sono disponibili acquista il componente e vengono scalati i soldi
		void sellModel(int); //viene passato l'id del model che viene venduto e viene guadagnato il prezzo di vendita 
	
	private:
		int money;
};
