#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

#define SENHA_ADMIN "admin123" // Defina a senha do admin aqui

int registro() {
    setlocale(LC_ALL, "Portuguese");

    char arquivo[40];
    char input[12]; // CPF temporário de entrada
    char cpf[12];
    char nome[40];
    char sobrenome[40];
    char job[40];
    char senhadigi[40];

    printf("Digite seu CPF a ser cadastrado: (SOMENTE NÚMEROS) \n");
    scanf("%s", input);

    while (1) {
        int i;

        if (strlen(input) != 11) {
            system("cls");
            printf("\nCPF inválido! Deve contar 11 dígitos\n");
            system("pause");
            continue;
        }

        for (i = 0; i < 11; i++) {
            if (!isdigit(input[i])) {
                system("cls");
                printf("CPF inválido! Deve conter apenas números. \n\n");
                system("pause");
                break;
            }
        }

        strcpy(cpf, input);
        break;
    }

    printf("Digite o nome a ser cadastrado: (APENAS PRIMEIRO NOME)\n");
    getchar();
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o sobrenome a ser cadastrado:\n");
    fgets(sobrenome, sizeof(sobrenome), stdin);
    sobrenome[strcspn(sobrenome, "\n")] = '\0';

    printf("Digite o cargo a ser cadastrado:\n");
    fgets(job, sizeof(job), stdin);
    job[strcspn(job, "\n")] = '\0';

    printf("Digite sua SENHA a ser cadastrada:\n");
    scanf("%s", senhadigi);

    sprintf(arquivo, "%s.txt", cpf);

    FILE *file = fopen(arquivo, "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo!\n");
        system("pause");
        return 1;
    }

    fprintf(file, "%s,%s,%s,%s,%s\n", cpf, nome, sobrenome, job, senhadigi);

    fclose(file);

    printf("\nRegistro salvo com sucesso!\n\n");
    system("pause");

    return 0;
}

int consulta() {
    setlocale(LC_ALL, "Portuguese");
    char cpf[12];
    char conteudo[200];

    printf("Digite o CPF a ser consultado:\n\n");
    scanf("%s", cpf);
    system("cls");

    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("\nNão foi possível abrir o arquivo, não localizado...\n\n");
        system("pause");
        return 1;
    }
    printf("\nEssas são as informações do usuário: \n\n");

    while (fgets(conteudo, 200, file) != NULL) {
        printf("%s", conteudo);
    }

    fclose(file);
    system("pause");
    return 0;
}

int deletar() {
    char cpf[12];
    char senhadigi[40];
    char conteudo[200];

    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");

    if (file == NULL) {
        printf("\nO usuário não se encontra no sistema... \n\n");
        system("pause");
    } else {
        printf("\nDigite a sua senha:\n");
        scanf("%s", senhadigi);
        getchar();

        while (fgets(conteudo, 200, file) != NULL) {
            if (strstr(conteudo, senhadigi) != NULL) {
                printf("\nSENHA VERIFICADA\n");
                fclose(file);
                remove(cpf);
                system("cls");
                printf("\nUsuário deletado com êxito.\n\n");
                system("pause");
                return 0;
            }
        }

        system("cls");
        printf("\nVocê deve saber a senha do usuário para deletá-lo\n");
        system("pause");
    }

    fclose(file);
    return 0;
}

int sair() {
    printf("\nSaindo do sistema...\n\n");
    system("pause");
    return 0;
}

// Função para verificar a senha do admin
int verificarSenhaAdmin() {
    char senha[40];
    printf("\nDigite a senha do administrador para acessar o menu: ");
    scanf("%s", senha);
    
    if (strcmp(senha, SENHA_ADMIN) == 0) {
        return 1; // Senha correta
    } else {
        printf("\nSenha incorreta! Acesso negado.\n");
        return 0; // Senha incorreta
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao = 0;
    char senhadigi[40];
    char cpf[12];
    char nome[40];
    char conteudo[200];

    printf("#### Cartório da EBAC ####\n");

    // Verifica se a senha de administrador está correta antes de acessar o menu
    if (!verificarSenhaAdmin()) {
        return 0; // Se a senha estiver incorreta, o programa termina
    }

    printf("\nDigite o seu CPF:\n");
    scanf("%s", cpf);

    FILE *file = fopen(cpf, "r");
    if (file == NULL) {
        system("cls");
        printf("\nVocê não possui cadastro ainda\n\n");

        char resposta[12];
        while (1) {
            printf("\nDeseja fazer o cadastro? (SIM/NAO): \n ");
            scanf("%s", resposta);

            if (strcmp(resposta, "SIM") == 0) {
                system("cls");
                registro();
                break;
            } else if (strcmp(resposta, "NAO") == 0) {
                system("cls");
                printf("\nMuito obrigado por usar o sistema...\n\n");
                return 0;
            } else {
                system("cls");
                printf("\nResposta inválida, responda apenas com SIM ou NAO (Em CAPS LOCK)...\n\n");
                system("pause");
            }
        }
    } else {
        fclose(file);

        system("cls");
        printf("\nDigite a sua senha:\n");
        scanf("%s", senhadigi);
        getchar();

        file = fopen(cpf, "r");
        if (file == NULL) {
            printf("\nErro ao abrir o arquivo para validação da senha.\n\n");
            fclose(file);
            return 1;
        }

        int senhaVerificada = 0;

        while (fgets(conteudo, 200, file) != NULL) {
            if (strstr(conteudo, senhadigi) != NULL) {
                printf("\nBem-vindo ao Cartório da EBAC\n");
                senhaVerificada = 1;
                system("pause");
                break;
            }
        }

        if (senhaVerificada == 0) {
            system("cls");
            printf("\nSenha INCORRETA... Tente novamente ou retorne ao menu.\n");
            system("pause");
            return 0;
        }

        fclose(file);
    }

    // Menu principal
    while (1) {
        system("cls");
        setlocale(LC_ALL, "Portuguese");

        printf("Escolha a opção desejada no menu: \n\n");
        printf("\t1 - Registrar nomes\n\n");
        printf("\t2 - Consultar nomes\n\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\n\t4 - Sair do menu\n\n");
        printf("Opção: ");

        scanf("%d", &opcao);
        system("cls");

        switch (opcao) {
            case 1:
                registro();
                break;
            case 2:
                consulta();
                break;
            case 3:
                deletar();
                break;
            case 4:
                sair();
                return 0;
            default:
                printf("\nEssa opção não está disponível!\n\n");
                system("pause");
                break;
        }
    }

    return 0;
}
