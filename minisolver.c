/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisolver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:21:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/29 15:23:27 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_solve2(t_stack **stack)
{
	if ((*stack)->nbr != ft_minimum(*stack))
		sasb(stack, 'a');
}

void	ft_solve3(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->nbr;
	b = (*stack)->next->nbr;
	c = (*stack)->next->next->nbr;
	if (b < a && a < c)
		sasb (stack, 'a');
	else if (c < a && a < b)
		rrarrb (stack, 'a');
	else if (b < c && c < a)
		rarb (stack, 'a');
	else if (a < c && c < b)
	{
		sasb (stack, 'a');
		rarb (stack, 'a');
	}
	else if (c < b && b < a)
	{
		sasb (stack, 'a');
		rrarrb (stack, 'a');
	}
}

int	ft_ordered(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	if (*b)
		return (0);
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("OK\n");
	ft_freestack(*a);
	exit (EXIT_SUCCESS);
}

void	ft_putback(t_stack **a, t_stack **b, int size, int tmpsize)
{
	ft_solve3(a);
	while (size < tmpsize)
	{
		papb(b, a, 'a');
		size++;
	}
}

void	ft_solve5(t_stack **a, t_stack **b, int size)
{
	int		pos;
	int		min;
	int		tmpsize;
	t_stack	*tmp;

	ft_ordered(a, b);
	pos = 1;
	min = 0;
	tmpsize = size;
	tmp = *a;
	while (size > 3)
	{
		min = ft_minimum(*a);
		while (tmp->nbr != min)
		{
			tmp = tmp->next;
			pos++;
		}
		ft_whichalf(a, b, pos, size);
		size--;
		pos = 1;
		tmp = *a;
	}
	ft_putback(a, b, size, tmpsize);
}
