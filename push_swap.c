/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:18:00 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/09 23:26:29 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackinit(int ac, char **av, t_stack **stack)
{
	int i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	ft_test(t_stack *stack)
{
	while(stack->prev)
		stack = stack->prev;
	while (stack)
	{
		ft_printf("%d\n", stack->nbr);
		stack = stack->next;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		size;

	a = NULL;
	b = NULL;
	size = 0;
	ft_stackinit (ac, av, &a);
	size = ft_lstsize (a);
	ft_test(a);
	if (size < 6)
		minisolver(&a, &b, size);
	ft_test(a);
	return (0);
}
