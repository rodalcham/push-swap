/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:55:20 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/22 14:26:15 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **start, char x)
{
	t_list	*temp;

	if (!(*start) || !((*start)->next))
		return ;
	temp = *start;
	*start = (*start)->next;
	temp->next = (*start)->next;
	(*start)->next = temp;
	if (x)
	{
		write(1, "s", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	push(t_list **src, t_list **dst, char x)
{
	t_list	*temp;

	if (!(*src))
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
	if (x)
	{
		write(1, "p", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	rotate(t_list **start, char x)
{
	t_list	*temp;

	if (!(*start) || !((*start)->next))
		return ;
	temp = *start;
	*start = (*start)->next;
	temp->next = NULL;
	get_last(*start)->next = temp;
	if (x)
	{
		write(1, "r", 1);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}

void	reverse_rotate(t_list **start, char x)
{
	t_list	*temp;

	if (!(*start) || !((*start)->next))
		return ;
	temp = get_last(*start);
	temp->next = *start;
	while ((*start)->next != temp)
	{
		*start = (*start)->next;
	}
	(*start)->next = NULL;
	*start = temp;
	if (x)
	{
		write(1, "rr", 2);
		write(1, &x, 1);
		write(1, "\n", 1);
	}
}
