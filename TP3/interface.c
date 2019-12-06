#include "bbt.h"
#include <time.h>
#define tam2 30

/*
  |--------------------CHAMADAS DAS FUNÇÕES DE ORDENAÇÃO PARA TEXTO--------------------|
  |                                                                                    |
  |                           ------------ESTATICO------------                         |                              
  |                             select_sort(&be->textos[0]);                           |
  |                     QuickSort(&be->textos[be->final],be->textos->tam);             |                     
  |                         mergeSort(be->textos,0,be->textos->tam-1);                 |
  |                         heapSort(be->textos,be->textos->tam);                      |
  |                           ------------DINAMICO------------                         |
  |                             select_sort_Dinamico(bd.Ultimo->textos);               | 
  |       bd.Ultimo->textos.Primeiro=QuickSort_Dinamico(bd.Ultimo->textos.Primeiro);   | 
  |                            MergeSort(&bd.Ultimo->textos.Primeiro);                 | 
  |                         insertionSort(&bd.Ultimo->textos.Primeiro);                | 
  |                                                                                    | 
  |                                                                                    | 
  |---------------------------CHAMADAS DE ORDENAÇÃO PARA  BBT--------------------------|
  |                                                                                    | 
  |                                                                                    |         
  |                             ------------ESTATICO------------                       | 
  |                             select_sort_vetor_bbt(be);                             | 
  |                             QuickSort_bbt(be,be->quantidade)                       | 
  |                            mergeSort_bbt(be,0,be->quantidade-1);                   |         
  |                             heapSort_bbt(be,be->quantidade);                       | 
  |                           ------------DINAMICO------------                         | 
  |                               select_sort_lista_bbt(bd);                           | 
  |                       bd.Primeiro =  QuickSort_Dinamico_bbt(bd.Primeiro);          | 
  |                               MergeSort_bbt(&bd.Primeiro);                         |         
  |                              insertionSort_bbt(&bd.Primeiro);                      | 
  --------------------------------------------------------------------------------------  
*/


void menu(palavra_e *pe,palavra pd,texto_e *te,texto td,bbt_e *be,biblioteca bd){
    int respostas_menu[4];
    srand(time(NULL));
    do{
        texto_e *copia;
        bbt_e *copia_be;
        texto copia_td;
        biblioteca copia_bd;
        clock_t fim,inicio;
        int max,min;
        double tempo;
        //-----------------PRIMEIRA ETAPA DO MENU ESCOLHA DO TAD--------------
        print_menu1();
        scanf("%d",&respostas_menu[0]);
        //-----------------SEGUNDA ETAPA DO MENU ESCOLHA ENTRE ESTÁTICO E DINAMICO JUSTAMENTE COM  INSERÇÃO------------------
        print_menu2();
        scanf("%d",&respostas_menu[1]);
        if(respostas_menu[0]==1 && respostas_menu[1]==3){
            pe = inicia_palavra_e();
            copia=inicia_texto_e();
            te = inicia_texto_e();
            int resposta,x,k;
            char *palavra = (char*) malloc(tam2 * sizeof(char));
            printf(" Digite (1) para 100 (2) para 1000  (3)10000 e (4) para 100000  palavras randomicas  que voce deseja criar\n");
            scanf("%d", &resposta);
            printf("\n");
            if(resposta==1){
                resposta=100;
            }
            if(resposta==2){
                resposta=1000;
            }
            if(resposta==3){
                resposta=10000;
            }
            if(resposta==4){
                resposta=100000;
            }
            for(x = 0; x < resposta; x++){
                RandomWord(tam2 - 1, palavra);
                for(k=0;k<strlen(palavra);k++){
                    insere_letra_e(pe,palavra[k]);
                }            
                insere_palavra_e(te,*pe); 
                insere_palavra_e(copia,*pe);
                // limpa as estruturas  
                pe=inicia_palavra_e();
            }  
            free(palavra);

        }
        if(respostas_menu[0]==1 &&respostas_menu[1]==4){
            FLVazia_palavra(&pd);
            FLVazia_texto(&copia_td);
            FLVazia_texto(&td);
            int resposta,x,k;
            char *palavra = (char*) malloc(tam2 * sizeof(char));
            srand(time(NULL));
            printf(" Digite (1) para 100 (2) para 1000  (3)10000 e (4) para 100000  palavras randomicas  que voce deseja criar\n");
            scanf("%d", &resposta);
            printf("\n");
            if(resposta==1){
                resposta=100;
            }
            if(resposta==2){
                resposta=1000;
            }
            if(resposta==3){
                resposta=10000;
            }
            if(resposta==4){
                resposta=100000;
            }
            for(x = 0; x < resposta; x++){
                RandomWord(tam2 - 1, palavra);
                for(k=0;k<strlen(palavra);k++){
                    Insere_letra(palavra[k],&pd);
                }            
                Insere_plv(pd,&td,palavra[0]);
                Insere_plv(pd,&copia_td,palavra[0]); 
                // limpa as estruturas  
                FLVazia_palavra(&pd);
            }  
            free(palavra);

        }
        if(respostas_menu[0]==2 && respostas_menu[1]==3){
            pe = inicia_palavra_e();
            te = inicia_texto_e();
            be = inicia_bbt_e();
            copia_be=inicia_bbt_e();
            int tam_bbt,j;
            int resposta,x,k;
            char *palavra = (char*) malloc(tam2 * sizeof(char));
            srand(time(NULL));
            printf("Digite (1) para 100 e (2) para 100000 quantidade de textos que deseja inserir na biblioteca:");
            scanf("%d",&tam_bbt);
            if(tam_bbt==1){
                tam_bbt=100;
                printf("Digite (1) para utilizar o intervalo de 1 a 100\n  e  (2) para para utilizar o interavalo de 50000 a 100000 palavras(zero para preencher um novo texto)...\n");
                scanf("%d", &resposta);
                if(resposta==1){
                    min=1;
                    max=100;
                }
                else{
                    min=50000;
                    max=100000;
                }
            }
            else{
                tam_bbt=100000;
                printf("Digite (1) para utilizar o intervalo de 1 a 100\n  e  (2) para para utilizar o interavalo de 50000 a 100000 (zero para preencher um novo texto)...\n");
                scanf("%d", &resposta);
                if(resposta==1){
                    min=1;
                    max=100;
                }
                else{
                    min=50000;
                    max=100000;
                }
            }
            for(j=0;j<tam_bbt;j++){
                resposta=RandomTam(max,min);
                for(x = 0; x < resposta; x++){
                    RandomWord(tam2 - 1, palavra);
                    for(k=0;k<strlen(palavra);k++){
                        insere_letra_e(pe,palavra[k]);
                    }            
                    insere_palavra_e(te,*pe); 
                    // limpa as estruturas  
                    pe=inicia_palavra_e();
                } 
                insere_texto_e(be,*te);
                insere_texto_e(copia_be,*te);
                
                te=inicia_texto_e();
            }
            free(palavra);
        }
    
        if(respostas_menu[0]==2 &&respostas_menu[1]==4){
            FLVazia_palavra(&pd);
            FLVazia_texto(&td);
            FLVazia_bbt(&bd);
            FLVazia_bbt(&copia_bd);
            int tam_bbt,j;
            int resposta,x,k;
            char *palavra = (char*) malloc(tam2 * sizeof(char));
            srand(time(NULL));
            printf("Digite (1) para 100 e (2) para 100000 quantidade de textos que deseja inserir na biblioteca:");
            scanf("%d",&tam_bbt);
            if(tam_bbt==1){
                tam_bbt=100;
                printf("Digite (1) para utilizar o intervalo de 1 a 100\ne  (2) para para utilizar o interavalo de 50000 a 100000 palavras(zero para preencher um novo texto)...\n");
                scanf("%d", &resposta);
                if(resposta==1){
                    max=100;
                    min=1;
                }
                else{
                    min=50000;
                    max=100000;
                }
            }
            else{
                tam_bbt=100000;
                printf("Digite (1) para utilizar o intervalo de 1 a 100\ne  (2) para para utilizar o interavalo de 50000 a 100000 (zero para preencher um novo texto)...\n");
                scanf("%d", &resposta);
                if(resposta==1){
                    max=100;
                    min=1;
                }
                else{
                    min=50000;
                    max=100000;
                }
            }
            for(j=0;j<tam_bbt;j++){
                resposta=RandomTam(max,min);
                for(x = 0; x < resposta; x++){
                    RandomWord(tam2 - 1, palavra);
                    for(k=0;k<strlen(palavra);k++){
                        Insere_letra(palavra[k],&pd);
                    }            
                    Insere_plv(pd,&td,palavra[0]); 
                    // limpa as estruturas  
                    FLVazia_palavra(&pd);  
                } 
                Insere_txt(td,&bd);
                Insere_txt(td,&copia_bd);
                FLVazia_texto(&td);
            }
            free(palavra);
        }
        //------------------TERCEIRA ETAPA MENU ESCOLHA DO ALGORITMO DE ORDENAÇÃO-------------
        if(respostas_menu[1]==3){
            print_menu3_estatico();
            scanf("%d",&respostas_menu[2]);
        }
        if(respostas_menu[1]==4){
            print_menu3_dinamico();
            scanf("%d",&respostas_menu[2]);
        }
        //---------------ordenações estáticas------------------------------------
        if(respostas_menu[0]==1 && respostas_menu[1]==3 && respostas_menu[2]==5){
            //select sort texto estático
            inicio=clock(); 
            select_sort(copia,1);
            fim=clock(); 
   
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==3 && respostas_menu[2]==6){
            //quick sort texto estático
            inicio=clock();
            QuickSort(copia,copia->tam,1);
            fim=clock(); 
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==3 && respostas_menu[2]==7){
            //Merge sort texto estático
            inicio=clock();
            mergeSort(copia,0,copia->tam-1,1);
            fim=clock();
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==3 && respostas_menu[2]==8){
            //Heap sort texto estático
            inicio=clock();
            heapSort(copia,copia->tam,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==3 && respostas_menu[2]==5){
            //select sort bbt estático
            inicio=clock();
            select_sort_vetor_bbt(copia_be,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==3 && respostas_menu[2]==6){
            //quick sort bbt estático
            inicio=clock();
            QuickSort_bbt(copia_be,copia_be->quantidade,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==3 && respostas_menu[2]==7){
            //Merge sort bbt estático
            inicio=clock();
            mergeSort_bbt(copia_be,0,copia_be->quantidade-1,1);
            fim=clock();   
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==3 && respostas_menu[2]==8){
            //Heap sort bbt estático
            inicio=clock(); 
            heapSort_bbt(copia_be,copia_be->quantidade,1);
            fim=clock(); 
        }
        
        //---------------------ordenações dinamica-------------------------------
        if(respostas_menu[0]==1 && respostas_menu[1]==4 && respostas_menu[2]==5){
            //select sort texto dinamico
            inicio=clock();
            select_sort_Dinamico(copia_td,1);
            fim=clock();
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==4 && respostas_menu[2]==6){
            //quick sort texto dinamico
            inicio=clock();
            copia_td.Primeiro=QuickSort_Dinamico(copia_td.Primeiro,1);
            fim=clock();
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==4 && respostas_menu[2]==7){
            //Merge sort texto dinamico 
            inicio=clock();
            MergeSort(&copia_td.Primeiro,1);
            fim=clock();
        }
        if(respostas_menu[0]==1 && respostas_menu[1]==4 && respostas_menu[2]==8){
            //insert sort texto dinamico
            inicio=clock();
            insertionSort(&copia_td.Primeiro,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==4 && respostas_menu[2]==5){
            //select sort bbt dinamica
            inicio=clock();
            select_sort_lista_bbt(copia_bd,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==4 && respostas_menu[2]==6){
            //quick sort bbt dinamica
            inicio=clock();
            copia_bd.Primeiro=QuickSort_Dinamico_bbt(copia_bd.Primeiro,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==4 && respostas_menu[2]==7){
            //Merge sort bbt dinamica 
            inicio=clock();
            MergeSort_bbt(&copia_bd.Primeiro,1);
            fim=clock();
        }
        if(respostas_menu[0]==2 && respostas_menu[1]==4 && respostas_menu[2]==8){
            //Insert sort bbt dinamica
            inicio=clock();
            insertionSort_bbt(&copia_bd.Primeiro,1);
            fim=clock();
        }
        //------------QUARTA E ÚLTIMA ETAPA DO MENU IMPRESSÃO DOS TADS ORDENADOS OU TEXTO GASTO PARA ORDENAÇÃO--------------
        print_menu4();
        scanf("%d",&respostas_menu[3]);
        if(respostas_menu[3]==9 && respostas_menu[0]==1&&respostas_menu[1]==3){
            printf("\nAntes da Ordenação\n\n");
            imprime_palavra_e(te);
            printf("\n\nDepois da Ordenação\n\n");
            imprime_palavra_e(copia);
            printf("\n\n");
        }
        if(respostas_menu[3]==9 && respostas_menu[0]==1&&respostas_menu[1]==4){
            printf("\nAntes da Ordenação\n\n");
            Imprime_plv(td);
            printf("\n\nDepois da Ordenação\n\n");
            Imprime_plv(copia_td);
             printf("\n\n");
        }
        if(respostas_menu[3]==9 && respostas_menu[0]==2&&respostas_menu[1]==3){
            printf("\nAntes da Ordenação\n\n");
            imprime_texto_e(be);
            printf("\n\nDepois da Ordenação\n\n");
            imprime_texto_e(copia_be);
            printf("\n\n");
        }
        if(respostas_menu[3]==9 && respostas_menu[0]==2&&respostas_menu[1]==4){
            printf("\nAntes da Ordenação\n\n");
            Imprime_txt(bd);
            printf("\n\nDepois da Ordenação\n\n");
            Imprime_txt(copia_bd);
            printf("\n\n");
        }
        tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
        if(respostas_menu[3]==10){
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
        if(respostas_menu[0]==0||respostas_menu[1]==0||respostas_menu[2]==0||respostas_menu[3]==0)
            break;
    } while(respostas_menu[0]!=0||respostas_menu[1]!=0||respostas_menu[2]!=0||respostas_menu[3]!=0);
}


void RandomWord(int max_tam, char *palavra){
    int x, maiusculo, tam_rand;
    char letra;

    tam_rand = rand() % (max_tam - 1);
    tam_rand++;

    for(x = 0; x < tam_rand; x++){
        maiusculo = rand() % 2;
        
        if(maiusculo){
            letra = rand() % 26;
            letra += 65;
        }
        else{
            letra = rand() % 26;
            letra += 97;
        }

        palavra[x] = letra;
    }
    palavra[x] = '\0';
}

int RandomTam(int max,int min){
    int x=(rand()%max)+(+min);
    return x;
}


//--------------------------------PRINTS DO MENU-------------------------------------------------------------
void print_menu1(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 30; i++){
        fputs(" ", stdout);
    }
    printf("Digite (1)  para utilizar o TAD Texto (2) para utilizar o TAD Biblioteca.");
    for (i = 0; i < 49; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }   
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void print_menu2(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (3) para utilizar Vetor como implementação e  (4) para utilizar Lista Encadeada como implementação");
    for (i = 0; i < 26; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }   
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void print_menu3_estatico(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (5) para utilizar Select Sort como Algoritmo de Ordenação  e (6) para utilizar Quick Sort como Algoritmo de Ordenação");
    for (i = 0; i < 7; i++){
        fputs(" ", stdout);
    } 
    printf("|");
    printf("\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (7) para utilizar Merge Sort como Algoritmo de Ordenação  e (8) para utilizar Heap Sort como Algoritmo de Ordenação");
    for (i = 0; i < 9; i++){
        fputs(" ", stdout);
    } 
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }   
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void print_menu3_dinamico(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (5) para utilizar Select Sort como Algoritmo de Ordenação  e (6) para utilizar Quick Sort como Algoritmo de Ordenação");
    for (i = 0; i < 7; i++){
        fputs(" ", stdout);
    } 
    printf("|");
    printf("\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (7) para utilizar Merge Sort como Algoritmo de Ordenação  e (8) para utilizar Insert Sort como Algoritmo de Ordenação");
    for (i = 0; i < 7; i++){
        fputs(" ", stdout);
    } 
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }   
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
}

void print_menu4(){
    int i;
    fputs(" ", stdout);
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 80; i++){
        fputs(" ", stdout);
    }
    printf("MENU");
    for (i = 0; i < 79; i++){
        fputs(" ", stdout);
    }
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|\n|");
    for (i = 0; i < 163; i++){
        fputs(" ", stdout);
    }
    printf("|\n|           ");
    for (i = 0; i < 21; i++){
        fputs(" ", stdout);
    }
    printf("Digite (9) para  imprimir os itens antes e depois de ordenados  e (10) para imprimir o tempo gasto de execução das ordenações");
    for (i = 0; i < 6; i++){
        fputs(" ", stdout);
    }   
    printf("|");
    printf("\n");
    printf("|");
    for (i = 0; i < 42; i++){
        fputs(" ", stdout);
    }   
    printf("  e Qualquer número diferente dos anteriores para fechar o programa.");
    for (i = 0; i < 53; i++){
        fputs(" ", stdout);
    }
    printf("|\n");
    printf("|");
    for (i = 0; i < 163; i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n");
    printf("------------->");
    fflush(stdin);
} 