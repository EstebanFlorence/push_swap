# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 18:13:54 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/03 19:37:25 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

CC		= cc

FLAGS	= -Wall -Wextra -Werror -I${INC_DIR}

INC_DIR	= ./libft/include

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
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "${GREEN}${NAME} created [0m ✔️"

all:		${NAME}					
						make -C ./libft/

bonus:			all
						cd bonus && ${MAKE}

clean:
						@ ${RM} *.o */*.o */*/*.o
						make clean -C ./libft/
						@ echo "${RED}Deleting ${CYAN}${NAME} ${CLR_RMV}objs ✔️"

bonusclean:		clean
						cd bonus && ${MAKE} clean

fclean:			clean
						@ ${RM} ${NAME}
						make fclean -C ./libft/
						@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

bonusfclean:	fclean
						cd bonus && ${MAKE} re

re:				fclean all

bonusre:		re
						cd bonus && ${MAKE} re

.PHONY:			all clean fclean re bonus bonusclean bonusfclean bonusre