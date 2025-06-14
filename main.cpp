#include <iostream>
#include "exchange.h"

using namespace std;

int main() {
	Carteira carteira1(153.5,277.8,434.90), carteira2(721,217.6,900.50), carteira3(57.2,23.7,698.7);
	Transacao transacao1, transacao2, transacao3, transacao4;
	Exchange exchange;
	
	carteira1.setEndereco(&carteira1);
	carteira2.setEndereco(&carteira2);
	carteira3.setEndereco(&carteira3);
	
	exchange.adicionar_carteira(carteira1);
	exchange.adicionar_carteira(carteira2);
	exchange.adicionar_carteira(carteira3);
	
	cout << endl << "=== Estado Inicial das Carteiras ===" << endl << endl;
	exchange.exibir_carteiras();
	
	cout << "=== Realizando Transações ===" << endl << endl;
	
	exchange.realizar_transacao(transacao1, "COMPRA", "BTC", "BRL", 53.5, 3.2, &carteira2, &carteira1);
	exchange.realizar_transacao(transacao2, "VENDA", "ETH", "BTC", 77.8, 0.5, &carteira1, &carteira3);
	exchange.realizar_transacao(transacao3, "COMPRA", "BTC", "BRL", 221, 4, &carteira3, &carteira2);
	exchange.realizar_transacao(transacao4, "VENDA", "ETH", "BRL", 423.6, 1, &carteira2, &carteira3);
	
	exchange.adicionar_carteira(carteira1);
	exchange.adicionar_carteira(carteira2);
	exchange.adicionar_carteira(carteira3);

	cout << "=== Estado Final das Carteiras ===" << endl << endl;
	
	exchange.exibir_carteiras();
	
	return 0;
}
