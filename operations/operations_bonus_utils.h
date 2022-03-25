/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:12:43 by skathale          #+#    #+#             */
/*   Updated: 2022/03/22 18:12:44 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_BONUS_UTILS_H
# define OPERATIONS_BONUS_UTILS_H
# include "../linked_list/linked_list.h"
# include "../program.h"

void	swap_first_elements_b(t_list *list);
void	push_elem_from_to_b(t_list *src, t_list *dst);
void	list_rotate_b(t_list *list, int is_reverse);
#endif