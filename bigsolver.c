/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 18:37:55 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/19 20:19:09 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_nonlis(t_stack **a, t_stack **b, t_lis *listruct, int *lis)
{
	int	i;
	int	pos;
	int stay;

	i = 0;
	pos = 1;
	stay = 0;
	while (listruct->stacklen > listruct->lislen)
	{
		while (lis[i])
		{
			if ((*a)->nbr == lis[i])
				stay++;
			i++;
		}
		if (!stay)
		{
			ft_whichalf(a, b, pos, listruct->stacklen);
			stay = 0;
		}
		i = 0;
		pos++;
		listruct->stacklen--;;
	}
}