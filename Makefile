#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW=\033[1;33m

NAME = pipex

LIBFT = ./libft/libft.a

SRCS = main.c error.c

OBJECTS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L ./libft -lft
RM = rm -rf

%.o: %.c 
	$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME) : $(OBJECTS)
	@$(CC) (CFLAGS) $(OBJECTS)$(LIBFT) -o $(NAME)
	@echo "$(GREEN)PIPEX DONE$(END)"

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) $(OBJECTS)
	@$(RM) $(NAME)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re