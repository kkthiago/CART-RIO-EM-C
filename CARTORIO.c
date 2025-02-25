#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //bibilioteca responsavel por cuidar das strings

int registro() //função responsável por cadastrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	//início de criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char job[40];

	printf("Digite seu CPF a ser cadastrado:\n"); //coletando a informação do usuário
	scanf("%s", cpf); // %s refere-se a string
	getchar();

	printf("Digite o nome a ser cadastrado:\n"); //coletando a informação do usuário
	scanf("%[^\n]", nome); //%[^\n] le apenas uma linha de texto, para encaixar na variável
	getchar();

	printf("Digite o sobrenome a ser cadastrado:\n"); //coletando a informação do usuário
	scanf("%[^\n]", sobrenome);
	getchar();

	printf("Digite o cargo a ser cadastrado:\n"); //coletando a informação do usuário
	scanf("%[^\n]", job);
	getchar();

	strcpy(arquivo, cpf); // Nome do arquivo será o CPF

	FILE *file = fopen(arquivo, "w"); // Criar ou sobrescrever o arquivo
	if (file == NULL) {
		printf("Erro ao criar o arquivo!\n");
		system("pause");
		return 1;
	}

	// Escrevendo os dados no arquivo de uma vez só
	fprintf(file, "%s,%s, %s,%s\n", cpf, nome, sobrenome, job);
	
	
	fclose(file);

	printf("\nRegistro salvo com sucesso!\n\n");
	system("pause");

	return 0;
}
int consulta() //função de consultar os cpf
{
	setlocale(LC_ALL, "Portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado:\n\n");  //escrever o cpf na variavel, para procurar no file depois
	scanf("%s", cpf);
	system("cls"); // funcao de limpar a tela
	
	FILE *file = fopen(cpf,"r"); //função de abrir o file
	
	if(file == NULL)
	{
		printf("\nNão foi possível abrir o arquivo, não localizado...\n\n");
		system("pause");
		return 1;
	}
	printf("\nEssas são as informações do usuário: \n\n");
	
	while(fgets(conteudo, 200, file)!= NULL) // "imprimir" o conteudo dentro do file, ou seja, o usuário
	{
		printf("%s", conteudo);
	}
	
	printf("\n\n");
	fclose(file);
	system("pause");
	return 0;		
}
	

int deletar() //funcao para deletar cpfs no arquivo file
{
	char cpf[40];
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	FILE * file = fopen(cpf,"r"); // abrir o arquivo file com intencao de read (ler)
	
	if(file == NULL) // SE nao houver nenhum cpf com este nome, informar que nao há
	{
		printf("\nO usuário não se encontra no sistema... \n\n");
		system("pause");
	}
	else // SE houver, apagar e remover o arquivo com este cpf
	{
		fclose(file);
		remove(cpf);
		printf("\nUsuário deletado com exito.\n\n"); 
		system("pause");
	}
	return 0;
	
}
int sair() // funcao para sair do programa, dando return 0
{
	printf("\nSaindo do sistema...\n\n");
	system("pause");	
}

int main()
{
	int opcao=0; //definindo variáveis
	int laco=1;	
	
	while(1) //sistema infinito de repeticao para voltar ao menu
	{
		system("cls");
		setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
		printf("#### Cartório da EBAC ####\n\n"); //inicio do menu
		printf("Escolha a opção desejada no menu: \n\n");
		printf("\t1 - Registrar nomes\n\n");
		printf("\t2 - Consultar nomes\n\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("\t4- Sair do menu\n\n");
		printf("Opção: "); //fim do menu
	
		scanf("%d", &opcao); //pergunta e resposta
		system("cls"); // funcao de limpar a tela
		
		switch(opcao) // sistema de escolhar, quase um if e elses
		{
			case 1:
				registro(); //comeback dos primeiras funções
				break;
			case 2:
				consulta(); //comeback dos primeiras funções
				break;
			case 3:
				deletar(); //comeback dos primeiras funções
				break;
			case 4: 
				sair(); // sair do app
				return 0; 
			default:
				printf("\nEssa opção não está disponível!\n\n");
				system("pause");
				break;
		} //fim do processo
}
}
