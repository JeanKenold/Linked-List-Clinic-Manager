# Sistema de Agendamento - Clínica Universitária

Trabalho prático desenvolvido para a disciplina de Estrutura de Dados Lineares. O sistema gere o cadastro de pacientes e o agendamento de consultas numa clínica universitária, utilizando diferentes implementações de listas encadeadas. Por Jean Kenold, Pablo Ishiai e Thales Cercal.

## Estruturas de Dados Utilizadas

Para atender aos requisitos e manter eficiência, o projeto utiliza:
- **Lista Dinâmica Simplesmente Encadeada:** Utilizada para o cadastro de **Pacientes**. Permite a inserção fluida e busca eficiente por CPF.
- **Lista Encadeada com Nó Cabeçalho (Header):** Utilizada para o **Histórico de Agendamentos**. O uso do nó cabeçalho facilita as operações de inserção e remoção, mantendo uma sentinela fixa no início da lista, sem ter que lidar com o caso exceção.

## Como Compilar e Rodar

O projeto utiliza `Makefiles` distintos para garantir a compatibilidade entre sistemas operacionais.

### No Linux (Terminal)
Utilize o comando padrão `make`:
1. **Compilar:** `make`
2. **Executar:** `make run`
3. **Limpar ficheiros (.o):** `make clean`

### No Windows (CMD/PowerShell)
Utilize o arquivo específico via `mingw32-make` (ou o comando do seu compilador):
1. **Compilar:** `mingw32-make -f Makefile.windows`
2. **Executar:** `sistema_clinica.exe`
3. **Limpar ficheiros:** `mingw32-make -f Makefile.windows clean`

## Funcionalidades do Sistema

1. **Gestão de Pacientes:**
   - Cadastro com validação real de CPF (algoritmo de dígitos verificadores).
   - Impedimento de CPFs duplicados.
   - Consulta de dados por CPF.

2. **Gestão de Agendamentos:**
   - Agendamento vinculado a um CPF existente.
   - Validação de integridade de **Data** (DD/MM/AAAA) e **Hora** (HH:MM).
   - Listagem filtrada por Sala de atendimento ou por CPF do paciente.
   - Cancelamento de consulta através da chave composta (CPF + Data).
   - Exibição de histórico completo utilizando a lógica de nó cabeçalho.

## Robustez e Segurança
- **Gestão de Memória:** Todas as alocações via `malloc` são verificadas. O sistema encerra de forma segura caso não haja memória disponível.
- **Prevenção de Memory Leak:** Funções de destruição de lista foram implementadas para libertar toda a memória alocada antes do encerramento do programa.
