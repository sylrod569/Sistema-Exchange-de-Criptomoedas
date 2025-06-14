// implementação dos métodos da classe Carteira

#include <iostream>
#include <cstring>	// incluindo a biblioteca cstring para o uso da função strcmp e strcpy
#include <string>	// incluindo a biblioteca string para o uso da função sprintf
#include "carteira.h"	// incluido a biblioteca criada carteira.h

using namespace std;

Carteira::Carteira(){
		strcpy(endereco,"INDEFINIDO");	// o endereço é por padrão "INDEFINIDO" e será alterado em setEndereco
		saldo_btc = 0;
		saldo_eth = 0;
		saldo_brl = 0;
}

Carteira::Carteira(float sbtc, float seth, float sbrl){
	strcpy(endereco,"INDEFINIDO");	// o endereço é por padrão "INDEFINIDO" e será alterado em setEndereco
	
	if(sbtc < 0){	// verifica se o usuário está tentando inserir um valor negativo para saldo_btc
			saldo_btc = 0; // caso ocorra a tentativa, saldo_btc será setado para 0
	}
	else{
		saldo_btc = sbtc;
	}
	
	if(seth < 0){	// verifica se o usuário está tentando inserir um valor negativo para saldo_eth
			saldo_eth = 0; // caso ocorra a tentativa, saldo_eth será setado para 0
	}
	else{
		saldo_eth = seth;
	}
	
	if(sbrl < 0){	// verifica se o usuário está tentando inserir um valor negativo para saldo_eth
			saldo_brl = 0; // caso ocorra a tentativa, saldo_eth será setado para 0
	}
	else{
		saldo_brl = sbrl;
	}
}

void Carteira::setEndereco(Carteira* carteira){	// após a criação de um objeto, setamos o endereco da carteira para o endereco do objeto
		char str_intermed[50]; 
		sprintf(str_intermed, "%p", (void*)carteira); // pega o endereco do objeto carteira, converte em uma string e o armazena em str_intermed
		strcpy(endereco,str_intermed);	// copia o conteúdo de str_intermed para endereco
}

int Carteira::alterar_saldo(float valor, const char* tsaldo){
		if(strcmp(tsaldo,"BTC") == 0){	// caso onde o usuário quer alterar o saldo de BTC
			if(valor < 0 && saldo_btc + valor < 0){	// verifica se o usuário está retirando mais do que possui
				cout << "> O depósito/transação não pode ser realizado(a)" << endl;
				return 1;	// retorna 1 caso a operação não possa ser realizada
			}
			else{
				saldo_btc += valor;
				return 0;	// retorna 0 caso a operação possa ser realizada
			}
		}
		else if(strcmp(tsaldo,"ETH") == 0){	// caso onde o usuário quer alterar o saldo de ETH
			if(valor < 0 && saldo_eth + valor < 0){	// verifica se o usuário está retirando mais do que possui
				cout << "> O depósito/transação não pode ser realizado(a)" << endl;
				return 1;	// retorna 1 caso a operação não possa ser realizada
			}
			else{
				saldo_eth += valor;
				return 0;	// retorna 0 caso a operação possa ser realizada
			}
		}
		else if(strcmp(tsaldo,"BRL") == 0){	// caso onde o usuário quer alterar o saldo de BRL
			if(valor < 0 && saldo_brl + valor < 0){	// verifica se o usuário está retirando mais do que possui
				cout << "> O depósito/transação não pode ser realizado(a)" << endl;
				return 1;	// retorna 1 caso a operação não possa ser realizada
			}
			else{
				saldo_brl += valor;
				return 0;	// retorna 0 caso a operação possa ser realizada
			}
		}
}

void Carteira::exibir_saldo(){
	cout << " (" << endereco << "):" << endl;
	cout << "BTC: " << saldo_btc << endl;
	cout << "ETH: " << saldo_eth << endl;
	cout << "BRL: " << saldo_brl << endl;
}

Carteira::~Carteira(){	
}
