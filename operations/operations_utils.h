/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:30:22 by skathale          #+#    #+#             */
/*   Updated: 2022/02/21 12:30:23 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_UTILS_H
# define OPERATIONS_UTILS_H
# include "../program.h"
# include "../io_processing/io_processing.h"

void	swap_first_elements(t_list *list);
void	push_elem_from_to(t_list *list1, t_list *list2);
void	list_rotate(t_list *list, int is_reverse);
#endif
