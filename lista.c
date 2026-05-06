#include <stdlib.h>
#include "lista.h"

// GESTAO DE PACIENTES com lista simples
ListaPacientes* criarListaPacientes() { // com auxilio PABLO
    ListaPacientes *lista = (ListaPacientes*)malloc(sizeof(ListaPacientes));
    if (lista == NULL) { printf("Erro de memoria\n"); exit(1); }

    lista->inicio = NULL;
    lista->tamanho = 0;
    return lista;
}

// Checa se cpf já existe
NoPaciente* buscarPacienteCPF(ListaPacientes *l, char *cpf) {
    NoPaciente *atual = l->inicio;
    while (atual != NULL) {
        if (strcmp(atual->dado.cpf, cpf) == 0) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void inserirPaciente(ListaPacientes *l, Paciente p) {
    // Validação de duplicado
    if (buscarPacienteCPF(l, p.cpf) != NULL) {
        printf("***[ERRO]***: Paciente com CPF %s já cadastrado.\n", p.cpf);
        return;
    }

    NoPaciente *novo = (NoPaciente*)malloc(sizeof(NoPaciente));
    if (novo == NULL) { printf("Erro de memoria\n"); exit(1); }

    novo->dado = p;
    novo->proximo = l->inicio; // Inserção no início
    l->inicio = novo;
    l->tamanho++;
}

// GESTÃO DE AGENDAMENTOS (lista com cabeçalho)
ListaAgendamentos* criarListaAgendamentos() { // funcao por THALES
    ListaAgendamentos *lista = (ListaAgendamentos*)malloc(sizeof(ListaAgendamentos));
    if (lista == NULL) { printf("Erro de memoria\n"); exit(1); }

    // header: no 'sentinela'
    lista->header = (NoAgendamento*)malloc(sizeof(NoAgendamento));
    if (lista->header == NULL) { printf("Erro de memoria\n"); exit(1); }

    lista->header->proximo = NULL;
    lista->tamanho = 0;
    return lista;
}

void inserirAgendamento(ListaAgendamentos *l, Agendamento a) {
    NoAgendamento *novo = (NoAgendamento*)malloc(sizeof(NoAgendamento));
    if (novo == NULL) { printf("Erro de memoria\n"); exit(1); }

    novo->dado = a;
    // Inserindo logo apos o cabecalho
    novo->proximo = l->header->proximo;
    l->header->proximo = novo;
    l->tamanho++;
}

int removerAgendamento(ListaAgendamentos *l, char *cpf, char *data) {
    NoAgendamento *anterior = l->header;
    NoAgendamento *atual = l->header->proximo;

    while (atual != NULL) {
        // Remoção por CPF + DATA
        if (strcmp(atual->dado.cpf_paciente, cpf) == 0 && strcmp(atual->dado.data, data) == 0) {
            anterior->proximo = atual->proximo;
            free(atual);
            l->tamanho--;
            return 1;
        }
        anterior = atual;
        atual = atual->proximo;
    }
    return 0; // nao encontrado
}

void listarPorCPF(ListaAgendamentos *l, char *cpf) {
    NoAgendamento *atual = l->header->proximo;
    int encontrou = 0;
    printf("\nAgendamentos para o CPF: %s\n", cpf);

    while (atual != NULL) {
        if (strcmp(atual->dado.cpf_paciente, cpf) == 0) {
            printf("Data: %s | Hora: %s | Sala: %d\n", atual->dado.data, atual->dado.hora, atual->dado.sala);
            encontrou = 1;
        }
        atual = atual->proximo;
    }
    if (!encontrou) printf("Nenhum agendamento encontrado.\n");
}

void listarPorSala(ListaAgendamentos *l, int sala) {
    NoAgendamento *atual = l->header->proximo;
    printf("\nAgendamentos na Sala: %d\n", sala);
    while (atual != NULL) {
        if (atual->dado.sala == sala) {
            printf("Paciente (CPF): %s | Data: %s | Hora: %s\n", atual->dado.cpf_paciente, atual->dado.data, atual->dado.hora);
        }
        atual = atual->proximo;
    }
}

void exibirHistoricoCompleto(ListaAgendamentos *l) {
    NoAgendamento *atual = l->header->proximo;
    printf("\n--- HISTÓRICO COMPLETO ---\n"); // (lista cabecalho)
    while (atual != NULL) {
        printf("CPF: %s | Sala: %d | Data: %s | Hora: %s\n", 
               atual->dado.cpf_paciente, atual->dado.sala, atual->dado.data, atual->dado.hora);
        atual = atual->proximo;
    }
    printf("Total de registros: %d\n", l->tamanho);
}

void destruirListaPacientes(ListaPacientes *l) {
    if (l == NULL) return;
    NoPaciente *atual = l->inicio;
    while (atual != NULL) {
        NoPaciente *aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    free(l);
}

void destruirListaAgendamentos(ListaAgendamentos *l) {
    if (l == NULL) return;
    NoAgendamento *atual = l->header; // Começamos a liberar pelo proprio header
    while (atual != NULL) {
        NoAgendamento *aux = atual->proximo;
        free(atual);
        atual = aux;
    }
    free(l);
}
