/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/30 23:50:56 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	put_texture_p(void *mlx, t_all *a)
{
	if (a->d_mlx->check_mouv == 0)
		mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_l,
			a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
	if (a->d_mlx->check_mouv == 1)
		mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_f,
			a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
	if (a->d_mlx->check_mouv == 2)
		mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_r,
			a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
	if (a->d_mlx->check_mouv == 13)
		mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->player_b,
			a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
}

void	put_str_to_window(int arg, t_all *a)
{
	char	*str;

	str = ft_itoa(arg);
	mlx_string_put(a->v_mlx->mlx, a->v_mlx->win, a->d_mlx->coor_x * 50,
		a->d_mlx->coor_y * 50.5, 0xCC00FF, str);
	free(str);
}

void	put_texture(void *mlx, t_all *a)
{
	a->y = 0;
	while (a->map->copie[a->y])
	{
		a->x = 0;
		while (a->map->copie[a->y][a->x])
		{
			mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->img,
				a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
			if (a->map->copie[a->y][a->x] == '1')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->wall,
					a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
			if (a->map->copie[a->y][a->x] == 'C')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->col,
					a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
			if (a->map->copie[a->y][a->x] == 'P')
				put_texture_p(mlx, a);
			if (a->map->copie[a->y][a->x] == 'E')
				mlx_put_image_to_window(mlx, a->v_mlx->win, a->d_mlx->exit,
					a->x * a->d_mlx->cell_size, a->y * a->d_mlx->cell_size);
			a->x++;
		}
		a->y++;
	}
	put_str_to_window(a->d_mlx->count_mouv, a);
}

int	loop(t_all *all)
{
	put_texture(all->v_mlx->mlx, all);
	mlx_key_hook(all->v_mlx->win, deal_key, (void *)all);
	mlx_hook(all->v_mlx->win, 17, 1L << 0, ft_close, &all->v_mlx);
	return (0);
}

void	do_mlx(t_all *all)
{
	nb_coll(all);
	mlx_do_key_autorepeaton(all->v_mlx->mlx);
	mlx_loop_hook(all->v_mlx->mlx, loop, all);
	mlx_loop(all->v_mlx->mlx);
}
