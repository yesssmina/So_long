/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:30 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/03 16:10:33 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(unsigned int nb, int *print)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10, print);
		ft_putnbr(nb % 10, print);
	}
	if (nb < 10)
	{
		ft_putchar_fd(nb + '0', 1);
		(*print)++;
	}
}

void	ft_u(unsigned int d, int	*print)
{
	if (d < 0)
		return ;
	ft_putnbr(d, print);
}
