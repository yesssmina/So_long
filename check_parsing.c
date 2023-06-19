/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:03:06 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/17 23:10:55 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check if check_way est ok
int	check_check_way(char **map, t_point	size, t_point cur, t_data *data)
{
	//t_map	maps;
	
	data->check_nb_collectible = 0;
	data->nb_player = 0;
	data->nb_exit = 0;

	
	check_way(map, size, cur, data);
	if (data->nb_collectible != data->check_nb_collectible || 
		data->nb_exit < 1 || data->nb_player < 1)
			return (0);
	return (1);
}

// check si check_map est ok
int	check_check_map(char **map, t_data *data, t_point	*point)
{
	int	res;
	data->nb_collectible = 0;
	data->nb_player = 0;
	data->nb_exit = 0;
	
	res = check_map(map, data, point);
	if (res == 0 || data->nb_collectible == 0 || 
		data->nb_exit != 1 || data->nb_player != 1)
			return (0);
	return (1);
}

//check les fonctions de mon parsing
int	check_parsing(t_map *map, t_data *data, t_point size, t_point cur)
{
	t_point	point;
	t_point	pos;
	int	i;
	
	if (!check_size(map, map->map, &point))
		error_mess("Error\nLa map n'est pas rectangulaire :(\n");
	if (!check_wall(map->map, &pos))
		error_mess("Error\nLa map n'est pas entouree de murs :(\n");
	i = 0;
	if (!check_check_map(map->copie, data, &point))
		error_mess("Error\nIl y a tres certainement un intru dans la map!\n");
	cur.y = data->coor_player_y;
	cur.x = data->coor_player_x;
	size.y = map->nb_lignes;
	size.x = map->nb_colones;
	printf("colones%d", size.x);
	if (!check_check_way(map->map, size, cur, data))
		error_mess("Error\nSurement un endroit inaccessible... Verifie le chemin!\n");
	data->nb_collectible = 0;
	return (1);
}