
int mdc (int num1, int num2)
{
	int resto
	
	do
	{
		resto = num1%num2;
		num1 = num2;
		num2 = resto;
	}while(resto);
	
	return abs(num1);
} 
