#ifndef PACIENTE_H
#define PACIENTE_H

#include "lista.h" // acessar a estrutura ListaPacientes

// ler dados do teclado, filtrar e cadastrar
void menuCadastrarPaciente(ListaPacientes *l);
int validarCPF(char *cpf);

// busca os dados e exibe na tela
void consultarPacientePorCPF(ListaPacientes *l);

#endif
