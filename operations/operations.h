/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:52:37 by skathale          #+#    #+#             */
/*   Updated: 2022/03/03 14:52:38 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H
# include "../program.h"
# include "../io_processing/io_processing.h"
# include "operations_utils.h"

void	swap_first_elements(t_list *list);
void	push_elem_from_to(t_list *src, t_list *dst);
void	list_rotate(t_list *list, int is_reverse);
#endif
