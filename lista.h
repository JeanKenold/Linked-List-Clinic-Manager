#ifndef LISTA_H
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    char nome[100];
    char cpf[12];
    char matricula[20];
    char curso[50];
} Paciente;

typedef struct {
    char cpf_paciente[12];
    int sala;
    char data[11]; // DD/MM/AAAA
    char hora[6];  // HH:MM
} Agendamento;

// Lista de pacientes encadeada simples
typedef struct no_paciente {
    Paciente dado;
    struct no_paciente *proximo;
} NoPaciente;

typedef struct {
    NoPaciente *inicio;
    int tamanho;
} ListaPacientes;

// lista agendamento com cabecalho
typedef struct no_agendamento {
    Agendamento dado;
    struct no_agendamento *proximo;
} NoAgendamento;

typedef struct {
    NoAgendamento *header; // header->proximo: o primeiro dado real
    int tamanho;
} ListaAgendamentos;


ListaPacientes* criarListaPacientes();
void inserirPaciente(ListaPacientes *l, Paciente p);
NoPaciente* buscarPacienteCPF(ListaPacientes *l, char *cpf);
void exibirPacientes(ListaPacientes *l);


ListaAgendamentos* criarListaAgendamentos();
void inserirAgendamento(ListaAgendamentos *l, Agendamento a);
int removerAgendamento(ListaAgendamentos *l, char *cpf, char *data);
void listarPorCPF(ListaAgendamentos *l, char *cpf);
void listarPorSala(ListaAgendamentos *l, int sala);
void exibirHistoricoCompleto(ListaAgendamentos *l);
void destruirListaPacientes(ListaPacientes *l);
void destruirListaAgendamentos(ListaAgendamentos *l);

#endif
