/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:56:50 by skathale          #+#    #+#             */
/*   Updated: 2022/02/19 17:56:51 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

int	find_max(t_list *list)
{
	int		max;
	t_node	*p;
	size_t	i;

	i = 0;
	if (list->size == 0)
		return (-2147483648);
	p = list->head;
	max = p->data;
	while (i < list->size)
	{
		if (p->data > max)
			max = p->data;
		p = p->next;
		i++;
	}
	return (max);
}

int	is_sorted_list(t_list *list)
{
	t_node	*p;
	size_t	i;

	i = 0;
	if (list->size == 0)
		return (1);
	p = list->head;
	while (i < list->size - 1)
	{
		if (p->data < p->next->data)
			return (0);
		p = p->next;
		i++;
	}
	return (1);
}

void	list_add_back(t_list *list, t_node *elem)
{
	if (list->size == 0)
	{
		list->head = elem;
		list->tail = elem;
	}
	else
	{
		list->tail->next = elem;
		elem->prev = list->tail;
		list->tail = elem;
	}
	list->tail->next = list->head;
	list->head->prev = list->tail;
	(list->size)++;
	if (elem->data > list->max_value)
		list->max_value = elem->data;
}

void	list_add_front(t_list *list, t_node *elem)
{
	if (list->size == 0)
	{
		elem->prev = elem;
		list->tail = elem;
	}
	else
	{
		elem->prev = list->tail;
		list->head->prev = elem;
		list->tail->next = elem;
	}
	elem->next = list->head;
	list->head = elem;
	(list->size)++;
	if (elem->data > list->max_value)
		list->max_value = elem->data;
}

void	list_pop_back(t_list *list)
{
	t_node	*temp;

	temp = list->tail;
	if (list->size == 1)
	{
		list->head = NULL;
		list->tail = NULL;
	}
	else
	{
		list->tail = temp->prev;
		list->tail->next = list->head;
		list->head->prev = list->tail;
	}
	(list->size)--;
	if (temp->data == list->max_value)
		list->max_value = find_max(list);
	free(temp);
}
