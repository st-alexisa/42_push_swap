/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:47:02 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 15:47:03 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus.h"

void	swap_first_elements_b(t_list *list)
{
	int	temp;

	if (list->size == 0)
		return ;
	temp = list->tail->data;
	list->tail->data = list->tail->prev->data;
	list->tail->prev->data = temp;
}

void	push_elem_from_to_b(t_list *src, t_list *dst)
{
	if (src->size == 0)
		return ;
	list_add_back(dst, copy_node(src->tail));
	list_pop_back(src);
}

void	list_rotate_b(t_list *list, int is_reverse)
{
	if (list->size != 0)
	{
		if (is_reverse)
		{
			list->head = list->head->next;
			list->tail = list->tail->next;
		}
		else
		{
			list->head = list->head->prev;
			list->tail = list->tail->prev;
		}
	}
}
