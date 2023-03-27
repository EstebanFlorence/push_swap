# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:13:54 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/27 16:11:25 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

RM	    = rm -f

FLAGS	= -Wall -Wextra -Werror -Ilibft/include

FIRST	= 

SRCS	= push_swap.c\
			utils.c\
			utils2.c\
			utilis.c\
			utilis2.c\
			moves.c\
			moves2.c\
			moves3.c\
			minisolver.c\
			bigsolver.c

OBJS	= ${SRCS:.c=.o}

.c.o:	${FIRST}
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		make -C ./libft
		${CC} ${FLAGS} ${OBJS} -o ${NAME} ./libft/libft.a


all:	${NAME}

clean:
			@ ${RM} *.o */*.o */*/*.o
			make clean -C ./libft

fclean:		clean
			@ ${RM} ${NAME}
			make fclean -C ./libft

re:		fclean all

.PHONY:			all clean fclean re bonus bonusclean bonusfclean bonusre