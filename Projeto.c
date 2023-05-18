#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define CLEAR_SCREEN "cls"



#define MaxUsers 1000

void cadastrarUsuario(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int *numUsuarios) {
  if (*numUsuarios >= MaxUsers) {
    printf("Numero maximo de usuarios atingido.\n");
    return;
  }

  id[*numUsuarios] = rand() % 1000 + 1; // Gera um ID aleatório entre 1 e 1000
  printf("ID gerado: %d\n", id[*numUsuarios]);

  printf("Digite o nome: ");
  scanf("%s", nome[*numUsuarios]);

  do {
    printf("Digite o sexo (feminino, masculino ou indiferente): ");
    scanf("%s", sexo[*numUsuarios]);

    if (strcmp(sexo[*numUsuarios], "feminino") == 0 || strcmp(sexo[*numUsuarios], "masculino") == 0 || strcmp(sexo[*numUsuarios], "indiferente") == 0) {
      printf("Sexo valido.\n");
    } else {
      printf("Sexo invalido. Digite novamente.\n");
    }
  } while (!(strcmp(sexo[*numUsuarios], "feminino") == 0 || strcmp(sexo[*numUsuarios], "masculino") == 0 || strcmp(sexo[*numUsuarios], "indiferente") == 0));

  do {
    printf("Digite a altura: ");
    scanf("%lf", &altura[*numUsuarios]);

    if (altura[*numUsuarios] >= 1 && altura[*numUsuarios] <= 2) {
      printf("Altura valida.\n");
    } else {
      printf("Altura invalida. Digite novamente.\n");
    }
  } while (!(altura[*numUsuarios] >= 1 && altura[*numUsuarios] <= 2));

  do {
    printf("Digite 1 se voce estiver vacinado ou 2 se nao estiver: ");
    scanf("%d", &vacinado[*numUsuarios]);

    switch (vacinado[*numUsuarios]) {
    case 1:
      printf("Voce esta vacinado!\n");
      break;
    case 2:
      printf("Voce nao esta vacinado.\n");
      break;
    default:
      printf("Opcao invalida. Digite novamente.\n");
      break;
    }
  } while (vacinado[*numUsuarios] != 1 && vacinado[*numUsuarios] != 2);

  do {
    printf("Digite o seu email: ");
    scanf("%s", email[*numUsuarios]);

    // Verificar se o caractere '@' está presente no email
    if (strstr(email[*numUsuarios], "@") == NULL) {
      printf("Email invalido. Digite novamente.\n");
    } else {
      printf("Email valido.\n");
      break; // Sai do loop quando o email for válido
    }
  } while (1);

  (*numUsuarios)++;
  printf("Usuario cadastrado com sucesso!\n");
}

void buscarUsuario(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int numUsuarios) {
  int i, idBusca;
  printf("Digite o ID do usuario que deseja buscar: ");
  scanf("%d", &idBusca);

  for (i = 0; i < numUsuarios; i++) {
    if (idBusca == id[i]) {
      printf("----- Informaçoes do Usuario -----\n");
      printf("ID: %d\n", id[i]);
      printf("Nome: %s\n", nome[i]);
      printf("Sexo: %s\n", sexo[i]);
      printf("Altura: %lf\n", altura[i]);
      printf("E-mail: %s\n", email[i]);
      printf("Vacina: %d\n", vacinado[i]);
      return;
    }
  }

  printf("Usuario nao encontrado.\n");
}

void deletarUsuario(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int *numUsuarios) {
  int i, idDeletar;
  printf("Digite o ID do usuario que deseja deletar: ");
  scanf("%d", &idDeletar);

  for (i = 0; i < *numUsuarios; i++) {
    if (idDeletar == id[i]) {
      // Deslocar os usuários para preencher o espaço do usuário deletado
      for (int j = i; j < *numUsuarios - 1; j++) {
        id[j] = id[j + 1];
        strcpy(nome[j], nome[j + 1]);
        strcpy(sexo[j], sexo[j + 1]);
        altura[j] = altura[j + 1];
        vacinado[j] = vacinado[j + 1];
        strcpy(email[j], email[j + 1]);
      }

      (*numUsuarios)--;
      printf("Usuario deletado com sucesso!\n");
      return;
    }
  }

  printf("Usuario nao encontrado.\n");
}

void fazerBackup(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int numUsuarios,
                 int backupId[], char backupNome[][20], char backupSexo[][15]) {
  int i;
  for (i = 0; i < numUsuarios; i++) {
    backupId[i] = id[i];
    strcpy(backupNome[i], nome[i]);
    strcpy(backupSexo[i], sexo[i]);
  }

  printf("Backup realizado com sucesso!\n");
}

void restaurarBackup(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int *numUsuarios,
                     int backupId[], char backupNome[][20], char backupSexo[][15]) {
  int i;
  for (i = 0; i < *numUsuarios; i++) {
    id[i] = backupId[i];
    strcpy(nome[i], backupNome[i]);
    strcpy(sexo[i], backupSexo[i]);
  }

  printf("Backup restaurado com sucesso!\n");
}

void imprimirUsuarios(int id[], char nome[][20], double altura[], int vacinado[], char email[][50], char sexo[][15], int numUsuarios) {
  if (numUsuarios == 0) {
    printf("Nenhum usuario cadastrado.\n");
    return;
  }

  printf("----- Usuarios Cadastrados -----\n");
  for (int i = 0; i < numUsuarios; i++) {
    printf("ID: %d\n", id[i]);
    printf("Nome: %s\n", nome[i]);
    printf("Sexo: %s\n", sexo[i]);
    printf("Altura: %lf\n", altura[i]);
    printf("E-mail: %s\n", email[i]);
    printf("Vacina: %d\n", vacinado[i]);
    printf("-----------------------------\n");
  }
}

void limparTela() {
  system(CLEAR_SCREEN);
}

int main() {
  int id[MaxUsers];
  char nome[MaxUsers][20];
  double altura[MaxUsers];
  int vacinado[MaxUsers];
  char email[MaxUsers][50];
  char sexo[MaxUsers][15];
  int numUsuarios = 0;

  int backupId[MaxUsers];
  char backupNome[MaxUsers][20];
  char backupSexo[MaxUsers][15];

  int opcao;

  srand(time(NULL));

  do {
    printf("----- Sistema de Cadastro -----\n");
    printf("1 - Cadastrar usuario\n");
    printf("2 - Buscar usuario\n");
    printf("3 - Deletar usuario\n");
    printf("4 - Fazer backup\n");
    printf("5 - Restaurar backup\n");
    printf("6 - Imprimir usuarios\n");
    printf("7 - Limpar tela\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);

    limparTela(); // Limpa a tela antes de exibir o resultado

    switch (opcao) {
    case 1:
      cadastrarUsuario(id, nome, altura, vacinado, email, sexo, &numUsuarios);
      break;
    case 2:
      buscarUsuario(id, nome, altura, vacinado, email, sexo, numUsuarios);
      break;
    case 3:
      deletarUsuario(id, nome, altura, vacinado, email, sexo, &numUsuarios);
      break;
    case 4:
      fazerBackup(id, nome, altura, vacinado, email, sexo, numUsuarios, backupId, backupNome, backupSexo);
      break;
    case 5:
      restaurarBackup(id, nome, altura, vacinado, email, sexo, &numUsuarios, backupId, backupNome, backupSexo);
      break;
    case 6:
      imprimirUsuarios(id, nome, altura, vacinado, email, sexo, numUsuarios);
      break;
    case 7:
      limparTela();
      break;
    case 0:
      printf("Encerrando o programa...\n");
      break;
    default:
      printf("Opcao invalida. Digite novamente.\n");
      break;
    }

    printf("\n");
  } while (opcao != 0);

  return 0;
}
