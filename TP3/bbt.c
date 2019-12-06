#include "bbt.h"
//----------------BBT ESTÁTICA-----------------------
bbt_e* inicia_bbt_e(){
    bbt_e *be;
    be=(bbt_e*)malloc(sizeof(bbt_e));
    if(be!=NULL){
        be->inicio=0;
        be->final=0;
        be->quantidade=0;
    }
    return be;
}

int insere_texto_e(bbt_e *be, texto_e te){
    if(be==NULL){
        return 0;
    }  
    be->textos[be->final]=te;
    be->final++; 
    be->quantidade++;
}

void imprime_texto_e(bbt_e *be){
    int i=0,j=0,k=0; 
    printf("biblioteca estatica\n");
    for(i=0;i<be->quantidade;i++){
        imprime_palavra_e(&be->textos[i]);
        printf("\n");
    }
}

int remove_texto_e(bbt_e *be){
    be->final--;
    be->quantidade--;    
}
int tam_bbt_e(bbt_e *be){
    return be->quantidade;
}

//----------------BBT DINÂMICA-----------------------
void FLVazia_bbt(biblioteca *bbt){
    bbt->Primeiro=(TiApontador)malloc(sizeof(TiCelula));
    bbt->quantidade=0;
    bbt->Primeiro->Ant=NULL;
    bbt->Ultimo=bbt->Primeiro;
}
void Insere_txt(texto x, biblioteca *bbt){
    
    bbt->Ultimo->Prox=(TiApontador)malloc(sizeof(TiCelula));
    bbt->Ultimo->Prox->textos=x; 
     
    bbt->Ultimo->Ant=bbt->Ultimo;
    bbt->Ultimo->Prox->Prox=NULL;
    bbt->Ultimo=bbt->Ultimo->Prox;  
    bbt->quantidade++;
    // armazena a quantidade de palavras no texto 
}

void Imprime_txt(biblioteca bbt){
    TiApontador Aux; 
    printf("biblioteca dinamica\n");
    Aux=bbt.Primeiro->Prox;
    while(Aux!=NULL){
        Imprime_plv(Aux->textos);
        printf("\n");
        Aux=Aux->Prox;
    }
} 

int tamanho_bbt(TiCelula *lista_bbt){ 
    int contador = 0 ; 
    for(;lista_bbt != NULL ; lista_bbt = lista_bbt->Prox){ 
        contador++; 
    } 
    return contador; 
}

int Remove_txt(biblioteca bbt){
    TiCelula *aux;
     if(bbt.quantidade==0){
       return 0;
   }
   else{
       aux=bbt.Ultimo;
       bbt.Ultimo=bbt.Ultimo->Prox;
       bbt.Ultimo->Prox=NULL;
       free(aux);
       bbt.quantidade--;
   }     
}


//-----------------ORDENAÇÕES-------------------------

//-----------------ESTÁTICO---------------------------

/* -----------esse return varia para cada celula------------
-----operações de ordenação   
-----a chave da orenação da bbt é o tamanho do texto 
-----ou seja o maior texto ficará no fim  
-----ordenações estáticas*/ 
void select_sort_vetor_bbt(bbt_e *ptr_bbt_estatica,int flag){ 
    int i, j,min;
    double comp=0,mov=0;
    int n= ptr_bbt_estatica->quantidade ;
    texto_e aux;
    for(i = 0; i< n-1 ;i++){
        min = i;
        for (j = i + 1; j < n ; j++){
            comp++;
            if(ptr_bbt_estatica->textos[j].tam < ptr_bbt_estatica->textos[min].tam){ 
                min = j ;  
            } 
        }
        mov++;
        aux = ptr_bbt_estatica->textos[min];
        ptr_bbt_estatica->textos[min]= ptr_bbt_estatica->textos[i];
        ptr_bbt_estatica->textos[i] = aux;
    }
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);

    }
}

void  QuickSort_bbt(bbt_e *be,int n,int flag){
    double comp=0,mov=0;
    ordena_bbt(0,n-1,be,&comp,&mov);

    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
}

void ordena_bbt(int left, int right,bbt_e *be,double* comp,double* mov){
    int i,j;
    particao_bbt(left,right,&i,&j,be,comp,mov);
    (*comp)++;
    if(left<j) ordena_bbt(left,j,be,comp,mov);
    (*comp)++; 
    if(i<right) ordena_bbt(i,right,be,comp,mov);
}

void particao_bbt(int left,int right,int *i,int *j,bbt_e *be,double* comp,double* mov){
     *i =left;
     *j=right;
    texto_e pivot =be->textos[(*i + *j)/2];
    texto_e aux;
    do{
         (*comp)++;
        while(pivot.tam > be->textos[*i].tam ){
             (*i)++;
            (*comp)++;
        }
       
        while(pivot.tam < be->textos[*j].tam){
            (*j)--;
            (*comp)++;
        }  
        (*comp)++;
        if(*i <= *j){
            (*mov)++;
            aux = be->textos[*i]; 
            be->textos[*i] = be->textos[*j]; 
            be->textos[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
}

void merge_bbt(bbt_e *be, int l, int m, int r,double *comp,double *mov,int flag) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* cria vetores temporários */
    texto_e L[n1], R[n2]; 
  
    /* copia os dados para os vetores  L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = be->textos[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = be->textos[m + 1+ j]; 
  
    /* Mesclar as matrizes temporárias novamente te[l..r]*/
    i = 0; // index inicial do primeiro subvetor 
    j = 0; // index inicial do segundo subvetor 
    k = l; // index inicial do terceiro subvetor 
    while (i < n1 && j < n2) {  
	(*comp)++; 
        if (L[i].tam <= R[j].tam) {
	    (*mov)++;	
            be->textos[k] = L[i]; 
            i++; 
        } 
        else{ 
	    (*mov)++;
            be->textos[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copia os elementos restantes de L [],se houver algum*/
    while (i < n1) { 
	(*mov)++;
        be->textos[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia os elementos restantes de R [],se houver algum*/
    while (j < n2) { 
	(*mov)++;
        be->textos[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l é para o índice esquerdo e r é o índice direito do subvetor de te[] a ser classificado*/
void mergeSort_bbt(bbt_e *be, int l, int r,int flag) { 
    double comp=0,mov=0;
    if (l < r) { 
        // Igual a (l + r) / 2, mas evita o excesso de
        // amplia l e h 
        int m = l+(r-l)/2; 
  
        // Classificar primeira e segunda metades
        mergeSort_bbt(be, l, m,0); 
        mergeSort_bbt(be, m+1, r,0); 
  
        merge_bbt(be, l, m, r,&comp,&mov,0); 
   } 
   if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
   }	
} 
void buildMaxHeap_bbt(bbt_e *be, int n, double *comp , double *mov)  {  
    for (int i = 1; i < n; i++)  { 
        // se o filho for maior que o pai
        if (be->textos[i].tam > be->textos[(i - 1) / 2].tam)  { 
            int j = i; 
      
            // se o filho for maior que o pai 
            while (be->textos[j].tam > be->textos[(j - 1) / 2].tam)  { 
                (*comp)++; 
                texto_e aux=be->textos[j];
                be->textos[j]=be->textos[(j - 1) / 2];
                be->textos[(j - 1) / 2]=aux;
                j = (j - 1) / 2; 
                (*mov)++;   
            } 
        } 
    } 
} 
  
void heapSort_bbt(bbt_e *be, int n, int flag)  { 
    double comp = 0 , mov = 0 ;
    buildMaxHeap_bbt(be, n, &comp ,  &mov); 
  
    for (int i = n - 1; i > 0; i--) { 
        // valor de swap do primeiro indexado com o último indexado     
        mov++; 
        texto_e aux =be->textos[0];
        be->textos[0]=be->textos[i];
        be->textos[i]=aux; 
      
        // valor de swap do primeiro indexado com o último indexado  
        int j = 0, index; 
          
        do
        { 
            index = (2 * j + 1); 
              
            //se filho esquerdo for menor que a variável de índice de ponto filho direito para filho direito
            comp++; 
            if (be->textos[index].tam < be->textos[index + 1].tam && index < (i - 1)) 
                index++; 
          
            // se pai for menor que filho, troque pai por filho com valor mais alto 
            comp++; 
            if (be->textos[j].tam < be->textos[index].tam && index < i){             
                mov++; 
                texto_e aux =be->textos[j];
                be->textos[j]=be->textos[index];
                be->textos[index]=aux; 
            }
            j = index; 
          
        } while (index < i); 
    }  
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
} 

//------------------------DINÂMICO-------------------------------------------------------

void select_sort_lista_bbt(biblioteca bbt_dinamica,int flag){ 
     //celulas no estilo da bbt 
     TiCelula *a, *b, *c, *d, *r; 
     double comp=0,mov=0;
    a = b = bbt_dinamica.Primeiro; 
    // While  b não é a última célula
    while (b->Prox) { 
        c = d = b->Prox; 
        // While d está apontando para um célula válida
        while (d) { 
            comp++;
            if (b->textos.qtd_palavra > d->textos.qtd_palavra) { 
                // Se d aparecer imediatamente após b
                if (b->textos.qtd_palavra == d->textos.qtd_palavra) { 
                    // Caso 1: b é a cabeça da lista encadeada
                    if (b == bbt_dinamica.Primeiro) { 
                        // Move d antes b 
                        b->Prox = d->Prox; 
                        d->Prox = b; 

                        // troca os ponteiros b de d
                        mov++;  
                        r = b; 
                        b = d; 
                        d = r; 
                        c = d; 

                        // att a célula 
                        bbt_dinamica.Primeiro = b; 
  
                        // Passar para o próximo elemento
                        // como já está em ordem
                        d = d->Prox; 
                    } 
                    // Case 2: b não é o cabeça da lista encadeada
                    else { 
                        // Move d antes de  b 
                        b->Prox = d->Prox; 
                        d->Prox = b; 
                        a->Prox = d; 
                        // troca os ponteiros d e b 
                        mov++;
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 

                        //Passar para o próximo elemento
                        // como já está em ordem 
                        d = d->Prox; 
                    } 
                }  
                // Se b e d tiverem valores diferentes de zero
                // número de nós entre eles
                else { 
                    // Caso 3: b é a cabeça da lista encadeada
                    if (b == bbt_dinamica.Primeiro) { 
                        // troca b->Prox e d->Prox 
                        r = b->Prox; 
                        b->Prox = d->Prox; 
                        d->Prox = r; 
                        c->Prox = b; 
  
                        // Troca os ponteiros de b e d  
                        mov++;
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
  
                        // Passar para o próximo elemento
                        // como já está em ordem 
                        d = d->Prox; 
  
                        // Update the head 
                        bbt_dinamica.Primeiro = b; 
                    } 
                    // Case 4: b não é a cabeça da lista encadeada
                    else { 
                        // troca b->Prox e d->Prox 
                        r = b->Prox; 
                        b->Prox = d->Prox; 
                        d->Prox = r; 
                        c->Prox = b; 
                        a->Prox = d; 
  
                        // Troca os ponteiros de b e d   
                        mov++;
                        r = b; 
                        b = d; 
                        d = r; 
  
                        c = d; 
                        // Passar para o próximo elemento
                        // como já está em ordem 
                        d = d->Prox; 
                    } 
                }     
            } 
            else { 
                // Passar para o próximo elemento
                // como já está em ordem
                c = d; 
                d = d->Prox; 
            } 
        } 
        a = b; 
        b = b->Prox; 
    }  
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
} 

TiCelula *pivo_aleatorio_QsD_bbt(TiCelula *bbt_celula_cabeca){ 
    int tam_lista = tamanho_bbt(bbt_celula_cabeca);
	int posicao_pivo = rand() % tam_lista; 

	for (int count = 0; count < posicao_pivo; count++){
		bbt_celula_cabeca = bbt_celula_cabeca->Prox;
	}
	return bbt_celula_cabeca;
    //encontra a celula que será o pivô na lista
}
TiCelula * ultima_celula_QsD_bbt(TiCelula *bbt_celula_atual){ 
     for (; bbt_celula_atual->Prox != NULL; bbt_celula_atual = bbt_celula_atual->Prox);
	return bbt_celula_atual;
}
TiCelula * junta_QsD_bbt(TiCelula* bbt_lista_esquerda, TiCelula * pivo, TiCelula * bbt_lista_direita){ 
    pivo->Prox = bbt_lista_direita;

	if (bbt_lista_esquerda == NULL)	return pivo;

	TiCelula * ultimo_esquerda = ultima_celula_QsD_bbt(bbt_lista_esquerda);
	ultimo_esquerda->Prox = pivo;

	return bbt_lista_esquerda;
}
TiCelula* QuickSort_Dinamico_bbt(TiCelula * bbt_lista,int flag){ 
    if(bbt_lista == NULL || bbt_lista->Prox == NULL ) return bbt_lista ;
    double comp=0,mov=0;
    TiCelula *pivo = pivo_aleatorio_QsD_bbt(bbt_lista);

	TiCelula *lista_sub_esquerda = NULL, *lista_sub_direita = NULL;

	for (TiCelula * celula_atual = bbt_lista; celula_atual != NULL;){
		TiCelula * prox_celula = celula_atual->Prox;
        comp++;
		if (celula_atual != pivo){
			if (celula_atual->textos.qtd_palavra <= pivo->textos.qtd_palavra){
                mov++;
				celula_atual->Prox = lista_sub_esquerda;
				lista_sub_esquerda = celula_atual;
			}
			else{
                mov++;
				celula_atual->Prox = lista_sub_direita;
				lista_sub_direita =celula_atual;
			}
		}
		celula_atual = prox_celula;
	}
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
	return junta_QsD_bbt(QuickSort_Dinamico_bbt(lista_sub_esquerda,0), pivo, QuickSort_Dinamico_bbt(lista_sub_direita,0));

 }

void MergeSort_bbt(TiCelula** referencia_cabeca,int flag) { 
    TiCelula* cabeca = * referencia_cabeca; 
    TiCelula* a; 
    TiCelula* b; 
    double comp=0,mov=0;
  
    /* Caso Básico-- tamanho 0 ou 1 */
    if ((cabeca == NULL) || (cabeca->Prox == NULL)) { 
        return; 
    } 
  
    /* Divida a cabeça em sublistas 'a' e 'b' */
    divide_frente_tras_bbt(cabeca, &a, &b); 
  
    /* Classificar recursivamente os sublistas */
    MergeSort_bbt(&a,0); 
    MergeSort_bbt(&b,0); 
  
    /*mescla as duas listas ordenadas */
    * referencia_cabeca = Classifica_Merge_bbt(a, b,&comp,&mov,0); 
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }	
} 

TiCelula* Classifica_Merge_bbt(TiCelula* a, TiCelula* b,double *comp,double *mov,int flag) { 
    TiCelula* resultado = NULL; 
  
    /* Base dos casos */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Escolha a ou b e volte a */
   (*comp)++;
    if (a->textos.qtd_palavra <= b->textos.qtd_palavra) { 
	(*mov)++;   
        resultado = a; 
        resultado->Prox = Classifica_Merge_bbt(a->Prox, b,comp,mov,1); 
    } 
    else {
	(*mov)++;    
        resultado = b; 
        resultado->Prox = Classifica_Merge_bbt(a, b->Prox,comp,mov,1); 
    } 
    return (resultado); 
} 
  
/* FUNÇÕES DE UTILIDADE */
/* Divida os nós da lista em metades da frente e de trás,
   e retorne as duas listas usando os parâmetros de referência.
   Se o comprimento for ímpar, o nó extra deve estar na lista da frente.
   Usa a estratégia de ponteiro rápido / lento. */ 
void divide_frente_tras_bbt(TiCelula* fonte, TiCelula** referencia_frente, TiCelula** referencia_tras){ 
    TiCelula* rapido; 
    TiCelula* devagar; 
    devagar = fonte; 
    rapido = fonte->Prox; 
  
    /* Avance dois nós 'rápidos' e avance um nó 'lento' */
    while (rapido != NULL) { 
        rapido = rapido->Prox; 
        if (rapido != NULL) { 
            devagar = devagar->Prox; 
            rapido = rapido->Prox; 
        } 
    } 
  
    /*'slow' está antes do ponto médio da lista, então divida-o em dois nesse ponto. */
    *referencia_frente =fonte; 
    *referencia_tras = devagar->Prox; 
    devagar->Prox = NULL; 
} 

void insertionSort_bbt(TiCelula **celula_refencia, int flag) { 
    //inicia lista dinamica sorted 
    double comp = 0 , mov = 0 ; 
    TiCelula *sorted = NULL; 
  
    // Percorra a lista vinculada fornecida e insira todos os nós para classificar
    TiCelula *current = *celula_refencia; 
    while (current != NULL) 
    { 
        //Armazenar próximo para a próxima iteração
        TiCelula *prox = current->Prox; 
  
        // inserir corrente na lista vinculada classificada
        sortedInsert_bbt(&sorted, current,&comp , &mov); 
  
        // Atualizar atual 
        current = prox; 
    } 
  
    //Atualize head_ref para apontar para a lista vinculada classificada
    *celula_refencia = sorted;  
    if(flag){ 
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    } 
} 
  
/* para inserir um novo nó em uma lista. Observe que essa função 
espera um ponteiro para head_ref, pois isso pode modificar o cabeçalho 
da lista vinculada de entrada (semelhante a push ())*/
void sortedInsert_bbt(TiCelula **celula_refencia,TiCelula* novo_no, double *comp , double *mov) { 
    TiCelula* atual; 
    /* caso especial para o final da celula cabeca */
    if (*celula_refencia == NULL || (*celula_refencia)->textos.qtd_palavra >= novo_no->textos.qtd_palavra) { 
        (*comp)++;
        novo_no->Prox = *celula_refencia; 
        *celula_refencia = novo_no; 
    } 
    else
    { 
        /* Localize o nó antes do ponto de inserção */
        atual = *celula_refencia; 
        while (atual->Prox!=NULL && 
               atual->Prox->textos.qtd_palavra < novo_no->textos.qtd_palavra) 
        {   (*comp)++; 
            atual = atual->Prox; 
        }  
        (*mov)++; 
        novo_no->Prox = atual->Prox; 
        atual->Prox = novo_no; 
    } 
} 