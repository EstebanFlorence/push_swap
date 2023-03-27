/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:16:38 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/27 15:22:26 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nonlis(t_stack **a, t_stack **b, t_lis *listruct, int *lis)
{
	int		i;
	t_stack	*tmpstack;

	i = 0;
	tmpstack = *a;
	while (listruct->stacklen > listruct->lislen)
	{
		while (i < listruct->lislen)
		{
			if (tmpstack->nbr == lis[i])
				listruct->stay++;
			i++;
		}
		ft_stayornot(a, b, &tmpstack, listruct);
		i = 0;
	}
}

void	ft_stayornot(t_stack **a, t_stack **b, t_stack **tmpstack, \
			t_lis *listruct)
{
	int	pos;

	pos = 1;
	if (!listruct->stay)
	{
		pos = ft_position(*a, (*tmpstack)->nbr);
		ft_whichalf(a, b, pos, listruct->stacklen);
		*tmpstack = (*tmpstack)->next;
		listruct->stacklen--;
	}
	else
	{
		*tmpstack = (*tmpstack)->next;
		listruct->stay = 0;
	}
}

void	ft_freelis(t_lis *listruct)
{
	free (listruct->index);
	free (listruct->tmplis);
	free (listruct);
}
