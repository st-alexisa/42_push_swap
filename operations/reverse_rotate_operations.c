/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:52:13 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 14:52:14 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus_utils.h"

void	rra(t_program_state *program)
{
	list_rotate_b(program->a_stack, 1);
}

void	rrb(t_program_state *program)
{
	list_rotate_b(program->b_stack, 1);
}

void	rrr(t_program_state *program)
{
	list_rotate_b(program->a_stack, 1);
	list_rotate_b(program->b_stack, 1);
}
