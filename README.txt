Observações e Instruções

> classe Carteira e arquivo carteira.cpp
    
    Carteira(float sbtc, float seth, float sbrl) 
        - os parâmetros são siglas dos atributos da classe Carteira (saldo_btc, saldo_eth, saldo_brl).
    
    void setEndereco(Carteira*) 
        - a função foi criada para colocar o endereço de memória do objeto carteira como atributo endereco do mesmo.
    
    int alterar_saldo(float valor, const char* tsaldo) 
        - o método retorna um valor inteiro que será utilizado em outro método de outra classe (executar_transacao());
        - para fazer uso desse método é nesseário passar "BTC", "ETH" ou "BRL" na segunda posição para indicar qual saldo deseja alterar.

> classe Transacao e arquivo transacao.cpp
    
    void executar_transacao(const char* t, const char* mcv, const char* mpr, float q, float pu, Carteira* co, Carteira* cd)
        - para fazer uso desse método é necessário passar como parâmetro "COMPRA" ou "VENDA" na primeira posição;
        - na segunda posição é necessário passar "BTC" ou "ETH" como parâmetro para espicificar qual criptomoeda será comprada/vendida;
        - na terceira posição é necessário passar "BTC", "ETH" ou "BRL" como parâmetro para espicificar qual criptomoeda/moeda fidunciária será usada para o pagamento da transação;
        - na quarta posição passa-se como parâmetro a quantidade de criptomoedas que serão compradas/vendidas;
        - na quinta posição passa-se como parâmetro o preço unitário da determinada criptomoeda de acordo com a moeda de pagamento;
        - na sexta posição passa-se como parâmetro o endereço da carteira de origem da transação;
        - na sétima posição passa-se como parâmetro o endereço da carteira de destino da transação;
	- o método printa a situação da transação (aprovada, recusa[motivo da recusa]).
    
   void exibir_detalhes()
	- o método printa os detalhes da transação, transações que mostram "Criptomoedas compradas/vendidas: 0" e "Total da transação: 0" não foram realizadas pelo motivo mostrado na execução do método .executar transação.

> arquivo main.cpp

    - na main encontra-se a declaração e inicialização de 3 objetos da classe Carteira e, a declaração de 4 objetos da classe Transacao e 1 objeto da classe Exchange;
    - o método .setEndereco() é acionado em cada um dos objetos carteira para atribuir o endereço de memória das variáveis aos seu respectivo atributo endereco;
    - o método .adicionar_carteira() é acionado três vezes para registrar as três carteiras ao vetor dinâmico do tipo Carteira;
    - o método .exibir_carteiras() é acionado para mostrar os dados iniciais das carteiras registradas;
    - o método .realizar_transacao é acionado 4 vezes para realizar 4 transações entre as carteiras registradas e armazená-las em um vetor dinâmico do tipo Transacao, sendo a primeira uma compra de BTC bem sucedida, a segunda uma venda de ETH bem sucedida, a terceira uma tentativa de compra de BTC onde o comprador não possui saldo suficiente de BRL e a quarta uma tentativa de venda de ETH onde o vendedor não possui estoque suficiente;
    - o saldo das carteiras após as transações realizadas é atualizado para o vetor dinâmico onde as mesmas se encontram;
    - por fim, o método .exibir_carteiras() é chamado para mostrar os dados finais das carteiras registradas.


