FILES = ./srcs/ft_basic.c ./srcs/int_process.c ./srcs/ft_error.c ./srcs/ft_convert_number.c ./srcs/ft_search_id.c ./srcs/file_parser.c ./srcs/ft_split.c ./srcs/main.c ./srcs/string_process.c
OBJ = ${FILES:.c=.o}
HSRCS = includes/
CC = gcc
CFLAGS =-Wall -Wextra -Werror
BIN = rush-02

all: ${BIN}
	 
${BIN}: ${OBJ}
	${CC} ${FILES} ${CFLAGS} -I ${HSRCS} -o $@

%.o : %.c
	${CC} -c $^ $(CFLAGS) -o $@

clean:
	rm ${OBJ}

fclean: ${OBJ}
	rm ${BIN}

re: fclean all

.PHONY: all clean fclean re 