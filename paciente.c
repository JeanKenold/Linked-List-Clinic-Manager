#include "paciente.h"
#include "lista.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Algoritmo dos digitos verificadores
int validarCPF(char *cpf) {
    int i, soma, resto, d1, d2;
    int num[11];

    // Remove caracteres não numéricos e converte para int
    int count = 0;
    for(i = 0; cpf[i] != '\0'; i++) {
        if(isdigit(cpf[i])) {
            num[count++] = cpf[i] - '0';
        }
    }

    if(count != 11) return 0; // CPF deve ter 11 dígitos

    // Cálculo do primeiro dígito (d1)
    soma = 0;
    for(i = 0; i < 9; i++) soma += num[i] * (10 - i);
    resto = soma % 11;
    d1 = (resto < 2) ? 0 : 11 - resto;

    // Cálculo do segundo dígito (d2)
    soma = 0;
    for(i = 0; i < 10; i++) soma += num[i] * (11 - i);
    resto = soma % 11;
    d2 = (resto < 2) ? 0 : 11 - resto;

    return (num[9] == d1 && num[10] == d2);
}

void menuCadastrarPaciente(ListaPacientes *l) {
    Paciente p;
    printf("\n--- Cadastro de Paciente ---\n");
    printf("CPF (apenas numeros): ");
    scanf("%s", p.cpf);

    if (!validarCPF(p.cpf)) {
        printf("***[ERRO]***: CPF invalido.\n");
        return;
    }

    if (buscarPacienteCPF(l, p.cpf) != NULL) {
        printf("***[ERRO]***: Paciente ja cadastrado.\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", p.nome);
    printf("Matricula: ");
    scanf("%s", p.matricula);
    printf("Curso: ");
    scanf(" %[^\n]", p.curso);

    inserirPaciente(l, p);
    printf("Paciente cadastrado com sucesso!\n");
}

void consultarPacientePorCPF(ListaPacientes *l) {
    char cpf[12];
    printf("Digite o CPF para consulta: ");
    scanf("%s", cpf);

    NoPaciente *busca = buscarPacienteCPF(l, cpf);
    if (busca) {
        printf("\nNome: %s\nMatricula: %s\nCurso: %s\n", 
               busca->dado.nome, busca->dado.matricula, busca->dado.curso);
    } else {
        printf("Paciente nao encontrado.\n");
    }
}
