#include <iostream>

class Money{
	public:
		getMoney(); //ritorna quanti fondi sono disponibili
		buyComponent(int); //viene passato l'id del componente e se i fondi sono disponibili acquista il componente e vengono scalati i soldi
		sellModel(int); //viene passato l'id del model che viene venduto e viene guadagnato il prezzo di vendita 
	
	private:
		int money;
};
