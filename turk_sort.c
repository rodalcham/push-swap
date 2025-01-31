/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:24:58 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 13:54:20 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	turk_sort(t_list **a)
// {
// 	t_list	*b;

// 	b = NULL;
// 	while (list_size(*a) > 3)
// 	{
// 		push(a, &b, 'b');
// 	}
// 	sort_3(a, 'a');
// 	while (list_size(b))
// 	{
// 		double_locate(&b, a, next_bigger);
// 		locate(&b, get_cheapest(b, *a, next_bigger), 'b');
// 		locate(a, next_bigger(*a, b->data), 'a');
// 		push(&b, a, 'a');
// 	}
// 	locate(a, get_min(*a), 'a');
// }

void	turk_sort(t_list **a)
{
	t_list	*b;

	b = NULL;
	while (list_size(*a) > 3)
	{
		if (b)
		{
			double_locate(a, &b, next_smaller);
			locate(a, get_cheapest(*a, b, next_smaller), 'a');
			locate(&b, next_smaller(b, (*a)->data), 'b');
		}
		push(a, &b, 'b');
	}
	sort_3(a, 'a');
	if (b)
		locate(&b, get_max(b), 'b');
	while (list_size(b))
	{
		double_locate(&b, a, next_bigger);
		locate(&b, get_cheapest(b, *a, next_bigger), 'b');
		locate(a, next_bigger(*a, b->data), 'a');
		push(&b, a, 'a');
	}
	locate(a, get_min(*a), 'a');
}
