/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:47:45 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 15:47:46 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_BONUS_H
# define OPERATIONS_BONUS_H
# include "../linked_list/linked_list.h"
# include "../program.h"

void	execute_command(char *command_name, t_program_state *ps);
void	ra(t_program_state *program);
void	rb(t_program_state *program);
void	rr(t_program_state *program);
void	rra(t_program_state *program);
void	rrb(t_program_state *program);
void	rrr(t_program_state *program);
void	pa(t_program_state *program);
void	pb(t_program_state *program);
void	sa(t_program_state *program);
void	sb(t_program_state *program);
void	ss(t_program_state *program);
#endif