# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/31 19:03:34 by adi-nata          #+#    #+#              #
#    Updated: 2023/04/01 20:15:59 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	checker

SRCS	=	checker.c\
			check.c\
			check2.c\
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
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${FLAGS} ${OBJS} ${LIB} -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

obj/%.o:	%.c
			@${CC} ${FLAGS} -c $< -o $@

objs:
			@mkdir -p obj

clean:
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@${RM} -r obj

fclean:		clean
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re