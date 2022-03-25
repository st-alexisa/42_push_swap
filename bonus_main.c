/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 17:52:42 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 17:52:43 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "io_processing/io_processing.h"
#include "operations/operations_bonus.h"
#include "gnl/get_next_line.h"

void	read_and_execute_commands(t_program_state *ps)
{
	char	*command_name;

	command_name = get_next_line(0);
	while (command_name)
	{
		execute_command(command_name, ps);
		free(command_name);
		command_name = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_program_state	*ps;
	size_t			initial_size;

	ps = NULL;
	initial_size = 0;
	if (argc > 1)
	{
		initialize_program(&ps);
		if (try_parse_args(ps->a_stack, argc, argv))
		{
			initial_size = ps->a_stack->size;
			read_and_execute_commands(ps);
			if (ps->a_stack->size == initial_size
				&& is_sorted_list(ps->a_stack))
				put_str("OK\n");
			else
				put_str("KO\n");
		}
		else
			put_str_fd("Error", 2);
		free_program_state(ps);
	}
	return (0);
}
