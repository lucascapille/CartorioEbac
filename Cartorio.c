#include <stdio.h> // biblioteca para comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro () //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	
	setlocale(LC_ALL, "PORTUGUESE");
	
	//inicio cria��o de vari�veis (strings)
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//fim cria��o de vari�veis (strings)
	
	printf("Digite o CPF a ser cadastrado:"); //coletando informa��o do usu�rio
	scanf("%S", cpf); //%s refere-se a strings (para salvar as strings)
	
	strcpy(arquivo, cpf); //strcpy � respons�vel para copiar os valores das strings
	
	FILE *file; //respons�vel para criar arquivo no computador
	file=fopen(arquivo,"w"); //W = write - cria arquivo no computador
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); //fecha o arquivo File, que foi aberto em "fopen"
	
	file = fopen(arquivo,"a"); //usou a letra A ao inves de W, pois est� acessando um arquivo j� criado, se fosse criar novo ia ser um W
	fprintf(file,","); //usou a virgula para separar o nome do arquivo
	fclose(file); //fechou o arquivo
	
	printf("Digite o Nome a ser cadastrado:"); //coletar informa��o do usu�rio
	scanf("%s", nome); //%s refere-se a strings (para salvar as strings)
	
	file = fopen (arquivo, "a"); //usou a letra A ao inves de W, pois est� acessando um arquivo j� criado, se fosse criar novo ia ser um W
	fprintf (file,nome); //salvou o valor da vari�vel
	fclose(file); //fechou o arquivo
	
	file = fopen(arquivo, "a"); //usou a letra A ao inves de W, pois est� acessando (atualiza��o) um arquivo j� criado, se fosse criar novo ia ser um W
	fprintf(file, ","); //usou a virgula para separar o nome do arquivo
	fclose(file); //fechou o arquivo
	
	printf("Digite o Sobrenome a ser cadastrado:"); //coletar informa��es de usuario
	scanf("%s", sobrenome); //salvou o valor da vari�vel
	
	file = fopen(arquivo, "a"); //acessando um arquivo que j� foi criado
	fprintf(file, sobrenome); //salvou o valor da vari�vel
	fclose(file); //fechou o arquivo
	
	file = fopen(arquivo, "a"); //usou a letra A ao inves de W, pois est� acessando um arquivo j� criado, se fosse criar novo ia ser um W
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
		printf("N�o foi poss�vel localizar o arquivo!. \n");
	}
	
	while(fgets(conteudo, 200, file)!=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
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
		printf("O usu�rio n�o est� cadastrado no sistema! \n");
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
	
	 printf ("### Cart�rio da EBAC ###\n\n"); // inicio do menu
	 printf ("Escolha a op��o desejada no menu:\n\n");
	 printf ("\t1 - Registrar nomes\n");
	 printf ("\t2 - Consultar nomes\n");
	 printf ("\t3 - Deletar nomes \n\n");
	 printf ("Op��o"); // fim do menu
	
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
		printf ("Essa op��o n�o est� dispon�vel!\n");
		system("pause");
		break;	 	
	 }
	
	}
}

