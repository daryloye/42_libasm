NAME = libasm.a

SRC_DIR = ./src
OBJ_DIR = ./obj

SRC = hello_world.s ft_strlen.s
OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.s=.o))

TEST = ./test
MAIN = ./main.c

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@nasm -f elf64 $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f $(TEST)

re: fclean all

test: re
	@gcc $(MAIN) $(NAME) -o $(TEST)
	@$(TEST)
