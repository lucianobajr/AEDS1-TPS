#include "texto.h"
#define MAX_BBT 100

//---------BBT DINÂMICO---------
typedef struct TiCelula *TiApontador;

typedef struct TiCelula {
  texto textos;
  TiApontador Prox;
  TiApontador Ant; 
  
}TiCelula;

typedef struct { 
    int quantidade;
    TiApontador Primeiro,Ultimo;
}biblioteca;

//---------BBT ESTÁTICO---------
typedef struct{ 
    int inicio,final;
    texto_e textos[MAX_BBT];  
    int quantidade; 
}bbt_e;

//-----OPERAÇÕES BASICAS BBT ESTÁTICO-----
bbt_e* inicia_bbt_e();
int  insere_texto_e(bbt_e *be,texto_e te);
void imprime_texto_e(bbt_e *be);
int remove_texto_e(bbt_e *be);
int tam_bbt_e(bbt_e *be);

//-----OPERAÇÕES BASICAS BBT DINÂMICO-----
void FLVazia_bbt(biblioteca *bbt);
void Insere_txt(texto x, biblioteca *bbt);
void Imprime_txt(biblioteca bbt);  
int tamanho_bbt(TiCelula *lista_bbt);
int Remove_txt(biblioteca bbt);

//---------------ORDENAÇÕES-------------------
//--------------ESTÁTICO----------------------
void select_sort_vetor_bbt(bbt_e *ptr_bbt_estatica,int flag);
void QuickSort_bbt(bbt_e *be ,int n,int flag);
void ordena_bbt(int left, int right,bbt_e *be,double* comp,double* mov); 
void particao_bbt(int left,int right,int *i,int *j,bbt_e *be,double* comp,double* mov);
void merge_bbt(bbt_e *be, int l, int m, int r,double *comp,double *mov,int flag);
void mergeSort_bbt(bbt_e *be, int l, int r,int flag);
void buildMaxHeap_bbt(bbt_e *be, int n, double *comp , double *mov);
void heapSort_bbt(bbt_e *be, int n, int flag);
//---------------DINÂMICO--------------------
// QsD => quick sort Dinamico 

void select_sort_lista_bbt(biblioteca bbt_dinamica,int flag);
TiCelula* QuickSort_Dinamico_bbt(TiCelula * bbt_lista,int flag); 
TiCelula * junta_QsD_bbt(TiCelula* bbt_lista_esquerda, TiCelula * pivo, TiCelula * bbt_lista_direita);
TiCelula * ultima_celula_QsD_bbt(TiCelula *bbt_celula_atual);
TiCelula *pivo_aleatorio_QsD_bbt(TiCelula *bbt_celula_cabeca);
void MergeSort_bbt(TiCelula** referencia_cabeca,int flag);
TiCelula* Classifica_Merge_bbt(TiCelula* a, TiCelula* b,double *comp,double *mov,int flag);
void divide_frente_tras_bbt(TiCelula* fonte, TiCelula** referencia_frente, TiCelula** referencia_tras);
void insertionSort_bbt(TiCelula **celula_refencia,int flag );
void sortedInsert_bbt(TiCelula **celula_refencia,TiCelula* novo_no, double *comp , double *mov);


//---------------------------FUNÇÕES MENU-------------------------------------
void menu(palavra_e *pe,palavra pd,texto_e *te,texto td,bbt_e *be,biblioteca bd);
void RandomWord(int max_tam, char *palavra);
int RandomTam(int max,int min);
void print_menu1();
void print_menu2();
void print_menu3_estatico();
void print_menu3_dinamico();
void print_menu4();