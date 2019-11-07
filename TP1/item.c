#include "item.h" 

void cria_lista_item_vazia(lista_item *ptr_lista_itens){ 	
	ptr_lista_itens -> p_item_primeiro = (tipo_item*)malloc(sizeof(tipo_item));
	ptr_lista_itens -> p_item_ultimo = ptr_lista_itens ->p_item_primeiro;  
	ptr_lista_itens -> p_item_primeiro -> proximo = NULL ;  
	ptr_lista_itens -> count_produto = 0 ; 
	ptr_lista_itens -> count_cliente = 0 ;
} 
void insere_lista_item(lista_item *ptr_lista_itens , tipo_item *item){  
	
	ptr_lista_itens -> p_item_ultimo -> proximo = (apontador_item)malloc(sizeof(tipo_item)); // nao sei no apontador vai um ponteiro   
	ptr_lista_itens -> p_item_ultimo = item -> proximo ; //m 
	ptr_lista_itens -> p_item_ultimo = item;  //m 
	ptr_lista_itens -> p_item_ultimo -> proximo = NULL;  //m 
	ptr_lista_itens -> count_cliente ++; 
	ptr_lista_itens -> count_produto += item -> quantidade;
}
