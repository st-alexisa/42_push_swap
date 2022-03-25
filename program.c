/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 12:18:13 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 12:18:14 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"

void	initialize_program(t_program_state **program)
{
	t_list	*a;
	t_list	*b;

	a = (t_list *) malloc(sizeof(t_list));
	a->tail = NULL;
	a->head = NULL;
	a->size = 0;
	a->name = 'a';
	a->med = 0;
	a->max_value = -2147483648;
	a->block_count = 1;
	b = (t_list *) malloc(sizeof(t_list));
	b->tail = NULL;
	b->head = NULL;
	b->size = 0;
	b->name = 'b';
	b->med = 0;
	b->max_value = -2147483648;
	b->block_count = 0;
	*program = (t_program_state *) malloc(sizeof(t_program_state));
	(*program)->a_stack = a;
	(*program)->b_stack = b;
}

void	free_program_state(t_program_state *ps)
{
	free_list(ps->a_stack);
	free_list(ps->b_stack);
	free(ps->a_stack);
	free(ps->b_stack);
	free(ps);
}
