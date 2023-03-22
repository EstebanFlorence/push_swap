/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:37:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/22 19:03:25 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_moves(t_stack **a, t_stack **b)
{
	int	sizeb;
	int	*mova;
	int	*movb;
	int	i;

	i = 0;
	sizeb = ft_lstsize(*b);
	mova = (int *)malloc(sizeb * sizeof(int));
	movb = (int *)malloc(sizeb * sizeof(int));
	while (*b)
	{
		if (i <= sizeb / 2)
			movb[i] = i;
		else
			movb[i] = i - sizeb;
		if (ft_position2(*a, ((*b)->nbr)) <= ft_lstsize(*a) / 2)
			mova[i] = ft_position2(*a, (*b)->nbr);
		else
			mova[i] = ft_position2(*a, (*b)->nbr) - ft_lstsize(*a);
		printf("MOVA: %d\n", mova[i]);
		printf("MOVB: %d\n", movb[i]);
		i++;
		*b = (*b)->next;
	}
	i = ft_findbestmoves(mova, movb);
	ft_makebestmoves(mova[i], movb[i]);
	free (mova);
	free (movb);
}

int	ft_findbestmoves(int *mova, int *movb)
{
	int		i;
	int		best;
	int		line;
	int		moves;

	i = 0;
	best = INT_MAX;
	while (mova[i])
	{
		if (mova[i] >= 0 && movb[i] >= 0)
			if (mova[i] >= movb[i])
				moves = mova[i];
		else
			moves = movb[i];
		if (mova[i] < 0 && movb[i] >= 0)
			moves = (mova[i] * -1) + movb[i];
		if (mova[i] >= 0 && movb[i] < 0)
			moves = mova[i] + (movb[i] * -1);
		if (mova[i] < 0 && movb[i] < 0)
			if (mova[i] >= movb[i])
				moves = movb[i] * -1;
		else
			moves = mova[i] * -1;
		if (moves < best)
		{
			line = i;
			best = moves;
		}
		i++;
	}
	return (line);
}

void	ft_makebestmoves(int mova, int movb)
{
	int	i;
	int	sum;

	i = 0;
/* 	while ()
	{
		sum = mova + movb;
	} */
}
