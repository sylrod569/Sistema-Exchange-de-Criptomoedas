// declaração da classe Transacao

#include "carteira.h" // incluido a biblioteca criada carteira.h 

class Transacao {
	private:
		char tipo[20];
		float quantidade;
		float preco_unitario;
		Carteira* carteira_origem;
		Carteira* carteira_destino;
	public:
		Transacao();	// método construtor padrão

		float calcular_total();
		
		void executar_transacao(const char*, const char*, const char*, float, float, Carteira*, Carteira*);
		
		void exibir_detalhes();
		
		~Transacao();	// método destrutor
};
