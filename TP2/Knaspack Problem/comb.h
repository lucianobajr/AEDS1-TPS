#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define W 40
    
typedef struct {
    int peso;
    int valor;
}item;

typedef struct{
    item *itens_arquivo;
    int quantidade_arquivo;
}arquivo;
typedef struct{
    int soma_peso,soma_valor,quantidade;
    item *itens_mochila ;
    int capacidade;
}mochila;

void combinationUtil(item *itens_vetor,mochila *moch, int data[], int data2[], int start, int end, int index, int r);
void printCombination(item* itens_vetor,mochila *moch, int n, int r);
void insere(arquivo *arq);
void imprime(arquivo *arq);
void inicializaVetor(mochila *moch, int N,int tam);
void imprime_mochila(mochila *moch);
void menu(arquivo *arq,mochila *moch);
void printa_menu();
