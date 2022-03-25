/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:30:52 by skathale          #+#    #+#             */
/*   Updated: 2022/03/13 17:30:53 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*get_min_more_than(t_list *list, int value)
{
	t_node	*p;
	t_node	*min_p;
	size_t	i;

	i = 0;
	p = list->head;
	min_p = p;
	while (min_p->data <= value)
		min_p = min_p->next;
	while (i < list->size)
	{
		if (p->data < min_p->data && p->data > value)
			min_p = p;
		p = p->next;
		i++;
	}
	return (min_p);
}

t_node	*get_min(t_list *list)
{
	t_node	*p;
	t_node	*min_p;
	size_t	i;

	i = 0;
	p = list->head;
	min_p = p;
	while (i < list->size)
	{
		if (p->data < min_p->data)
			min_p = p;
		p = p->next;
		i++;
	}
	return (min_p);
}

void	get_indexes(t_list *list)
{
	int		prev_min;
	int		i;
	t_node	*temp;

	if (list->size == 0)
		return ;
	temp = get_min(list);
	temp->index = 1;
	temp->med = list->med;
	prev_min = temp->data;
	i = 2;
	while ((size_t)i <= list->size)
	{
		temp = get_min_more_than(list, prev_min);
		temp->index = i;
		temp->med = list->med;
		prev_min = temp->data;
		i++;
	}
}

int	is_contains(t_list *list, int value)
{
	t_node	*p;
	size_t	i;

	i = 0;
	p = list->head;
	while (i < list->size)
	{
		if (p->data == value)
			return (1);
		p = p->next;
		i++;
	}
	return (0);
}

void	free_list(t_list *list)
{
	while (list->tail)
		list_pop_back(list);
}
