#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int info;
    int altD, altE;
    struct node *left;
    struct node *right;
} NODE;

typedef NODE * ARV_AVL;

void rot_dir(ARV_AVL *);

main()
{

}

void rot_dir(ARV_AVL *arvore)
{
    ARV_AVL aux1, aux2;

    aux1 = (*arvore)->left;
    aux2 = aux1->right;

    aux1->right = (*arvore);
    (*arvore)->left = aux2;

    if(!(*arvore)->left)
        (*arvore)->altE=0;
    else
        if((*arvore)->left->altE > (*arvore)->left->altD)
            (*arvore)->altE = (*arvore)->left->altE+1;
        else
            (*arvore)->altE = (*arvore)->left->altD+1;

    if((*arvore)->altE > (*arvore)->altD)
        aux1->altD = (*arvore)->altE+1;
    else
        aux1->altD - (*arvore)->altD+1;

    (*arvore) = aux1;

}

void rot_esq(ARV_AVL *arvore)
{
    ARV_AVL aux1, aux2;

    aux1 = (*arvore)->right; //endereço da nova arvore
    aux2 = aux1->left; //endereço do antigo filho esq da nova arvore

    aux1->left = (*arvore); //nova arvore recebe arvore antiga como filho esq
    (*arvore)->right = aux2; //arvore antiga recebe o filho esq da nova arv como filho dir

    if(!(*arvore)->right) //atualizando a altura direita da antiga arvore
        (*arvore)->altD = 0;
    else
        if((*arvore)->right->altE > (*arvore)->right->altD)
        (*arvore)->altD = (*arvore)->right->altE + 1;
        else
            (*arvore)->altD = (*arvore)->right->altD + 1;
    
    if((*arvore)->altE > (*arvore)->altD) //atualizando a altura esquerda da nova arvore
        aux1->altE = (*arvore)->altE + 1;
    else
        aux1->altE = (*arvore)->altD + 1;
    
    (*arvore) = aux1; //atualizo o referencial pra arvore para conter anova arvore

}

void balanceamente(ARV_AVL *arvore)
{
    int FBpai, FBfilho;

    FBpai = (*arvore)->altD - (*arvore)->altE;
    if(FBpai == 2)
    {
        FBfilho = (*arvore)->right->altD - (*arvore)->right->altE;
        if(FBfilho >= 0)
            rot_esq(arvore);
        else
        {
            rot_dir(&(*arvore)->right);
            rot_esq(arvore);
        }
    }
    else if(FBpai == -2)
    {
        FBfilho = (*arvore)->left->altD - (*arvore)->left->altE;
        if(FBfilho <= 0)
            rot_dir(arvore);
        else
        {
            rot_esq(&(*arvore)->left);
            rot_dir(arvore);
        }
    }
}