/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_structure.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 00:42:59 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/15 00:58:38 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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