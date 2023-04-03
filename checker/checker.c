/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 19:08:25 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/03 18:58:29 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_stackinit(int ac, char **av, t_stack **stack)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		ft_lstadd_back(stack, ft_lstnew(ft_atoi(av[i])));
		i++;
	}
}

void	ft_read(t_stack **a, t_stack **b)
{
	char	*line;

	ft_ordered(a, b);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL)
		{
			free (line);
			break ;
		}
		ft_execute(a, b, line);
		free (line);
	}
	if (!ft_ordered(a, b))
	{
		ft_printf("KO\n");
		ft_freechecker(a, b);
		exit (EXIT_FAILURE);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac == 1)
		return (0);
	if (!ft_check1(ac, av))
		return (0);
	if (!ft_check2(ac, av))
		return (0);
	a = NULL;
	b = NULL;
	ft_stackinit (ac, av, &a);
	if (!ft_check3(a))
	{
		ft_freestack(a);
		return (0);
	}
	ft_read(&a, &b);
	ft_freestack(a);
	ft_freestack(b);
	return (0);
}
