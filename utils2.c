/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/22 18:57:39 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_whichalf(t_stack **a, t_stack **b, int pos, int size)
{
	if (pos > (size / 2))
	{
		while (pos <= size)
		{
			rrarrb (a, 'a');
			pos++;
		}
		papb (a, b, 'b');
	}
	else
	{
		while (pos > 1)
		{
			rarb (a, 'a');
			pos--;
		}
		papb (a, b, 'b');
	}
}

int	ft_position2(t_stack *stack, int nbr)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (nbr < stack->nbr && stack->nbr == ft_minimum2(stack, nbr))
			return (pos);
		if (nbr > stack->nbr && nbr > stack->next->nbr \
				|| nbr > stack->nbr && !stack->next)
			return (pos + 1);
		else
			pos++;
		stack = stack->next;
	}
}

//	ritornare lo stack->nbr successivamente maggiore di nbr, altrimenti nbr
int	ft_minimum2(t_stack *stack, int nbr)
{
	int	min;
	int	next_min;

	if (nbr >= ft_maximum(stack))
		return (ft_minimum(stack));
	min = nbr;
	next_min = ft_maximum(stack);
	while (stack)
	{
		if (stack->nbr > nbr && stack->nbr < next_min)
			next_min = stack->nbr;
		stack = stack->next;
	}
	return (next_min);
}
