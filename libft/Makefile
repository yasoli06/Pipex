NAME = libft.a

SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	  ft_isprint.c ft_memset.c ft_strlcpy.c ft_strlen.c ft_tolower.c \
	  ft_toupper.c ft_memmove.c ft_memcpy.c ft_strchr.c ft_memchr.c \
	  ft_strrchr.c ft_strncmp.c ft_memcmp.c ft_strlcat.c ft_atoi.c \
	  ft_strnstr.c ft_calloc.c ft_strdup.c ft_substr.c	ft_strjoin.c \
	  ft_strtrim.c ft_split.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_striteri.c ft_itoa.c ft_strmapi.c

OBJECTS = $(SRC:%.c=%.o)

HEADER = 	libft.h
cc = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

#metodo implicito
%.o:%.c 	$(HEADER) Makefile
			$(CC) $(FLAGS) -c $< -o $@

#mis metodos
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean:
	$(RM) $(OBJECTS) 

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean 
