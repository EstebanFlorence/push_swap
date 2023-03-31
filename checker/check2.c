/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 16:58:22 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/31 18:47:44 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*ft_last(t_stack *stack)
{
	while (stack)
		stack = stack->next;
	return (stack);
}

void	ft_freechecker(t_stack *a, t_stack *b)
{
	ft_printf("KO\n");
	ft_freestack(a);
	if (b)
		ft_freestack(b);
	exit (1);
}

int	ft_ordered(t_stack *stack)
{
	int		min;
	int		max;
	t_stack	*tmp;

	min = ft_minimum(a);
	max = ft_maximum(a);
	tmp = a;
	if (b != NULL || a->nbr != min || ft_last(a)->nbr != max)
		ft_freechecker(a, b);
	while (tmp)
	{
		if (tmp->nbr > tmp->next->nbr) 
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	ft_execute(t_stack *a, t_stack *b, char *line)
{
	
}

void	ft_read(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(0);
	if (line == NULL || ft_oredered(a))
	{
		ft_printf("OK/n");
		ft_freestack(a);
		exit (1);
	}
	ft_execute(a, b, line)
	free (line);

}
