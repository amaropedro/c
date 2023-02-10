#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 100

typedef struct nodo
{
    int inf;
    struct nodo *next;
}NODE;

typedef NODE *PILHA_ENC;

void create (PILHA_ENC *);
int empty (PILHA_ENC);
void push (PILHA_ENC *, int);
int top (PILHA_ENC);
void pop (PILHA_ENC *);
int top_pop (PILHA_ENC *);
void destroy (PILHA_ENC);
void converter_s_p(char *, char *);

main()
{
    char S[MAX], D[MAX];
    printf("	>"); scanf("%[^\n]s", S);
    printf("string: %s\n", S);
    converter_s_p(S, D);
    printf("string: %s", D);
    printf(" = %d\n", func(D));
}

void create (PILHA_ENC *P)
{
   *P = NULL;
}

int empty (PILHA_ENC P)
{
    return P==NULL;
}

void push (PILHA_ENC *pP, int v)
{
    PILHA_ENC new;

    new = (NODE*) malloc(sizeof(NODE));
    if(!new)
    {
        puts("erro na alloc");
        return;
    }

    new->inf = v;
    new->next = *pP;

    *pP = new;
}

int top (PILHA_ENC P)
{
    if(!P)
    {
        puts("-pilha vazia");
        exit(1);
    }

    return P->inf;
}

void pop (PILHA_ENC *pP)
{
    if(!(*pP))
    {
        puts("--pilha vazia");
        exit(2);
    }
    else
    {
        PILHA_ENC aux=*pP;
        *pP = (*pP)->next;
        free(aux);
    }
}

int top_pop (PILHA_ENC *pP)
{
    if(!(*pP))
    {
        puts("---pilha vazia");
        exit(3);
    }
    else
    {
        PILHA_ENC aux=*pP;
        int v=(*pP)->inf;

        *pP = (*pP)->next;
        free(aux);

        return v;
    }
}

/*void destroy (PILHA_ENC P)
{
    while(P)
        destroy(P->next);
    free(P);
}*/

void destroy (PILHA_ENC P)
{
    PILHA_ENC aux;
    while(P)
    {
        aux = P;
        P = P->next;
        free(aux);
    }
}

int number(char C)
{
    return '0'<=C && C<='9';
}

int aplicar(int a, char c, int b)
{
    switch (c)
    {
    case '+':
        return a+b;
    case '-':
        return a-b;
    case '*':
        return a*b;
    case '/':
        return a/b;
    case '^':
        return (int)pow(a,b);
    }
}

int func(char *S)
{
    PILHA_ENC P;
    int i=0;

    create(&P);

    while(S[i]!='\0')
    {
        if(number(S[i]))
            push(&P, S[i]-'0');
        else
        {
            int a, b;
            b = top_pop(&P);
            a = top_pop(&P);
            push(&P, aplicar(a, S[i], b));
        }
        i++;
    }
    return top_pop(&P);
}

int prcd(char a, char b)
{
    if((a=='+'||a=='-')&&(b=='+'||b=='-'))
        return 1;
    if((a=='*'||a=='/')&&(b=='+'||b=='-'||b=='*'||b=='/')) 
        return 1;
    if((a=='^')&&(b=='^'||b=='+'||b=='-'||b=='*'||b=='/'))
        return 1;
    if((a=='+'||a=='-'||a=='*'||a=='/'||a=='^')&&(b==')'))
        return 1;
    return 0;
}

void converter_s_p(char *O, char *D)
{
    int i=0, j=0;
    PILHA_ENC P;

    create(&P);

    while(O[i]!='\0')
    {
        if(number(O[i]))
            D[j++] = O[i];
        else
        {
            while( !empty(P) && prcd(top(P), O[i]) )
                D[j++] = (char) top_pop(&P);

            if(O[i]==')')
                pop(&P);
            else                
                push(&P, O[i]);
        }
        i++;
    }
    while(!empty(P))
        D[j++]= (char) top_pop(&P);
    D[j] = '\0';
}
