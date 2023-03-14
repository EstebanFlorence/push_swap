/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 20:22:43 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/14 16:36:07 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lis(t_stack **stack, int size)
{
	int		i;
	int		len;
	int		lis[100];
	t_stack	*tmp;

	i = 0;
	len = 1;
	//lis = (int *)malloc(sizeof(int) * size);
	lis[i] = (*stack)->nbr;
	tmp = *stack;
	tmp = tmp->next;
	while (tmp)
	{
		while (i < len && tmp->nbr > lis[i])
			i++;
		lis[i] = tmp->nbr;
		if (i == len)
			len++;
		tmp = tmp->next;
	}
	//free (lis);
	return (len);
}
