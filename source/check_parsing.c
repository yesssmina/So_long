/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:03:06 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/04 22:39:42 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//check if check_way is ok
int	check_check_way(char **map, t_point	size, t_point cur, t_data *data)
{
	data->check_nb_col = 0;
	data->nb_player = 0;
	data->nb_exit = 0;
	check_way(map, size, cur, data);
	if (data->nb_player == 1 && data->check_nb_col == 0 && data->nb_exit == 0)
		error_mess("Error\nLe Playeur est isolé...\n");
	if (data->nb_col != data->check_nb_col || data->nb_exit
		< 1 || data->nb_player < 1)
	{
		if (data->nb_col > data->check_nb_col)
			error_mess("Error\nAu moins un collectible n'est pas accessible\n");
		if (data->nb_exit < 1)
			error_mess("Error\nLa sortie n'est pas accessible...\n");
		return (0);
	}
	return (1);
}

// check if check_map is ok
int	check_check_map(char **map, t_data *data, t_point	*point)
{
	int	res;

	data->nb_col = 0;
	data->nb_player = 0;
	data->nb_exit = 0;
	res = check_map(map, data, point);
	if (res == 0 || data->nb_col == 0
		|| data->nb_exit != 1 || data->nb_player != 1)
	{
		if (data->nb_col == 0)
			error_mess("Error\nIl n'y a pas de collectible...\n");
		if (data->nb_exit < 1)
			error_mess("Error\nIl n'y a pas de sortie...\n");
		if (data->nb_exit > 1)
			error_mess("Error\nIl y a plus d'une sortie...\n");
		if (data->nb_player < 1)
			error_mess("Error\nIl y a pas de Player...\n");
		if (data->nb_player > 1)
			error_mess("Error\nIl y a plus d'un Player...\n");
		return (0);
	}
	return (1);
}

//check the parsing
int	check_parsing(t_map *map, t_data *data, t_point size, t_point cur)
{
	t_point	point;
	t_point	pos;
	int		i;

	if (!check_size(map->map, &point))
		error_mess("Error\nLa map n'est pas rectangulaire :(\n");
	if (!check_wall(map->map, &pos))
		error_mess("Error\nLa map n'est pas entouree de murs :(\n");
	i = 0;
	if (!check_check_map(map->copie, data, &point))
		error_mess("Error\nCertainement un intru dans la map, ou un absent!\n");
	cur.y = data->coor_player_y;
	cur.x = data->coor_player_x;
	size.y = map->nb_lignes;
	size.x = map->nb_colones;
	if (!check_check_way(map->map, size, cur, data))
		error_mess("Error\nUn endroit inaccessible? Verifie le chemin!\n");
	data->nb_col = 0;
	return (1);
}
