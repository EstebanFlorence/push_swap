/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/31 16:57:06 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	int	i;

	i = 0;
	if (nbr >= ft_maximum(stack))
		return (ft_position(stack, ft_minimum(stack)) - 1);
	while (stack)
	{
		if (stack->nbr == ft_nextmaximum(stack, nbr))
			return (i);
		else
			i++;
		stack = stack->next;
	}
	return (i);
}

int	ft_nextmaximum(t_stack *stack, int nbr)
{
	int	next_max;

	next_max = ft_maximum(stack);
	while (stack)
	{
		if (stack->nbr > nbr && stack->nbr < next_max)
			next_max = stack->nbr;
		stack = stack->next;
	}
	return (next_max);
}

void	ft_order(t_stack **stack, int size)
{
	if (ft_position(*stack, ft_minimum(*stack)) > (size / 2))
	{
		while ((*stack)->nbr != ft_minimum(*stack))
			rrarrb(stack, 'a');
	}
	else
	{
		while ((*stack)->nbr != ft_minimum(*stack))
			rarb(stack, 'a');
	}
}

void	ft_freestack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free (tmp);
	}
}
