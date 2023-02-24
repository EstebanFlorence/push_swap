/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/02/24 19:05:04 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_push	*a_stack;
	t_push	*b_stack;

	if (ac > 1)
	{
		if (ac == 3)
			ft_solve2(a_stack);
	}
}

void	ft_pushinit(int ac, char **av, t_push **push)
{

}

void	ft_solve2(t_push *a_stack)
{

}

int	ft_minimum(t_push *push)
{
	int	min;

	min = push->nbr;
	while (push)
	{
		if (push->nbr < min)
			min = push->nbr;
		push = push->next;
	}
	return (min);
}
