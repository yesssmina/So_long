/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:42:59 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/28 00:47:32 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init(t_data *data)
{
	data->check_nb_col = 0;
	data->nb_col = 0;
	data->nb_exit = 0;
	data->nb_player = 0;
	data->coor_player_x = 0;
	data->coor_player_y = 0;
}

void	ft_init1(t_map *map, t_data *data, t_point *cur, t_point *size)
{
	data->nb_player = 0;
	data->nb_exit = 0;
	size->x = map->nb_colones;
	size->y = map->nb_lignes + 1;
	cur->x = data->coor_player_x;
	cur->y = data->coor_player_y;
}

void	check_open_xpm(void *img)
{
	if (img == NULL)
	{
		error_mess("Error\nEchec lors du chargement d'une image :(\n");
		return ;
	}
}

void	ft_init_xpm(void *mlx, t_data_mlx *i)
{
	i->img = mlx_xpm_file_to_image(mlx, i->path, &(i->wid), &(i->hei));
	check_open_xpm(i->img);
	i->wall = mlx_xpm_file_to_image(mlx, i->p_wall, &(i->wid), &(i->hei));
	check_open_xpm(i->wall);
	i->col = mlx_xpm_file_to_image(mlx, i->p_col, &(i->wid), &(i->hei));
	check_open_xpm(i->col);
	i->player_f = mlx_xpm_file_to_image(mlx, i->p_pl_f, &(i->wid), &(i->hei));
	check_open_xpm(i->player_f);
	i->player_l = mlx_xpm_file_to_image(mlx, i->p_pl_l, &(i->wid), &(i->hei));
	check_open_xpm(i->player_l);
	i->player_r = mlx_xpm_file_to_image(mlx, i->p_pl_r, &(i->wid), &(i->hei));
	check_open_xpm(i->player_r);
	i->player_b = mlx_xpm_file_to_image(mlx, i->p_pl_b, &(i->wid), &(i->hei));
	check_open_xpm(i->p_pl_b);
	i->exit = mlx_xpm_file_to_image(mlx, i->p_ex, &(i->wid), &(i->hei));
	check_open_xpm(i->exit);
	i->addr = mlx_get_data_addr(i->img, &(i->bits_per_pixel),
			&(i->line_length), &(i->endian));
}

void	ft_init_img(t_data_mlx	*img, t_map *map, void *mlx)
{
	img->path = "./images/texture.xpm";
	img->p_wall = "./images/wall.xpm";
	img->p_col = "./images/diams.xpm";
	img->p_pl_f = "./images/pitch_front.xpm";
	img->p_pl_l = "./images/pitch_left.xpm";
	img->p_pl_r = "./images/pitch_right.xpm";
	img->p_pl_b = "./images/pitch_behind.xpm";
	img->p_ex = "./images/trone.xpm";
	img->img_width = (map->nb_colones) * 50;
	img->img_height = map->nb_lignes * 50;
	ft_init_xpm(mlx, img);
	img->coor_x = 0;
	img->coor_y = 0;
	img->count_coll = 0;
	img->nb_coll = 0;
	img->count_mouv = 1;
	img->check_mouv = 0;
	img->cell_size = 50;
}
