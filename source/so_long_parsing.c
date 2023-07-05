/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/04 01:05:30 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// check if the map is rectangular
int	check_size(char	**map, t_point *point)
{
	int	i;

	i = 0;
	point->y = 0;
	while (map[point->y][i] != '\0' && map[point->y][i] != '\n')
		i++;
	while (map[point->y])
	{
		point->x = 0;
		while (map[point->y][point->x] != '\0' &&
			map[point->y][point->x] != '\n')
			point->x++;
		if (point->x != i)
			return (0);
		point->y++;
	}
	return (1);
}

//check if the map is well surrounded by walls
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
			break ;
		if (map[pos->y - 1][pos->x] != '1')
			return (0);
		pos->x++;
	}
	return (1);
}

//check if there is an accessible path between the P, a C and an E
void	check_way(char **map, t_point size, t_point cur, t_data *data)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| map[cur.y][cur.x] == '1')
		return ;
	if (map[cur.y][cur.x] == 'P')
		data->nb_player++;
	if (map[cur.y][cur.x] == 'C')
		data->check_nb_col++;
	if (map[cur.y][cur.x] == 'E')
		data->nb_exit++;
	map[cur.y][cur.x] = '1';
	check_way(map, size, (t_point){cur.x - 1, cur.y}, data);
	check_way(map, size, (t_point){cur.x + 1, cur.y}, data);
	check_way(map, size, (t_point){cur.x, cur.y - 1}, data);
	check_way(map, size, (t_point){cur.x, cur.y + 1}, data);
}

//check if there is the right number of P's, C's and E's and nothing else
int	check_map(char **map, t_data *data, t_point	*point)
{
	point->y = 0;
	point->x = 0;
	while (map[point->y])
	{
		while (map[point->y][point->x])
		{
			if (!egal_ecp1or0(map, point->y, point->x, data))
				return (0);
			if (map[point->y][point->x] == 'C')
				data->nb_col++;
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

//check if there is an intruder in the map
int	egal_ecp1or0(char **map, int y, int x, t_data *data)
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
	return (0);
}
