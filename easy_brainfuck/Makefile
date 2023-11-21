CFLAGS = -W -Wall -Wextra -I./include -g3

SRC = $(shell find . -name '*.c')

OBJ = $(SRC:.c=.o)

TARGET = compile

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
