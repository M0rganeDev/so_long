CFLAGS = -Wall -Wextra -Werror -c
SOURCES = ft_strlen.c \
		  ft_isalpha.c \
		  ft_isdigit.c \
		  ft_isalnum.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_isascii.c \
		  ft_isprint.c \
		  ft_memset.c \
		  ft_bzero.c \
		  ft_memcpy.c \
		  ft_memmove.c \
		  ft_atoi.c \
		  ft_strlcpy.c \
		  ft_strlcat.c \
		  ft_strnstr.c \
		  ft_strncmp.c \
		  ft_strrchr.c \
		  ft_memcmp.c \
		  ft_strchr.c \
		  ft_memchr.c \
		  ft_calloc.c \
		  ft_strdup.c \
		  ft_substr.c \
		  ft_strjoin.c \
		  ft_strtrim.c \
		  ft_split.c \
		  ft_itoa.c \
		  ft_strmapi.c \
		  ft_striteri.c \
		  ft_putchar_fd.c \
		  ft_putstr_fd.c \
		  ft_putendl_fd.c \
		  ft_putnbr_fd.c \
		  ft_printf.c \
		  ft_printf_handle_basics.c \
		  ft_printf_handle_complex.c \
		  ft_printf_handle_hexa.c \
		  ft_uitoa.c \
		  ft_ultoa.c


BONUS_SOURCES = ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c

NAME = libft.a

OBJECTS = $(SOURCES:.c=.o)

OBJECT_BONUS = $(BONUS_SOURCES:.c=.o)

CC = gcc

all: $(NAME)

bonus: $(OBJECTS) $(OBJECT_BONUS)
	ar -rcs libft.a $(OBJECTS) $(OBJECT_BONUS)

$(NAME): $(OBJECTS)
	ar -rcs libft.a $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(OBJECT_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
