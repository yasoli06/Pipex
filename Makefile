#COLORS#
GREEN = \033[1;92m
RED = \033[1;91m
NC = \033[0m
YELLOW= \033[1;33m

NAME = pipex

LIBFT = ./libft/libft.a

SRCS = main.c error.c utils.c pipex.c processes.c

OBJECTS = $(SRCS:%.c=%.o)

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
LIBFT_FLAGS = -L ./libft -lft
RM = rm -rf

%.o: %.c Makefile pipex.h
	$(CC) -c $< $(CFLAGS) -o $@
	@echo "$(YELLOW)Compiling... $(END)$(patsubst $(DIR_BUILD)%,%,$@)"

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft -s
$(NAME) : $(OBJECTS)
	@$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)PIPEX DONE$(END)"

clean:
	@$(MAKE) clean -C ./libft -s
	@$(RM) $(OBJECTS)
	@$(RM) $(NAME)
	@echo "$(RED)OBJECTS DELETED$(END)"

fclean: clean
	@$(MAKE) fclean -C ./libft -s
	@$(RM) $(NAME)
	@echo "$(RED)OBJECTS DELETED$(END)"

re: fclean all

.PHONY: all clean fclean re
.SILENT: 
