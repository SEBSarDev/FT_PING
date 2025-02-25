CFLAGS = -Wall -Wextra -Werror
CC = clang
NAME = libft.a
HEADER = libft.h
SRCS = ft_atoi.c ft_memccpy.c ft_putstr_fd.c ft_strncmp.c ft_strcmp.c ft_bzero.c ft_memchr.c ft_split.c ft_strnstr.c ft_calloc.c ft_memcmp.c ft_strchr.c ft_strrchr.c ft_isalnum.c ft_memcpy.c ft_strdup.c ft_strtrim.c ft_isalpha.c ft_memmove.c ft_strjoin.c ft_substr.c ft_isascii.c ft_memset.c ft_strlcat.c ft_tolower.c ft_isdigit.c ft_putchar_fd.c ft_strlcpy.c ft_toupper.c ft_isprint.c ft_putendl_fd.c ft_strlen.c ft_itoa.c ft_putnbr_fd.c ft_strmapi.c ft_lstadd_back.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstsize.c ft_lstadd_front.c ft_lstdelone.c ft_lstlast.c ft_lstnew.c printf/ft_printf_utils2.c printf/ft_printf.c printf/ft_get_conv.c printf/ft_init_flags.c ft_itoa_base.c printf/ft_printf_utils.c printf/ft_treat_flag.c printf/ft_treat_flag_details.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)
%.o : %.c $(HEADER)
	$(CC) -c $(CFLAGS) $<
$(NAME) : $(OBJS)
	mv *.o ./objs
	ar -rc $@ ./objs/*
clean :
	rm -f ./objs/*.o
fclean : clean
	rm -f libft.a
re : fclean all
