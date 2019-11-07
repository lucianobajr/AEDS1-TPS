#include <stdlib.h>
#include <stdio.h>
#include <string.h>  



typedef struct item* apontador_item ; 
typedef struct item{ 
	char data[11]; // modelo de data  
	int quantidade;  
	apontador_item proximo; 
}tipo_item; 

typedef struct { 
	apontador_item p_item_primeiro , p_item_ultimo ;  
	// celulas na lista item == compras por cliente  
	int count_cliente;  
	int count_produto;
}lista_item; 
// funcoes do item  
void cria_lista_item_vazia(lista_item *ptr_item); 
void insere_lista_item(lista_item *itens, tipo_item *item);
