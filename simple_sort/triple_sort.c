/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:28:26 by skathale          #+#    #+#             */
/*   Updated: 2022/03/21 15:28:28 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple_sort.h"

void	sort_triple(t_list *list)
{
	int	beg;
	int	mid;
	int	end;

	if (is_sorted_list(list))
		return ;
	beg = list->head->index;
	mid = list->head->next->index;
	end = list->tail->index;
	if (beg > mid && beg > end)
		swap_first_elements(list);
	else if (beg < mid && mid > end)
		list_rotate(list, 1);
	else if (end > beg && end > mid)
		list_rotate(list, 0);
	sort_triple(list);
}
