//matriz 
#include "item.h"


typedef struct celula* apontador;  // erro no apontador  ,Mudar esse nome pq tem outro ponteiro igual by luciano
typedef struct celula{  
    apontador  direita; // perguntar como funciona o direita abaixo , sempre vai comecar do canto superior esquerdo e ir fazendo circulos no sentido horario  
    apontador  abaixo; 
	lista_item item ; // n é só um item é uma lista de itens 
	int coluna;// coordenadas  pra que tem que ter as coordenadas 
	int linha; //coordenadas  
}tipo_celula;   
typedef struct {   
	apontador celula_cabeca; 
	apontador lin_primeiro; // apontadores para linha  
	apontador col_primeiro; // apontadores para coluna 
	int qtL, qtC; // usado no for em que cada repeticao criara uma alocaçao  
	
}tipo_matriz;

void inicializa_matriz(tipo_matriz *ptr_matriz);
void le_matriz(tipo_matriz *ptr_matriz);  
void insere_itens_matriz(tipo_matriz *ptr_matriz, int coordenada_linha , int coordenada_coluna, lista_item *itens); 
void celula_cabeca_linha(tipo_matriz *ptr_matriz, tipo_celula *ptr_celula); 
void celula_cabeca_coluna(tipo_matriz *ptr_matriz, tipo_celula *ptr_celula); 
void quantidadeComprasPorProduto(tipo_matriz *ptr_matriz);
void quantidadeComprasPorCliente(tipo_matriz *ptr_matriz); 
void imprimeMatriz(tipo_matriz *ptr_matriz);
void menu(tipo_matriz *ptr_matriz);
