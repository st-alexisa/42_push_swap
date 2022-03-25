/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 20:33:37 by skathale          #+#    #+#             */
/*   Updated: 2022/03/11 20:33:38 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSERTION_SORT_H
# define INSERTION_SORT_H
# include "../program.h"
# include "../operations/operations.h"

void	insertion_sort(t_program_state *ps);
void	merge(t_list *dst, t_list *src);
#endif
