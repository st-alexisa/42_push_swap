/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:42:53 by skathale          #+#    #+#             */
/*   Updated: 2022/02/19 17:42:54 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				med;
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_list
{
	char	name;
	int		med;
	int		max_value;
	int		block_count;
	size_t	size;
	t_node	*head;
	t_node	*tail;
}	t_list;

t_node	*create_node(int data);
t_node	*copy_node(t_node *other);
void	swap_values(t_node *n1, t_node *n2);

int		find_max(t_list *list);
int		is_sorted_list(t_list *list);
int		is_contains(t_list *list, int value);
void	get_indexes(t_list *list);
void	list_add_front(t_list *list, t_node *elem);
void	list_add_back(t_list *list, t_node *elem);
void	list_pop_back(t_list *list);
void	free_list(t_list *list);
#endif
