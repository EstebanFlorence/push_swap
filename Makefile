# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:13:54 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/08 03:48:44 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

RM	    = rm -f

FLAGS	= -Wall -Wextra -Werror -g -Ilibft/include/

FIRST	= make -C ./libft/srcs/

SRCS	= push_swap.c\
			utils.c\
			moves.c

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			make all -C ./libft
			${CC} ${FLAGS} -o ${NAME} ${OBJS}


all:	${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			make clean -C ./libft

fclean:		clean
			@ ${RM} ${NAME}
			make fclean -C ./libft

re:		fclean all

.PHONY:			all clean fclean re bonus bonusclean bonusfclean bonusre