/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_and_close_and_utils.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 23:42:52 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/04 22:42:31 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	reprint_map(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
	{
		ft_putstr_fd(map[i], 1);
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	if_mouv_1(int key, t_all *all)
{
	all->d_mlx->check_mouv = 1;
	ft_mouv_player(all->d_mlx->coor_x, all->d_mlx->coor_y + 1, all, key);
}

int	ft_close(int keycode, t_all *all)
{
	(void)keycode;
	(void)all;
	exit(0);
}

char	*error_mess(char *message)
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
