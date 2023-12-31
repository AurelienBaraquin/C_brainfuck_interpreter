CFLAGS = -W -Wall -Wextra -I./include -g3

SRC = main.c

OBJ = $(SRC:.c=.o)

TARGET = brainfuck

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(TARGET)

re:	fclean all
