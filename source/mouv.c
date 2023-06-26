/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 00:10:54 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/26 02:29:16 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
					all->d_mlx->coor_p_y = j;
					all->d_mlx->coor_p_x = i;
					//printf("hello1");
					return ;
				}
				i++;
			}
			j++;
		}
		//printf("hello2");
	return ;
}

int	deal_key(int key, void	*param)
{
	//printf("%d", key);
	t_all *all = (t_all *)param;
	
	if (key == 53)
		ft_close(key, all);

	position_player(all);

	if (key == 0 || key == 123)
	{
		ft_mouv_player(all->d_mlx->coor_p_x - 1, all->d_mlx->coor_p_y, all, key);
	}	
	if (key == 2 || key == 124)
	{
		ft_mouv_player(all->d_mlx->coor_p_x + 1, all->d_mlx->coor_p_y, all, key);
	}
	if (key == 13 || key == 126)
	{
		ft_mouv_player(all->d_mlx->coor_p_x, all->d_mlx->coor_p_y - 1, all, key);
	}
	if (key == 1 || key == 125)
	{
		ft_mouv_player(all->d_mlx->coor_p_x, all->d_mlx->coor_p_y + 1, all, key);
	}

	return (0);
}

void	ft_mouv_player(int new_x, int new_y, t_all *all, int key)
{
	//if (all->map->copie[new_y][new_x] == 'E' && all->d_mlx->count_coll != all->data->check_nb_collectible)
	//	return ;
	if (new_x >= 0 && new_x < all->map->nb_colones && new_y >= 0 && new_y < all->map->nb_lignes)
	{
		if (all->map->copie[new_y][new_x] != '1' && all->map->copie[new_y][new_x] != 'E' )
		{
			if (all->map->copie[new_y][new_x] == 'C')
				all->d_mlx->count_coll++;
			printf("count%d\n", all->d_mlx->count_coll);
			all->map->copie[new_y][new_x] = 'P';
			
			all->map->copie[all->d_mlx->coor_p_y][all->d_mlx->coor_p_x] = '0';

			if (key == 0)
				all->d_mlx->coor_p_x -= 1;

			if (key == 2)
				all->d_mlx->coor_p_x += 1;

			if (key == 13)
				all->d_mlx->coor_p_y -= 1;
				
			if (key == 1)
				all->d_mlx->coor_p_y += 1;
		}
		//if (all->d_mlx->count_coll == all->data->check_nb_collectible && all->map->copie[new_y][new_x] == 'E' )
		//{
		//	all->map->copie[new_y][new_x] = 'P';
		//	all->map->copie[all->d_mlx->coor_p_y][all->d_mlx->coor_p_x] = '0';
		//	//exit(0);
		//}
		reprint_map(all->map->copie);
	}
}

void	reprint_map(char **map)
{
	int	i;

	i = 0;

	while(map[i] != NULL)
	{
		ft_putstr_fd(map[i], 1);
		ft_putchar('\n');
		i++;
	}
	ft_putchar('\n');
}