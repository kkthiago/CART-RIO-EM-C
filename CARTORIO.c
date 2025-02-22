#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região

int main()
{
	setlocale(LC_ALL, "Portuguese");
	printf("#### Cartório da EBAC ####\n\n");
	printf("Escolha a opção desejada no menu: \n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar nomes\n");
	printf("\t3 - Deletar nomes\n\n");
	printf("Esse software é de livre uso dos alunos\n");
}
