// declaração da classe Carteira

class Carteira {
	private:
		char endereco[50];
		float saldo_btc;
		float saldo_eth;
		float saldo_brl;
	
	public:
		Carteira(); // método construtor padrão
		
		Carteira(float, float, float);
		
		void setEndereco(Carteira*);
		
		int alterar_saldo(float, const char*); 
		
		void exibir_saldo();
		
		~Carteira(); // método destrutor
};
