#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define MAX_PLV 30

//---------PALAVRA DINÂMICA---------
typedef struct{
    char letra;
}registro;


typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  registro Item;
  TipoApontador Prox;
  
}TipoCelula;

typedef struct {
  int qtd_letras;
  TipoApontador Primeiro,Ultimo;
}palavra;

//---------PALAVRA ESTÁTICA---------
typedef struct{
    int tam;
    int inicio,final;
    registro dados[MAX_PLV];
}palavra_e;

//-----OPERAÇÕES BASICAS PLV ESTÁTICO-----
palavra_e* inicia_palavra_e();
void imprime_letra_e(palavra_e *le);
void remove_letra_e(palavra_e *le);
int insere_letra_e(palavra_e *le,char letra); 
int tamanho_plv_e(palavra_e *le);

//-----OPERAÇÕES BASICAS TXT DINÂMICO-----
void FLVazia_palavra(palavra *plv);
void Insere_letra(char x, palavra *plv);
void Imprime_letra(palavra plv);
int Retira_letra( palavra *plv);
int Vazia_letra(palavra plv);
int tamanho_plv(palavra plv);