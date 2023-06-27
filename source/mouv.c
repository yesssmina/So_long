/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:10:54 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/28 01:06:56 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	nb_coll(t_all *all)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	all->d_mlx->nb_coll = 0;
	while (all->map->copie[y] != NULL)
	{
		x = 0;
		while (all->map->copie[y][x] != '\0')
		{
			if (all->map->copie[y][x] == 'C')
				all->d_mlx->nb_coll++;
			x++;
		}
		y++;
	}
}

void	position_player(t_all *all)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (all->map->copie[j] != NULL)
	{
		i = 0;
		while (all->map->copie[j][i] != '\0')
		{
			if (all->map->copie[j][i] == 'P')
			{
				all->d_mlx->coor_y = j;
				all->d_mlx->coor_x = i;
				return ;
			}
			i++;
		}
		j++;
	}
	return ;
}

int	deal_key(int key, void	*param)
{
	t_all	*all = (t_all *)param;

	if_key_close(key, all);
	position_player(all);
	if (key == 0 || key == 123)
	{
		all->d_mlx->check_mouv = 0;
		ft_mouv_player(all->d_mlx->coor_x - 1, all->d_mlx->coor_y, all, key);
	}	
	if (key == 2 || key == 124)
	{
		all->d_mlx->check_mouv = 2;
		ft_mouv_player(all->d_mlx->coor_x + 1, all->d_mlx->coor_y, all, key);
	}
	if (key == 13 || key == 126)
	{
		all->d_mlx->check_mouv = 13;
		ft_mouv_player(all->d_mlx->coor_x, all->d_mlx->coor_y - 1, all, key);
	}
	if (key == 1 || key == 125)
	{
		all->d_mlx->check_mouv = 1;
		ft_mouv_player(all->d_mlx->coor_x, all->d_mlx->coor_y + 1, all, key);
	}
	return (0);
}

void	if_key(int key, t_all *all)
{
	if (key == 0)
		all->d_mlx->coor_x -= 1;
	if (key == 2)
		all->d_mlx->coor_x += 1;
	if (key == 13)
		all->d_mlx->coor_y -= 1;
	if (key == 1)
		all->d_mlx->coor_y += 1;
}

void	ft_mouv_player(int new_x, int new_y, t_all *all, int key)
{
	if (new_x >= 0 && new_x < all->map->nb_colones && new_y
		>= 0 && new_y < all->map->nb_lignes)
	{
		if (all->map->copie[new_y][new_x] != '1' &&
			all->map->copie[new_y][new_x] != 'E')
		{
			ft_printf("%d mouv'\n", all->d_mlx->count_mouv++);
			if (all->map->copie[new_y][new_x] == 'C')
				all->d_mlx->count_coll++;
			all->map->copie[new_y][new_x] = 'P';
			all->map->copie[all->d_mlx->coor_y][all->d_mlx->coor_x] = '0';
			if_key(key, all);
		}
		if (all->map->copie[new_y][new_x] == 'E' &&
			all->d_mlx->count_coll == all->d_mlx->nb_coll)
		{
			ft_printf("%d mouv'! Bravo!\n", all->d_mlx->count_mouv);
			ft_close(key, all);
		}
	}
}

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
