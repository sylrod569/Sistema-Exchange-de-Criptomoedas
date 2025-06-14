// declaração da classe Transacao

#include "transacao.h" // incluido a biblioteca criada transacao.h

class Exchange {
	private:
		Carteira* carteiras;
		int num_carteiras;
		Transacao* transacoes;
		int num_transacoes;
	public:
		Exchange(); // método construtor padrão
		
		void adicionar_carteira(Carteira);
		
		void realizar_transacao(Transacao, const char*, const char*, const char*, float, float, Carteira*, Carteira*);
		
		void exibir_carteiras();

		~Exchange(); // método destrutor
};
