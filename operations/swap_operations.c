/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:56:42 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 14:56:42 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations_bonus_utils.h"

void	sa(t_program_state *program)
{
	swap_first_elements_b(program->a_stack);
}

void	sb(t_program_state *program)
{
	swap_first_elements_b(program->b_stack);
}

void	ss(t_program_state *program)
{
	swap_first_elements_b(program->a_stack);
	swap_first_elements_b(program->b_stack);
}
