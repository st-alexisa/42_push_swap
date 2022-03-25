/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skathale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 10:32:18 by skathale          #+#    #+#             */
/*   Updated: 2022/03/10 10:32:19 by skathale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io_processing.h"

int	print_recursive(int nb, int notation, int isLowerCase)
{
	int	count;
	int	digit;

	count = 0;
	if (nb == 0)
		return (0);
	count += print_recursive(nb / notation, notation, isLowerCase);
	digit = nb % notation;
	if (nb < 0)
		digit *= -1;
	if (digit >= 0 && digit < 10)
		count += put_char('0' + digit);
	else if (isLowerCase == 1)
		count += put_char('a' + digit - 10);
	else
		count += put_char('A' + digit - 10);
	return (count);
}

int	put_nbr(int nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		count += put_char('0');
	if (nb < 0)
		count += put_char('-');
	count += print_recursive(nb, 10, 0);
	return (count);
}
