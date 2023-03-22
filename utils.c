/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:13:09 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/22 17:47:09 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_minimum(t_stack *stack)
{
	int	min;

	min = stack->nbr;
	while (stack)
	{
		if (stack->nbr < min)
			min = stack->nbr;
		stack = stack->next;
	}
	return (min);
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

int	ft_maximum(t_stack *stack)
{
	int	max;

	max = stack->nbr;
	while (stack)
	{
		if (stack->nbr > max)
			max = stack->nbr;
		stack = stack->next;
	}
	return (max);
}

void	ft_addfirstnbr(t_stack **stack, int n)
{
	t_stack	*new;

	new = ft_lstnew(n);
	if (!*stack)
		*stack = new;
	else
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
}

void	ft_rmfirstnbr(t_stack **stack)
{
	if ((*stack)->next)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		*stack = NULL;
}

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
