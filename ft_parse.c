/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 15:53:09 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 14:44:12 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse(int argc, char **argv, t_list **list_a)
{
	int			pos;
	int			max;
	int			accept;
	long int	buff;

	pos = 1;
	max = argc;
	if (argc == 2)
	{
		pos = 0;
		max = ft_countwords(argv[1], ' ');
		argv = ft_split(argv[1], ' ');
	}
	while (pos < max)
	{
		buff = ft_atoi(argv[pos], &accept);
		if (!accept || (*list_a && distance(*list_a, buff, 'n') != -1)
			|| buff < INT_MIN || buff > INT_MAX)
			return (write(1, "Error\n", 6));
		*list_a = create_node(list_a, (int)buff);
		pos++;
	}
	if (argc == 2)
		ft_splitfree(argv, max);
	return (1);
}
