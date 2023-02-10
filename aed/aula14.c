#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo *ant;
    struct nodo *prox;
}NODO;

typedef NODO *LISTA_DUP_ENC;

void cria_lista (LISTA_DUP_ENC *);
int vazia (LISTA_DUP_ENC);
int tam (LISTA_DUP_ENC);
void ins (LISTA_DUP_ENC *, int, int);
int cons (LISTA_DUP_ENC, int);
void ret (LISTA_DUP_ENC *, int);
void destruir (LISTA_DUP_ENC);
void inverter_lista (LISTA_DUP_ENC *);

main()
{
        
	LISTA_DUP_ENC L;
	int ind, val, o;
	
	
	cria_lista(&L);
	
	printf("------------------\n 1 - inserir\n 2 - consultar\n 3 - retirar\n 0 - parar\n------------------\n");
	
	do
	{
		printf("\nDigite a operacao que deseja realizar:\n");
		scanf("%d", &o);
		
		switch(o)
		{
			case 1:
				printf("\nEntre com o valor que deseja inserir:\n");
				scanf("%d", &val);
				printf("Entre com a posicao deste valor:\n");
				scanf("%d", &ind);
				ins(&L, val, ind);
				break;
			case 2:
			    if(!vazia(L))
				{
					int i;
					
					for(i=1; i <= tam(L); i++)
					{
						printf("	item %d > %d\n", i, cons(L, i));
					}
				}
				break;
			case 3:
				printf("\nEntre com a posicao do valor que deseja retirar:\n");
				scanf("%d", &ind);
				ret(&L, ind);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
	if(!vazia(L))
	{
		int i;
		
        inverter_lista(&L);
		
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}
}

void cria_lista (LISTA_DUP_ENC *pL)
{
    *pL = NULL;
}

int vazia (LISTA_DUP_ENC L)
{
    return L == NULL;
}

int tam (LISTA_DUP_ENC L)
{
    int cont;

    for(cont=0; L!=NULL; L = L->prox)
        cont++;
    return cont;
}

void ins (LISTA_DUP_ENC *pL, int val, int pos)
{
    LISTA_DUP_ENC novo;

    if(pos<1 || pos>tam(*pL)+1)
    {
        printf("pos invalida!");
        return;
    }

    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }
    
    novo->inf = val;

    if(pos==1)
    {
        novo->ant = NULL;
        novo->prox = *pL;
        *pL = novo;
        if(novo->prox)
            (novo->prox)->ant = novo;
    }
    else
    {
        LISTA_DUP_ENC aux;

        for(aux = *pL; pos>2; aux = aux->prox, pos--);
        novo->prox = aux->prox;
        aux->prox = novo;
        novo->ant = aux;
        if(novo->prox)
            aux->prox->ant = novo;
    }   
}

int cons (LISTA_DUP_ENC L, int pos)
{
    if(pos<1 || pos>tam(L))
    {
        printf("pos invalida");
        return 404;
    }

    for( ; pos>1 ; L = L->prox, pos--);
    return L->inf;
}

void ret (LISTA_DUP_ENC *pL, int pos)
{
    LISTA_DUP_ENC aux;

    if(pos<1 || pos>tam(*pL));
    {
        printf("pos invalida");
        return ;
    }

    if(pos==1)
    {
        aux = *pL;
        *pL = aux->prox;
        if(*pL)
            (*pL)->ant = NULL;
        free(aux);
    }
    else
    {
        for(aux = (*pL)->prox; pos>2; aux=aux->prox, pos--);
            aux->ant->prox = aux->prox;
        if(aux->prox)
            aux->prox->ant = aux->ant;
        free(aux);
    }
}

void destruir (LISTA_DUP_ENC L)
{
    LISTA_DUP_ENC aux;
    while (L)
    {
        aux = L;
        L = L->prox;
        free(aux);
    }
}

void inverter_lista (LISTA_DUP_ENC *pL)
{
    if(*pL)
    {
        LISTA_DUP_ENC aux;
        do
        {
            aux = (*pL)->prox;
            (*pL)->prox=(*pL)->ant;
            (*pL)->ant=aux;
            if(aux)
                *pL=aux;
        } while (aux);
    }
}
