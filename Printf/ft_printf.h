/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:13:26 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/08 16:21:01 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../Libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

void	choice(char c, va_list args, int *print);
int		ft_printf(const char *format, ...);
void	ft_c(int c, int	*print);
void	ft_upperx(unsigned int d, int *print);
void	ft_x(unsigned int d, int *print);
void	ft_p(unsigned long long d, int *print);
void	ft_putnbr_base(char	*base, size_t nb, int *print);
void	ft_d(int nb, int *print);
void	ft_putnbr(unsigned int nb, int *print);
void	ft_u(unsigned int d, int *print);
void	ft_s(char *s, int	*print);

#endif
