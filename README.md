Cartório da EBAC
Este é um sistema simples de cartório, implementado em C, com funcionalidades para registrar, consultar e deletar usuários com base em seus CPF. O sistema utiliza arquivos para armazenar e gerenciar os dados dos usuários.

Funcionalidades
O sistema possui as seguintes funcionalidades:

Registrar: Permite cadastrar um novo usuário, incluindo CPF, nome, sobrenome e cargo.
Consultar: Permite consultar os dados de um usuário por seu CPF.
Deletar: Permite deletar o registro de um usuário com base em seu CPF.
Sair: Encerra o programa.
Como Usar
Registrar: Ao selecionar a opção 1, o sistema pedirá o CPF, nome, sobrenome e cargo do usuário. Esses dados serão salvos em um arquivo com o nome do CPF do usuário.

Consultar: Ao selecionar a opção 2, o sistema pedirá o CPF e exibirá os dados salvos associados a esse CPF, caso o arquivo correspondente exista.

Deletar: Ao selecionar a opção 3, o sistema pedirá o CPF e, se encontrar um arquivo com o nome correspondente, irá deletá-lo.

Sair: Ao selecionar a opção 4, o sistema será fechado.

Requisitos
Um compilador C (por exemplo, GCC) para compilar o código.
Sistema operacional que suporte funções padrão de C (como fopen, remove, etc.).
