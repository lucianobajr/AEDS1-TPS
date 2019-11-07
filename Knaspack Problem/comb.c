#include "comb.h"

void printCombination(item *itens_vetor,mochila *moch,int n, int r){
    int data[r];
    int data2[r];
    combinationUtil(itens_vetor,moch,data, data2, 0, n - 1, 0, r);
}

void combinationUtil(item *itens_vetor,mochila *moch,int data[], int data2[], int start, int end, int index, int r){
    int i = 0, valor = 0, peso = 0, j = 0;
    int vec_aux_peso[r];
    int vec_aux_valor[r];
    int valor_aux, peso_aux = 0; 
    if (index == r){
        for (j = 0; j < r; j++){
            /*printa as combinações r a r
                printf("%d ", data[j]);
                printf("%d ", data2[j]);
            */
            peso_aux += data[j];
            valor_aux += data2[j];
        }
        if ((valor_aux > moch->soma_valor && peso_aux <= W) || ( valor_aux ==  moch->soma_valor  && r >= moch -> quantidade && peso_aux<=W)){
            for (j = 0; j < r; j++){
                    moch->itens_mochila[j].peso=data[j];
                    moch->itens_mochila[j].valor=data2[j];
                }
            moch->soma_peso=peso_aux;
            moch->soma_valor=valor_aux;    
            moch->quantidade=j;
        }
        peso_aux = 0;
        valor_aux = 0;
        return;
    }

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
    printf("Digite o nome do arquivo para o caso de teste (Na mesma pasta e com .txt) = ");
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

void imprime(arquivo *arq){
    int i,j;
     fputs(" ", stdout);
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|"); 
        for(i=0;i<80;i++){
        fputs(" ", stdout);
    }
    printf("ITENS");
    for(i=0;i<78;i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for(i=0;i<152;i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n"); 
    for (i = 0; i <arq->quantidade_arquivo; i++){
        printf("|");
        for(j=0;j<78;j++){
            fputs(" ", stdout);
        }  
        printf("PESO = %d",arq->itens_arquivo[i].peso);
        if(arq->itens_arquivo[i].peso<10){
            fputs(" ", stdout);
        }
        for(j=0;j<76;j++){
            fputs(" ", stdout);
        }  
        printf("|");
        printf("\n");
        printf("|");
        for(j=0;j<78;j++){
            fputs(" ", stdout);
        }  
        printf("VALOR = %d",arq->itens_arquivo[i].valor);
        if(arq->itens_arquivo[i].valor<10){
            fputs(" ", stdout);
        }
        for(j=0;j<75;j++){
            fputs(" ", stdout);
        }  
        printf("|");
        printf("\n");
        printf("|");
        for(j=0;j<163;j++){
            fputs(" ", stdout);
        }
         printf("|");
        printf("\n");
    }
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n");
    fflush(stdin); 
}

void imprime_mochila(mochila *moch){
    int i,j;
    fputs(" ", stdout);
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|"); 
        for(i=0;i<80;i++){
        fputs(" ", stdout);
    }
    printf("MOCHILA");
    for(i=0;i<76;i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n\n\n"); 
    for(i=0;i<(147-moch->quantidade)/2;i++){
        fputs(" ", stdout);
    }
    printf("[");
   
    for (i = 0; i<moch->quantidade; i++){   
        printf("(%d,",moch->itens_mochila[i].peso);
        printf("%d)",moch->itens_mochila[i].valor);   
    }   
    printf("]\n\n\n");
}

void menu(arquivo *arq,mochila *moch){
    int i,resposta=1,r = 1;
    double tempo;
    clock_t fim,inicio;
    insere(arq);
    inicializaVetor(moch,arq->quantidade_arquivo,W);
    inicio=clock(); 
    for(i=0;i<arq->quantidade_arquivo;i++){
            /* print para saber qual combinação está sendo feita.
                    printf("combinação de tamanho %d\n",r);
            */
            printCombination(arq->itens_arquivo,moch,arq->quantidade_arquivo,r);
            r++;
        }  
    fim=clock(); 
    tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
    do{
        printa_menu();
        scanf("%d",&resposta);
        if(resposta==1||resposta==2||resposta==3){
            if(resposta==1){
                imprime_mochila(moch);
            }
            if(resposta==2){
                 fputs(" ", stdout);
                for(i=0;i<163;i++){
                    fputs("_", stdout);
                }
                printf("\n|");
                for(i=0;i<163;i++){
                    fputs(" ", stdout);
                }
                printf("|\n|"); 
                    for(i=0;i<80;i++){
                    fputs(" ", stdout);
                }
                printf("TEMPO");
                for(i=0;i<78;i++){
                    fputs(" ", stdout);
                }
                printf("|");
                printf("\n");
                printf("|");
                for(i=0;i<163;i++){
                    fputs("_", stdout);
                }
                printf("|\n\n\n"); 
                for(i=0;i<(147)/2;i++){
                    fputs(" ", stdout);
                }
                printf("Tempo Gasto = %lf segundos\n\n\n",tempo);
            }
            if(resposta==3){
                imprime(arq);
            }
        }
        else{
            break;
        }
    }
    while(resposta!=1||resposta!=2||resposta!=3);
}   

void printa_menu(){
    int i;
    fputs(" ", stdout);
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|"); 
        for(i=0;i<80;i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for(i=0;i<79;i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    printf("Digite (1)  para Imprimir os itens adicionados na mochila (2) para Imprimir o tempo gasto na execução do programa (3) para imprimir os itens do arquivo |");
    printf("\n");
    printf("|"); 
    for(i=0;i<43;i++){
        fputs(" ", stdout);
    } 
    printf("E Qualquer número diferente dos anteriores para fechar o programa.");     
    for(i=0;i<54;i++){
        fputs(" ", stdout);
    }  
    printf("|\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|\n");
    printf("------------->");
    fflush(stdin);
}
