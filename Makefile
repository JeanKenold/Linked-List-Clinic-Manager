# Nome do executável final
TARGET = sistema_clinica

# Compilador
CC = gcc

# Flags de compilação (-Wall mostra todos os avisos, -g é para debug)
CFLAGS = -Wall -g

# Lista de arquivos fonte (.c)
SRC = main.c lista.c paciente.c agendamento.c

# Gera a lista de arquivos objeto (.o) automaticamente a partir dos nomes em SRC
OBJ = $(SRC:.c=.o)

# Regra principal: compila o alvo final
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Regra para limpar os arquivos temporários de compilação
clean:
	rm -f $(OBJ) $(TARGET)

# Regra para rodar o programa após compilar
run: $(TARGET)
	./$(TARGET)
