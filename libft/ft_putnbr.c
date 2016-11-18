/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edescoin <edescoin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 12:51:13 by edescoin          #+#    #+#             */
/*   Updated: 2016/11/17 17:54:30 by edescoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long	l;

	l = (long)n;
	if (n < 0)
	{
		ft_putchar('-');
		l = -l;
	}
	if (n > 10 || n < -10)
		ft_putnbr(l / 10);
	ft_putchar('0' + (l % 10));
}