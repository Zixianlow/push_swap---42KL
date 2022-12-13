/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:28:19 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/07 18:30:07 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_dup(char ***c)
{
	int	i;
	int	j;

	i = -1;
	while ((*c)[++i])
	{
		j = i;
		while ((*c)[++j])
		{
			if (ft_ps_atoi((*c)[i]) == ft_ps_atoi((*c)[j]))
			{
				i = 0;
				while ((*c)[i])
					free((*c)[i++]);
				return (1);
			}
		}
	}
	return (0);
}

int	ft_free_c(char ***c)
{
	int	i;

	i = 0;
	while ((*c)[i])
		free((*c)[i++]);
	return (0);
}

int	ft_check_ascend(char **c)
{
	int	i;

	i = 0;
	while (c[i] && c[i + 1])
	{
		if (c[i + 1])
		{
			if (ft_ps_atoi(c[i + 1]) < ft_ps_atoi(c[i]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_one(char **c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (ft_ps_atoi(c[i]) < -2147483648)
			ft_error();
		else if (ft_ps_atoi(c[i]) > 2147483647)
			ft_error();
		i++;
	}
	if (i == 1)
		return (1);
	return (0);
}

int	ft_free_all(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = NULL;
	temp2 = NULL;
	while (*a)
	{
		temp = *a;
		*a = (*a)->next;
		free(temp);
	}
	while (*b)
	{
		temp = *b;
		*b = (*b)->next;
		free(temp2);
	}
	return (0);
}
