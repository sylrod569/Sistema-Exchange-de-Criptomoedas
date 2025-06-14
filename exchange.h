// declara��o da classe Transacao

#include "transacao.h" // incluido a biblioteca criada transacao.h

class Exchange {
	private:
		Carteira* carteiras;
		int num_carteiras;
		Transacao* transacoes;
		int num_transacoes;
	public:
		Exchange(); // m�todo construtor padr�o
		
		void adicionar_carteira(Carteira);
		
		void realizar_transacao(Transacao, const char*, const char*, const char*, float, float, Carteira*, Carteira*);
		
		void exibir_carteiras();

		~Exchange(); // m�todo destrutor
};
