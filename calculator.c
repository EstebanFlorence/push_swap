/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:15:52 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/26 19:12:17 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
