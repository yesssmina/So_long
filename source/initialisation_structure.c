/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:42:59 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/26 02:10:24 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void ft_init(t_data *data)
{
	data->check_nb_collectible = 0;
	data->nb_collectible = 0;
	data->nb_exit = 0;
	data->nb_player = 0;
	//data->check_nb_collectible = 0;
	data->coor_player_x = 0;
	data->coor_player_y = 0;
}

//initialiser alleger main

void ft_init1(t_map	*map, t_data *data, t_point *cur, t_point *size)
{
	data->nb_player = 0;
	data->nb_exit = 0;
	size->x = map->nb_colones;
	size->y = map->nb_lignes + 1;
	cur->x = data->coor_player_x;
    cur->y = data->coor_player_y;
}

void	ft_init_img(t_data_mlx	*img, t_map *map, void *mlx)
{
	img->path = "./images/texture.xpm";
	img->path_wall = "./images/wall.xpm";
	img->path_collectible = "./images/diams.xpm";
	img->path_player = "./images/pitch_front.xpm";
	img->path_exit = "./images/trone.xpm";
	img->img = mlx_xpm_file_to_image(mlx, img->path, &(img->wall_width), &(img->wall_height));
	img->wall = mlx_xpm_file_to_image(mlx, img->path_wall, &(img->wall_width), &(img->wall_height));
	img->collectible = mlx_xpm_file_to_image(mlx, img->path_collectible, &(img->wall_width), &(img->wall_height));
	img->player = mlx_xpm_file_to_image(mlx, img->path_player, &(img->wall_width), &(img->wall_height));
	img->exit = mlx_xpm_file_to_image(mlx, img->path_exit, &(img->wall_width), &(img->wall_height));
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img->img_width = (map->nb_colones) * 50;
	img->img_height = map->nb_lignes * 50;
	img->coor_p_x = 0;
	img->coor_p_y = 0;
	img->count_coll = 0;
	printf("wall_w%d\n", img->wall_width);
}