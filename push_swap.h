/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:42:28 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/06 21:13:09 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/include/libft.h"
# include "libft/include/ft_printf.h"

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void		ft_stackinit(int ac, char **av, t_stack **stack);
void		ft_solve2(t_stack *stack);
void		ft_solve3(t_stack *a, t_stack *b);;
int			ft_minimum(t_stack *stack);
void		ft_addfirstnbr(t_stack **stack, int n);
void		ft_rmfirstnbr(t_stack **stack);

//	LST

t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int nb);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
int			ft_lstsize(t_stack *stack);

//	MOVES

void		rarb(t_stack **stack, char c);
void		rrarrb(t_stack **stack, char c);
void		papb(t_stack **a, t_stack **b, char c);

#endif