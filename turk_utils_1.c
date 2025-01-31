/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:14:32 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/22 14:26:07 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *start)
{
	int	min;

	min = start->data;
	while (start)
	{
		if (start->data < min)
			min = start->data;
		start = start->next;
	}
	return (min);
}

int	get_max(t_list *start)
{
	int	max;

	max = start->data;
	while (start)
	{
		if (start->data > max)
			max = start->data;
		start = start->next;
	}
	return (max);
}

int	next_smaller(t_list *start, int value)
{
	int	ret;

	ret = get_min(start);
	if (value < ret)
		return (get_max(start));
	while (start)
	{
		if (start->data > ret && start->data < value)
			ret = start->data;
		start = start->next;
	}
	return (ret);
}

int	next_bigger(t_list *start, int value)
{
	int	ret;

	ret = get_max(start);
	if (value > ret)
		return (get_min(start));
	while (start)
	{
		if (start->data < ret && start->data > value)
			ret = start->data;
		start = start->next;
	}
	return (ret);
}

void	sort_3(t_list **start, char x)
{
	if ((*start)->data > (*start)->next->data)
		swap(start, x);
	if ((*start)->next->next && !is_sorted(*start))
	{
		reverse_rotate(start, x);
		sort_3(start, x);
	}
}
