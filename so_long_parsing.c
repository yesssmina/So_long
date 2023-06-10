/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/10 22:23:08 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(char	**map) //ok
{
	int		i;
	int		len_line;
	t_pos	pos;
	
	i = 0;
	len_line = ft_strlen(map[0]);
	pos.x = 0;
	pos.y = 0;
	while (map[pos.y])
	{
		pos.x = 0;
		while (map[pos.y][pos.x])
			pos.x++;
		i = ft_strlen(map[pos.y]);
		if (pos.x != len_line)
			return (0);
		pos.y++;
	}
	return (1);
}

int	check_wall(char **map) //ok
{
	t_pos	pos;
	
	pos.x = 0;
	pos.y = 0;
	while (map[0])
	{
		if (map[0][pos.x] == '\0')
			break;
		if (map[0][pos.x] != '1')
			return (0);
		pos.x++;
	}
	while (map[pos.y])
	{
		if (map[pos.y][0] != '1' || map[pos.y][pos.x - 1] != '1')
			return (0);
		pos.y++;
	}
	printf("%d", pos.x);
	pos.x = 0;
	while (map[pos.y - 1])
	{
		puts("ici");
		if (map[0][pos.x] == '\0')
			break;
		if (map[pos.y - 1][pos.x] != '1')
			return (0);
		pos.x++;
	}	
	return (1);
}

void	check_way(char **map, t_point size, t_point cur, t_data *data)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x 
		|| map[cur.y][cur.x] == 1)
		return ;
	
	if (map[cur.y][cur.x] == 'P')
		data->nb_collectible++;
	if (map[cur.y][cur.x] == 'C')
		data->nb_collectible++;
	if (map[cur.y][cur.x] == 'E')
		data->nb_exit++;
	if (data->nb_exit < 1 || data->nb_collectible < 1)
		return ;
	// checker a l'exterieur si nb collectible correct
	// garder void et checker la les donnees de ma structure pour savoir si ok
	
	if (map[cur.y][cur.x] != 1)
	{	
		check_way(map, size, (t_point){cur.x - 1, cur.y}, data);
		check_way(map, size, (t_point){cur.x + 1, cur.y}, data);
		check_way(map, size, (t_point){cur.x, cur.y - 1}, data);
		check_way(map, size, (t_point){cur.x, cur.y + 1}, data);
	}
}

int	check_map(char **map)
{
	int	nb_exit;
	int	nb_player;
	t_pos	pos;

	nb_exit = 0;
	nb_player = 0;
	while (map[pos.y])
	{
		while (map[pos.x])
		{
			if (map[pos.y][pos.x] != '1' && map[pos.y][pos.x] != 'P'
				&& map[pos.y][pos.x] != 'E' && map[pos.y][pos.x] != 'C' && 
					map[pos.y][pos.x] != '0')
						return (0);
					
			if (map[pos.y][pos.x] == 'E')
				nb_exit++;

			if (map[pos.y][pos.x] == 'P')
				nb_player++;
			
			pos.x++;
		}
		pos.x = 0;
		pos.y++;
	}
	
	if (nb_exit != 1 || nb_player != 1)
		return (0);
	return (1);
}