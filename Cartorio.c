#include <stdio.h> // biblioteca para comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocação de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro () //Função responsável por cadastrar os usuários no sistema
{
	
	setlocale(LC_ALL, "PORTUGUESE");
	
	//inicio criação de variáveis (strings)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//fim criação de variáveis (strings)
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informação do usuário
	scanf("%S", cpf); //%s refere-se a strings (para salvar as strings)
	
	strcpy(arquivo, cpf); //strcpy é responsável para copiar os valores das strings
	
	FILE *file; //responsável para criar arquivo no computador
	file=fopen(arquivo,"w"); //W = write - cria arquivo no computador
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo File, que foi aberto em "fopen"
	
	file = fopen(arquivo,"a"); //usou a letra A ao inves de W, pois está acessando um arquivo já criado, se fosse criar novo ia ser um W
	fprintf(file,","); //usou a virgula para separar o nome do arquivo
	fclose(file); //fechou o arquivo
	
	printf("Digite o Nome a ser cadastrado:"); //coletar informação do usuário
	scanf("%s", nome); //%s refere-se a strings (para salvar as strings)
	
	file = fopen (arquivo, "a"); //usou a letra A ao inves de W, pois está acessando um arquivo já criado, se fosse criar novo ia ser um W
	fprintf (file,nome); //salvou o valor da variável
	fclose(file); //fechou o arquivo
	
	file = fopen(arquivo, "a"); //usou a letra A ao inves de W, pois está acessando (atualização) um arquivo já criado, se fosse criar novo ia ser um W
	fprintf(file, ","); //usou a virgula para separar o nome do arquivo
	fclose(file); //fechou o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado:"); //coletar informações de usuario
	scanf("%s", sobrenome); //salvou o valor da variável
	
	file = fopen(arquivo, "a"); //acessando um arquivo que já foi criado
	fprintf(file, sobrenome); //salvou o valor da variável
	fclose(file); //fechou o arquivo
	
	file = fopen(arquivo, "a"); //usou a letra A ao inves de W, pois está acessando um arquivo já criado, se fosse criar novo ia ser um W
	fprintf(file, ","); //usou a virgula para separar o nome do arquivo
	fclose(file);
	
	printf("Digite o Cargo a ser cadastrado:");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta ()
{
	setlocale(LC_ALL, "PORTUGUESE"); // definindo a linguagem
	
	char cpf [40];
	char conteudo [100];
	
	printf("Digite o CPF a ser consultado:");
	scanf("%s", cpf);
	
	FILE *file;
	file= fopen(cpf, "r"); //a Letra R usada para ler o arquivo
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o arquivo!. \n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar ()
{
	char cpf [40];
	printf ("Digite o CPF a ser deletado:");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
		
	if(file == NULL)
	{
		printf("O usuário não está cadastrado no sistema! \n");
		system("pause");
	}
}

int main ()

{
	
	int opcao=0; // definindo as variaveis
	int x=1;
	
	for(x=1;x=1;)
	{
		
	 system("cls");	
	
	 setlocale(LC_ALL, "PORTUGUESE"); // definindo a linguagem
	
	 printf ("### Cartório da EBAC ###\n\n"); // inicio do menu
	 printf ("Escolha a opção desejada no menu:\n\n");
	 printf ("\t1 - Registrar nomes\n");
	 printf ("\t2 - Consultar nomes\n");
	 printf ("\t3 - Deletar nomes \n\n");
	 printf ("Opção"); // fim do menu
	
	 scanf("%d", &opcao); // armazenando escolha usuario
	
	 system("cls");
	
	 switch(opcao)
	 {
	 	case 1:
	 	registro();
	 	break;
	 	
	 	case 2:
	 	consulta();
		break;
		
		case 3:
		deletar();
		break;
		
		default:
		printf ("Essa opção não está disponível!\n");
		system("pause");
		break;	 	
	 }
	
	}
}

