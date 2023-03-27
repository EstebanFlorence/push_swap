# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/24 18:59:58 by adi-nata          #+#    #+#              #
#    Updated: 2023/03/27 16:09:31 by adi-nata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
		make -C ./srcs/
		make -C ./ft_printf/
		cp ./include/ft_libft.a libft.a
		cp ./include/libftprintf.a libft.a


clean:
		make clean -C ./srcs/
		make clean -C ./ft_printf/

fclean:
		make fclean -C ./srcs/
		make fclean -C ./ft_printf/
		rm libft.a