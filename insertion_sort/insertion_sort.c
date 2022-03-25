/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:33:23 by skathale          #+#    #+#             */
/*   Updated: 2022/03/11 20:33:24 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "insertion_sort.h"
#include "../simple_sort/simple_sort.h"

void	print_program_state(t_program_state *ps);

void	merge_step(t_list *dst, t_list *src)
{
	while (src->size > 1 && src->head->data >= src->tail->data)
		list_rotate(src, 1);
	if (dst->size == 0)
		push_elem_from_to(src, dst);
	else if (src->size == 0 || (dst->size != 1 && src->size && dst->head->data
			< dst->tail->data && (src->tail->data < dst->head->data
				|| src->tail->data > dst->max_value)))
		list_rotate(dst, 1);
	else if (src->size && (dst->size == 1 || ((src->tail->data
					< dst->tail->data) && (dst->head->data < src->tail->data
					|| dst->head->data > dst->tail->data))))
		push_elem_from_to(src, dst);
	else if (src->size && dst->max_value < src->tail->data)
	{
		push_elem_from_to(src, dst);
		list_rotate(dst, 0);
	}
	else
		list_rotate(dst, 0);
}

void	merge(t_list *dst, t_list *src)
{
	while (src->size != 0 || (src->size == 0 && !is_sorted_list(dst)))
		merge_step(dst, src);
}

void	insertion_sort(t_program_state *ps)
{
	while (ps->a_stack->size > 5 && !is_sorted_list(ps->a_stack))
		push_elem_from_to(ps->a_stack, ps->b_stack);
	if (ps->a_stack->size == 2 && !is_sorted_list(ps->a_stack))
		list_rotate(ps->a_stack, 0);
	else if (ps->a_stack->size < 5 && !is_sorted_list(ps->a_stack))
	{
		if (ps->a_stack->size == 4)
			push_elem_from_to(ps->a_stack, ps->b_stack);
		sort_triple(ps->a_stack);
	}
	else if (ps->a_stack->size == 5 && !is_sorted_list(ps->a_stack))
		sort_five(ps);
	merge(ps->a_stack, ps->b_stack);
}
