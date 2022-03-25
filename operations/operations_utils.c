/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:58:17 by skathale          #+#    #+#             */
/*   Updated: 2022/02/28 14:58:18 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_utils.h"

void	swap_first_elements(t_list *list)
{
	int	temp;

	temp = list->tail->data;
	list->tail->data = list->tail->prev->data;
	list->tail->prev->data = temp;
	put_char('s');
	put_char(list->name);
	put_char('\n');
}

void	push_elem_from_to(t_list *src, t_list *dst)
{
	list_add_back(dst, copy_node(src->tail));
	list_pop_back(src);
	put_char('p');
	put_char(dst->name);
	put_char('\n');
}

void	list_rotate(t_list *list, int is_reverse)
{
	if (list->size != 0)
	{
		put_char('r');
		if (is_reverse)
		{
			list->head = list->head->next;
			list->tail = list->tail->next;
			put_char('r');
		}
		else
		{
			list->head = list->head->prev;
			list->tail = list->tail->prev;
		}
		put_char(list->name);
		put_char('\n');
	}
}
