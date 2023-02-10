#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef NODO * LISTA_CIRCULAR_NC;

void cria_lista (LISTA_CIRCULAR_NC *);
int vazia (LISTA_CIRCULAR_NC);
int tam (LISTA_CIRCULAR_NC);
void ins (LISTA_CIRCULAR_NC, int, int);
int cons (LISTA_CIRCULAR_NC, int);
void ret (LISTA_CIRCULAR_NC, int);
void destruir (LISTA_CIRCULAR_NC);

main()
{
    
	LISTA_CIRCULAR_NC L;
	int ind, val, o;
	
	
	cria_lista(&L);
	
	printf("------------------\n 1 - inserir\n 2 - consultar\n 3 - retirar\n 0 - parar\n------------------\n");
	
		printf("\nDeseja preencher com os valores automaticos? 1-y 0-n\n");
        scanf("%d", &val);
        if(val)
        {
            ins(L, 11, 1);
		    ins(L, 22, 2);
		    ins(L, 44, 3);
		    ins(L, 33, 3);
		    ins(L, 0, 1);
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
		
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}
	
}

void cria_lista (LISTA_CIRCULAR_NC *pL)
{
    *pL = (NODO*) malloc(sizeof(NODO));
    if(!*pL)
    {
        printf("erro na alloc");
        exit(1);
    }

    (*pL)->inf = 0;
    (*pL)->next = NULL;
}

int vazia(LISTA_CIRCULAR_NC L)
{
    return !L->inf;
}

int tam (LISTA_CIRCULAR_NC L)
{
    return L->inf;
}

void ins (LISTA_CIRCULAR_NC L, int val, int pos)
{
    LISTA_CIRCULAR_NC novo;
    int tamanho = tam(L);

    if(pos<1 || pos>tamanho+1)
    {
        printf("pos invalida");
        return;
    }
    
    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }

    novo->inf = val;
    L->inf++;

    if(!L->inf)
    {
        L->next = novo;
        novo->next = novo;
    }
    else
    {
        if(pos==tamanho+1)
            L->next = novo;

        for(; pos>1; L = L->next, pos--);

        novo->next = L->next;
        L->next = novo;
    }
}

int cons (LISTA_CIRCULAR_NC L, int pos)
{
    if(pos<1 || pos>tam(L))
    {
        printf("pos invalida");
        return 404;
    }

    for( ; pos>0 ; L = L->next, pos--);
    return L->inf;
}

void ret (LISTA_CIRCULAR_NC L, int pos)
{
    int tamanho = tam(L);

    if(pos<1 || pos>tamanho)
    {
        printf("pos invalida");
        return;
    }

    if(tamanho==1)
    {
        free(L);
        L = NULL;
    }
    else
    {
        LISTA_CIRCULAR_NC aux, aux2;

        for(aux = L; pos>1; aux = aux->next, pos--);

        aux2 = aux->next;
        aux->next = aux2->next;

        if(aux2 == L)
            L = aux;

        free(aux2);
    }
}

void destruir (LISTA_CIRCULAR_NC L)
{
    if(L)
    {
        LISTA_CIRCULAR_NC aux;
        for(aux = L->next; aux!=L->next; aux = aux->next)
            free(aux);
        free(aux);
    }
}
