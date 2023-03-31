/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-nata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:42:28 by adi-nata          #+#    #+#             */
/*   Updated: 2023/03/31 17:14:24 by adi-nata         ###   ########.fr       */
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
void		ft_freechecker(t_stack *a, t_stack *b);
int			ft_ordered(t_stack *stack);
void		ft_execute(t_stack *a, t_stack *b);
void		ft_read(t_stack *a, t_stack *b);


int			ft_check1(int ac, char **av);
int			ft_check2(int ac, char **av);
int			ft_check3(t_stack *stack);
long int	ft_atol(const char *nbr);
void		ft_stackinit(int ac, char **av, t_stack **stack);
void		minisolver(t_stack **a, t_stack **b, int size);
void		bigsola, t_stack *bver(t_stack **a, t_stack **b, int size);
void		ft_freestack(t_stack *stack);

void		ft_solve2(t_stack **stack);
void		ft_solve3(t_stack **stack);
void		ft_solve4(t_stack **a, t_stack **b);
void		ft_solve5(t_stack **a, t_stack **b, int size);
void		ft_solve5to50(t_stack **a, t_stack **b, int size);

void		ft_moves(t_stack **a, t_stack **b);
int			movcases(int *mova, int *movb, int i);
int			ft_findbestmoves(int *mova, int *movb, int sizeb);
void		ft_makebestmoves(t_stack **a, t_stack **b, int x, int y);
void		ft_calculator(t_stack **a, t_stack **b, int *mova, int *movb);

//	UTILS

int			ft_minimum(t_stack *stack);
int			ft_nextmaximum(t_stack *stack, int nbr);
int			ft_maximum(t_stack *stack);
void		ft_addfirstnbr(t_stack **stack, int n);
void		ft_rmfirstnbr(t_stack **stack);
int			ft_position(t_stack *stack, int nbr);
int			ft_position2(t_stack *stack, int nbr);
void		ft_whichalf(t_stack **a, t_stack **b, int pos, int size);
void		ft_putback(t_stack **a, t_stack **b, int size, int tmpsize);
void		ft_order(t_stack **stack, int size);

//	UTILIS

void		ft_lis(t_lis *listruct, t_stack **stack, int **lis);
void		ft_lisinnit(t_lis *listruct, t_stack **stack, int size);
void		ft_lislen(t_stack *tmpstack, t_lis *listruct);
int			searchreplace(int *lis, int start, int i, int nbr);
void		ft_lisarr(t_stack **stack, t_stack *tmpstack, \
						t_lis *listruct, int **lis);
void		ft_nonlis(t_stack **a, t_stack **b, t_lis *listruct, int *lis);
void		ft_stayornot(t_stack **a, t_stack **b, t_stack **tmpstack, \
							t_lis *listruct);
void		ft_freelis(t_lis *listruct);

//	MOVES

void		sasb(t_stack **stack, char c);
void		rarb(t_stack **stack, char c);
void		rrarrb(t_stack **stack, char c);
void		papb(t_stack **a, t_stack **b, char c);
void		ss(t_stack **a, t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rrr(t_stack **a, t_stack **b);

void		move_plusplus(t_stack **a, t_stack **b, int x, int y);
void		move_plusminus(t_stack **a, t_stack **b, int x, int y);
void		move_minusplus(t_stack **a, t_stack **b, int x, int y);
void		move_minusminus(t_stack **a, t_stack **b, int x, int y);

#endif