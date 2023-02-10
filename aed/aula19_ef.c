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
void ins (LISTA_CIRCULAR *, int);
int cons (LISTA_CIRCULAR);
void ret (LISTA_CIRCULAR *);
void destruir (LISTA_CIRCULAR);
void imprimir (LISTA_CIRCULAR);

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
                    ins(&L, 11);
				    ins(&L, 22);
				    ins(&L, 33);
				    ins(&L, 44);
				    break;
                }
				printf("\nEntre com o valor que deseja inserir:\n");
				scanf("%d", &val);
				ins(&L, val);
				break;
			case 2:
                if(!vazia(L))
                {
                	printf("	item > %d\n", cons(L));
                }
                imprimir(L);
				break;
			case 3:
				ret(&L);
				break;
			default:
				if(o)
					printf("entre um valor valido!\n");
		}
	}while(o);
	
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

void ins (LISTA_CIRCULAR *pL, int val)
{
    LISTA_CIRCULAR novo;
    
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
        novo->next = (*pL)->next;
        (*pL)->next = novo;
        *pL = novo;
    }
}

int cons (LISTA_CIRCULAR L)
{
    if(vazia(L))
    {
        puts("lista vazia");
        return;
    }
    return L->inf;
}

void ret (LISTA_CIRCULAR *pL)
{
    int tamanho = tam(*pL);

    if(vazia(*pL))
    {
        puts("lista vazia");
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

        for(aux2 = aux = *pL; tamanho>1; aux = aux->next, tamanho--);

        aux->next = aux2->next;

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

void imprimir (LISTA_CIRCULAR L)
{
    if(!vazia(L))
    {
        int i = 0;
        LISTA_CIRCULAR aux = L;
        
        L = L->next;

        while(L!=aux)
        {
            printf("    > item %d = %d", ++i, L->inf);
            L = L->next;
        }
            printf("    > item %d = %d", ++i, L->inf);
        
    }
    else
        puts("lista vazia!");
}
