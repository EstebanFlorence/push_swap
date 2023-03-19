/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/19 16:08:03 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis(t_stack **stack, int **lis, int size)
{
	int		i;
	int		pos;
	int		tmp;
	int		lislen;
	int		*index;
	int		*tmplis;
	t_stack	*tmpstack;
	
	i = 1;
	pos = 1;
	tmp = 0;
	lislen = -1;
	index = (int *)malloc(size * sizeof(int));
	tmplis = (int *)malloc(size * sizeof(int));
	tmpstack = (*stack)->next;
	tmplis[0] = (*stack)->nbr;
	while (i < size)
	{
		tmplis[i] = INT_MAX;
		i++;
	}
	i = 1;
	while (tmpstack)
	{
		index[i] = searchreplace(tmplis, 0, i, tmpstack->nbr);
		if (lislen < index[i])
			lislen = index[i];
		i++;
		tmpstack = tmpstack->next;
	}
	i = size - 1;
	tmp = lislen;
	tmpstack = *stack;
	*lis = (int *)malloc((lislen + 1) * sizeof(int));
	while (i >= 0)
	{
		if (index[i] == tmp)
		{
			while (pos != i + 1)
			{
				tmpstack = tmpstack->next;
				pos++;
			}
			(*lis)[tmp] = tmpstack->nbr;
			tmpstack = *stack;
			pos = 1;
			--tmp;
		}
		--i;
	}
	free (index);
	free (tmplis);
	return (lislen + 1);
}

int		searchreplace(int *lis, int start, int i, int nbr)
{
	int	pos;

	pos = (start + i) / 2;
	while (start <= i)
	{
		if (lis[pos] > nbr)
			i = pos - 1;
		else if (lis[pos] == nbr)
			return (pos);
		else if (pos + 1 <= i && lis[pos + 1] >= nbr)
		{
			lis[pos + 1] = nbr;
			return (pos + 1);
		}
		else
			start = pos + 1;

		pos = (start + i) / 2;
	}
	if (pos == start)
	{
		lis[pos] = nbr;
		return (pos);
	}
	lis[pos + 1] = nbr;
	return (pos + 1);
}
