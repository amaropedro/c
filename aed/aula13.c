#include <stdio.h>
#include <stdlib.h>

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef NODO * LISTA_CIRCULAR;

void cria_lista (LISTA_CIRCULAR *);
int vazia (LISTA_CIRCULAR);
int tam (LISTA_CIRCULAR);
void ins (LISTA_CIRCULAR *, int, int);
int cons (LISTA_CIRCULAR, int);
void ret (LISTA_CIRCULAR *, int);
void destruir (LISTA_CIRCULAR);

main()
{
        
	LISTA_CIRCULAR L;
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
                printf("\nDeseja preencher com os valores automaticos? 1-y 0-n\n");
                scanf("%d", &val);
                if(val)
                {
                    ins(&L, 11, 1);
				    ins(&L, 22, 2);
				    ins(&L, 44, 3);
				    ins(&L, 33, 3);
				    ins(&L, 0, 1);
				    break;
                }
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
		
		for(i=1; i <= tam(L); i++)
		{
			printf("	item %d > %d\n", i, cons(L, i));
		}
	}
	
}

void cria_lista (LISTA_CIRCULAR *pL)
{
    *pL = NULL;
}

int vazia(LISTA_CIRCULAR L)
{
    return L==NULL;
}

int tam (LISTA_CIRCULAR L)
{
    if(!L)
        return 0;
    else
    {
        LISTA_CIRCULAR aux;
        int cont;

        for(cont=1, aux = L->next; aux!=L; aux = aux->next, cont++);

        return cont;
    }
}

void ins (LISTA_CIRCULAR *pL, int val, int pos)
{
    LISTA_CIRCULAR novo;
    int tamanho = tam(*pL);

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

    if(vazia(*pL))
    {
        *pL = novo;
        novo->next = novo;
    }
    else
    {
        LISTA_CIRCULAR aux = *pL;
        if(pos==tamanho+1)
            *pL = novo;
        else
            for(; pos>1; aux = aux->next, pos--);

        novo->next = aux->next;
        aux->next = novo;
    }
}

int cons (LISTA_CIRCULAR L, int pos)
{
    if(pos<1 || pos>tam(L))
    {
        printf("pos invalida");
        return 404;
    }

    for( ; pos>0 ; L = L->next, pos--);
    return L->inf;
}

void ret (LISTA_CIRCULAR *pL, int pos)
{
    int tamanho = tam(*pL);

    if(pos<1 || pos>tamanho)
    {
        printf("pos invalida");
        return;
    }

    if(tamanho==1)
    {
        free(*pL);
        *pL = NULL;
    }
    else
    {
        LISTA_CIRCULAR aux, aux2;

        for(aux = *pL; pos>1; aux = aux->next, pos--);

        aux2 = aux->next;
        aux->next = aux2->next;

        if(aux2 == *pL)
            *pL = aux;

        free(aux2);
    }
}

void destruir (LISTA_CIRCULAR L)
{
    if(L)
    {
        LISTA_CIRCULAR aux;
        for(aux = L->next; aux!=L->next; aux = aux->next)
            free(aux);
        free(aux);
    }
}
