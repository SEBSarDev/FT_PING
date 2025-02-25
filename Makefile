CC = clang
CFLAGS = -Wall -Werror -Wextra
NAME = ft_ping
HEADER = inc/ft_ping.h libft/libft.h
SRCS = src/ft_ping.c src/codes.c src/helpers.c src/receive.c src/send.c src/stat.c src/print.c
OBJS = ${SRCS:.c=.o}
DSRCS = ./libft/*.c
DOBJS = ./libft/objs/*.o

all : ${NAME}
%.o : %.c ${HEADER}
	$(CC) -c $(CFLAGS) $<
	mv *.o src/
$(NAME) : $(OBJS)
	make -C libft
	$(CC) -o $(NAME) $(OBJS) $(DOBJS)
clean :
	make clean -C libft 
	rm -f $(OBJS)
fclean : clean
	rm -f libft/libft.a
	rm -f ${NAME}
re : fclean all