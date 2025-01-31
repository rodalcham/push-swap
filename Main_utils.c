/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez@student.42heilbronn.de <rchavez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:01:16 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/22 18:58:57 by rchavez@stu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str, int *accept)
{
	long int	ret;
	int			factor;

	factor = 1;
	*accept = 1;
	if (*(str) == '-')
	{
		factor = -1;
		str++;
	}
	if (!*str)
		*accept = 0;
	ret = 0;
	while (*str)
	{
		if (*str < '0' || *str > '9' || ret > INT_MAX || ret < INT_MIN)
			*accept = 0;
		ret *= 10;
		ret += ((*str) - '0') * factor;
		str++;
	}
	return (ret);
}

int	is_sorted(t_list *start)
{
	while (start->next)
	{
		if (start->data > start->next->data)
		{
			return (0);
		}
		start = start->next;
	}
	return (1);
}
