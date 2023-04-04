/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:58:22 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/04 22:52:28 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_last(t_stack *stack)
{
	while (stack)
		stack = stack->next;
	return (stack);
}

void	ft_freechecker(t_stack **a, t_stack **b)
{
	if (*a)
		ft_freestack(*a);
	if (*b)
		ft_freestack(*b);
}

int	ft_ordered(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	if (*b)
		return (0);
	while (tmp->next)
	{
		if (tmp->nbr > tmp->next->nbr)
			return (0);
		tmp = tmp->next;
	}
	ft_printf("OK\n");
	ft_freestack(*a);
	exit (EXIT_SUCCESS);
}

void	ft_error(t_stack **a, t_stack **b)
{
	ft_printf("KO\n");
	ft_freechecker(a, b);
	exit(EXIT_FAILURE);
}

void	ft_execute(t_stack **a, t_stack **b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0)
		sasb(a);
	else if (ft_strcmp(line, "sb\n") == 0)
		sasb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
		rarb(a);
	else if (ft_strcmp(line, "rb\n") == 0)
		rarb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
		rrarrb(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrarrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(a, b);
	else if (ft_strcmp(line, "pa\n") == 0)
		papb(b, a, 'a');
	else if (ft_strcmp(line, "pb\n") == 0)
		papb(a, b, 'b');
	else
		ft_error(a, b);
}
