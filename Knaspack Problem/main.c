 #include "comb.c"

int main() { 
    int r = 1,i;
    double tempo;
    clock_t fim,inicio;
    arquivo vetor;
    inicio=clock();
    insere(&vetor);
    //imprime(vetor.itens_arquivo,vetor.quantidade_arquivo);
    mochila dora;
    inicializaVetor(&dora,vetor.quantidade_arquivo,W);  
    for(i=0;i<vetor.quantidade_arquivo;i++){
        printf("combinação de tamanho %d\n",r);
        printCombination(vetor.itens_arquivo,&dora,vetor.quantidade_arquivo,r);
        r++;
    }
    fim=clock();
    tempo=((double)(fim-inicio))/CLOCKS_PER_SEC;
    imprime_mochila(&dora);
    printf("tempo gasto = %lf\n",tempo);
} 