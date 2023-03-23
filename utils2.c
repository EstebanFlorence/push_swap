/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/23 02:04:32 by adi-nata         ###   ########.fr       */
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
	int	i;

	i = 0;
	while (stack)
	{
		if (nbr < stack->nbr && stack->nbr == ft_nextminimum(stack, nbr))
			return (i);
		if (nbr > stack->nbr && nbr > stack->next->nbr \
				|| nbr > stack->nbr && !stack->next)
			return (i + 1);
		else
			i++;
		stack = stack->next;
	}
	return (i);
}

//	ritornare lo stack->nbr successivamente maggiore di nbr, altrimenti nbr
int	ft_nextminimum(t_stack *stack, int nbr)
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

void	movcases1(int *mova, int *movb, int i, int moves)
{
	if (mova[i] >= 0 && movb[i] >= 0)
	{
		if (mova[i] >= movb[i])
			moves = mova[i];
		else
			moves = movb[i];
	}
	else if (mova[i] < 0 && movb[i] >= 0)
		moves = (mova[i] * -1) + movb[i];
}

void	movcases2(int *mova, int *movb, int i, int moves)
{
	if (mova[i] < 0 && movb[i] < 0)
	{
		if (mova[i] >= movb[i])
			moves = movb[i] * -1;
		else
			moves = mova[i] * -1;
	}
	else if (mova[i] >= 0 && movb[i] < 0)
		moves = mova[i] + (movb[i] * -1);
}
