#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    struct node *left;
    struct node *right;
    struct node *father;
} NODE;

typedef NODE * ARV_BIN_ENC;

void maketree(ARV_BIN_ENC *, int);
void setleft(ARV_BIN_ENC, int);
void setright(ARV_BIN_ENC, int);
int info(ARV_BIN_ENC);
ARV_BIN_ENC left(ARV_BIN_ENC);
ARV_BIN_ENC right(ARV_BIN_ENC);
ARV_BIN_ENC father(ARV_BIN_ENC);
ARV_BIN_ENC brother(ARV_BIN_ENC);
int isleft(ARV_BIN_ENC);
int isright(ARV_BIN_ENC);

typedef struct nodo
{
    int inf;
    struct nodo * next;
}NODO;

typedef struct
{
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;

void cria_fila(FILA_ENC *);
int vazia(FILA_ENC);
void ins(FILA_ENC, int);
int cons(FILA_ENC);
void ret(FILA_ENC);
int cons_ret(FILA_ENC);
void destruir(FILA_ENC);

main()
{

}

void maketree(ARV_BIN_ENC *T, int x)
{
    *T = (NODE*) malloc(sizeof(NODE));
    if(!(*T))
    {
        puts("erro na alloc");
        return;
    }

    (*T)->info = x;
    (*T)->father = (*T)->left = (*T)->left = NULL;
}

void setleft(ARV_BIN_ENC T, int x)
{
    T->left = (NODE*)  malloc(sizeof(NODE));
    if(!T->left)
    {
        puts("erro na alloc");
        return;
    }

    T->left->info = x;
    T->left->father = T;
    T->left->left = T->left->right = NULL;
}

void setright(ARV_BIN_ENC T, int x)
{
    T->right = (NODE*)  malloc(sizeof(NODE));
    if(!T->right)
    {
        puts("erro na alloc");
        return;
    }

    T->right->info = x;
    T->right->father = T;
    T->right->left = T->right->right = NULL;
}

int info(ARV_BIN_ENC T)
{
    return T->info;
}

ARV_BIN_ENC left(ARV_BIN_ENC T)
{
    return T->left;
}

ARV_BIN_ENC right(ARV_BIN_ENC T)
{
    return T->right;
}

ARV_BIN_ENC father(ARV_BIN_ENC T)
{
    return T->father;
}

ARV_BIN_ENC brother(ARV_BIN_ENC T)
{
    if(T->father)
    {
        if(isleft(T))
            return T->father->right;
        return T->father->left;
    }   
    return NULL;
}

int isleft(ARV_BIN_ENC T)
{
    if(T->father)
        return T->father->left == T;
    return 0;
}

int isright(ARV_BIN_ENC T)
{
    if(T->father)
        return T->father->right == T;
    return 0; 
}

void cria_fila(FILA_ENC *pF)
{
    *pF = (DESCRITOR*) malloc(sizeof(DESCRITOR));
    if(!*pF)
    {
        puts("erro na alloc");
        return;
    }

    (*pF)->INICIO = NULL;
    (*pF)->FIM = NULL;
}

int vazia(FILA_ENC F)
{
    return F->INICIO==NULL;
}

void ins(FILA_ENC F, int v)
{
    NODO *novo;

    novo = (NODO*) malloc(sizeof(NODO));

    if(!novo)
    {
        puts("erro na alloc");
        return;
    }

    novo->inf = v;
    novo->next = NULL;

    if(!F->INICIO)
        F->INICIO = novo;
    else
        F->FIM->next = novo;
    
    F->FIM = novo;
}

int cons(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return 404;
    }

    return F->INICIO->inf;
}

void ret(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return;
    }
    else
    {
        NODO *aux = F->INICIO;

        F->INICIO = F->INICIO->next;

        free(aux);

        if(!F->INICIO)
            F->FIM = NULL;
    }
}

int cons_ret(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
        return;
    }
    else
    {
        NODO *aux = F->INICIO;
        int i = F->INICIO->inf;

        F->INICIO = F->INICIO->next;

        free(aux);

        if(!F->INICIO)
            F->FIM = NULL;

        return i;
    }
}

void destruir(FILA_ENC F)
{
    NODO *aux;

    while(F->INICIO)
    {
        aux = F->INICIO;
        F->INICIO = F->INICIO->next;
        free(aux);
    }
    F->FIM = NULL;
    free(F);
}

void percursoEmLargura(ARV_BIN_ENC T)
{
    FILA_ENC fila;

    cria_fila(&fila);

    if(T)
    {
        ins(fila, T);

        while(!vazia(fila))
        {
            printf("%d ", inf(cons(fila)));
            if(left(cons(fila)))
                ins(fila, left(cons(fila)));
            if(right(cons(fila)))
                ins(fila, right(cons(fila)));
            
            ret(fila);
        }
    }
}

void preOrdem(ARV_BIN_ENC T)
{
    if(T)
    {
        printf("%d", T->info);  //V
        preOrdem(T->left);      //L
        preOrdem(T->right);     //R
    }
}

void inOrdem(ARV_BIN_ENC T)
{
    if(T)
    {
        inOrdem(T->left);
        printf("%d", T->info);
        inOrdem(T->right);
    }
}

void posOrdem(ARV_BIN_ENC T)
{
    if(T)
    {
        posOrdem(T->left);
        posOrdem(T->right);
        printf("%d", T->info);
    }
}

void ins_ele(ARV_BIN_ENC *T, int v)
{
    if(!(*T))
        maketree(T, v);
    else
    {
        ARV_BIN_ENC father = *T;
        do
        {
            if(v < father->info)
            {
                if(father->left)
                    father = father->left;
                else
                {
                    setleft(father, v);
                    break;
                }
            }
            else
            {
                if(father->right)
                    father = father->right;
                else
                {
                    setright(father, v);
                    break;
                }
            }
        } while(1);
        
    }
}

void ret_fusion(ARV_BIN_ENC *T) //coloca a sub arvore dir no elemento mais dir da sub arvore esquerda
{
    if(*T)
    {
        ARV_BIN_ENC tmp = *T;
        
        if(!(*T)->right)
        {
            if((*T)->left)
                (*T)->left->father = (*T)->father;
            *T = (*T)->left;
        }
        else
        {
            if(!(*T)->left)
            {
                (*T)->right->father = (*T)->father;
                *T = (*T)->right;
            }
            else
            {
                tmp = (*T)->left;

                while(tmp->right)
                    tmp = tmp->right;
                
                tmp->right = (*T)->right;
                tmp->right->father = tmp;
                tmp = *T;
                *T = (*T)->left;
            }
        }

        free(tmp);
    }
}

void ret_copy(ARV_BIN_ENC *T) //sucessor imediato toma o lugar do elemento removido
{
    if(*T)
    {
        ARV_BIN_ENC tmp = *T;
        
        if(!(*T)->right)
        {
            if((*T)->left)
                (*T)->left->father = (*T)->father;
            *T = (*T)->left;
        }
        else
        {
            if(!(*T)->left)
            {
                (*T)->right->father = (*T)->father;
                *T = (*T)->right;
            }
            else //tem ambos filhos
            {
                tmp = (*T)->right;

                while(tmp->left) 
                    tmp = tmp->left;
                //saindo do while encontramos o filho mais a esquerda da sub-arvore dir
                (*T)->info = tmp->info;
                if(tmp->father==*T)
                {
                    tmp->father->right = tmp->right;
                    tmp->father->right->father = tmp->father;
                }
                else
                {
                    tmp->father->left = tmp->right;
                    tmp->father->left->father = tmp->father;
                }
            }
        }
        free(tmp);
    }
}