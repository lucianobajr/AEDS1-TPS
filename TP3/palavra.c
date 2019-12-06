#include "palavra.h"
//----------------PALAVRA ESTÁTICA-----------------------
palavra_e* inicia_palavra_e(){
    palavra_e *le;
    le = (palavra_e*) malloc(sizeof(palavra_e));
    if(le!=NULL){
       le->tam=0;
       le->inicio=0;
       le->final=0;
    }
    return le;
}
void imprime_letra_e(palavra_e *le){
    int i;
    for(i=le->inicio;i<le->final;i++){
        printf("%c",le->dados[i].letra);
    }
}
void remove_letra_e(palavra_e *le){
    le->final--;
    le->tam--;
}
int insere_letra_e(palavra_e *le,char letra){
    if(le==NULL){
        return 0;
    }
    le->dados[le->final].letra=letra;
    le->final++;
    le->tam++;
} 
int tamanho_plv_e(palavra_e *le){
    return le->tam;
}

//----------------PALAVRA DINÂMICA-----------------------
void FLVazia_palavra(palavra *plv){ 
    plv -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    plv -> Ultimo = plv -> Primeiro;
    plv -> Primeiro -> Prox = NULL;
    plv->qtd_letras=0;
}

void Insere_letra(char x, palavra *plv){ 
    plv -> Ultimo -> Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    plv -> Ultimo = plv -> Ultimo -> Prox;
    plv -> Ultimo -> Item.letra = x;
    plv -> Ultimo -> Prox = NULL;
    plv->qtd_letras++;
}

int Retira_letra( palavra *plv){ 
   TipoCelula *aux;
   if(plv->qtd_letras==0){
       return 0;
   }
   else{
       aux=plv->Ultimo;
       plv->Ultimo=plv->Ultimo->Prox;
       plv->Ultimo->Prox=NULL;
       free(aux);
       plv->qtd_letras--;
   } 
}

int Vazia_letra(palavra plv){ 
    return (plv.Primeiro == plv.Ultimo);
}

void Imprime_letra(palavra plv){ 
    TipoApontador Aux;
    Aux = plv.Primeiro -> Prox;
    while (Aux != NULL) { 
        printf("%c", Aux -> Item.letra);
        Aux = Aux -> Prox;
    }
}

int tamanho_plv(palavra plv){
  return plv.qtd_letras;
}