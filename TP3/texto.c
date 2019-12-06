#include "texto.h" 
//----------------TEXTO ESTÁTICO-----------------------
texto_e* inicia_texto_e(){
    texto_e *te;
    te=(texto_e*)malloc(sizeof(texto_e));
    if(te!=NULL){
        te->tam=0;
        te->inicio=0;
        te->final=0; 
        te->id_texto = 0 ; 
    }
    return te;
}

int  insere_palavra_e(texto_e *te,palavra_e pe){
    int i;
    if(te==NULL){
        return 0;
    }
    te->palavras[te->final]=pe;
    te->final++;
    te->tam++;
    te -> id_texto ++ ;  
}

void imprime_palavra_e(texto_e *te){
    int i,j; 
    printf("Texto (V) %d:  ",te->tam);
    for(i=0;i<te->tam;i++){
        imprime_letra_e(&te->palavras[i]);
        printf(" ");
    }
}
int tamanho_texto_estatico(texto_e *te){ 
    return te->tam ;
}

int remove_palavra_e(texto_e *te){
    te->final--;
    te->tam--;
}

//----------------TEXTO DINÂMICO-----------------------

void FLVazia_texto(texto *txt){
    txt->Primeiro=(TApontador)malloc(sizeof(TCelula));
    txt->Primeiro->Ant=NULL;
    txt->Ultimo=txt->Primeiro;
    txt->Ultimo->id_texto=0;
    txt->qtd_palavra=0;
}
void Insere_plv(palavra x, texto *txt,char frsle){
    int i;
    txt->Ultimo->Prox=(TApontador)malloc(sizeof(TCelula));
    txt->Ultimo->Prox->first_letter=frsle;
    txt->Ultimo->Prox->palavras=x;
    txt->Ultimo->Ant=txt->Ultimo;
    txt->Ultimo->Prox->Prox=NULL;
    txt->Ultimo=txt->Ultimo->Prox;
    txt->Ultimo->id_texto++;  
    txt->qtd_palavra++; 
}

void Imprime_plv(texto txt){
    TApontador Aux;
    Aux=txt.Primeiro->Prox;
    printf("Texto (L) %d : ",txt.qtd_palavra);
    while(Aux!=NULL){
        Imprime_letra(Aux->palavras);
        printf(" ");
        Aux=Aux->Prox;
    }
}

int tamanho_txt(texto txt){
    return txt.qtd_palavra;
}
int Retira_plv(texto txt){
    TCelula *aux;
     if(txt.qtd_palavra==0){
       return 0;
   }
   else{
       aux=txt.Ultimo;
       txt.Ultimo=txt.Ultimo->Prox;
       txt.Ultimo->Prox=NULL;
       free(aux);
       txt.qtd_palavra--;
   } 
}

//-----------------ORDENAÇÕES-------------------------

//-----------------ESTÁTICO---------------------------
void select_sort(texto_e *txt,int flag){
    int i, j,min;
    double comp=0,mov=0;
    int n=txt->tam;
    palavra_e aux;
    for(i = 0; i< n-1 ;i++){
        min = i;
        for (j = i + 1; j < n ; j++){
            comp++;
            if (txt->palavras[j].dados[0].letra < txt->palavras[min].dados[0].letra){
                min=j;        
            }
        } 
        mov++;
        aux = txt->palavras[min];
        txt->palavras[min]= txt->palavras[i];
        txt->palavras[i] = aux;
       
    }
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);

    }
}

void  QuickSort(texto_e *te,int n,int flag){
    double comp=0,mov=0;
    ordena(0,n-1,te,&comp,&mov);
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
}

void ordena(int left, int right,texto_e *te,double* comp,double* mov){
    int i,j;
    particao(left,right,&i,&j,te,comp,mov);
    (*comp)++;
    if(left<j) ordena(left,j,te,comp,mov);
    (*comp)++; 
    if(i<right) ordena(i,right,te,comp,mov);
}

void particao(int left,int right,int *i,int *j,texto_e *te,double* comp,double* mov){
     *i =left;
     *j=right;
    palavra_e pivot =te->palavras[(*i + *j)/2];
    palavra_e aux;
    do{
        (*comp)++;
        while(pivot.dados[0].letra > te->palavras[*i].dados[0].letra ){
            (*i)++;
            (*comp)++;
        } 
        while(pivot.dados[0].letra < te->palavras[*j].dados[0].letra){
            (*j)--;
            (*comp)++;
        }  
        (*comp)++;
        if(*i <= *j){
            (*mov)++;
            aux = te->palavras[*i]; 
            te->palavras[*i] = te->palavras[*j]; 
            te->palavras[*j] = aux;
            (*i)++; (*j)--;
        }
    }while(*i <= *j);
}

void merge(texto_e *te, int l, int m, int r,double *comp,double *mov,int flag) { 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* cria vetores temporários */
    palavra_e L[n1], R[n2]; 
  
    /* copia os dados para os vetores  L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = te->palavras[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = te->palavras[m + 1+ j]; 
  
    /* Mesclar as matrizes temporárias novamente te[l..r]*/
    i = 0; // index inicial do primeiro subvetor 
    j = 0; // index inicial do segundo subvetor 
    k = l; // index inicial do terceiro subvetor 
    while (i < n1 && j < n2) {
        (*comp)++; 
        if (L[i].dados[0].letra <= R[j].dados[0].letra) { 
            (*mov)++;
            te->palavras[k] = L[i]; 
            i++; 
        } 
        else{ 
            (*mov)++;
            te->palavras[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copia os elementos restantes de L [],se houver algum*/
    while (i < n1) { 
         (*mov)++;
        te->palavras[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copia os elementos restantes de R [],se houver algum*/
    while (j < n2) {
         (*mov)++; 
        te->palavras[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
/* l é para o índice esquerdo e r é o índice direito do subvetor de te[] a ser classificado*/
void mergeSort(texto_e *te, int l, int r,int flag) { 
    double comp=0,mov=0;
    if (l < r) { 
        // Igual a (l + r) / 2, mas evita o excesso de
        // amplia l e h 
        int m = l+(r-l)/2; 
  
        // Classificar primeira e segunda metades
        mergeSort(te, l, m,0); 
        mergeSort(te, m+1, r,0); 
  
        merge(te, l, m, r,&comp,&mov,0); 
    } 
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }

} 

void buildMaxHeap(texto_e *te, int n, double *comp , double *mov)  {  
    for (int i = 1; i < n; i++)  { 
        // se o filho for maior que o pai
        if (te->palavras[i].dados[0].letra > te->palavras[(i - 1) / 2].dados[0].letra){ 
            int j = i; 
      
            //  se o filho for maior que o pai
            while (te->palavras[j].dados[0].letra > te->palavras[(j - 1) / 2].dados[0].letra)  { 
                (*comp)++;
                palavra_e aux=te->palavras[j];
                te->palavras[j]=te->palavras[(j - 1) / 2];
                te->palavras[(j - 1) / 2]=aux;
                j = (j - 1) / 2; 
                (*mov)++; 
            } 
        } 
    } 
} 
  
void heapSort(texto_e *te, int n,int flag)  { 
    double comp = 0  , mov =0 ; 
    buildMaxHeap(te, n,&comp,&mov); 

    for (int i = n - 1; i > 0; i--) { 
        // valor de swap do primeiro indexado com o último indexado  
        mov++ ;  
        palavra_e aux =te->palavras[0];
        te->palavras[0]=te->palavras[i];
        te->palavras[i]=aux; 
      
        // valor de swap do primeiro indexado com o último indexado  
        int j = 0, index; 
          
        do{ 
            index = (2 * j + 1); 
              
            // se filho esquerdo for menor que a variável de índice de ponto filho direito para filho direito
            comp++; 
            if (te->palavras[index].dados[0].letra < te->palavras[index + 1].dados[0].letra && index < (i - 1)) 
                index++; 
          
            // se pai for menor que filho, troque pai por filho com valor mais alto
            comp++; 
            if (te->palavras[j].dados[0].letra < te->palavras[index].dados[0].letra && index < i){             
                palavra_e aux =te->palavras[j];
                te->palavras[j]=te->palavras[index];
                te->palavras[index]=aux; 
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

void select_sort_Dinamico(texto txt,int flag) {
    TCelula *a, *b, *c, *d, *r; 
    double comp=0,mov=0;
    a = b = txt.Primeiro; 
    // While  b não é a última célula
    while (b->Prox) { 
        c = d = b->Prox; 
        // While d está apontando para um célula válida
        while (d) { 
            comp++;
            if (b->first_letter > d->first_letter) { 
                // Se d aparecer imediatamente após b
                if (b->first_letter == d->first_letter) { 
                    // Caso 1: b é a cabeça da lista encadeada
                    if (b == txt.Primeiro) { 
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
                        txt.Primeiro = b; 
  
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
                    if (b == txt.Primeiro) { 
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
                        txt.Primeiro = b; 
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

int tam_texto(TCelula *lista) {
	int counter = 0;
	for (; lista != NULL; lista = lista->Prox){
		counter++;
	}
	return counter;
    //retorna o tamanho da lista
}

TCelula *pivo_aleatorio(TCelula *celula_cabeca){
	int tam_lista = tam_texto(celula_cabeca);
	int posicao_pivo = rand() % tam_lista; 

	for (int count = 0; count < posicao_pivo; count++){
		celula_cabeca = celula_cabeca->Prox;
	}
	return celula_cabeca;
    //encontra a celula que será o pivô na lista
}

TCelula * ultima_celula(TCelula * celula_atual){
	for (; celula_atual->Prox != NULL;celula_atual = celula_atual->Prox);
	return celula_atual;
}

TCelula * junta(TCelula* lista_esquerda, TCelula * pivo,TCelula * lista_direita){
	pivo->Prox = lista_direita;

	if (lista_esquerda == NULL)	return pivo;

	TCelula * ultimo_esquerda = ultima_celula(lista_esquerda);
	ultimo_esquerda->Prox = pivo;

	return lista_esquerda;
}

TCelula* QuickSort_Dinamico(TCelula * lista,int flag){
	if (lista == NULL || lista->Prox == NULL) return lista;
    double comp=0,mov=0;
    TCelula *pivo = pivo_aleatorio(lista);

	TCelula *lista_sub_esquerda = NULL, *lista_sub_direita = NULL;

	for (TCelula * celula_atual = lista; celula_atual != NULL;){
		TCelula * prox_celula = celula_atual->Prox;
        comp++;
		if (celula_atual != pivo){
            comp++;
			if (celula_atual->first_letter <= pivo->first_letter){
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
	return junta(QuickSort_Dinamico(lista_sub_esquerda,0), pivo, QuickSort_Dinamico(lista_sub_direita,0));
}

void MergeSort(TCelula** referencia_cabeca,int flag) { 
    TCelula* cabeca = * referencia_cabeca; 
    TCelula* a; 
    TCelula* b; 
    double comp=0,mov=0;
    /* Caso Básico-- tamanho 0 ou 1 */
    if ((cabeca == NULL) || (cabeca->Prox == NULL)) { 
        return; 
    } 
  
    /* Divida a cabeça em sublistas 'a' e 'b' */
    divide_frente_tras(cabeca, &a, &b); 
  
    /* Classificar recursivamente os sublistas */
    MergeSort(&a,0); 
    MergeSort(&b,0); 
  
    /*mescla as duas listas ordenadas */
    * referencia_cabeca = Classifica_Merge(a,b,&comp,&mov,0); 
    if(flag){
        printf("Comparações iguais a = %lf\n",comp);
        printf("Movimentações iguais a = %lf\n",mov);
    }
} 

TCelula* Classifica_Merge(TCelula* a, TCelula* b,double *comp,double *mov,int flag) { 
    TCelula* resultado = NULL; 
  
    /* Base dos casos */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Escolha a ou b e volte a */
    (*comp)++;
    if (a->first_letter <= b->first_letter) { 
        (*mov)++;
        resultado = a; 
        resultado->Prox = Classifica_Merge(a->Prox, b,comp,mov,1); 
    } 
    else { 
        (*mov)++;
        resultado = b; 
        resultado->Prox = Classifica_Merge(a, b->Prox,comp,mov,1); 
    }  
   
    return (resultado); 
} 
  
/* ---------------FUNÇÕES DE UTILIDADE --------------------*/
/* Divida os nós da lista em metades da frente e de trás,
   e retorne as duas listas usando os parâmetros de referência.
   Se o comprimento for ímpar, o nó extra deve estar na lista da frente.
   Usa a estratégia de ponteiro rápido / lento. */
void divide_frente_tras(TCelula* fonte, TCelula** referencia_frente, TCelula** referencia_tras){ 
    TCelula* rapido; 
    TCelula* devagar; 
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

void insertionSort(TCelula **celula_refencia,int flag) { 
    //inicia lista dinamica sorted 
    double comp =  0 , mov = 0 ;  
    TCelula *sorted = NULL; 
  
    // Percorra a lista vinculada fornecida e insira todos os nós para classificar
    TCelula *current = *celula_refencia; 
    while (current != NULL) { 
        //Armazenar próximo para a próxima iteração
        TCelula *prox = current->Prox; 
  
        // inserir corrente na lista vinculada classificada
        sortedInsert(&sorted, current,&comp,&mov); 
  
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
void sortedInsert(TCelula **celula_refencia,TCelula* novo_no,double *comp , double *mov) { 
    TCelula* atual; 
    /* caso especial para o final da celula cabeca */
    (*mov)++; 
    if (*celula_refencia == NULL || (*celula_refencia)->first_letter >= novo_no->first_letter) { 
        (*comp)++; 
        novo_no->Prox = *celula_refencia; 
        *celula_refencia = novo_no; 
    } 
    else{ 
        /* Localize o nó antes do ponto de inserção */
        atual = *celula_refencia; 
        while (atual->Prox!=NULL && atual->Prox->first_letter < novo_no->first_letter) { 
            (*comp)++; 
            atual = atual->Prox; 
        } 
        (*mov)++; 
        novo_no->Prox = atual->Prox; 
        atual->Prox = novo_no; 
    } 
} 