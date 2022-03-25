/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:30:26 by skathale          #+#    #+#             */
/*   Updated: 2022/02/21 12:30:27 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus_utils.h"

void	ra(t_program_state *program)
{
	list_rotate_b(program->a_stack, 0);
}

void	rb(t_program_state *program)
{
	list_rotate_b(program->b_stack, 0);
}

void	rr(t_program_state *program)
{
	list_rotate_b(program->b_stack, 0);
	list_rotate_b(program->a_stack, 0);
}
