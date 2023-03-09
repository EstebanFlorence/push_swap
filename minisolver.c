/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisolver.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 23:21:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/09 23:24:23 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	minisolver(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_solve2 (*a);
	else if (size == 3)
		ft_solve3 (a);
	else if (size == 4)
		ft_solve4 (a, b);
}

void	ft_solve2(t_stack *stack)
{
	if (stack->nbr != ft_minimum(stack))
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
		sasb ((*stack), 'a');
	else if (c < a && a < b)
		rrarrb (stack, 'a');
	else if (b < c && c < a)
		rarb (stack, 'a');
	else if (a < c && c < b)
	{
		sasb ((*stack), 'a');
		rarb (stack, 'a');
	}
	else if (c < b && b < a)
	{
		sasb ((*stack), 'a');
		rrarrb (stack, 'a');
	}
}

void	ft_solve4(t_stack **a, t_stack **b)
{
	int	n;
	int	x;
	int	y;
	int	z;
	
	papb (a, b, 'b');
	ft_solve3 (a);
	while ((*a)->prev)
		(*a) = (*a)->prev;
	papb (b, a, 'a');
	n = (*a)->nbr;
	x = (*a)->next->nbr;
	y = (*a)->next->next->nbr;
	z = (*a)->next->next->next->nbr;
	if (y < n && n < z)
	{
		rrarrb (a, 'a');
		sasb ((*a), 'a');
		rrarrb (a, 'a');
		rrarrb (a, 'a');
	}
	else if (x < n && n < y)
		sasb ((*a), 'a');
	else if (n > z)
		rarb (a, 'a');
}

void	ft_solve5(t_stack **a, t_stack ** b)
{}