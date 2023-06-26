/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/26 03:43:52 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_close(int keycode, t_all *all)
{
	(void)keycode;
	(void)all;
	exit(0);
	return (0);
}

void	put_texture(void *mlx, t_map *map, t_data_mlx *img, t_vars_mlx *vars)
{	
	t_point	point;
	
	point.y = 0;
	point.x = 0;
	while (map->copie[point.y])
	{
		while (map->copie[point.y][point.x])
		{
			mlx_put_image_to_window(mlx, vars->win, img->img, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == '1')
				mlx_put_image_to_window(mlx, vars->win, img->wall, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == 'C')
				mlx_put_image_to_window(mlx, vars->win, img->collectible, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == 'P')
				mlx_put_image_to_window(mlx, vars->win, img->player, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == 'E')
				mlx_put_image_to_window(mlx, vars->win, img->exit, point.x * 50, point.y * 50);
			point.x++;
		}
		point.x = 0;
		point.y++;
	}
}

int	loop(t_all *all)
{
	put_texture(all->v_mlx->mlx, all->map, all->d_mlx, all->v_mlx);
	mlx_key_hook(all->v_mlx->win, deal_key, (void*)all);
	mlx_hook(all->v_mlx->win, 17, 1L<<0, ft_close, &all->v_mlx);
	return(0);
}

void	do_mlx(t_all *all)
{
	//ft_init(data);
	nb_coll(all);
	mlx_loop_hook(all->v_mlx->mlx, loop, all);
	mlx_loop(all->v_mlx->mlx);
}
