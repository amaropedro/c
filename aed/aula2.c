#include <stdio.h>

typedef struct
{
    int num;
    int dem;
}RACIONAL;

void criar_racional(int, int, RACIONAL*);
void multiplicar_racionais(RACIONAL*, RACIONAL*, RACIONAL*);
void somar_racionais(RACIONAL*, RACIONAL*, RACIONAL*);
int equivalencia_racinal(RACIONAL*, RACIONAL*);

main()
{
    RACIONAL r1, r2, r3;
    int a, b;
    char opi;

    printf("Entre com os racionais e sua operacao na fomra 'x + y':\n");
    scanf("%d/%d %c", &a, &b, &opi);
    criar_racional(a, b, &r1);
    scanf("%d/%d", &a, &b);
    criar_racional(a, b, &r2);

    switch (opi)
    {
    case '*':
        multiplicar_racionais(&r1, &r2, &r3);
        break;
    case '+':
        somar_racionais(&r1, &r2, &r3);
        break;
    case '=':
        if (equivalencia_racinal(&r1, &r2))
            printf("sao equivalentes");
        else
            printf("nao sao equivalentes");
        return 0;
    default:
        printf("digite uma das operacoes: '*' ou '+' ou '='");
        return 1;
    }

    printf("%d/%d %c %d/%d = %d/%d", r1.num, r1.dem, opi, r2.num, r2.dem, r3.num, r3.dem);
}

void criar_racional(int a, int b, RACIONAL *r)
{
    r->num = a;
    (*r).dem = b; //as duas formas de atribuição são equivalentes
};

void multiplicar_racionais(RACIONAL *r1, RACIONAL *r2, RACIONAL *r3)
{
    r3->num = r1->num*r2->num;
    r3->dem = r1->dem*r2->dem;
};

void somar_racionais(RACIONAL *r1, RACIONAL *r2, RACIONAL *r3)
{
    r3->num = r1->num*r2->dem + r2->num*r1->dem;
    r3->dem = r1->dem*r2->dem;
};

int equivalencia_racinal(RACIONAL *r1, RACIONAL *r2)
{
    return r1->num*r2->dem == r2->num*r1->dem;
};