/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:08:39 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/31 16:56:29 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_moves(t_stack **a, t_stack **b)
{
	int		i;
	int		sizeb;
	int		*mova;
	int		*movb;

	i = 0;
	sizeb = ft_lstsize(*b);
	mova = (int *)malloc(sizeb * sizeof(int));
	movb = (int *)malloc(sizeb * sizeof(int));
	ft_calculator(a, b, mova, movb);
	i = ft_findbestmoves(mova, movb, sizeb);
	ft_makebestmoves(a, b, mova[i], movb[i]);
	free (mova);
	free (movb);
}

void	ft_calculator(t_stack **a, t_stack **b, int *mova, int *movb)
{
	int		i;
	int		sizeb;
	t_stack	*tmpb;

	i = 0;
	sizeb = ft_lstsize(*b);
	tmpb = *b;
	while (tmpb)
	{
		if (i <= sizeb / 2)
			movb[i] = i;
		else
			movb[i] = i - sizeb;
		if (ft_position2(*a, (tmpb->nbr)) <= ft_lstsize(*a) / 2)
			mova[i] = ft_position2(*a, tmpb->nbr);
		else
			mova[i] = ft_position2(*a, tmpb->nbr) - ft_lstsize(*a);
		i++;
		tmpb = tmpb->next;
	}
}

int	ft_findbestmoves(int *mova, int *movb, int sizeb)
{
	int		i;
	int		best;
	int		line;
	int		moves;

	i = 0;
	best = INT_MAX;
	while (i < sizeb)
	{
		moves = movcases(mova, movb, i);
		if (moves < best)
		{
			line = i;
			best = moves;
		}
		i++;
	}
	return (line);
}

int	movcases(int *mova, int *movb, int i)
{
	int	moves;

	moves = 0;
	if (mova[i] >= 0 && movb[i] >= 0)
	{
		if (mova[i] >= movb[i])
			moves = mova[i];
		else
			moves = movb[i];
	}
	else if (mova[i] < 0 && movb[i] >= 0)
		moves = (mova[i] * -1) + movb[i];
	else if (mova[i] < 0 && movb[i] < 0)
	{
		if (mova[i] >= movb[i])
			moves = movb[i] * -1;
		else
			moves = mova[i] * -1;
	}
	else if (mova[i] >= 0 && movb[i] < 0)
		moves = mova[i] + (movb[i] * -1);
	return (moves);
}

void	ft_makebestmoves(t_stack **a, t_stack **b, int x, int y)
{
	if (x >= 0 && y >= 0)
		move_plusplus (a, b, x, y);
	if (x >= 0 && y < 0)
		move_plusminus (a, b, x, y);
	if (x < 0 && y >= 0)
		move_minusplus (a, b, x, y);
	if (x < 0 && y < 0)
		move_minusminus (a, b, x, y);
}
