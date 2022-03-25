/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 11:21:17 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 11:21:17 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H
# include "linked_list/linked_list.h"

typedef struct s_program_state
{
	t_list	*a_stack;
	t_list	*b_stack;
}	t_program_state;

void	initialize_program(t_program_state **program);
void	free_program_state(t_program_state *ps);
#endif