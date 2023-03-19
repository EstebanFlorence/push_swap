# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:13:54 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/19 18:29:14 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= gcc

RM	    = rm -f

FLAGS	= -Wall -Wextra -Werror -g -Ilibft/include/

FIRST	= make -C ./libft/

SRCS	= push_swap.c\
			utilis.c\
			utils.c\
			utils2.c\
			moves.c\\
			doublemoves.c\
			minisolver.c\
			bigsolver.c

OBJS	= ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${FIRST}
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