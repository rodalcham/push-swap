/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 11:41:37 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 12:05:09 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_d(t_list *start, t_list *dst, int arr[2], char x)
{
	int	a;
	int	b;

	a = distance(start, arr[0], x);
	b = distance(dst, arr[1], x);
	if (a > b)
		return (a);
	return (b);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}
