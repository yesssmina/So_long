/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:42:52 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/28 00:28:38 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

char	*error_mess(char	*message)
{
	ft_putstr_fd(message, 1);
	exit(EXIT_FAILURE);
}

void	if_key_close(int key, t_all *all)
{
	if (key == 53)
	{
		ft_printf("Vous avez quitté le jeu...PERDU!\n");
		ft_close(key, all);
	}	
}