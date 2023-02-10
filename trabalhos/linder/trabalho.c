#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Formato de todas as data: AAAA/MM/DD
typedef struct
{
	int todos, dataI[3], dataF[3], *tab, Ii, IP;
	FILE *F;
}PESQUISA;

typedef struct inf
{
	int data[3];
    long long casos, mortes, hospitalizados, testes, populacao;
    struct inf *prox, *ant;
}INF;

typedef struct pais
{   
    char *nome, *continente;
    INF *inf_primeiro, *inf_ultimo;
    int alt, qtd, mar;
    struct pais *esq, *dir;
}PAIS;

typedef PAIS* ArvoreAVL;

typedef struct nodo
{
    ArvoreAVL inf;
    struct nodo * next;
}NODO;

typedef struct
{
    NODO *INICIO;
    NODO *FIM;
}DESCRITOR;

typedef DESCRITOR *FILA_ENC;

typedef struct
{
	ArvoreAVL p;
	long long *d;
}LINHA;

//Funções/Macros criados por Gerson

//Retorna o  maximo entre os dois elementos x e y
#define max(x, y) ((x) > (y) ? (x) : (y))
//Retorna a altura do país, sendo zero se ele for NULL. Usado pra descobrir a altura dos filhos
#define altura(x) ((x) ? (x)->alt : 0)
//Retorna a quantidade de elementos da arvore
#define quantidade(x) ((x) ? (x)->qtd : 0)
#define qtd_tracos 103

ArvoreAVL criar_pais(ArvoreAVL*, char*, char*);
void buscar_pais(ArvoreAVL, char*);
ArvoreAVL buscar_pais2(ArvoreAVL, char*);
ArvoreAVL buscar_pais3(ArvoreAVL, char*);
void balancear_arvore(ArvoreAVL*, char*);
void rot_esquerda(ArvoreAVL*);
void rot_direita(ArvoreAVL*);
void destruir_arvore(ArvoreAVL*);

void* malloc_com_erro(int);
void* calloc_com_erro(int, int);
void* realloc_com_erro(void*, int);
char char_pergunta(char*);
void string_pergunta(char*, char*);
long long ll_pergunta(char*);

void inicializar_dados(ArvoreAVL*, int);
void pular_linha(FILE*);
ArvoreAVL inicializar_pais(ArvoreAVL*, char*, int);
char* pular_campos(char*, int);
char* ler_string_campo(char*);
void inserir_dado(ArvoreAVL, char*, int);
void adicionar_dado(ArvoreAVL*);
int validar_data(int*);
int ano_bissexto(int);
int comp_data(int*, int*);
char* copia_string(char*);
void alterar_banco(ArvoreAVL*);
void salvar_dados(ArvoreAVL);
void salvar_pais(ArvoreAVL, FILE*);
void imprime_linha_tracejada(int);
void pesquisa_personalizada(ArvoreAVL, int);
void criar_linhas(LINHA***, PAIS*, int, int*);
void adiciona_dado_linha(LINHA*, int, char, int*, int*);
void ordenar_linhas(LINHA**, int, int);

//Funções criadas por Pedro Amaro

void cria_fila(FILA_ENC *);
int vazia(FILA_ENC);
void ins(FILA_ENC, ArvoreAVL);
ArvoreAVL cons(FILA_ENC);
void ret(FILA_ENC);
void destruir(FILA_ENC);

void inicializar_tabela(int**);
void readme();
void imprimir(PAIS*, PESQUISA*);
void inicializar_P(PESQUISA*);
void buscar_cont(ArvoreAVL, char*, int);
void limpar(ArvoreAVL);

int main()
{
	PESQUISA P;
	char S[20], opi;
	ArvoreAVL a = NULL;
	
	puts("\tInicializando o banco de dados com o arquivo owid-covid-data.csv");
	inicializar_dados(&a, 2);
	char_pergunta("Digite algo para continuar");

	srand(time(0));
	inicializar_P(&P);
	
	while(1)
	{
		system("clear||cls");
		readme();
		opi = char_pergunta(NULL);	
		switch (opi)
		{
			case '1':
				alterar_banco(&a);
				continue;
			case '2':
				opi = char_pergunta("| 1 - Imprimir na tela | 2 - Salvar em um arquivo de texto | Outro: Cancelar");
				if(opi == '1')
				{
					P.F = stdout;
					imprimir(a, &P);
				}
				else if(opi == '2')
				{
					sprintf(S, "dados-%d.txt", rand());
					P.F = fopen(S, "a");
					imprimir(a, &P);
					fclose(P.F);
					printf("	Arquivo salvo como %s . Confira o diretorio onde o programa se encontra.", S);
				}
				break;
			case '3':
				opi = char_pergunta("| 1: Inverter ordem alfabetica | 2: Inverter data | Outro: Fim");
				switch (opi)
				{
					case '1':
						P.IP ^= 1;
						break;
					case '2':
						P.Ii ^= 1;
						break;
					default:
						break;
				}
				continue;
			case '4':
				opi = char_pergunta("Pesquisar por: 1 - Pais | 2- Continente | 3 - Data | Outro - Fim");
				while(opi>='1' && opi<='3')
				{
					if(opi=='1')
					{
						string_pergunta("Digite o nome do pais desejado ou 'todos'/'1' para imprimir todos. '-1' para limpar:", S);

						if(!strcmp(S,"1")||!strcmp(S, "todos"))
						{
							P.todos = 1;
							puts("	Todos os paises incluidos");
						}
						else if(!strcmp(S,"-1"))
							limpar(a);
						else
						{
							P.todos = 0;
							buscar_pais(a, S);
						}
					}
					else if(opi=='2')
					{
						string_pergunta("Digie o nome do continente desejado:", S);
						opi = char_pergunta("1- incluir | 0 - remover");

						if(opi=='1')
							P.todos = 0;

						buscar_cont(a, S, opi=='1');
					}
					else if(opi=='3')
					{
						opi = char_pergunta("incluir todas as datas? 1-S | 2-N");
						if(opi=='2')
						{
							while (1)
							{
								printf("\tDigite a data inicial:[AAAA/MM/DD]\n\t>");
								setbuf(stdin, NULL);
								opi = scanf(" %d/%d/%d", P.dataI, P.dataI + 1, P.dataI + 2);
								if(opi==3&&validar_data(P.dataI))
									break;
								puts("	Data invalida!");
							}

							while (1)
							{
								printf("\tDigite a data final:[AAAA/MM/DD]\n\t>");
								setbuf(stdin, NULL);
								opi = scanf(" %d/%d/%d", P.dataF, P.dataF + 1, P.dataF + 2);
								if(opi==3&&validar_data(P.dataF)&&comp_data(P.dataF,P.dataI)>=0)
									break;
								puts("	Data invalida!");
							}
						}
						else
						{
							P.dataI[0] = P.dataI[1] = P.dataI[2] = 0; 
							P.dataF[0] = P.dataF[1] = P.dataF[2] = 9999;
						}
						
					}

					opi = char_pergunta("Pesquisar por: 1 - Pais | 2- Continente | 3 - Data | Outro - Fim");
				}
				continue;
			case '5':
				opi = char_pergunta("Digite o numero do dado que deseja alterar: 1->Casos, 2->Mortes, 3->Hospitalizados, 4->Testes, 5->Populacao, outro->fim") - '1';
				while(opi>=0 && opi<=4)
				{
					if(P.tab[opi])
					{
						puts("	Dado removido da tabela.");
						P.tab[opi]=0;
					}
					else
					{
						puts("	Dado incluido na tabela.");
						P.tab[opi]=1;
					}
					opi = char_pergunta("Digite o numero do dado que deseja alterar: 1->Casos, 2->Mortes, 3->Hospitalizados, 4->Testes, 5->Populacao, outro->fim") - '1';
				}
				continue;
			case '6':
				pesquisa_personalizada(a, P.todos);
				break;
			default:
				opi = char_pergunta("Deseja realmente fechar o programa:[S/N]");
				if(opi != 'S' && opi != 's')
					continue;
				opi = char_pergunta("Deseja salvar o banco de dados antes de fechar:[S/N]");
				if(opi == 'S' || opi == 's')
					salvar_dados(a);
				exit(0);
		}
		char_pergunta("Digite algo para continuar");
	}
}


//Cria um pais e retorna um ponteiro para ele, inicializando a lista duplamente encadeada de informações com um elemento zerado
ArvoreAVL criar_pais(ArvoreAVL *a, char *nome, char *cont)
{
	//inicializa os dados do país
	*a = (PAIS*) malloc_com_erro(sizeof(PAIS));
	(*a)->esq = (*a)->dir = NULL;
	(*a)->alt = (*a)->qtd = 1;
	(*a)->mar = 0;
	(*a)->nome = nome;
	(*a)->continente = cont;
	
	//Cria uma elemento da lista de informações zerado
	(*a)->inf_ultimo = (*a)->inf_primeiro = (INF*) calloc_com_erro(1, sizeof(INF));
	
	return *a;
}

//Busca por um pais e troca o estado da marcação dele se encontrar
void buscar_pais(ArvoreAVL a, char *n)
{
	int c;
	while(a)
	{
		//Compara o nome com o país atual
		c = strcmp(n, a->nome);
		if(!c)
		{
			//Se for igual troca o estado da variavel mar informando o novo estado e sai da função
			puts((a->mar ^= 1) ? "\tPais incluido na pesquisa":"\tPais excluido da pesquisa");
			return;
		}
		
		//Se não for igual se desloca para lado correspondente da arvore
		a = (c < 0 ? a->esq : a->dir);
	}

	puts("Pais nao encontrado");
}

//Retorna o ponteiro pro país, sendo o que seria o pai dele se ele não existir
ArvoreAVL buscar_pais2(ArvoreAVL a, char *n)
{
	int c;
	while(1)
	{
		//Compara o nome com o país atual
		c = strcmp(n, a->nome);
		
		//Se for igual ou se não tem o filho do lado correspodende sai do loop
		if(!c || !(c < 0 ? a->esq : a->dir))
			break;
			
		//Recebe o filho correspondente
		a = (c < 0 ? a->esq : a->dir);
	}
	return a;
}

//Balancea a arvore ajustando as alturas e quantidades seguindo o caminho de um país
void balancear_arvore(ArvoreAVL *a, char *n)
{
	int c;
	
	//Compara o nome do país com o atual
	c = strcmp(n, (*a)->nome);
	
	//Se for igual termina a execução da função
	if(!c)
		return;
		
	//Chama o banceamento do lado que o pais está
	balancear_arvore((c < 0 ? &(*a)->esq : &(*a)->dir), n);
	
	//Verifica se está desbalanceado para um dos dois lados chamando as rotações para corrigir
	if(altura((*a)->esq) > altura((*a)->dir) + 1)
	{
		if(altura((*a)->esq->esq) < altura((*a)->esq->dir))
			rot_esquerda(&(*a)->esq);
		rot_direita(a);
	}
	else if(altura((*a)->esq) + 1 < altura((*a)->dir))
	{
		if(altura((*a)->dir->esq) > altura((*a)->dir->dir))
			rot_direita(&(*a)->dir);
		rot_esquerda(a);
	}
	else
	{
		//Só corrigi a altura e a quantidade do país atual se não estiver desbalanceada
		(*a)->alt = max(altura((*a)->esq) , altura((*a)->dir)) + 1;
		(*a)->qtd = quantidade((*a)->esq) + quantidade((*a)->dir) + 1;
	}
}

//Rotaciona a arvore a esquerda no nodo atual
void rot_esquerda(ArvoreAVL *p)
{
	PAIS *aux = *p;
	*p = (*p)->dir;
	aux->dir = (*p)->esq;
	(*p)->esq = aux;
	aux->alt = max(altura(aux->esq) , altura(aux->dir)) + 1;
	aux->qtd = quantidade(aux->esq) + quantidade(aux->dir) + 1;
	(*p)->alt = max(altura((*p)->esq) , altura((*p)->dir)) + 1;
	(*p)->qtd = quantidade((*p)->esq) + quantidade((*p)->dir) + 1;
}

//Rotaciona a arvore a direita no nodo atual
void rot_direita(ArvoreAVL *p)
{
	PAIS *aux = *p;
	*p = (*p)->esq;
	aux->esq = (*p)->dir;
	(*p)->dir = aux;
	aux->alt = max(altura(aux->esq) , altura(aux->dir)) + 1;
	aux->qtd = quantidade(aux->esq) + quantidade(aux->dir) + 1;
	(*p)->alt = max(altura((*p)->esq) , altura((*p)->dir)) + 1;
	(*p)->qtd = quantidade((*p)->esq) + quantidade((*p)->dir) + 1;
}

//destroi toda a sub-arvore apartir do nodo atual
void destruir_arvore(ArvoreAVL *a){
	INF *i, *p;
	if(*a)
	{
		//Destroi os dois filhos
		destruir_arvore(&(*a)->esq);
		destruir_arvore(&(*a)->dir);
		
		//Destroi todas as informações
		i = (*a)->inf_primeiro;
		while(i)
		{
			p = i->prox;
			free(i);
			i = p;
		}
		
		//Libera o nome, continente e a estrutura do pais
		free((*a)->nome);
		free((*a)->continente);
		free(*a);
		*a = NULL;
	}
}

//Função malloc com a captura do erro embutido
void* malloc_com_erro(int n){
	void *v = malloc(n);
	if(!v)
	{
		puts("Erro de memoria!");
		exit(1);
	}
	return v;
}

//Função calloc com a captura do erro embutido
void* calloc_com_erro(int q, int t)
{
	void *v = calloc(q, t);
	if(!v)
	{
		puts("Erro de memoria!");
		exit(1);
	}
	return v;
}

//Função realloc com a captura do erro embutido
void* realloc_com_erro(void *p, int t)
{
	void *v = realloc(p, t);
	if(!v)
	{
		puts("Erro de memoria!");
		exit(1);
	}
	return v;
}

//Faz uma pergunta e depois le e retorna um caracter
char char_pergunta(char* p)
{
	char c;
	if(p)
		printf("\n\t%s\n", p);
	printf("\t>");
	setbuf(stdin, NULL);
	scanf(" %c", &c);
	return c;
}

//Faz uma pergunta e depois le uma string no endereço dado
void string_pergunta(char *p, char *e)
{
	if(p)
		printf("\n\t%s\n", p);
	printf("\t>");
	setbuf(stdin, NULL);
	scanf(" %[^\n]", e);
}

//Faz uma pergunta e depois le e retorna um long long int
long long ll_pergunta(char *p)
{
	long long l;
	if(p)
		printf("\n\t%s\n", p);
	printf("\t>");
	setbuf(stdin, NULL);
	scanf(" %lld", &l);
	return l;
}

//Inicializa os dados de um banco de dados
void inicializar_dados(ArvoreAVL *a, int owid)
{
	char linha[1001];
	FILE *arq;
	PAIS *p;
	
	//Abrindo o arquivo de texto com todos os dados
	if(owid==2)
	{
		arq = fopen("owid-covid-data.csv", "r");
		if(!arq)
		{
			puts("\tERRO! base de dados nao esta contida no diretorio.");
			exit(1);
		}
	}
	else
		while(1)
		{
			//Pergunta o nome do arquivo
			if(owid)
				string_pergunta("Digite o nome do arquivo que contem os dados do OWID:", linha);
			else
				string_pergunta("Digite o nome do arquivo que contem os dados gerados pelo usuario:", linha);
				
			//Tenta abrir o arquivo
			arq = fopen(linha, "r");
			if(arq)
			{
				//Testa o primeiro caracter para verificar se o arquivo é a base de dados
				if(owid && fgetc(arq) == 'i' || !owid && fgetc(arq) == 'P')
					break;
				printf("\n\tArquivo nao corresponde a base de dados %s\n", (owid ? "do OWID" : "gerada pelo usuario"));
				continue;
			}
			puts("\n\tArquivo inexistente!!");
		}
	
	puts("\n\tCarregando banco de dados...");
	
	//Destroi a arvore existente
	destruir_arvore(a);
	
	//Pula a linha que contem os cabeçalhos da tabela
	pular_linha(arq);
	
	//Enquanto ainda tem linhas na tabela, insere ela na arvore
	while(fgets(linha, 1000, arq))
		inserir_dado(inicializar_pais(a, linha, owid), linha, owid);
	
	//Fecha o arquivo de texto
	fclose(arq);
	printf("\n\t%d locais carregados\n", quantidade(*a));
}

//Pula uma linha de um arquivo de texto
void pular_linha(FILE *arq)
{
	char c = fgetc(arq);

	while(c != EOF && c != '\n')
	{
		c = fgetc(arq);
	}
}

//Inicializa um pais se ele ainda não existe e depois retorna o ponteiro para o pais, apenas para banco de dados do owid
ArvoreAVL inicializar_pais(ArvoreAVL *a, char *linha, int owid)
{
	int c;
	char *nome, *cont;
	ArvoreAVL p;
	
	//Le o nome do país e do continente que estão no segundo e primeiro campos da linha respectivamente
	nome = ler_string_campo(pular_campos(linha, (owid ? 2 : 0)));
	cont = ler_string_campo(pular_campos(linha, 1));
	
	//Se a arvore for vazia cria um pais na raiz
	if(*a == NULL)
		return criar_pais(a, nome, cont);
	
	//Procura pelo país na arvore, recebendo o que seria o pai do pais se ele não existe
	p = buscar_pais2(*a, nome);
	c = strcmp(nome, p->nome);
	
	//Se não existe cria no lugar correspondente
	if(c)
	{
		p = criar_pais((c < 0 ? &p->esq : &p->dir), nome, cont);
		balancear_arvore(a, nome);
	}
	else
	{
		//Libera as strings nome e cont porque elas não seram mais usadas
		free(nome);
		free(cont);
	}
	
	return p;
}

//Pula q campos da linha da tabela
char* pular_campos(char *pt, int q)
{
	while(q--)
	{
		while(*pt != ',')
			pt++;
		pt++;
	}
	return pt;
}

//Le uma string da tabela, para na virgula ou no fim da linha
char* ler_string_campo(char *pt){
	int tam;
	char *l;
	
	//Calcula o tamanho da string
	for(tam = 0; pt[tam] && pt[tam] != ','; tam++);
	
	//Aloca o espaço para string e depois copia todos os caracteres
	l = (char*) malloc_com_erro((tam + 1) * sizeof(char));
	l[tam] = 0;
	while(tam--)
		l[tam] = pt[tam];
		
	return l;
}

//Insere os dados retirados da linha da tabela no pais
void inserir_dado(ArvoreAVL a, char *linha, int owid)
{
	int k, qp[] = {1, 3, 12, 7, 9}; //qp guarda a quantidade de campos que precisam ser pulado no OWID
	INF *i = (INF*) malloc_com_erro(sizeof(INF));
	
	a->inf_ultimo->prox = i;
	i->ant = a->inf_ultimo;
	
	//Le a data
	linha = pular_campos(linha, (owid ? 3 : 2));
	sscanf(linha, "%d-%d-%d", i->data, i->data + 1, i->data + 2);
	
	//Le os outros dados, colocando o resultado do resgistro anterior se o dado não for informado
	//Como casos, mortes, hospitalizados, testes, populacao ficam em sequencia dentro da struct,
	//usa o endereço de casos como base para o local de armazenamento de todos
	for(k = 0; k < 5; k++)
	{
		linha = pular_campos(linha, (owid ? qp[k] : 1));
		
		//tenta ler o dado, e se não ler nada repete o dado anterior
		if(!sscanf(linha, "%lld", &i->casos + k))
			(&i->casos)[k] = (k == 2 ? 0 : (&a->inf_ultimo->casos)[k]);
	}
	
	a->inf_ultimo = i;
	i->prox = NULL;
}

//Cria o dado de acordo com informações fornecidas pelo usurio
void adicionar_dado(ArvoreAVL *a)
{
	int c = 1;
	char nome[1001], cont[1001], op = 0;
	ArvoreAVL p;
	INF *i = (INF*) malloc_com_erro(sizeof(INF));
	
	//Pergunta o nome do país enquanto ele não informar o nome de país que já existe ou decidir criar o país
	while(op != 'S' && op != 's')
	{
		string_pergunta("Digite o nome do pais:", nome);
		if(*a == NULL)
			break;
		p = buscar_pais2(*a, nome);
		if(!strcmp(nome, p->nome))
		{
			c = 0;
			break;
		}
		op = char_pergunta("Pais nao encontrado, voce quer criar um novo?[S/N]");
	}
	
	//Se for para criar um pais pegunta o nome do continente depois cria ele balanceando a arvore depois
	if(c)
	{
		string_pergunta("Digite o nome do continente:", cont);
		if(*a == NULL)
			p = criar_pais(a, copia_string(nome), copia_string(cont));
		else
		{
			p = criar_pais((strcmp(nome, p->nome) < 0 ? &p->esq : &p->dir), copia_string(nome), copia_string(cont));
			balancear_arvore(a, nome);
		}
	}
	
	p->inf_ultimo->prox = i;
	i->ant = p->inf_ultimo;
	
	//Pergunta a data até ele informar uma data valida e que é depois do ultimo registro
	while(1)
	{
		printf("\tDigite a data:[AAAA/MM/DD]\n\t>");
		setbuf(stdin, NULL);
		c = scanf(" %d/%d/%d", i->data, i->data + 1, i->data + 2);
		
		//Verifica se leu 3 inteiros, a validade da data e depois se a data é depois do ultimo registro
		if(c == 3 && validar_data(i->data) && comp_data(i->data, p->inf_ultimo->data) > 0)
			break;
			
		printf("\n\tData invalida");
		if(p->inf_ultimo == p->inf_primeiro)
			putchar('\n');
		else
			printf(",ultima data: %04d/%02d/%02d\n", p->inf_ultimo->data[0], p->inf_ultimo->data[1], p->inf_ultimo->data[2]);
	}
	
	//Pergunta o total de casos até informar um valor maior do que o ultimo registro
	while(1)
	{
		i->casos = ll_pergunta("Digite a quantidade de casos:");
		if(i->casos >= p->inf_ultimo->casos)
			break;
		printf("\n\tQuantidade invalida, ultimo valor já adicionado: %lld\n", p->inf_ultimo->casos);
	}
	
	//Pergunta o total de mortes até informar um valor maior do que o ultimo registro
	while(1)
	{
		i->mortes = ll_pergunta("Digite a quantidade de mortes:");
		if(i->mortes >= p->inf_ultimo->mortes)
			break;
		printf("\tQuantidade invalida, ultimo valor já adicionado: %lld\n", p->inf_ultimo->mortes);
	}
	
	//Pergunta o numero de hospitalizados até informar um valor não negativo
	while(1)
	{
		i->hospitalizados = ll_pergunta("Digite a quantidade de hospitalizados:");
		if(i->hospitalizados >= 0)
			break;
		puts("\n\tQuantidade invalida");
	}
	
	//Pergunta o total de testes até informar um valor maior do que o ultimo registro
	while(1)
	{
		i->testes = ll_pergunta("Digite a quantidade de testes:");
		if(i->testes >= p->inf_ultimo->testes)
			break;
		printf("\n\tQuantidade invalida, ultimo valor já adicionado: %lld\n", p->inf_ultimo->testes);
	}
	
	//Pergunta a população até informar um valor não negativo
	while(1)
	{
		i->populacao = ll_pergunta("Digite a populacao:");
		if(i->populacao >= 0)
			break;
		puts("\n\tPopulacao invalida");
	}
	
	puts("\n\tInformacoes adicionadas com sucesso!");
	p->inf_ultimo = i;
	i->prox = NULL;
}

//Verifica se a data está correta
int validar_data(int *d)
{
	int qdm[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return d[0] >= 0 && d[1] > 0 && d[1] < 13 && d[2] > 0 && d[2] <= qdm[d[1]] + (d[1] == 2 && ano_bissexto(d[0]));
}

//Verifica se é um ano bissexto
int ano_bissexto(int a)
{
	return a % 4 == 0 && (a % 100 || a % 400 == 0);
}

//Compara duas datas, retornando a diferença entre as datas
int comp_data(int *a, int *b){
	if(a[0] != b[0])
		return a[0] - b[0];
	if(a[1] != b[1])
		return a[1] - b[1];
	return a[2] - b[2];
}

//Cria uma copia da string com alocação dinamica
char* copia_string(char *s)
{
	int i;
	char *c = malloc((strlen(s) + 1) * sizeof(char));
	for(i = 0; s[i]; i++)
		c[i] = s[i];
	c[i] = 0;
	return c;
}

//Menu de alteração do banco de dados
void alterar_banco(ArvoreAVL *a)
{
	char op;
	while(1)
	{
		system("clear||cls");
		imprime_linha_tracejada(qtd_tracos);
		puts("Alterar Banco de Dados:\n");
		puts("\t1 - carregar banco de dados do our world in data");
		puts("\t2 - carregar banco de dados gerado pelo usuario");
		puts("\t3 - inserir novos dados");
		puts("\t4 - Salvar o banco de dados num arquivo");
		puts("\t5 - limpar banco de dados");
		puts("\tOutro para voltar ao menu principal\n");
		imprime_linha_tracejada(qtd_tracos);
		op = char_pergunta(NULL);
		switch(op)
		{
			case '1':
				inicializar_dados(a, 1);
				break;
			case '2':
				inicializar_dados(a, 0);
				break;
			case '3':
				adicionar_dado(a);
				break;
			case '4':
				salvar_dados(*a);
				break;
			case '5':
				destruir_arvore(a);
				puts("\n\tArvore destruida com sucesso");
				break;
			default:
				return;
		}
		char_pergunta("Digite algo para continuar");
	}
}

void salvar_dados(ArvoreAVL a)
{
	char s[1001], op;
	FILE *f;
	
	//Pergunta o nome do arquivo enquanto o arquivo já existir e o usuario não quiser subistituir
	while(1)
	{
		string_pergunta("Digite o nome do arquivo:[.csv de preferencia]", s);
		
		//Tenta abrir o arquivo no modo leitura pra testar se ele já existe
		f = fopen(s, "r");
		if(f)
		{
			fclose(f);
			op = char_pergunta("Arquivo ja existe, deseja substituir:[S/N]");
			if(op != 'S' && op != 's')
				continue;
		}
		
		//Tenta abrir no modo de escrita
		f = fopen(s, "w");
		if(f)
			break;
		puts("\tNome de arquivo invalido");
	}
	
	//Imprime o cabeçalho da tabela e depois salva todos os dados
	fprintf(f, "Pais,Continente,Data,Casos,Mortes,Hospitalizados,Testes,Populacao\n");
	salvar_pais(a, f);
	fclose(f);
	puts("\n\tAquivo gerado com sucesso"); 
}

//Salva todos os dados em ordem alfabética no arquvivo dado
void salvar_pais(ArvoreAVL a, FILE *f)
{
	INF *i;
	if(a)
	{
		salvar_pais(a->esq, f);
		
		i = a->inf_primeiro->prox;
		while(i)
		{
			fprintf(f, "%s,%s,%04d-%02d-%02d,", a->nome, a->continente, i->data[0], i->data[1], i->data[2]);
			fprintf(f, "%lld,%lld,%lld,%lld,%lld\n", i->casos, i->mortes, i->hospitalizados, i->testes, i->populacao);
			i = i->prox;
		}
		
		salvar_pais(a->dir, f);
	}
}

//Imprime uma linha com q traços
void imprime_linha_tracejada(int q)
{
	while(q--)
		putchar('-');
	putchar('\n');
}

//Faz uma pesquisa personalizada
void pesquisa_personalizada(ArvoreAVL a, int t)
{
	char opi, n[1001];
	const char *titulos[] = {"Casos   ", "Mortes   ", "Hospitaliza.", "Testes   ", "Popululacao "};
	LINHA **l = NULL;
	int q = 0, d = 0, al, i, j, *tipo = NULL, **datas = NULL;
	FILE *f;
	
	//Cria as linhas com os paises marcados
	criar_linhas(&l, a, t, &q);
	
	//Pergunta se deseja ordenar em ordem alfabética e salva em al 'true' se sim
	opi = char_pergunta("ordenar em ordem alfabetica?[S/N]");
	al = (opi == 'S' || opi == 's');
	
	
	//Insere todos os dados pedido pelo usuário
	while(1){
		opi = char_pergunta("Digite os dados que vc quer adicionar:[1->Casos 2->Mortes 3->Hosp 4->Testes 5->Populacao Outro->Fim]") - '1';
		if(opi < 0 || opi > 4)
			break;
		
		//Aloca espaço pra mais uma dada no fim do vetor
		datas = (int**) realloc_com_erro(datas, (d + 1) * sizeof(int*));
		datas[d] = (int*) malloc_com_erro(6 * sizeof(int));
		
		//Pede a data inicial até o usuário fornecer uma data valida
		while (1)
		{
			printf("\n\tDigite a data inicial:[AAAA/MM/DD]\n\t>");
			setbuf(stdin, NULL);
			if(scanf(" %d/%d/%d", datas[d], datas[d] + 1, datas[d] + 2) == 3 && validar_data(datas[d]))
				break;
			puts("\n\tData invalida!");
		}
		
		//Pede a data final até o usuário fornecer uma data valida que não é antes da primeira
		while (1)
		{
			printf("\n\tDigite a data final:[AAAA/MM/DD]\n\t>");
			setbuf(stdin, NULL);
			if(scanf(" %d/%d/%d", datas[d] + 3, datas[d] + 4, datas[d] + 5) == 3 && validar_data(datas[d] + 3) && comp_data(datas[d], datas[d] + 3) <= 0)
				break;
			puts("\n\tData invalida!");
		}
		
		//Adiciona esse novo dado para todos as linhas da tabela
		for(i = 0; i < q; i++)
			adiciona_dado_linha(l[i], d, opi, datas[d], datas[d] + 3);
		
		//Aloca espaço pra mais um tipo e salva a ultima opção selecianada pelo usuário
		tipo = (int*) realloc_com_erro(tipo, (d + 1) * sizeof(int));
		tipo[d++] = opi;
	}
	
	//Se a ordenação não for alfabética ordena as linhas de acordo com os dados adicionados
	if(!al)
		ordenar_linhas(l, q, d);
		
	//Pergunta se o usuário quer salvar a pesquisa num arquivo de texto no lugar de imprimir na telas
	opi = char_pergunta("Deseja salvar a pesquisa num arquivo de texto?:[S/N]");
	if(opi == 's' || opi == 'S')
	{
		//Pergunta o nome do arquivo enquanto o arquivo já existir e o usuario não quiser subistituir
		while(1)
		{
			string_pergunta("Digite o nome do arquivo:", n);
			
			//Tenta abrir o arquivo no modo leitura pra testar se ele já existe
			f = fopen(n, "r");
			if(f)
			{
				fclose(f);
				opi = char_pergunta("Arquivo ja existe, deseja substituir:[S/N]");
				if(opi != 'S' && opi != 's')
					continue;
			}
			
			//Tenta abrir no modo de escrita
			f = fopen(n, "w");
			if(f)
				break;
			puts("\n\tNome de arquivo invalido");
		}
	}
	else
		f = stdout;
	
	//Imprime uma linha com os titulos das colunas
	fprintf(f, "\n%-32s|", "Paises");
	for(i = 0; i < d; i++)
		fprintf(f, "%12s|", titulos[tipo[i]]);
		
	//Imprime uma linha com as datas iniciais das colunas
	fprintf(f, "\n%33s", "|");
	for(i = 0; i < d; i++)
		fprintf(f, " %02d/%02d/%04d |", datas[i][2], datas[i][1], datas[i][0]);
		
	//Imprime uma linha com as datas finais das colunas
	fprintf(f, "\n%33s", "|");
	for(i = 0; i < d; i++)
		fprintf(f, " %02d/%02d/%04d |", datas[i][5], datas[i][4], datas[i][3]);
	fprintf(f, "\n");
	
	//Imprime uma linha só com traços
	for(i = 32 + 13 * d; i != -1; i--)
		fprintf(f, "-");
	fprintf(f, "\n");
	
	//Para todos as linhas, imprime o nome do pais e todos os dados contidos na linha
	for(i = 0; i < q; i++){
		fprintf(f, "%-32.32s|", l[i]->p->nome);
		for(j = 0; j < d; j++)
			fprintf(f, "%11lld |", l[i]->d[j]);
		fprintf(f, "\n");
	}
	
	//Se o arquivo for diferente da saida padrão informa que salvou o arquivo e fecha esse arquivo
	if(f != stdout)
	{
		puts("\n\tArquivo salvo com sucesso!");
		fclose(f);
	}
	
	//Libera todo o espaço usado pelas linhas
	for(i = 0; i < q; i++)
	{
		free(l[i]->d);
		free(l[i]);
	}
	free(l);
	
	//Libera os espaços das datas e dos tipos
	for(i = 0; i < d; i++)
		free(datas[i]);
	free(datas);
	free(tipo);
}

//Cria as linhas com os paises marcados
void criar_linhas(LINHA ***l, PAIS *p, int t, int *q)
{
	if(p)
	{
		criar_linhas(l, p->esq, t, q);
		
		//Se o pais estiver marcado aloca espaço pra uma nova linha e salva ela
		if(t || p->mar)
		{
			*l = (LINHA**) realloc_com_erro(*l, (*q + 1) * sizeof(LINHA*));
			(*l)[*q] = (LINHA*) malloc_com_erro(sizeof(LINHA));
			(*l)[*q]->d = NULL;
			(*l)[(*q)++]->p = p;
		}
		criar_linhas(l, p->dir, t, q);
	}
}

//Adiciona o dado na linha
void adiciona_dado_linha(LINHA *l, int d, char o, int *di, int *df)
{
	int i;
	
	//Aloca espaço pra um dado a mais na linha e insere o novo dado
	l->d = (long long*) realloc(l->d, (d+1) * sizeof(long long));
	if(o < 2 || o == 3)
	{
		//Se for casos, mortes ou testes salva a diferença entre os valores na data final e antes da data inicial
		INF *i = l->p->inf_primeiro;
		
		//Pula todas as datas menores do que a inicial
		while(i && comp_data(i->data, di) < 0)
			i = i->prox;
			
		//Se a data inicial for depois da ultima data no banco só salva 0 e sai da função	
		if(!i)
		{
			l->d[d] = 0;
			return;
		}
		
		//Salva menos o valor contido no registro anterior da data inicial
		l->d[d] = (i->ant ? -(&(i->ant)->casos)[o] : 0);
		
		//Pula todas as datas menores ou iguais a data final
		while(i->prox && comp_data(i->data, df) <= 0)
			i = i->prox;
			
		//Se a data atual for maior do que a data final adiciona o valor da anterior, se não adiciona a atual
		l->d[d] += (comp_data(i->data, df) > 0 ? (&(i->ant)->casos)[o] : (&i->casos)[o]);
	}
	else
	{
		//Para hospitalizados e população calcula o valor máximo no intervalo de tempo indicado
		INF *i = l->p->inf_primeiro;
		l->d[d] = 0;
		
		//Pula todas as datas menores do que a inicial
		while(i && comp_data(i->data, di) < 0)
			i = i->prox;
			
		//Vai calculando o maximo entre os valores com datas menores ou iguais a data final
		while(i && comp_data(i->data, df) <= 0)
		{
			l->d[d] = max(l->d[d], (&i->casos)[o]);
			i = i->prox;
		}
	}
}

//Ordena as linhas usando um bubble sort
void ordenar_linhas(LINHA **l, int q, int d)
{
	int i, j, k, m;
	LINHA *aux;
	
	//Para cada uma das linhas calcula a menor entre as próximas e troca com a atual
	for(i = 0; i < q; i++)
	{
		m = i;
		for(j = i + 1; j < q; j++)
		{
			//Pula todos os dados iguais entre as linhas até chegar no ultimo ou num valor diferente
			for(k = 0; k < d && l[m]->d[k] == l[j]->d[k]; k++);
			
			//Se a linha atual for menor, coloca ela como menor
			if(l[m]->d[k] < l[j]->d[k])
				m = j;
		}
		
		//Se a menor linha for diferente da atual troca as duas linhas
		if(i != m)
		{
			aux = l[i];
			l[i] = l[m];
			l[m] = aux;
		}
	}
}

void inicializar_tabela(int **tab)
{
	int i;

	*tab = (int*) malloc_com_erro(5*sizeof(int));

	for(i=0; i<5; i++)
		(*tab)[i]=1;
}


void readme()
{
	FILE *F;
	char c;
	
	F = fopen("readme.txt", "r");
	if(!F)
	{
		printf("Faltando 'readme.txt'.\n");
		exit(10);
	}
	
	c = fgetc(F);
	while(c!=EOF)
	{
		printf("%c", c);
		c = fgetc(F);
	}
}

void imprimir(PAIS *p, PESQUISA *P)
{
	if(p)
	{
		INF *i;
		i = P->Ii?p->inf_ultimo:p->inf_primeiro->prox;

		imprimir(P->IP?p->dir:p->esq, P);
	
		if(P->todos||p->mar)
		{
			fprintf(P->F, "\n	%s - %s\n", p->nome, p->continente);
			
			if(P->Ii)
			{
				while (i!=p->inf_primeiro&&comp_data(P->dataF,i->data)<0)
					i = i->ant;
			

				while(i!=p->inf_primeiro&&comp_data(P->dataI,i->data)<=0)
				{
					fprintf(P->F, "\t| %04d-%02d-%02d |", i->data[0], i->data[1], i->data[2]);
					if(P->tab[0])
						fprintf(P->F, " Casos:%-10lld", i->casos);
					if(P->tab[1])
						fprintf(P->F, " Mortes:%-10lld", i->mortes);
					if(P->tab[2])
						fprintf(P->F, " Hospitalizados:%-10lld", i->hospitalizados);
					if(P->tab[3])
						fprintf(P->F, " Testes:%-10lld", i->testes);
					if(P->tab[4])
						fprintf(P->F, " Populacao:%10lld", i->populacao);
					fprintf(P->F, "|\n");
					i = i->ant;
				}
			}
			else
			{
				while (i&&comp_data(P->dataI,i->data)>0)
					i = i->prox;
			

				while(i&&comp_data(P->dataF,i->data)>=0)
				{
					fprintf(P->F, "\t| %04d-%02d-%02d |", i->data[0], i->data[1], i->data[2]);
					if(P->tab[0])
						fprintf(P->F, " Casos:%-10lld", i->casos);
					if(P->tab[1])
						fprintf(P->F, " Mortes:%-10lld", i->mortes);
					if(P->tab[2])
						fprintf(P->F, " Hospitalizados:%-10lld", i->hospitalizados);
					if(P->tab[3])
						fprintf(P->F, " Testes:%-10lld", i->testes);
					if(P->tab[4])
						fprintf(P->F, " Populacao:%10lld", i->populacao);
					fprintf(P->F, "|\n");
					i = i->prox;
				}
			}
			
		}
		
		imprimir(P->IP?p->esq:p->dir, P);
	}
}

void inicializar_P(PESQUISA *P)
{
	inicializar_tabela(&P->tab);
	P->todos = 1;
	P->dataI[0] = P->dataI[1] = P->dataI[2] = 0; 
	P->dataF[0] = P->dataF[1] = P->dataF[2] = 9999;
	P->Ii = P->IP = 0;
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

void ins(FILA_ENC F, ArvoreAVL v)
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

ArvoreAVL cons(FILA_ENC F)
{
    if(!F->INICIO)
    {
        puts("fila vazia");
		exit(404);
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

void destruir(FILA_ENC F)
{
    NODO *aux;

    while(F->INICIO)
    {
        aux = F->INICIO;
        F->INICIO = F->INICIO->next;
        free(aux);
    }
    free(F);
}

void buscar_cont(ArvoreAVL A, char *S, int opi) 
{
    FILA_ENC fila;

    cria_fila(&fila);

    if(A)
    {
        ins(fila, A);

        while(!vazia(fila))
        {
            if(!(strcmp(cons(fila)->continente, S)))
			{
				(cons(fila))->mar = opi;
			}

            if(cons(fila)->esq)
                ins(fila, cons(fila)->esq);
            if(cons(fila)->dir)
                ins(fila, cons(fila)->dir);
            
            ret(fila);
        }
    }

	destruir(fila);
}

void limpar(ArvoreAVL A)
{
	FILA_ENC fila;

    cria_fila(&fila);

    if(A)
    {
        ins(fila, A);

        while(!vazia(fila))
        {
            
			(cons(fila))->mar = 0;
			
            if(cons(fila)->esq)
                ins(fila, cons(fila)->esq);
            if(cons(fila)->dir)
                ins(fila, cons(fila)->dir);
            
            ret(fila);
        }
    }

	destruir(fila);
}
