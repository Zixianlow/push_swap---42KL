/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rule_rev_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:18:40 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 17:44:49 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_rule_rev_r(t_stack **a, int type)
{
	t_stack	*temp;
	t_stack	*last;

	temp = (t_stack *) malloc(sizeof(t_stack));
	temp->prev = NULL;
	temp->content = ft_last_node_content(*a);
	temp->order = ft_last_node_order(*a);
	temp->next = *a;
	(*a)->prev = temp;
	*a = (*a)->prev;
	while ((*a)->next && (*a)->next->next)
		*a = (*a)->next;
	last = (*a)->next;
	free(last);
	(*a)->next = NULL;
	if (type == 1)
		ft_putstr_fd("rra\n", 1);
	else if (type == 2)
		ft_putstr_fd("rrb\n", 1);
	return (temp);
}

void	ft_rule_rev_rr(t_stack **a, t_stack **b, int type)
{
	if (ft_stack_size(*a))
		*a = ft_rule_rev_r(a, 0);
	if (ft_stack_size(*b))
		*b = ft_rule_rev_r(b, 0);
	if (type == 1)
		ft_putstr_fd("rrr\n", 1);
}
