/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/14 23:40:59 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis(t_stack **stack, int **lis, int size)
{
	int		i;
	int		len;
	int		*tmplis;
	t_stack	*tmp;

	i = 0;
	len = 1;
	tmplis = (int *)malloc(size * sizeof(int));
	if (tmplis == NULL)
		return (0);
	tmplis[i] = (*stack)->nbr;
	tmp = (*stack)->next;
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
	free (tmplis);
	return (len);
}

void	ft_lisarr(int **lis, int **tmplis, int len)
{
	int	i;

	i = 0;
	*lis = (int *)malloc(len * sizeof(int));
	if (*lis == NULL)
		return ;
	while (i < len)
	{
		(*lis)[i] = (*tmplis)[i];
		i++;
	}
}
