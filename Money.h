//Pagotto Francesco 1195886

class Money{
	public:
		class notEnoughMoney{};
		
		Money();
		Money(int); //soldi iniziali
		
		double getMoney(); //ritorna quanti fondi sono disponibili
		
		void buyComponent(int,int); //viene passato l'id del componente e la quantit�, se i fondi sono disponibili acquista il componente e vengono scalati i soldi
		void sellModel(int,int); //viene passato l'id del model e la quantit� che vengono venduti e viene guadagnato il prezzo di vendita 
	
	private:
		double money;
};
