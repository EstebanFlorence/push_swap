/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/02/28 18:12:51 by adi-nata         ###   ########.fr       */
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

void	ft_stackinit(int ac, char **av, t_stack **push)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(push, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

int	ft_minimum(t_stack *push)
{
	int	min;

	min = push->nbr;
	while (push)
	{
		if (push->nbr < min)
			min = push->nbr;
		push = push->next;
	}
	return (min);
}

void	ft_solve2(t_stack *a)
{
	(void)a;
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	ft_stackinit(ac, av, &a);
	/*if (ac > 1)
	{
		if (ac == 3)
			ft_solve2(a);
	}*/
	while (a)
	{
		printf("%d\n", a->nbr);
		a = a->next;
	}
	return (0);
}