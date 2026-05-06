#include <stdio.h>
#include "lista.h"
#include "paciente.h"
#include "agendamento.h"

void exibirMenu() {
    printf("\n\n~~~ AGENDAMENTO CLINICO UNIVERSITARIO ~~~\n");
    printf("1--> Cadastrar Paciente\n");
    printf("2--> Consultar Paciente por CPF\n");
    printf("3--> Novo Agendamento\n");
    printf("4--> Listar Agendamentos por CPF\n");
    printf("5--> Listar Agendamentos por Sala\n");
    printf("6--> Cancelar Agendamento\n");
    printf("7--> Historico Completo de Agendamentos\n");
    printf("0--> Sair\n\n");
    printf("Escolha uma opcao: ");
}

int main() { // por PABLO
    // Inicializacao das estruturas de dados
    ListaPacientes *lp = criarListaPacientes();
    ListaAgendamentos *la = criarListaAgendamentos();
    
    int opcao;
    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida! Use numeros.\n");
            while(getchar() != '\n'); // Limpa o buffer
            continue;
        }

        switch (opcao) {
            case 1:
                menuCadastrarPaciente(lp);
                break;
            case 2:
                consultarPacientePorCPF(lp);
                break;
            case 3:
                menuCadastrarAgendamento(la, lp);
                break;
            case 4:
                menuListarPorCPF(la);
                break;
            case 5:
                menuListarPorSala(la);
                break;
            case 6:
                menuRemoverAgendamento(la);
                break;
            case 7:
                exibirHistoricoCompleto(la);
                break;
            case 0:
                printf("Encerrando o sistema...\n");
                break;
            default:
                printf("Opcao inexistente!\n");
        }
    } while (opcao != 0);

    destruirListaPacientes(lp);
    destruirListaAgendamentos(la);

    printf("Sistema encerrado.\n");
    return 0;
}
