/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_methods.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:13:55 by skathale          #+#    #+#             */
/*   Updated: 2022/02/19 18:13:58 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

t_node	*create_node(int data)
{
	t_node	*p;

	p = (t_node *) malloc(sizeof(t_node));
	p->data = data;
	p->next = NULL;
	p->prev = NULL;
	p->index = -1;
	return (p);
}

t_node	*copy_node(t_node *other)
{
	t_node	*p;

	p = create_node(other->data);
	p->index = other->index;
	p->med = other->med;
	return (p);
}

void	swap_values(t_node *n1, t_node *n2)
{
	int	temp;

	temp = n1->data;
	n1->data = n2->data;
	n2->data = temp;
}
