#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INTGR 1
#define FLT 2
#define STRING 3

typedef union
    {
        int ival;
        float fval;
        char sval[20];
    } inf;

typedef struct nodo
{
    int etype;
    inf element;
    struct nodo *ant;
    struct nodo *prox;
}NODO;

typedef NODO *LISTA_CIR_DUP_ENC;

void cria_lisa (LISTA_CIR_DUP_ENC *);
int vazia (LISTA_CIR_DUP_ENC);
int tam (LISTA_CIR_DUP_ENC);
void ins (LISTA_CIR_DUP_ENC*, inf, int ,int);
int cons (LISTA_CIR_DUP_ENC, int);
void ret (LISTA_CIR_DUP_ENC, int);
void destruir (LISTA_CIR_DUP_ENC);
void inverter_lista(LISTA_CIR_DUP_ENC);
int pertence(LISTA_CIR_DUP_ENC, inf, int);

main()
{
        
        
	LISTA_CIR_DUP_ENC L;
	int ind, val, o;
	
	
	cria_lista(&L);
	
	printf("------------------\n 1 - inserir\n 2 - consultar\n 3 - retirar\n 0 - parar\n------------------\n");
	
	printf("\nDeseja preencher com os valores automaticos? 1-y 0-n\n");
    scanf("%d", &val);
    if(val)
    {
    	int i;
    	
        ins(&L, 11, 1, 1);
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

void cria_lista (LISTA_CIR_DUP_ENC *pL)
{
    *pL = NULL;
}

int vazia(LISTA_CIR_DUP_ENC L)
{
    return L==NULL;
}

int tam(LISTA_CIR_DUP_ENC L)
{
    if(!L)
        return 0;
    else
    {
        LISTA_CIR_DUP_ENC aux;
        int cont;

        for(cont=1, aux = L->prox; aux!=L; aux = aux->prox, cont++);

        return cont;
    }
}

void ins (LISTA_CIR_DUP_ENC *pL, inf val, int type,int pos)
{
    int t = tam(*pL);

    if(pos<1 || pos>t)
    {
        printf("pos invalida");
        return;
    }

    if(pertence(*pL, val, type))
        printf("valor ja pertence a lista");
    else
    {
        LISTA_CIR_DUP_ENC novo;

        novo = (NODO*) malloc(sizeof(NODO));
        if(!novo)
        {
            printf("erro na alloc");
            return;
        }

        novo->etype = type;
        novo->element = val;

        if(*pL==NULL)
        {
            *pL = novo;
            novo->ant = novo;
            novo->prox = novo;
        }
        else
        {
            LISTA_CIR_DUP_ENC aux;
            int p=pos;
            if(pos<=t/2)
                for(aux = *pL; pos>1; aux = aux->prox, pos--);
            else
                for(aux = *pL; pos<=t; aux=aux->ant, pos++);
            novo->ant = aux;
            novo->prox = aux->prox;
            aux->prox = novo;
            novo->prox->ant = novo;
            if(p==t+1)
                *pL = novo;
        }
    }

}

int pertence(LISTA_CIR_DUP_ENC l, inf v, int etype)
{
    if(!l)
        return 0;
    else
    {
        LISTA_CIR_DUP_ENC aux = l;
        do
        {
            if(aux->etype==etype &&
            ((INTGR==etype && aux->element.ival==v.ival) ||
            (FLT==etype && aux->element.fval==v.ival) ||
            (STRING==etype && !strcmp(aux->element.sval,v.sval))))
                return 1;
        } while (aux!=l);
        return 0;
    }
}