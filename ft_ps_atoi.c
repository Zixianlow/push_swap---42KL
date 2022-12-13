/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:06:54 by lzi-xian          #+#    #+#             */
/*   Updated: 2022/12/06 20:48:35 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ps_atoi_part_b(const char *str, int i, int j, long *r)
{
	while (str[i] != '\0')
	{
		if (j > 10)
			ft_error();
		else if (str[i] >= '0' && str[i] <= '9')
			*r = *r * 10 + str[i] - '0';
		else if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			break ;
		else
			ft_error();
		i++;
		j++;
	}
}

long	ft_ps_atoi(const char *str)
{
	int		i;
	int		s;
	long	r;
	int		j;

	i = 0;
	s = 1;
	r = 0;
	j = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s = s * -1;
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			ft_error();
	}
	ft_ps_atoi_part_b(str, i, j, &r);
	return (r * s);
}
