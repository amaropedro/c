#include <stdio.h>
#include <string.h>

int fat(int num)
{
	if(num==1)
	return num;
	else
	return num*fat(num-1);
}

int main(int argc, char *argv[])
{
	int i;
	printf("vivo\n");
	sscanf(argv[1], "%d", &i);
	printf("i=%d\n", i);
	printf("%d", fat(i));
}
