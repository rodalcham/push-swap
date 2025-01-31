/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchavez <rchavez@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 14:16:08 by rchavez           #+#    #+#             */
/*   Updated: 2024/04/23 12:00:38 by rchavez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_list
{
	struct s_list	*next;
	int				data;
}					t_list;

int			min(int a, int b);
int			max(int a, int b);
int			get_min(t_list *start);
int			get_max(t_list *start);
int			is_sorted(t_list *start);
int			list_size(t_list *start);
int			next_bigger(t_list *start, int value);
int			next_smaller(t_list *start, int value);
int			parse(int argc, char **argv, t_list **list_a);
int			distance(t_list *start, int to_find, char x);
int			compatible(t_list *x, t_list *y, int *t, char *s);
int			max_d(t_list *start, t_list *dst, int arr[2], char x);
int			get_cheapest(t_list *src, t_list *dst,
				int (*f)(t_list *, int value));

long int	ft_atoi(char *str, int *accept);

size_t		ft_countwords(char const *s, char c);

t_list		*get_last(t_list *start);
t_list		*free_list(t_list *start);
t_list		*list_find(t_list *start, int value);
t_list		*create_node(t_list **start, int new_data);

char		**ft_split(char const *s, char c);
char		**ft_splitfree(char **ret, size_t i);

void		turk_sort(t_list **a);
void		swap(t_list **start, char x);
void		sort_3(t_list **start, char x);
void		rotate(t_list **start, char x);
void		reverse_rotate(t_list **start, char x);
void		push(t_list **src, t_list **dst, char x);
void		locate(t_list **start, int to_find, char x);
void		double_locate(t_list **x, t_list **y,
				int (*f)(t_list *, int value));

#endif