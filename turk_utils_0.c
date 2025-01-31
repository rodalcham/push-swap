/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 13:37:21 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 12:15:57 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_cheapest(t_list *src, t_list *dst, int (*f)(t_list *, int n))
{
	t_list	*st;
	int		value;
	int		moves;
	int		temp;
	int		arr[2];

	st = src;
	moves = INT_MAX;
	while (src)
	{
		arr[0] = src->data;
		arr[1] = f(dst, src->data);
		if (compatible(st, dst, arr, "fb") || compatible(st, dst, arr, "bf"))
			temp = min(max_d(st, dst, arr, 'f'), max_d(st, dst, arr, 'b'));
		else
			temp = distance(st, src->data, 'x')
				+ distance(dst, f(dst, src->data), 'x');
		if (temp < moves)
		{
			moves = temp;
			value = src -> data;
		}
		src = src->next;
	}
	return (value);
}

int	compatible(t_list *x, t_list *y, int *t, char *s)
{
	int	fd_x;
	int	bd_x;
	int	fd_y;
	int	bd_y;

	fd_x = distance(x, t[0], s[0]);
	bd_x = distance(x, t[0], s[1]);
	fd_y = distance(y, t[1], s[0]);
	bd_y = distance(y, t[1], s[1]);
	if ((fd_x <= bd_x && fd_y - fd_x < bd_y)
		|| (fd_y <= bd_y && fd_x - fd_y < bd_x))
	{
		if ((bd_x <= fd_x && bd_y - bd_x < fd_y)
			|| (bd_y <= fd_y && bd_x - bd_y < fd_x))
			if (max(bd_x, bd_y) < max(fd_x, fd_y))
				return (0);
		return (1);
	}
	return (0);
}

int	distance(t_list *start, int to_find, char f)
{
	int		forwards;
	int		backwards;
	t_list	*temp;

	if (!start)
		return (0);
	forwards = 0;
	temp = start;
	while (temp && temp->data != to_find)
	{
		temp = temp->next;
		forwards++;
	}
	if (!temp)
		return (-1);
	if (f == 'f')
		return (forwards);
	backwards = list_size(temp);
	if (f == 'b' || backwards < forwards)
		return (backwards);
	return (forwards);
}

void	double_locate(t_list **x, t_list **y, int (*f)(t_list *, int value))
{
	int	x_t;
	int	y_t;

	x_t = get_cheapest(*x, *y, f);
	y_t = f(*y, x_t);
	if (compatible(*x, *y, (int []){x_t, y_t}, "fb"))
	{
		while ((*x)->data != x_t && (*y)->data != y_t)
		{
			rotate(x, '\0');
			rotate(y, '\0');
			write(1, "rr\n", 3);
		}
	}
	else if (compatible(*x, *y, (int []){x_t, y_t}, "bf"))
	{
		while ((*x)->data != x_t && (*y)->data != y_t)
		{
			reverse_rotate(x, '\0');
			reverse_rotate(y, '\0');
			write(1, "rrr\n", 4);
		}
	}
}

void	locate(t_list **start, int to_find, char x)
{
	if (list_size(list_find(*start, to_find)) <= list_size(*start) / 2)
	{
		while ((*start)->data != to_find)
		{
			reverse_rotate(start, x);
		}
	}
	else
	{
		while ((*start)->data != to_find)
		{
			rotate(start, x);
		}
	}
}
