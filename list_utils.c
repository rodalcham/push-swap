/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:00:27 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/22 14:26:24 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_node(t_list **start, int new_data)
{
	t_list	*temp;

	temp = (t_list *)malloc(sizeof(t_list));
	if (!temp)
		return (free_list(*start));
	temp->next = NULL;
	temp->data = new_data;
	if (!*start)
		*start = temp;
	else
		get_last(*start)->next = temp;
	return (*start);
}

t_list	*get_last(t_list *start)
{
	t_list	*temp;

	temp = start;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

t_list	*free_list(t_list *start)
{
	t_list	*temp;

	while (start)
	{
		temp = start;
		start = start->next;
		free(temp);
	}
	return (NULL);
}

int	list_size(t_list *start)
{
	int	size;

	size = 0;
	while (start)
	{
		size++;
		start = start->next;
	}
	return (size);
}

t_list	*list_find(t_list *start, int value)
{
	while (start)
	{
		if (start->data == value)
			return (start);
		start = start->next;
	}
	return (NULL);
}
