/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moveslis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:34:18 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/23 18:46:52 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_plusplus(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	i = 0;
	while (i < x && i < y)
	{
		rr(a, b);
		i++;
	}
	while (i < x || i < y)
	{
		if (i < x)
			rarb(a, 'a');
		else if (i < y)
			rarb(b, 'b');
		i++;
	}
	papb(b, a, 'a');
}

void	move_plusminus(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	i = 0;
	while (i < x)
	{
		rarb(a, 'a');
		i++;
	}
	while (y < 0)
	{
		rrarrb(b, 'b');
		y++;
	}
	papb(b, a, 'a');
}

void	move_minusplus(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	i = 0;
	while (x < 0)
	{
		rrarrb(a, 'a');
		x++;
	}
	while (i < y)
	{
		rarb(b, 'b');
		i++;
	}
	papb(b, a, 'a');
}

void	move_minusminus(t_stack **a, t_stack **b, int x, int y)
{
	int	i;

	i = 0;
	while (x < 0 && y < 0)
	{
		rrr(a, b);
		x++;
		y++;
	}
	while (x < 0 || y < 0)
	{
		while (x < 0)
		{
			rrarrb(a, 'a');
			x++;
		}
		while (y < 0)
		{
			rrarrb(b, 'b');
			y++;
		}
	}
	papb(b, a, 'a');
}
