/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:42:28 by adi-nata          #+#    #+#             */
/*   Updated: 2023/04/04 16:37:21 by adi-nata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/include/libft.h"
# include "../libft/include/ft_printf.h"

typedef struct s_lis
{
	int	*index;
	int	*tmplis;
	int	lislen;
	int	stacklen;
	int	stay;
}	t_lis;

t_stack		*ft_last(t_stack *stack);
void		ft_freechecker(t_stack **a, t_stack **b);
int			ft_ordered(t_stack **a, t_stack **b);
void		ft_error(t_stack **a, t_stack **b);
void		ft_execute(t_stack **a, t_stack **b, char *line);
void		ft_read(t_stack **a, t_stack **b);
int			ft_check1(int ac, char **av);
int			ft_check2(int ac, char **av);
int			ft_check3(t_stack *stack);
long int	ft_atol(const char *nbr);
void		ft_stackinit(int ac, char **av, t_stack **stack);
void		ft_freestack(t_stack *stack);
int			ft_minimum(t_stack *stack);
int			ft_maximum(t_stack *stack);
void		ft_addfirstnbr(t_stack **stack, int n);
void		ft_rmfirstnbr(t_stack **stack);
void		ft_putback(t_stack **a, t_stack **b, int size, int tmpsize);

//	MOVES

void		sasb(t_stack **stack);
void		rarb(t_stack **stack);
void		rrarrb(t_stack **stack);
void		papb(t_stack **a, t_stack **b, char c);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

#endif