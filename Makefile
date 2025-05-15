NAME = asem

SRC = ./asem.s

OBJECTS = $(SRC:.s=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ld $(OBJECTS) -o $(NAME)

%.o: %.s
	nasm -f elf64 $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
