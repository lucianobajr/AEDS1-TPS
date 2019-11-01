 #include "comb.c"

int main() { 
    int r = 1,i;
    arquivo vetor;
    insere(&vetor);
    imprime(vetor.itens_arquivo,vetor.quantidade_arquivo);
    mochila dora;
    inicializaVetor(&dora,vetor.quantidade_arquivo,W);  
    for(i=0;i<vetor.quantidade_arquivo;i++){
        printCombination(vetor.itens_arquivo,&dora,vetor.quantidade_arquivo,r);
        r++;
    }
    imprime_mochila(&dora);
} 