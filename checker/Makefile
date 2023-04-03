# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 19:03:34 by adi-nata          #+#    #+#              #
#    Updated: 2023/04/03 16:04:32 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker

SRCS	=	checker.c\
			check.c\
			utils.c\
			utils2.c\
			moves.c\
			moves2.c

OBJS	=	$(addprefix obj/,$(notdir $(SRCS:.c=.o)))

CC		=	gcc

RM		=	rm -f

FLAGS	=	-g -Wall -Wextra -Werror -I../libft/include/

LIB		=	../libft/include/libft.a


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m


${NAME}:	objs ${OBJS}
			@${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}

all:		${NAME}

obj/%.o:	%.c
			@${CC} ${FLAGS} -c $< -o $@

objs:
			@mkdir -p obj

clean:
			@${RM} -r obj

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re