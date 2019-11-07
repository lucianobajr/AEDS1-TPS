#include "celula.h"    
#include <stddef.h>
// a matriz tipo matriz de fato sera criada no main 
void inicializa_matriz(tipo_matriz *ptr_matriz){ 
    
    int linhas,colunas,i,j;   
    int valor_celula_cabeca; 
    

    ptr_matriz->celula_cabeca = (tipo_celula*)malloc(sizeof(tipo_celula)); 
    linhas = ptr_matriz -> qtL; 
    colunas = ptr_matriz -> qtC; 
    apontador aux ; // usado no ponteiro matriz 
    
    // cria a celula cabeça  
    valor_celula_cabeca = -1 ; // mudei de aux para valor da celula cabeca pq aux é uma variavel do tipo ponteiro e preciso so de um inteiro nesse caso 
    ptr_matriz -> celula_cabeca->linha = valor_celula_cabeca; 
    ptr_matriz -> celula_cabeca->coluna = valor_celula_cabeca; 
    // os parametros abaixo e direita são iguais  e nulos 
    // ptr_matriz é um conjunto de celulas que serão usados para inserir itens 
    ptr_matriz -> col_primeiro-> abaixo =NULL ;  
    aux = ptr_matriz -> col_primeiro -> abaixo;      
    ptr_matriz -> lin_primeiro->direita = aux ; 

    for(i = 0 ; i< linhas ; i++){ 
        for(j = 0 ; j < colunas ; j++){ 
            ptr_matriz -> lin_primeiro = (tipo_celula*)malloc(sizeof(tipo_celula)); 
            ptr_matriz -> col_primeiro = ptr_matriz -> lin_primeiro  ; /**/ 
            ptr_matriz -> lin_primeiro->item.p_item_primeiro = NULL; // deixa  nulo os campos de itens para o lin_primeiro e col_primeiro  
            ptr_matriz -> col_primeiro->item.p_item_primeiro = NULL ;    
            //isso vai tornar as listas circulares toda vez q ela atingir  
            //o valor da coluna -1 (pq o for comeca em 0 ) ela retorna pra celula cabeca que é -1


            // isso vai no insere matriz por que precisa ser posto continuamente enquanto a matriz rodar e tiver elementos sendo inseridos deve
            
        }
    }
}   
// as funçoes da celula_cabeca_linha e celula_cabeca_coluna que vão nos ajudar a colocar os itens no lugar  
// e criar a matriz esparsa  
// pq no insere vai ser criada uma variavel celula onde vao tá os campos da celula principalmente suas coordenadas  
// dai esses campos serao passados por referencia para a funcao celula_cabeca_linha/ coluna para que elas possam se 
// conectar a essas celulas 
// o erro do insere esta em não criar uma celula 
// alem do item  que vai ser inserido em uma  celula  
// é necessario criar um celula do tipo_celula na funcao insere 
void celula_cabeca_linha(tipo_matriz *ptr_matriz, tipo_celula *ptr_celula){ 
    apontador celula_cabeca ; 
    ptr_matriz -> celula_cabeca->coluna = -1 ; 
    int i;
    int linha = ptr_matriz -> qtL; 
    ptr_matriz -> celula_cabeca->item   = ptr_celula -> item ;
    for(i = 0 ; i < linha; i++){   
        ptr_matriz -> celula_cabeca->linha = i ;   
        if(ptr_celula -> linha == i ){  
            ptr_matriz-> celula_cabeca->direita = ptr_celula -> linha ;
            ptr_matriz -> lin_primeiro = ptr_matriz ->  celula_cabeca ; 


        }  


        // passa as coordenadas da celula com o item inseridos na funcao insere que essa parte da celula cabeca vai se conectar a ela 
        // em aberto precisa terminar 
    }

}
void celula_cabeca_coluna(tipo_matriz *ptr_matriz , tipo_celula *ptr_celula){  
    ptr_matriz -> celula_cabeca->linha = -1 ;  
    ptr_matriz ->celula_cabeca->item   = ptr_celula -> item ;
    int coluna = ptr_matriz -> qtC; 
    for(int i = 0 ; i< coluna;i++ ){ 
        ptr_matriz ->celula_cabeca->coluna = i; 
        if(ptr_celula -> coluna == i ){  
            ptr_matriz ->celula_cabeca->abaixo = ptr_celula -> coluna;
            ptr_matriz -> col_primeiro = ptr_matriz -> celula_cabeca ; 
        } 
         
    }
}      


void insere_itens_matriz(tipo_matriz *ptr_matriz, int coordenada_linha , int coordenada_coluna, lista_item *itens){
   // cria lista
    int i,j,aux,linha,coluna;
    linha=ptr_matriz->qtL;
    coluna=ptr_matriz->qtC; 
    
    ptr_matriz->lin_primeiro->linha=1;
    ptr_matriz->col_primeiro->coluna=1; 
    
    tipo_celula *nova_celula; // criei uma celula pq o item será inserido dentro da celula repara que criei ponteiro pq a matriz ja está criada com as celulas  
    nova_celula -> coluna = coordenada_coluna; // preenchendo a celula da matriz 
    nova_celula -> linha = coordenada_linha ; 
    nova_celula -> item  = *itens; 
    celula_cabeca_linha(&ptr_matriz,&nova_celula);  
    celula_cabeca_coluna(&ptr_matriz,&nova_celula);  

   
 //aqui  adicionamos os items olhar o endereço de &aux_item pq n sei se é nele que se encontram nossos itens tem se ele é do tipo*
    // de onde é esse aux_item? 
}       

void le_matriz(tipo_matriz *ptr_matriz){  
    // inicializa matriz lendo o arquivo     
    lista_item itens ; 
    tipo_item *ptr_item; 
    int aux_quantidade;   
     // cria uma lista , precisamos de uma lista ao invés de um tipo_item  
    // na verdade é valido criar uma lista com celulas  
    int i,*aux_resposta,k;
    int int_linhas,int_colunas; 
    int contador=0;
    char aux_data[11],nome[100],*p_frase,frase[100] ;
    FILE *arquivo ;

    fputs(" ", stdout);
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("\n|");
    for(i=0;i<163;i++){
        fputs(" ", stdout);
    }
    printf("|\n|  ");
    printf("Digite o nome do arquivo para o caso de teste (Na mesma pasta e sem .txt)");
    for(i=0;i<88;i++){
        fputs(" ", stdout);
    }
    printf("|"); 
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|");
    printf("\n--->");
    setbuf(stdin,NULL);
    fgets(nome,100,stdin);
    i=0;
    while(nome[i]!='\n'){
        i++;
    }
    nome[i]='.';
    nome[i+1]='t';
    nome[i+2]='x';
    nome[i+3]='t';
    nome[i+4]='\0';
    arquivo =fopen(nome,"a");//caso não exista cria
    fprintf(arquivo,"\n0");
    fclose(arquivo);
    arquivo == fopen(nome,"r");
        
    if( arquivo == NULL){ 
        printf("Arquivo não foi aberto"); 
        return 0;
    } 
    //ler antes do while linha e coluna da matriz
    //gerar as cabeças da matriz

    fscanf(arquivo,"%d %d",&int_linhas,&int_colunas);  

    ptr_matriz->qtL = int_linhas; 
    ptr_matriz->qtC = int_colunas;
    inicializa_matriz(&ptr_matriz);

    while(arquivo!=EOF){        
        fgets(&frase,sizeof(frase),arquivo);
        while(frase!=NULL){ 
            while(frase!=NULL){
                p_frase = strtok(frase," ");
                if(contador == 0){ 
                    int_linhas = (int*)p_frase;
                } 
                else if(contador == 1 ){
                    int_colunas= (int*)p_frase;
                } 
                if(contador%2 == 0 && contador != 0){ 
                    strcpy(aux_data,p_frase);
                }else if(contador%2 != 0 && contador != 1 ){ 
                    aux_quantidade = (int*)p_frase;
                }    
                contador++; 
                p_frase=(NULL," ");    
            }
            strcpy(aux_data,ptr_item->data);
            ptr_item->quantidade=aux_quantidade; 
            insere_lista_item(&itens,&ptr_item);
            fgets(&p_frase,sizeof(p_frase),arquivo);     
            insere_itens_matriz(&ptr_matriz,  int_linhas ,  int_colunas, &itens);
        }
    }
}


void quantidadeComprasPorProduto(tipo_matriz *ptr_matriz){ 
    int produtos = 0 ; 
    int produto ; 
    produto = ptr_matriz -> lin_primeiro -> coluna;  
    ptr_matriz -> lin_primeiro -> item.count_produto;  
    printf("A quantidade de Compras do produto %d foi de : %d ",produto, produtos);
    menu(&ptr_matriz);
} 
void  quantidadeComprasPorCliente(tipo_matriz *ptr_matriz){
    int clientes = 0;   
    int cliente; 
    cliente = ptr_matriz -> lin_primeiro -> linha ;
    ptr_matriz -> lin_primeiro -> item.count_cliente;
    printf("A quantidade de Compras pelo cliente %d foi de : %d ",cliente, clientes);
    menu(&ptr_matriz);
} 

void imprimeMatriz(tipo_matriz *ptr_matriz){
    int i,j,k,quantidade_espaco,coluna,linha,resposta,aux_coo_linha,aux_coo_coluna;
    apontador pAux_lin , pAux_col;
    linha=ptr_matriz->qtL;
    coluna=ptr_matriz->qtC;
    quantidade_espaco=(150-coluna)/2.0 -coluna;
    printf("        |A matriz abaixo possui algarismos (1) para posições em que há listas encadeadas e algarismos (0) para posições que se encontram vazias|\n"        );
    printf("\n\n");
  
    ptr_matriz->celula_cabeca->linha=ptr_matriz->lin_primeiro;
    // apontadoores auxiliares para linha e coluna 
    pAux_lin = ptr_matriz-> lin_primeiro ; 
    pAux_col = ptr_matriz-> col_primeiro ;  
  
    for(i=0;i<linha;i++){
        for(k=0;k<quantidade_espaco;k++){
            fputs(" ", stdout);
        }
        ptr_matriz->celula_cabeca->coluna=ptr_matriz->col_primeiro;
        for(j=0;j<coluna;j++){
            printf("|");
            if(j==ptr_matriz->celula_cabeca->coluna){//onde possui lista encadeada
                printf("1");
            }else{
                printf("0");
            }
            printf("|");
            ptr_matriz->celula_cabeca->direita;
        }
        ptr_matriz->celula_cabeca->abaixo;
        printf("\n");
    } 
    printf("        |Digite (1) para acessar uma lista encadeada e (0) para sair:\n");
    scanf("%d",&resposta); 
    // corrigi algumas coisas 

    if(resposta==1){
        printf("Digite as coordenadas(Posição de linha e coluna) da lista encadeada desejada:\n");
        scanf("%d %d",&aux_coo_linha,&aux_coo_coluna);
        pAux_col-> coluna=aux_coo_coluna;
        pAux_lin-> linha=aux_coo_linha;

        while(pAux_col !=NULL && pAux_lin!= NULL){ 
            // apenas imprimira se forem iguais linha e coluna e enquanto não for nulo 
            if(pAux_col->item.p_item_ultimo == pAux_lin->item.p_item_ultimo){
            printf("%d\n",pAux_lin->item.p_item_ultimo->data);
            printf("%d\n",pAux_lin->item.p_item_ultimo->quantidade);
            pAux_lin=pAux_lin->direita;//proxima celula , direita pois está mexendo com paux de linha 
            }
         }
    }else{
        menu(&ptr_matriz);
    }
} 


void menu(tipo_matriz *ptr_matriz){
    int i,*aux_resposta;
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
    printf("|\n|  ");
    printf("Digite (1) para Imprimir a matriz (2) para Imprimir a quantidade de produtos que cada cliente comprou (3) para Imprimir a soma total de compras por produto      |");
    printf("\n");
    printf("|");
    for(i=0;i<163;i++){
        fputs("_", stdout);
    }
    printf("|");
    scanf("%d",aux_resposta);
    if(&aux_resposta==1){
        imprimeMatriz(&ptr_matriz);
    }
    if(&aux_resposta==2){
        quantidadeComprasPorCliente(&ptr_matriz);
    }
    if(&aux_resposta==3){
        quantidadeComprasPorProduto(&ptr_matriz);
    }
    if(&aux_resposta!=1||&aux_resposta!=2||&aux_resposta!=3){
        exit(0);    
    }
} 
//
