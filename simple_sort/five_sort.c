/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:01:24 by skathale          #+#    #+#             */
/*   Updated: 2022/03/21 16:01:25 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_sort.h"
#include "../insertion_sort/insertion_sort.h"

void	sort_five(t_program_state *ps)
{
	if (is_sorted_list(ps->a_stack))
		return ;
	push_elem_from_to(ps->a_stack, ps->b_stack);
	if (is_sorted_list(ps->a_stack))
		merge(ps->a_stack, ps->b_stack);
	else
	{
		push_elem_from_to(ps->a_stack, ps->b_stack);
		sort_triple(ps->a_stack);
		if (ps->b_stack->tail->prev->data > ps->a_stack->max_value
			&& ps->b_stack->tail->data > ps->a_stack->max_value)
		{
			if (ps->b_stack->tail->prev->data < ps->b_stack->tail->data)
				swap_first_elements(ps->b_stack);
			push_elem_from_to(ps->b_stack, ps->a_stack);
			list_rotate(ps->a_stack, 0);
			push_elem_from_to(ps->b_stack, ps->a_stack);
			list_rotate(ps->a_stack, 0);
		}
		else
			merge(ps->a_stack, ps->b_stack);
	}
}
