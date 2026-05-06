#include "agendamento.h"
#include "lista.h"
#include <stdio.h>
#include <string.h>

void menuCadastrarAgendamento(ListaAgendamentos *la, ListaPacientes *lp) {
    Agendamento a;
    printf("\n--- Novo Agendamento ---\n");
    printf("CPF do Paciente: ");
    scanf("%s", a.cpf_paciente);

    // O paciente deve existir
    if (buscarPacienteCPF(lp, a.cpf_paciente) == NULL) {
        printf("***[ERRO]***: Paciente nao encontrado. Cadastre o paciente primeiro.\n");
        return;
    }

    printf("Numero da Sala: ");
    scanf("%d", &a.sala);
    printf("Data (DD/MM/AAAA): ");
    scanf("%s", a.data);
    if (!validarData(a.data)) {
        printf("***[ERRO]***: Data invalida ou formato incorreto.\n");
        return;
    }

    printf("Hora (HH:MM): ");
    scanf("%s", a.hora);
    if (!validarHora(a.hora)) {
        printf("***[ERRO]***: Hora invalida ou formato incorreto.\n");
        return;
    }

    inserirAgendamento(la, a);
    printf("Agendamento realizado com sucesso!\n");
}

void menuRemoverAgendamento(ListaAgendamentos *l) {
    char cpf[12], data[11];
    printf("\n--- Cancelar Agendamento ---\n");
    printf("CPF: ");
    scanf("%s", cpf);
    printf("Data do agendamento: ");
    scanf("%s", data);

    if (removerAgendamento(l, cpf, data)) {
        printf("Agendamento removido com sucesso.\n");
    } else {
        printf("***[ERRO]***: Agendamento nao encontrado.\n");
    }
}

void menuListarPorSala(ListaAgendamentos *l) {
    int sala;
    printf("Digite o numero da sala: ");
    scanf("%d", &sala);
    listarPorSala(l, sala);
}

void menuListarPorCPF(ListaAgendamentos *l) {
    char cpf[12];
    printf("Digite o CPF: ");
    scanf("%s", cpf);
    listarPorCPF(l, cpf);
}

// Valida formato DD/MM/AAAA - logica básica
int validarData(char *data) {
    if (strlen(data) != 10) return 0;
    if (data[2] != '/' || data[5] != '/') return 0;

    int d, m, a;
    if (sscanf(data, "%d/%d/%d", &d, &m, &a) != 3) return 0;

    if (a < 2024 || a > 2100) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1 || d > 31) return 0;

    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;
    if (m == 2 && d > 29) return 0; // Fevereiro simplificado

    return 1;
}

// Valida formato HH:MM
int validarHora(char *hora) {
    if (strlen(hora) != 5) return 0;
    if (hora[2] != ':') return 0;

    int h, m;
    if (sscanf(hora, "%d:%d", &h, &m) != 2) return 0;

    if (h < 0 || h > 23) return 0;
    if (m < 0 || m > 59) return 0;

    return 1;
}
