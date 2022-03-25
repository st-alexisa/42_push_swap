/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:46:49 by skathale          #+#    #+#             */
/*   Updated: 2022/02/19 16:46:50 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "program.h"
#include "io_processing/io_processing.h"
#include "qsort/quick_sort.h"
#include "insertion_sort/insertion_sort.h"

int	main(int argc, char **argv)
{
	t_program_state	*ps;

	ps = NULL;
	if (argc > 1)
	{
		initialize_program(&ps);
		if (try_parse_args(ps->a_stack, argc, argv))
		{
			if (ps->a_stack->size < 20)
				insertion_sort(ps);
			else if (!is_sorted_list(ps->a_stack))
				quick_sort(ps);
		}
		else
			put_str_fd("Error", 2);
		free_program_state(ps);
	}
	return (0);
}
