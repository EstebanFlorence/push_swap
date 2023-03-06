# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:13:54 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/06 11:24:05 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror -Ilibft/include/

SRCS	= push_swap.c \
			utils.c

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m


RM		    = rm -f

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}
			make -C ./libft/

all:		${NAME}					

bonus:			all
						cd bonus && ${MAKE}

clean:
						@ ${RM} *.o */*.o */*/*.o
						make clean -C ./libft/

bonusclean:		clean
						cd bonus && ${MAKE} clean

fclean:			clean
						@ ${RM} ${NAME}
						make fclean -C ./libft/

bonusfclean:	fclean
						cd bonus && ${MAKE} re

re:				fclean all

bonusre:		re
						cd bonus && ${MAKE} re

.PHONY:			all clean fclean re bonus bonusclean bonusfclean bonusre