// implementa��o dos m�todos da classe Exchange

#include <iostream>
#include "exchange.h"	// incluido a biblioteca criada exchange.h

#define tamanhoC 3 // definindo um limite de carteiras que podem ser registradas
#define tamanhoT 4 // definindo um limite de transa��es que podem ser armazenadas

using namespace std;

Exchange::Exchange(){
		carteiras = new Carteira[tamanhoC]; // reserva espa�o na mem�ria para um vetor do tipo Carteira de tamanho definido pelo programador (10)
		num_carteiras = 0;
		transacoes = new Transacao[tamanhoT]; // reserva espa�o na mem�ria para um vetor do tipo Transacao de tamanho definido pelo programador (10)
		num_transacoes = 0;
}

void Exchange::adicionar_carteira(Carteira gcarteira){
	if(num_carteiras < tamanhoC){ // verifica se o limite de carteiras que podem ser registradas est� dispon�vel
		num_carteiras += 1; // incrementa o n�mero de carteiras registradas
		carteiras[num_carteiras - 1] = gcarteira; // atribui a carteira criada � uma carteira do vetor carteiras na posi��o respectiva
	}
	else{ // caso o limite de carteiras que podem ser registradas seja alcan�ado
		num_carteiras = 0;	// zera o n�mero de carteiras (permitindo sobrescrita)
		
		num_carteiras += 1; // incrementa a o n�mero de carteiras registradas
		carteiras[num_carteiras - 1] = gcarteira; // atribui a carteira passada por par�metro � uma carteira do vetor carteiras na posi��o respectiva
	}
}

void Exchange::realizar_transacao(Transacao gtransacao, const char* t, const char* mcv, const char* mpr, float q, float pu, Carteira* co, Carteira* cd){
	if(num_carteiras >= 2 && num_transacoes < tamanhoT){	// verifica se existe ao menos 2 carteiras para realizar a transa��o e se o limite de transa��es est� dispon�vel
		num_transacoes += 1;	// incrementa o n�mero de transa��es realizadas
		gtransacao.executar_transacao(t,mcv,mpr,q,pu,co,cd);	// executa a transa��o a partir dos par�metros passados
		transacoes[num_transacoes - 1] = gtransacao;	// atribui a transa��o passa por par�metro � uma transa��o do vetor transacoes na posi��o respectiva

		cout << endl << "Transa��o " << num_transacoes << ":" << endl;
		gtransacao.exibir_detalhes();	// exibe os detalhes da transa��o
		cout << endl;
	}
	else{
		num_transacoes = 0;	// zera o n�mero de transa��es (permitindo sobrescrita)
		
		num_transacoes += 1;	// incrementa o n�mero de transa��es realizadas
		gtransacao.executar_transacao(t,mcv,mpr,q,pu,co,cd);	// executa a transa��o a partir dos par�metros passados
		transacoes[num_transacoes - 1] = gtransacao;	// atribui a transa��o passa por par�metro � uma transa��o do vetor transacoes na posi��o respectiva
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
	delete[] carteiras;	// liberando a mem�ria alocada dinamicamente para a vari�vel carteira
	delete[] transacoes;	// liberando a mem�ria alocada dinamicamente para a vari�vel transacoes
}
