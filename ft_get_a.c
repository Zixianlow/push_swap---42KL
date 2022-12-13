/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 16:27:34 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 18:28:51 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_set_new_node(t_stack	*a, char *s)
{
	a->prev = NULL;
	a->content = ft_ps_atoi(s);
	a->order = 0;
	a->next = NULL;
}

t_stack	*ft_get_a(char **c, t_stack	*a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	if (c[i++])
	{
		a = malloc (sizeof(t_stack));
		ft_set_new_node(a, c[0]);
		while (c[i])
		{
			temp = malloc (sizeof(t_stack));
			ft_set_new_node(temp, c[i]);
			while (a->next)
				a = a->next;
			a->next = temp;
			temp->prev = a;
			if (c[i])
				a = a->next;
			i++;
		}
		a->next = NULL;
		while (a->prev)
			a = a->prev;
	}
	return (a);
}
