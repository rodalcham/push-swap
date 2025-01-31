/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:00:08 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 14:46:53 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;

	list_a = NULL;
	if ((argc == 2 && !argv[1][0]) || argc == 1)
		return (0);
	if (parse(argc, argv, &list_a) == 6)
	{
		free_list(list_a);
		return (0);
	}
	if (!is_sorted(list_a))
		turk_sort(&list_a);
	free_list(list_a);
}
