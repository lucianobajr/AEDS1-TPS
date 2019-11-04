#include "comb.h"
// A principal função que imprime todas as combinações de tamanho r
// em arr [] de tamanho n. Essa função usa principalmente o combinaçãoUtil ()
void printCombination(item *itens_vetor,mochila *moch,int n, int r){
    // Uma matriz temporária para armazenar todas as combinações uma a uma
    int data[r];
    int data2[r];
    // Imprime todas as combinações usando a matriz temporária 'data []'
    combinationUtil(itens_vetor,moch,data, data2, 0, n - 1, 0, r);
}
/*  arr [] ---> Matriz de entrada
    data [] ---> Matriz temporária para armazenar a combinação atual
    início e fim ---> Índices de início e término em arr []
    índice ---> Índice atual nos dados []
    r ---> Tamanho de uma combinação a ser impressa */

void combinationUtil(item *itens_vetor,mochila *moch,int data[], int data2[], int start, int end, int index, int r){
    int i = 0, valor = 0, peso = 0, j = 0;
    int vec_aux_peso[r];
    int vec_aux_valor[r];
    int valor_aux, peso_aux = 0; 

    // A combinação atual está pronta para ser impressa, imprima-a
    if (index == r){
        for (j = 0; j < r; j++){
            //printf("%d ", data[j]);
            //printf("%d ", data2[j]);
            peso_aux += data[j];
            valor_aux += data2[j];
        }
        if ((valor_aux > moch->soma_valor && peso_aux <= W) || ( valor_aux ==  moch->soma_valor  && r >= moch -> quantidade && peso_aux<=W)){
            for (j = 0; j < r; j++){
                // como vou tratar se tiverem as somas dos valores iguais  == > lista final
                    moch->itens_mochila[j].peso=data[j];
                    moch->itens_mochila[j].valor=data2[j];
                }
            moch->soma_peso=peso_aux;
            moch->soma_valor=valor_aux;    
            moch->quantidade=j;
        }
        
        // zera para nao dar lixo de memoria
        peso_aux = 0;
        valor_aux = 0;
        //printf("\n");
        return;
    }

    /*  substitui o índice por todos os elementos possíveis. A condição
            no index fará uma combinação com os elementos restantes
            "end-i + 1> = r-index" garante que a inclusão de um elemento
            nas posições restantes*/

    for (i = start; i <= end && end - i + 1 >= r - index; i++){
        data[index] = itens_vetor[i].peso;
        data2[index] = itens_vetor[i].valor;
        combinationUtil(itens_vetor,moch, data, data2, i + 1, end, index + 1, r);
    }
}

void insere(arquivo *arq){
    FILE *teste;
    int tamanho_vet, i = 0, cont = 0;
    char nome[30];
    item copia;
    printf("Digite o nome do arquivo para o caso de teste (Na mesma pasta e com .txt)");
    fgets(nome, 30, stdin);
    nome[strlen(nome) - 1] = '\0';
    teste = fopen(nome, "r");
    if (teste == NULL){
        printf("dando erro");
    }
    else{
        fscanf(teste, "%d", &tamanho_vet);
        item *aux =(item*)malloc(tamanho_vet*sizeof(item));
        if(aux == NULL){
            printf("ERRO");
        }
        
        while (!feof(teste)){
            //add os items na lista    
            fscanf(teste, "%d %d", &copia.peso, &copia.valor);
                aux[i].peso= copia.peso;
                aux[i].valor =copia.valor;
                i++;
        } 
        arq->itens_arquivo = aux;
        arq->quantidade_arquivo = tamanho_vet;
        fclose(teste);
        i--; 
    }
}

void imprime(item* itens_vetor,int qt){
    int i;
    for (i = 0; i <qt; i++){
        printf("ITENS\n");
        printf("PESO = %d\n", itens_vetor[i].peso);
        printf("RELEVANCIA = %d \n", itens_vetor[i].valor);
        printf("\n");
    }
}

void inicializaVetor(mochila *moch, int N,int tam){
    item *aux =(item*)malloc(N*sizeof(item));
    aux->peso=0;
    aux->valor=0;
    moch->itens_mochila = aux;
    moch->capacidade = tam;
    moch->quantidade=0;
    moch->soma_peso=0;
    moch->soma_valor=0; 
}

void imprime_mochila(mochila *moch){
     int i;
     printf("ITENS\n");
     printf("[");
     for (i = 0; i<moch->quantidade; i++){   
        printf("(%d,",moch->itens_mochila[i].peso);
        printf("%d)",moch->itens_mochila[i].valor);   
     }   
     printf("]\n");
}
