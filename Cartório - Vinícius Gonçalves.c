#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocações de espao em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings


int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Início da criação das variáveis/string
	char arquivo[40]; 
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf(" %s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file;  //Cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo e o "w" significa escrever
	fprintf(file, " %s", cpf);  //salva o valor da variável
	fclose(file);  //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf(" %s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf(" %s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf(" %s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
	return 0;
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CFP a ser consultado: ");
	scanf(" %s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");	
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf(" %s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	return 0;
	
	
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf(" %s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
		return 0;
	}
	
}


int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	char senhadigitada[]="a";
	int comparacao;
	
	printf("### Cartório da Ebac ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha:");
	scanf(" %s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
		
	
		system ("cls");
		for (laco=1;laco=1;)
		{
		
			system("cls");
	
			setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
			printf("### Cartório da EBAC ###\n\n"); //Início do Menu
			printf("Escolha a opção desejada do menu:\n\n");
			printf("\t1 - Registrar Nomes\n");
			printf("\t2 - Consultar Nomes\n");
			printf("\t3 - Deletar Nomes\n\n");
			printf("\t4 - Sair do Sistema\n\n");
			printf("Qual opção você deseja?\n\n"); //Fim do Menu

			scanf(" %s" , &opcao); //Armazenando a escolha do usuário

			system("cls"); //responsável por limpar a tela
		
		
			switch(opcao) //início da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default: 
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
				
			
			} //fim da seleção
		
	
		}
	}
}	
