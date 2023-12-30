# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbico <mbico@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/01 18:22:15 by nrontey           #+#    #+#              #
#    Updated: 2023/08/02 20:04:29 by mbico            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ./src/display.c ./main.c ./src/parsing.c ./src/value_attribution.c ./lib/map.c ./lib/str_edit.c
OBJ = ${FILES:.c=.o}
HSRCS = includes/
CC = gcc
CFLAGS = -g
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