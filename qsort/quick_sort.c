/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 18:47:29 by skathale          #+#    #+#             */
/*   Updated: 2022/03/13 18:47:30 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "quick_sort.h"
#include "../insertion_sort/insertion_sort.h"

void	divide_block_by_two(t_list *dst, t_list *src, int is_from_top,
			int med_dif)
{
	int	med;

	med = src->head->med;
	if (is_from_top == 1)
		med = src->tail->med;
	while (src->size && ((is_from_top == 1 && src->tail->med == med)
			|| (is_from_top == 0 && src->head->med == med)))
	{
		if (!is_from_top)
			list_rotate(src, 1);
		push_elem_from_to(src, dst);
		if (dst->tail->index <= dst->tail->med)
		{
			dst->tail->med = dst->tail->med - med_dif;
			list_rotate(dst, 0);
		}
		else
			dst->tail->med = dst->tail->med + (med_dif);
	}
	src->block_count--;
	dst->block_count += 2;
}

void	divide_block_by_three(t_list *dst, t_list *src, int med_dif,
			size_t initial_size)
{
	int		med;
	size_t	i;

	med = src->tail->med;
	i = 0;
	while (i < initial_size)
	{
		if (src->tail->index <= med)
		{
			push_elem_from_to(src, dst);
			dst->tail->med = med - med_dif / 2;
			if (dst->tail->index <= med - med_dif)
			{
				dst->tail->med = med - med_dif - med_dif / 2;
				list_rotate(dst, 0);
			}
		}
		else
		{
			src->tail->med = med + med_dif;
			list_rotate(src, 0);
		}
		i++;
	}
	dst->block_count += 2;
}

void	divide_blocks_from_bottom(t_list *dst, t_list *src, int med_dif,
			int block_count)
{
	while (block_count)
	{
		if (src->size)
		{
			divide_block_by_two(dst, src, 0, med_dif);
			block_count--;
		}
		if (src->size && src->block_count != 1)
		{
			divide_block_by_two(dst, src, 1, med_dif);
			block_count--;
		}
	}
}

void	divide_blocks_from_top(t_list *dst, t_list *src, int med_dif,
			int block_count)
{
	while (block_count)
	{
		if (src->size)
		{
			divide_block_by_two(dst, src, 1, med_dif);
			block_count--;
		}
		if (src->size && src->block_count != 1)
		{
			divide_block_by_two(dst, src, 0, med_dif);
			block_count--;
		}
	}
}

void	quick_sort(t_program_state *ps)
{
	int	med_dif;
	int	count;

	med_dif = ps->a_stack->med / 2;
	count = 1;
	if (ps->a_stack->size > 400)
		count++;
	while (count > 0)
	{
		divide_block_by_three(ps->b_stack, ps->a_stack, med_dif,
			ps->a_stack->size);
		if (ps->a_stack->size > 100)
			divide_blocks_from_top(ps->a_stack, ps->b_stack, med_dif / 4, 2);
		else
			divide_blocks_from_top(ps->a_stack, ps->b_stack, med_dif / 4, 1);
		divide_blocks_from_bottom(ps->b_stack, ps->a_stack, med_dif / 8,
			ps->a_stack->block_count - 1);
		med_dif /= 2;
		count--;
	}
	divide_block_by_three(ps->b_stack, ps->a_stack, med_dif, ps->a_stack->size);
	divide_block_by_three(ps->b_stack, ps->a_stack, med_dif / 2,
		ps->a_stack->size);
	divide_block_by_two(ps->b_stack, ps->a_stack, 1, med_dif / 4);
	merge(ps->a_stack, ps->b_stack);
}
