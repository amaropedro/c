#include <stdio.h>

typedef struct
{
	int num;
	int den;
} RACIONAL;

void criar_racional (int, int, RACIONAL* );
void mult (RACIONAL*, RACIONAL*, RACIONAL* );
void soma (RACIONAL*, RACIONAL*, RACIONAL* );
int equi (RACIONAL*, RACIONAL*);

main()
{
	RACIONAL a, b, c;
	int n, d;
	char opi;
	scanf("%d/%d %c", &n, &d, &opi);
	criar_racional(n, d, &a);
	scanf("%d/%d", &n, &d);
	criar_racional(n, d, &b);
	
	switch(opi)
	{
		case '*': 
			mult(&a, &b, &c);
			printf("= %d/%d\n", c.num, c.den);
			break;
		case '+': 
			soma(&a, &b, &c);
			printf("= %d/%d\n", c.num, c.den);
			break;
		case '=': 
			if(equi(&a, &b)) printf("sao equivalentes\n");
			else printf("nao sao equivalentes\n");
			break;
	}
}

void criar_racional (int n, int d, RACIONAL *r)
{
	r->num=n;
	r->den=d;
}

void mult (RACIONAL* a, RACIONAL* b, RACIONAL* c)
{
	c->num = a->num * b->num;
	c->den = a->den * b->den;
}

void soma (RACIONAL*a, RACIONAL*b, RACIONAL*c)
{
	c->num = a->num * b->den + b->num * a->den;
	c->den = a->den * b->den;
}

int equi(RACIONAL*a, RACIONAL*b)
{
	if(a->num * b->den == b->num * a->den)
	return 1;
	return 0;
}
