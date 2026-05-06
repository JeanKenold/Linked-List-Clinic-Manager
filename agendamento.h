#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H

#include "lista.h"

// validacao de integridade
int validarData(char *data);
int validarHora(char *hora);

// realiza agendamento consulta, verificando se o CPF existe na lista de pacientes
void menuCadastrarAgendamento(ListaAgendamentos *la, ListaPacientes *lp);

// remove agendamento especifico baseado em CPF e data
void menuRemoverAgendamento(ListaAgendamentos *l);

// filtragem e exibicao de agendamentos por categoria
void menuListarPorSala(ListaAgendamentos *l);
void menuListarPorCPF(ListaAgendamentos *l);

#endif
