/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:27:13 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/25 19:21:24 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lis(t_lis *listruct, t_stack **stack, int **lis, int size)
{
	t_stack	*tmpstack;

	tmpstack = (*stack)->next;
	ft_lislen(stack, tmpstack, listruct, size);
	tmpstack = *stack;
	ft_lisarr(stack, tmpstack, listruct, lis);
	listruct->lislen++;
}

void	ft_lislen(t_stack **stack, t_stack *tmpstack, t_lis *listruct, int size)
{
	int		i;

	i = 1;
	while (tmpstack)
	{
		listruct->index[i] = \
			searchreplace(listruct->tmplis, 0, i, tmpstack->nbr);
		if (listruct->lislen < listruct->index[i])
			listruct->lislen = listruct->index[i];
		i++;
		tmpstack = tmpstack->next;
	}
}

void	ft_lisarr(t_stack **stack, t_stack *tmpstack, \
			t_lis *listruct, int **lis)
{
	int		i;
	int		tmp;
	int		pos;

	i = listruct->stacklen -1;
	tmp = listruct->lislen;
	pos = 1;
	*lis = (int *)malloc((listruct->lislen + 1) * sizeof(int));
	while (i >= 0)
	{
		if (listruct->index[i] == tmp)
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
}

int	searchreplace(int *lis, int start, int i, int nbr)
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

void	ft_lisinnit(t_lis *listruct, t_stack **stack, int size)
{
	int	i;

	i = 1;
	listruct->index = (int *)malloc(size * sizeof(int));
	listruct->tmplis = (int *)malloc(size * sizeof(int));
	listruct->tmplis[0] = (*stack)->nbr;
	listruct->lislen = -1;
	listruct->stacklen = size;
	listruct->stay = 0;
	while (i < size)
	{
		listruct->tmplis[i] = INT_MAX;
		i++;
	}
}
