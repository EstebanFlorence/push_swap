/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:13:09 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/01 16:13:40 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*next;

	if (lst != NULL)
	{
		next = lst;
		while (1)
		{
			if (next->next == NULL)
				return (next);
			next = next->next;
		}
	}
	return (NULL);
}

t_stack	*ft_lstnew(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack) * 1);
	if (new == NULL)
		return (NULL);
	new->nbr = nb;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		if (last != NULL)
		{
			last->next = new;
			new->prev = last;
		}
	}
}