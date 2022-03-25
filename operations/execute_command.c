/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:55:32 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 17:55:33 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../program.h"
#include "operations_bonus.h"
#include "../io_processing/io_processing.h"

void	process_push(char *command_name, t_program_state *ps)
{
	if (ft_strncmp(command_name, "pa", 2) == 0)
		pa(ps);
	else if (ft_strncmp(command_name, "pb", 2) == 0)
		pb(ps);
}

void	process_rotate(char *command_name, t_program_state *ps)
{
	if (ft_strncmp(command_name, "ra", 2) == 0)
		ra(ps);
	else if (ft_strncmp(command_name, "rb", 2) == 0)
		rb(ps);
	else if (ft_strncmp(command_name, "rr", 2) == 0)
		rr(ps);
}

void	process_reverse_rotate(char *command_name, t_program_state *ps)
{
	if (ft_strncmp(command_name, "ra", 2) == 0)
		rra(ps);
	else if (ft_strncmp(command_name, "rb", 2) == 0)
		rrb(ps);
	else if (ft_strncmp(command_name, "rr", 2) == 0)
		rrr(ps);
}

void	process_swap(char *command_name, t_program_state *ps)
{
	if (ft_strncmp(command_name, "sa", 2) == 0)
		sa(ps);
	else if (ft_strncmp(command_name, "sb", 2) == 0)
		sb(ps);
	else if (ft_strncmp(command_name, "ss", 2) == 0)
		ss(ps);
}

void	execute_command(char *command_name, t_program_state *ps)
{
	size_t	size;

	size = ft_strlen(command_name);
	if (command_name[0] == 'p' && size == 3)
		process_push(command_name, ps);
	else if (command_name[0] == 'r' && (size == 3 || size == 4))
	{
		if (command_name[1] == 'r' && size == 4)
			process_reverse_rotate(command_name + 1, ps);
		else if (size == 3)
			process_rotate(command_name, ps);
		else
			put_str_fd("Error\n", 2);
	}
	else if (command_name[0] == 's' && size == 3)
		process_swap(command_name, ps);
	else
		put_str_fd("Error\n", 2);
}
