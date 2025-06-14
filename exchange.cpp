// implementação dos métodos da classe Exchange

#include <iostream>
#include "exchange.h"	// incluido a biblioteca criada exchange.h

#define tamanhoC 3 // definindo um limite de carteiras que podem ser registradas
#define tamanhoT 4 // definindo um limite de transações que podem ser armazenadas

using namespace std;

Exchange::Exchange(){
		carteiras = new Carteira[tamanhoC]; // reserva espaço na memória para um vetor do tipo Carteira de tamanho definido pelo programador (10)
		num_carteiras = 0;
		transacoes = new Transacao[tamanhoT]; // reserva espaço na memória para um vetor do tipo Transacao de tamanho definido pelo programador (10)
		num_transacoes = 0;
}

void Exchange::adicionar_carteira(Carteira gcarteira){
	if(num_carteiras < tamanhoC){ // verifica se o limite de carteiras que podem ser registradas está disponível
		num_carteiras += 1; // incrementa o número de carteiras registradas
		carteiras[num_carteiras - 1] = gcarteira; // atribui a carteira criada à uma carteira do vetor carteiras na posição respectiva
	}
	else{ // caso o limite de carteiras que podem ser registradas seja alcançado
		num_carteiras = 0;	// zera o número de carteiras (permitindo sobrescrita)
		
		num_carteiras += 1; // incrementa a o número de carteiras registradas
		carteiras[num_carteiras - 1] = gcarteira; // atribui a carteira passada por parâmetro à uma carteira do vetor carteiras na posição respectiva
	}
}

void Exchange::realizar_transacao(Transacao gtransacao, const char* t, const char* mcv, const char* mpr, float q, float pu, Carteira* co, Carteira* cd){
	if(num_carteiras >= 2 && num_transacoes < tamanhoT){	// verifica se existe ao menos 2 carteiras para realizar a transação e se o limite de transações está disponível
		num_transacoes += 1;	// incrementa o número de transações realizadas
		gtransacao.executar_transacao(t,mcv,mpr,q,pu,co,cd);	// executa a transação a partir dos parâmetros passados
		transacoes[num_transacoes - 1] = gtransacao;	// atribui a transação passa por parâmetro à uma transação do vetor transacoes na posição respectiva

		cout << endl << "Transação " << num_transacoes << ":" << endl;
		gtransacao.exibir_detalhes();	// exibe os detalhes da transação
		cout << endl;
	}
	else{
		num_transacoes = 0;	// zera o número de transações (permitindo sobrescrita)
		
		num_transacoes += 1;	// incrementa o número de transações realizadas
		gtransacao.executar_transacao(t,mcv,mpr,q,pu,co,cd);	// executa a transação a partir dos parâmetros passados
		transacoes[num_transacoes - 1] = gtransacao;	// atribui a transação passa por parâmetro à uma transação do vetor transacoes na posição respectiva
		cout << endl;
	}
}


void Exchange::exibir_carteiras(){
	int i;

	for(i = 0; i < num_carteiras; i++){
		cout << "Carteira " << i + 1;
		carteiras[i].exibir_saldo();
		cout << endl;
	}
}

Exchange::~Exchange(){
	delete[] carteiras;	// liberando a memória alocada dinamicamente para a variável carteira
	delete[] transacoes;	// liberando a memória alocada dinamicamente para a variável transacoes
}
