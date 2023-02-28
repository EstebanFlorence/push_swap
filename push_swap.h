/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:42:28 by adi-nata          #+#    #+#             */
/*   Updated: 2023/02/28 16:58:00 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void		ft_stackinit(int ac, char **av, t_stack **push);
void		ft_solve2(t_stack *a);
int			ft_minimum(t_stack *push);

t_stack		*ft_lstlast(t_stack *lst);
t_stack		*ft_lstnew(int nb);
void		ft_lstadd_back(t_stack **lst, t_stack *new);


#endif