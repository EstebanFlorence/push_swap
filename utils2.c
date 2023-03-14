/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/14 22:57:04 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis(t_stack **stack, int **lis)
{
	int		i;
	int		len;
	int		tmplis[100];
	t_stack	*tmp;

	i = 0;
	len = 1;
	tmplis[i] = (*stack)->nbr;
	tmp = *stack;
	tmp = tmp->next;
	while (tmp)
	{
		while (i < len && tmp->nbr > tmplis[i])
			i++;
		tmplis[i] = tmp->nbr;
		if (i == len)
			len++;
		tmp = tmp->next;
	}
	ft_lisarr(lis, &tmplis, len);
	return (len);
}

void	ft_lisarr(int **lis, int (*tmplis)[100], int len)
{
	int	i;

	i = 0;
	*lis = (int *)malloc(len * sizeof(int));
	while (i < len)
	{
		(*lis)[i] = (*tmplis)[i];
		i++;
	}
}
