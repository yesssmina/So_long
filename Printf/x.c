/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:10:46 by sanaggar          #+#    #+#             */
/*   Updated: 2023/05/03 16:10:48 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_upperx(unsigned int d, int	*print)
{
	if (d < 0)
		return ;
	ft_putnbr_base("0123456789ABCDEF", d, print);
}

void	ft_x(unsigned int d, int	*print)
{
	if (d < 0)
		return ;
	ft_putnbr_base("0123456789abcdef", d, print);
}
