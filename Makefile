# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 18:24:03 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/29 00:17:53 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c\
			utils.c\
			utils2.c\
			utilis.c\
			utilis2.c\
			moves.c\
			moves2.c\
			moves3.c\
			minisolver.c\
			bigsolver.c

OBJS	=	$(addprefix obj/,$(notdir $(SRCS:.c=.o)))

CC		=	gcc

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror -Ilibft/include/



${NAME}:	objs ${OBJS}
			make -C ./libft
			${CC} ${FLAGS} ${OBJS} -L./libft/include -lft -o ${NAME}

all:		${NAME}

obj/%.o:	%.c
			${CC} ${FLAGS} -c $< -o $@

objs:
			mkdir -p obj

clean:
			${RM} -r obj
			make clean -C ./libft

fclean:		clean
			${RM} ${NAME}
			make fclean -C ./libft

re:			fclean all

.PHONY:		all clean fclean re
