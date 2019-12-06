#include "palavra.h"
#define MAX_TXT 100

//---------TEXTO DINÂMICO---------
typedef struct TCelula *TApontador;

typedef struct TCelula {
  char first_letter;
  palavra palavras;
  TApontador Prox;
  TApontador Ant;
  int id_texto; 
}TCelula;

typedef struct {
    int qtd_palavra;
    TApontador Primeiro,Ultimo;
}texto;

//---------TEXTO ESTÁTICO---------
typedef struct{
    int tam;
    int inicio,final;
    palavra_e palavras[MAX_TXT];
    int id_texto;
}texto_e;


//-----OPERAÇÕES BASICAS TXT ESTÁTICO-----
texto_e* inicia_texto_e();
int  insere_palavra_e(texto_e *te,palavra_e pe);
void imprime_palavra_e(texto_e *te);
int remove_palavra_e(texto_e *te);
int tamanho_texto_estatico(texto_e *te);
//-----OPERAÇÕES BASICAS TXT DINÂMICO-----
void FLVazia_texto(texto *txt);
void Insere_plv(palavra x, texto *txt,char frsle);
void Imprime_plv(texto txt);
int tamanho_txt_dinamico(texto txt);
int Retira_plv(texto txt);

//---------------ORDENAÇÕES-------------------
//--------------ESTÁTICO----------------------
void select_sort(texto_e *te,int flag);
void  QuickSort(texto_e *te,int n,int flag);
void ordena(int left, int right,texto_e *te,double* comp,double* mov);
void particao(int left,int right,int *i,int *j,texto_e *te,double* comp,double* mov);
void merge(texto_e *te, int l, int m, int r,double *comp,double *mov,int flag);
void mergeSort(texto_e *te, int l, int r,int flag);
void heapSort(texto_e *te, int n,int flag);
void buildMaxHeap(texto_e *te, int n, double *comp , double *mov);

//---------------DINÂMICO--------------------
void select_sort_Dinamico(texto txt,int flag);
TCelula* QuickSort_Dinamico(TCelula * lista,int flag);
TCelula * junta(TCelula* lista_esquerda, TCelula * pivo,TCelula * lista_direita);
TCelula * ultima_celula(TCelula *celula_atual);
TCelula *pivo_aleatorio(TCelula *celula_cabeca);
int tam_texto(TCelula *lista);
void MergeSort(TCelula** referencia_cabeca,int flag);
TCelula* Classifica_Merge(TCelula* a, TCelula* b,double *comp,double *mov,int flag);
void divide_frente_tras(TCelula* fonte, TCelula** referencia_frente, TCelula** referencia_tras);
void insertionSort(TCelula **celula_refencia,int flag);
void sortedInsert(TCelula ** celula_refencia,TCelula* new_node,double *comp , double *mov);