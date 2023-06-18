/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/19 01:25:53 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// check si la map est bien rectangulaire
int	check_size(t_map *data, char	**map, t_point *point)
{
	int		i;
	
	i = 0;
	point->x = 0;
	point->y = 0;
	while (map[point->y])
	{
		point->x = 0;
		while (map[point->y][point->x])
			point->x++;
		i = ft_strlen(map[point->y]);
		if (point->x != data->nb_colones -1)
			return (0);
		point->y++;
	}
	return (1);
}

//check si la map est bien entoure de murs
int	check_wall(char **map, t_point *pos)
{
	pos->x = 0;
	pos->y = 0;
	while (map[0] && map[0][pos->x] != '\0')
	{
		if (map[0][pos->x] != '1')
			return (0);
		pos->x++;
	}
	while (map[pos->y])
	{
		if (map[pos->y][0] != '1' || map[pos->y][pos->x - 1] != '1')
			return (0);
		pos->y++;
	}
	pos->x = 0;
	while (map[pos->y - 1])
	{
		if (map[0][pos->x] == '\0')
			break;
		if (map[pos->y - 1][pos->x] != '1')
			return (0);
		pos->x++;
	}	
	return (1);
}

//check s'il y a un chemin accessible entre le P, un C et un E
void	check_way(char **map, t_point size, t_point cur, t_data *data)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x 
		|| map[cur.y][cur.x] == '1')
		return ;
	
	if (map[cur.y][cur.x] == 'P')
		data->nb_player++;
	if (map[cur.y][cur.x] == 'C')
		data->check_nb_collectible++;
	if (map[cur.y][cur.x] == 'E')
		data->nb_exit++;
	
	map[cur.y][cur.x] = '1';
	check_way(map, size, (t_point){cur.x - 1, cur.y}, data);
	check_way(map, size, (t_point){cur.x + 1, cur.y}, data);
	check_way(map, size, (t_point){cur.x, cur.y - 1}, data);
	check_way(map, size, (t_point){cur.x, cur.y + 1}, data);
}

// check s'il y a le bon nombre de de P, C et E et rien d'autre
int	check_map(char **map, t_data *data, t_point	*point)
{	
	point->y = 0;
	point->x = 0;
	while (map[point->y])
	{
		while (map[point->y][point->x])
		{
			if (!egal_ECP1or0(map, point->y, point->x, data))
				return(0);
			if (map[point->y][point->x] == 'C')
				data->nb_collectible++;
			if (map[point->y][point->x] == 'E')
				data->nb_exit++;
			if (map[point->y][point->x] == 'P')
				data->nb_player++;
			point->x++;
		}
		point->x = 0;
		point->y++;
		}
	return (1);
}

int	egal_ECP1or0(char **map, int y, int x, t_data *data)
{	
	if (map[y][x] == '1')
		return (1);
	if (map[y][x] == '0')
		return (1);				
	if (map[y][x] == 'P')
	{
		data->coor_player_y = y;
		data->coor_player_x = x;
		return (1);
	}
	if (map[y][x] == 'E')
		return (1);
	if (map[y][x] == 'C')
		return (1);
	puts("ici");
	return (0);
}