1-

int tam(LIST_ENC L)
{
	int cont=0;
	
	if(L==NULL)
		return cont;
		
	return tam(L->next)+1;
}

2-

int cons(LIST_ENC L, int pos)
{
	if(pos<1||pos>tam(L))
	{
		printf("pos invalida");
		exit(0);
	}
	
	if(pos==1)
	{
		return L->inf
	}
	
	return cons(L->next), pos-1);
}

3-

void destruir(LIST_ENC L)
{	
	if(L)
	{
		destruir(L->next);
		free(L);
	}
}

4- 
	a)
		int pertence(LISTA_ENC L, int val)
		{	
			while(L)
			{
				if(L->inf == val)
					return 1;
					
				L = L->next;
			}
			
			return 0;
		}
	
	b)
		int pertence(LISTA_ENC L, int val)
		{
			if(!L)
				return 0
				
			if(L->inf == val)
				return 1;
			
			return pertence(L->next, val);
		}
		
5-
	a)
		int ord(LISTA_ENC L)
		{
			int aux;
			
			if(vazia(L) || tam(L)==1)
			{
				return 1;
			}
			
			do
			{
				if( L->inf >= (L->next)->inf )
					return 0;
				
				L = L->next;
			}while(L->next);
			
			return 1;
		}
	
	b)
		int ord(LISTA_ENC L)
		{
			if(!L || ( L && !(L->next) ) )
			{
				return 1;
			}
			
			if( L-inf >= (L->next)->inf )
				return 0;
			
			return ord(L->next);
		}
		
6-
	void gera_lista(LISTNA_ENC *pL, int m, int n)
	{
		if(m>n)
		{
			printf("intervalo invalido");
			return;	
		}
		
		if(m==n)
		{
			criar_lista(pL);
			ins(pL, 1, m);
		}
		else
		{
			gera_lista(pL, m+1, n);
			ins(pL, 1, m);
		}
	}




