/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_and_last_node.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:10:28 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:15 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	ft_stack_min(t_stack *a)
{
	int	i;
	int	min;

	i = 0;
	min = a->order;
	while (a)
	{
		if (min > a->order)
			min = a->order;
		a = a->next;
	}
	return (min);
}

int	ft_stack_max(t_stack *a)
{
	int	i;
	int	max;

	i = 0;
	max = a->order;
	while (a)
	{
		if (max < a->order)
			max = a->order;
		a = a->next;
	}
	return (max);
}

int	ft_last_node_content(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->content);
}

int	ft_last_node_order(t_stack *a)
{
	while (a->next)
		a = a->next;
	return (a->order);
}
