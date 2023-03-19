/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/19 18:42:14 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lisinnit(t_lis *listruct, t_stack **stack, int size)
{
	int	i;

	i = 1;
	listruct->index = (int *)malloc(size * sizeof(int));
	listruct->tmplis = (int *)malloc(size * sizeof(int));
	listruct->tmplis[0] = (*stack)->nbr;
	listruct->lislen = -1;
	listruct->stacklen = size;
	while (i < size)
	{
		listruct->tmplis[i] = INT_MAX;
		i++;
	}
}

void	ft_freelis(t_lis *listruct)
{
	free (listruct->index);
	free (listruct->tmplis);
	free (listruct);
}
