# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/28 18:24:03 by adi-nata          #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2023/04/29 15:13:24 by adi-nata         ###   ########.fr        #
=======
#    Updated: 2023/04/04 16:42:59 by adi-nata         ###   ########.fr        #
>>>>>>> 45a63a5f4ca167a78e5186ad602bb5bd2151099f
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

SRCS	=	push_swap.c\
			check.c\
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

FLAGS	=	-g -Wall -Wextra -Werror -Ilibft/include/

LIB		=	libft

BONUS	=	checker


CLR_RMV		= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m


${NAME}:	objs ${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(LIB) ${CLR_RMV}..."
			@make -C ./libft
			@echo "$(GREEN)$(LIB) created[0m ✔️"

			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@${CC} ${FLAGS} ${OBJS} -L./libft/include -lft -o ${NAME}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

all:		${NAME}

bonus:		${NAME}

			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(BONUS) ${CLR_RMV}..."
			@make -C ./checker
			@echo "$(GREEN)$(BONUS) created[0m ✔️"

obj/%.o:	%.c
			@${CC} ${FLAGS} -c $< -o $@

objs:
			@mkdir -p obj

clean:
			@ echo "$(RED)Deleting $(CYAN)$(LIB) $(CLR_RMV)libft objs ✔️"
			@make clean -C ./libft

			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"
			@${RM} -r obj

			@ echo "$(RED)Deleting $(CYAN)$(BONUS) $(CLR_RMV)objs ✔️"
			@make clean -C ./checker

fclean:		clean
			@ echo "$(RED)Deleting $(CYAN)$(LIB) $(CLR_RMV)binary ✔️"
			@make fclean -C ./libft

			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"
			@${RM} ${NAME}

			@ echo "$(RED)Deleting $(CYAN)checker $(CLR_RMV)binary ✔️"
			@make fclean -C ./checker

re:			fclean all

rebonus:	fclean all bonus

.PHONY:		all clean fclean re
