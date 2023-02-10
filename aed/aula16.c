#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo *ant;
    struct nodo *prox;
}NODO;

typedef NODO *LISTA_CIR_DUP_ENC_NC;

void cria_lista (LISTA_CIR_DUP_ENC_NC *);
int vazia (LISTA_CIR_DUP_ENC_NC);
int tam (LISTA_CIR_DUP_ENC_NC);
void ins (LISTA_CIR_DUP_ENC_NC, int, int);
int cons (LISTA_CIR_DUP_ENC_NC, int);
void ret (LISTA_CIR_DUP_ENC_NC, int);
void destruir (LISTA_CIR_DUP_ENC_NC);
void inverter_lista(LISTA_CIR_DUP_ENC_NC);

main()
{
    
        
	LISTA_CIR_DUP_ENC_NC L;
	int ind, val, o;
	
	
	cria_lista(&L);
	
	printf("------------------\n 1 - inserir\n 2 - consultar\n 3 - retirar\n 0 - parar\n------------------\n");
	
	printf("\nDeseja preencher com os valores automaticos? 1-y 0-n\n");
    scanf("%d", &val);
    if(val)
    {
    	int i;
    	
        ins(L, 11, 1);
        for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
        printf("--------------------------\n");
	    ins(L, 22, 2);
	    for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
        printf("--------------------------\n");
	    ins(L, 44, 3);
	    for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
        printf("--------------------------\n");
	    ins(L, 33, 3);
	    for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
        printf("--------------------------\n");
	    ins(L, 0, 1);
	    for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
        printf("--------------------------\n");
	    ins(L, 3, 3);
	    for(i=1; i <= tam(L); i++)
        {
            printf("	item %d > %d\n", i, cons(L, i));
        }
    }
        
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
				ins(L, val, ind);
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
				ret(L, ind);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
	if(!vazia(L))
	{
		int i;

        inverter_lista(L);
		
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}
	
    destruir(L);
}

void cria_lista (LISTA_CIR_DUP_ENC_NC *pL)
{
    *pL = (NODO*) malloc(sizeof(NODO));
    if(!(*pL))
    {
        printf("erro na alloc!");
        exit(0);
    }

    (*pL)->inf = 0;
    (*pL)->prox = *pL;
    (*pL)->ant = *pL;
}

int vazia (LISTA_CIR_DUP_ENC_NC L)
{
    return L->inf == 0;
}

int tam (LISTA_CIR_DUP_ENC_NC L)
{
    return L->inf;
}

void ins (LISTA_CIR_DUP_ENC_NC L, int val, int pos)
{
    LISTA_CIR_DUP_ENC_NC novo;

    if(pos<1 || pos>L->inf+1)
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

    if(pos <= L->inf/2)
    {
        L->inf++;

        for(; pos>1; L = L->prox, pos--);

        novo->prox = L->prox;
        novo->ant = L;
        L->prox = novo;
        novo->prox->ant = novo;
    }    
    else
    {
        LISTA_CIR_DUP_ENC_NC aux;

        for(aux=L; pos <= L->inf; aux = aux->ant, pos++);

        novo->prox = aux;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;

        L->inf++;
    }

}
int cons (LISTA_CIR_DUP_ENC_NC L, int pos)
{
    int tam=L->inf;

    if(pos<1||pos>tam)
    {
        printf("pos invalida");
        exit(0);
    }

    if(pos <= tam/2)
        for(L=L->prox; pos>1; L = L->prox, pos--);
    else
        for(; pos<=tam; L = L->ant, pos++);

    return L->inf;
}

void ret (LISTA_CIR_DUP_ENC_NC L, int pos)
{
    int tam = L->inf;
    if(pos<1||pos>tam)
    {
        printf("pos invalida");
        exit(0);
    }

    L->inf--;

    if(pos <= tam/2)
        for(L=L->prox; pos>1; L = L->prox, pos--);
    else
        for(; pos<=tam; L = L->ant, pos++);

    L->ant->prox = L->prox;
    L->prox->ant = L->ant;
    free(L);
}

void destruir (LISTA_CIR_DUP_ENC_NC L)
{
    LISTA_CIR_DUP_ENC_NC aux=NULL, cabesalho;
    int tam = L->inf;

    do
    {   
        aux = L;
        L = L->prox;
        free(aux);
    }while(tam--);
}

void inverter_lista(LISTA_CIR_DUP_ENC_NC L)
{
    if(L->inf>1)
    {
        LISTA_CIR_DUP_ENC_NC aux=L, aux2;

        do
        {
            aux2 = aux->prox;
            aux->prox = aux->ant;
            aux->ant = aux2;
            aux = aux->ant;
        }while(aux!=L);
    }
}
