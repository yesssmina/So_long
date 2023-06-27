/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/27 19:48:32 by sanaggar         ###   ########.fr       */
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


void	put_texture(void *mlx, t_all *a)
{	
	a->y = 0;
	a->x = 0;
	while (a->map->copie[a->y])
	{
		while (a->map->copie[a->y][a->x])
		{
			mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->img, a->x * 50, a->y * 50);
			if (a->map->copie[a->y][a->x] == '1')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->wall, a->x * 50, a->y * 50);
				
			if (a->map->copie[a->y][a->x] == 'C')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->collectible, a->x * 50, a->y * 50);

			if (a->map->copie[a->y][a->x] == 'P' && a->d_mlx->check_mouv == 0)
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_l, a->x * 50, a->y * 50);

			if (a->map->copie[a->y][a->x] == 'P' && a->d_mlx->check_mouv == 1)
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_f, a->x * 50, a->y * 50);

			if (a->map->copie[a->y][a->x] == 'P' && a->d_mlx->check_mouv == 2)
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_r, a->x * 50, a->y * 50);

			if (a->map->copie[a->y][a->x] == 'P' && a->d_mlx->check_mouv == 13)
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_b, a->x * 50, a->y * 50);	

			if (a->map->copie[a->y][a->x] == 'E')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->exit, a->x * 50, a->y * 50);
			a->x++;
		}
		a->x = 0;
		a->y++;
	}
}

int	loop(t_all *all)
{
	put_texture(all->v_mlx->mlx, all);
	mlx_key_hook(all->v_mlx->win, deal_key, (void*)all);
	mlx_hook(all->v_mlx->win, 17, 1L<<0, ft_close, &all->v_mlx);
	return(0);
}

void	do_mlx(t_all *all)
{
	//ft_init(data);
	nb_coll(all);
	mlx_do_key_autorepeaton(all->v_mlx->mlx);
	mlx_loop_hook(all->v_mlx->mlx, loop, all);
	mlx_loop(all->v_mlx->mlx);
}
