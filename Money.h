//Pagotto Francesco 1195886

class Money{
	public:
		class notEnoughMoney{};
		class invalidQuantity{};
		
		Money();
		Money(double); //soldi iniziali
		
		double getMoney(); //ritorna quanti fondi sono disponibili
		
		bool buyComponent(int,int); //viene passato l'id del componente e la quantità, se i fondi sono disponibili acquista il componente e vengono scalati i soldi
		bool sellModel(int,int); //viene passato l'id del model e la quantità che vengono venduti e viene guadagnato il prezzo di vendita 
	
	private:
		double money;
};
