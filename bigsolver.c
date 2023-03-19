/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:37:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/20 00:17:07 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nonlis(t_stack **a, t_stack **b, t_lis *listruct, int *lis)
{
	int		i;
	int		pos;
	int 	stay;
	t_stack	*tmpstack;

	i = 0;
	pos = 1;
	stay = 0;
	tmpstack = *a;
	while (listruct->stacklen > listruct->lislen || tmpstack)
	{
		while (i < listruct->lislen)
		{
			if ((*a)->nbr == lis[i])
				stay++;
			i++;
		}
		if (!stay)
		{
			tmpstack = *a;
			pos = ft_position(*a, (*a)->nbr);
			ft_whichalf(a, b, pos, listruct->stacklen);
			listruct->stacklen--;
		}
		else
		{
			tmpstack = tmpstack->next;
			stay = 0;
		}
		i = 0;
	}
}
