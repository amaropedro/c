#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo* next;
}NODO;

typedef NODO * LISTA_ENC_NC_ORD;

void cria_lista (LISTA_ENC_NC_ORD *);
int vazia (LISTA_ENC_NC_ORD);
int tam (LISTA_ENC_NC_ORD);
void ins (LISTA_ENC_NC_ORD, int);
int cons (LISTA_ENC_NC_ORD, int);
int recup (LISTA_ENC_NC_ORD, int);
void ret (LISTA_ENC_NC_ORD, int);
void ret2 (LISTA_ENC_NC_ORD, int);
void destruir (LISTA_ENC_NC_ORD);
LISTA_ENC_NC_ORD concatenar (LISTA_ENC_NC_ORD, LISTA_ENC_NC_ORD);

main()
{
    
	LISTA_ENC_NC_ORD L;
	int val, o;
	
	
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
				ins(L, val);
				break;
			case 2:
				printf("\nEntre com a posicao do valor que deseja consultar:\n");
				scanf("%d", &val);
				printf("	> %d", cons(L, val));
				break;
			case 3:
				printf("\nEntre com a posicao do valor que deseja retirar:\n");
				scanf("%d", &val);
				ret(L, val);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
	if(!vazia(L))
	{
		int i;
		
        printf("    tamanho da lista > %d\n", tam(L));
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}

    destruir(L);
}

void cria_lista (LISTA_ENC_NC_ORD *C)
{
    *C = (NODO*) malloc(sizeof(NODO));
    if(!*C)
    {
        printf("erro na alloc");
        exit(0);
    }

    (*C)->inf = 0;
    (*C)->next = NULL; 
}

int vazia (LISTA_ENC_NC_ORD C)
{
    return !C->inf;
}

int tam (LISTA_ENC_NC_ORD C)
{
    return C->inf;
}

/*
void ins (LISTA_ENC_NC_ORD C, int val)
{
    LISTA_ENC_NC_ORD novo;

    novo = (NODO*) malloc(sizeof(NODO));
    if(!novo)
    {
        printf("erro na alloc");
        return;
    }

    novo->inf = val;
    C->inf++;

    for( ; C->next!=NULL && val > (C->next)->inf; C = C->next);
    novo->next = C->next;
    C->next = novo;
}
*/

void ins (LISTA_ENC_NC_ORD C, int val)
{
    if(C->next==NULL||(val<=(C->next)->inf))
    {
        LISTA_ENC_NC_ORD novo;

        novo = (NODO*) malloc(sizeof(NODO));
        if(!novo)
        {
            printf("erro na alloc");
            return;
        }

        novo->inf = val;
        novo->next = C->next;
        C->next = novo;
    }
    else
    {
        ins (C->next, val);
        C->next->inf--;
    }
    
    C->inf++;
}

/*int cons (LISTA_ENC_NC_ORD C, int pos)
{
    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return 404;
    }

    for(C = C->next; pos>1; C = C->next, pos--);

    return C->inf;
}*/

int cons (LISTA_ENC_NC_ORD C, int pos)
{
    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return 404;
    }

   return recup (C->next, pos);
}

int recup (LISTA_ENC_NC_ORD C, int pos)
{
    if(pos==1)
        return C->inf;

    return recup(C->next, pos-1);
}

/*void ret (LISTA_ENC_NC_ORD C, int pos)
{
    LISTA_ENC_NC_ORD aux, aux2;

    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return;
    }

    for(aux = C; pos>1; aux = aux->next, pos--);
    aux2 = aux->next;
    aux->next = aux2->next;
    free(aux2);

    C->inf--;
}*/

void ret (LISTA_ENC_NC_ORD C, int pos)
{
    if(pos<1 || pos>C->inf)
    {
        printf("pos invalida!");
        return;
    }

    C->inf--;
    ret2 (C, pos);
}

void ret2 (LISTA_ENC_NC_ORD C, int pos)
{
    if(pos==1)
    {
        LISTA_ENC_NC_ORD aux;
        aux = C->next;
        C->next = aux->next;
        free(aux);
    }
    else
        ret2(C->next, pos-1);
}

void destruir (LISTA_ENC_NC_ORD C)
{
    LISTA_ENC_NC_ORD aux;
    aux = C;
    if(C->next)
        destruir(C->next);
    free(aux);
}

LISTA_ENC_NC_ORD concatenar (LISTA_ENC_NC_ORD A, LISTA_ENC_NC_ORD B)
{
    LISTA_ENC_NC_ORD C, aux;
    int i;

    cria_lista(&C);

    for(A = A->next; A!=NULL; A = A->next)
        ins(C, A->inf);

    for(B = B->next; B!=NULL; B = B->next)
    {
        for(i=1, aux = C->next; aux!=NULL; aux = aux->next)
        {
            if(B->inf == aux->inf)
            {
                i=0;
                break;
            }
        }

        if(i)
            ins(C, B->inf);
    }
    
    return C;
}
