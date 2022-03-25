/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:56:00 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:01 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus_utils.h"

void	pa(t_program_state *program)
{
	push_elem_from_to_b(program->b_stack, program->a_stack);
}

void	pb(t_program_state *program)
{
	push_elem_from_to_b(program->a_stack, program->b_stack);
}
