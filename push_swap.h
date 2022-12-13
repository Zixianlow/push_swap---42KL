/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 15:07:58 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 17:54:03 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				order;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_ps_int
{
	int	part;
	int	part2;
	int	i;
	int	l;
	int	c;
}	t_ps_int;

t_stack	*ft_get_a(char **c, t_stack *a);
long	ft_ps_atoi(const char *str);
int		ft_put_b_part(t_stack **a, t_stack **b);
void	ft_set_order(t_stack	*a);
void	ft_sort_three(t_stack **a);
//ft_rule
void	ft_rule_p(t_stack **a, t_stack **b, int type);
void	ft_rule_r(t_stack *a, int type);
void	ft_rule_rr(t_stack *a, t_stack *b, int type);
t_stack	*ft_rule_rev_r(t_stack **a, int type);
void	ft_rule_rev_rr(t_stack **a, t_stack **b, int type);
void	ft_rule_s(t_stack *a, int type);
void	ft_rule_ss(t_stack *a, t_stack *b, int type);
// ft_get_join_sort
void	ft_sorting_stack(t_stack **a, t_stack **b);
char	*ft_join_arg(int ac, char **av);
char	*ft_get_arguments(int ac, char **av);
//ft_check_and_free
int		ft_check_dup(char ***c);
int		ft_free_c(char ***c);
int		ft_check_ascend(char **c);
int		ft_check_one(char **c);
int		ft_free_all(t_stack **a, t_stack **b);
// ft_chk_and_error
int		ft_chk_not_num(char **av);
int		ft_chk_ascend(t_stack *a);
void	ft_error(void);
//ft_stack_and_last_node
int		ft_stack_size(t_stack *a);
int		ft_stack_min(t_stack *a);
int		ft_stack_max(t_stack *a);
int		ft_last_node_content(t_stack *a);
int		ft_last_node_order(t_stack *a);
//ft_put_b
void	ft_put_back(t_stack **a, t_stack **b, int part);
void	ft_put_back_10(t_stack **a, t_stack **b);
//ft_put_b_utils
int		ft_bottom_high(t_stack *b, int part);
int		ft_sorted_min(t_stack *a, int part, int k);
void	ft_put_back_part_a(t_stack **a, t_stack **b, int s, int part);
int		ft_calc_part(t_stack *a, int increment, int part);

#endif