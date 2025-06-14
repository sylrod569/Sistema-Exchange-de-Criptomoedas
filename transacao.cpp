// implementação dos métodos da classe Transacao

#include <iostream>
#include <cstring>	// incluindo a biblioteca cstring para o uso da função strcmp e strcpy
#include "transacao.h"	// incluido a biblioteca criada transacao.h

using namespace std;

Transacao::Transacao(){ // o método construtor padrão inicializa todas as variáveis com valores padrões
	strcpy(tipo,"INDEFINIDO");
	quantidade = 0.0;
	preco_unitario = 0.0;
	carteira_origem = 0;
	carteira_destino = 0;
}

float Transacao::calcular_total(){ // calcula a quantidade de criptomoedas compradas e o valor da transação (quantidade * preco_unitario)
	return quantidade * preco_unitario;
}

void Transacao::executar_transacao(const char* t, const char* mcv, const char* mpr, float q, float pu, Carteira* co, Carteira* cd){
	// parâmetro mcv = "Moeda de Compra/Troca": especifica qual criptomoeda vai ser comprada/trocada
	// parâmetro mpr = "Moeda de Pagamento/Recebimento": especifica qual criptomoeda/moeda fidunciária será utilizada como pagamento/troca da transação
	
	strcpy(tipo,t);
	carteira_origem = co;
	carteira_destino = cd;
	
	if(q < 0 || pu < 0){ // identifica se algum valor negativo foi inserido nos parâmetros float q e float pu
		cout << "> Não é possível inserir valor(es) de criptmoeda(s)/moeda(s) fidunciária(s) negativo(s)" << endl;
	}
	else{
		if(strcmp(t,"COMPRA") == 0){	// caso onde o tipo de transação será uma compra realizada pela carteira_origem da vendedora carteira_destino
			if(co->alterar_saldo(-(q*pu),mpr) == 1){ // verifica se a carteira_origem possui saldo para realizar a compra
				cout << "> O comprador não possui saldo suficiente para realizar a compra" << endl;
				return;
			}
			else if(cd->alterar_saldo(-q,mcv) == 1){ // verifica se a cartei_destino possui estoque para a venda
				co->alterar_saldo((q*pu),mpr); // corrige a alteração feita no saldo da carteira_origem duranto o comparativo anterior
				cout << "> O vendedor está tentando vender mais do que possui" << endl;
				return;
			}
			else{
				co->alterar_saldo((q*pu),mpr); // corrige a alteraçã feita no saldo da carteira_origem durante os comparativos anteriores
				cd->alterar_saldo(q,mcv);	// corrige a alteração feita no saldo da carteira_destino durante os comparativos anteriores
				
				co->alterar_saldo(q,mcv);	// soma a quantidade de criptmoeda(s) comprada(s) ao saldo da carteira_origem
				co->alterar_saldo(-(q*pu),mpr);		// subtrai o valor da transação (q = "quantidade" * pu = "preco unitário") do saldo carteira_origem		
	
				cd->alterar_saldo(-q,mcv);	// subtrai a quantdade de criptomoeda(s) vendida(s) do saldo da carteira_destino
				cd->alterar_saldo((q*pu),mpr);	//	soma o valor da transação ao saldo da carteiro_destino
				
				cout << "> Transação realizada com sucesso!" << endl;
				
				// atribuição dos detalhes da transação à cada atributo da classe Transacao
				
				quantidade = q;
				preco_unitario = pu;	
			}
		}
		else if(strcmp(t,"VENDA") == 0){ // caso onde o tipo de transação será uma venda realizada pela carteira_origem para o comprador carteira_destino
			if(co->alterar_saldo(-q,mcv) == 1){	// verifica se a carteira_origem possui estoque para a venda
				cout << "> O vendedor está tentando vender mais do que possui" << endl;
				return;
			}
			else if(cd->alterar_saldo(-(q*pu),mpr) == 1){	// verifica se a carteira_destino possui saldo para realizar a compra
				co->alterar_saldo(q,mcv);	// corrige a alteração feita no saldo da carteira_origem duranto o comparativo anterior
				cout << "> O comprador não possui saldo suficiente" << endl;
				return;
			}
			else{
				co->alterar_saldo(q,mcv);	// corrige a alteraçã feita no saldo da carteira_origem durante os comparativos anteriores
				cd->alterar_saldo((q*pu),mpr);	// corrige a alteração feita no saldo da carteira_destino durante os comparativos anteriores
				
				co->alterar_saldo(-q,mcv);	// subtrai a quantidade de criptmoeda(s) vendidas(s) do saldo da carteira_origem
				co->alterar_saldo((q*pu),mpr);	// soma o valor da transação (q = "quantidade" * pu = "preco unitário") ao saldo da carteira_origem	
				
				cd->alterar_saldo(q,mcv);	// soma a quantdade de criptomoeda(s) comprada(s) ao saldo da carteira_destino
				cd->alterar_saldo(-(q*pu),mpr); //	subtrai o valor da transação do saldo da carteiro_destino
				
				cout << "> Transação realizada com sucesso!" << endl;
				
				// atribuição dos detalhes da transação à cada atributo da classe Transacao
				
				quantidade = q;
				preco_unitario = pu;
			}		
		}
	}
}

void Transacao::exibir_detalhes(){
	cout << "Tipo: " << tipo << endl;
	cout << "Criptomoedas compradas/vendidas: " << quantidade << endl;
	cout << "Total da transação: " << calcular_total() << " criptomoeda(s)/moeda(s) fidunciária(s)" << endl;
	cout << "Carteira Origem: " << carteira_origem << endl;
	cout << "Carteira Destino: " << carteira_destino << endl;
}

Transacao::~Transacao(){
}
