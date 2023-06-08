/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:12:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/08 19:41:51 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_size(char	**map)
{
	int		i;
	size_t	len_line;
	t_pos	pos;
	
	i = 0;
	len_line = 0;
	pos.x = 0;
	pos.y = 0;
	
	while (map[0][len_line])
		len_line++;

	while (map[pos.y][pos.x])
	{
		while (map[pos.y][pos.x])
			pos.x++;
		if (pos.x != i)
			return (0);
		pos.x = 0;
		pos.y++;
	}
	return (1);
}

int	chek_wall(char **map)
{
	t_pos	pos;
	
	pos.x = 0;
	pos.y = 0;
	while (map[0][pos.x])
	{
		if (map[0][pos.x] != 1)
			return (0);
		pos.x++;
	}

	while (map[pos.y])
	{
		if (map[pos.y][0] != 1 || map[pos.y][pos.x - 1] != 1)
			return (0);
		pos.y++;
	}
	
	pos.x = 0;
	while (map[pos.y - 1][pos.x])
	{
		if (map[pos.y - 1][pos.x] != 1)
			return (0);
		pos.x++;
	}	
	return (1);
}

void	check_way(char **map, t_point size, t_point cur)
{
	int	nb_collectible;
	int	nb_exit;

	//nb_collectible = 0;
	//nb_exit = 0;
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
	|| map[cur.y][cur.x] == 1)
		return ;
		
	if (map[cur.y][cur.x] == 'C')
		nb_collectible++;
	if (map[cur.y][cur.x] == 'E')
		nb_exit++;
	if (nb_exit < 1)
		return ;
	// checker a l'exterieur si nb collectible correct
	
//if (tab[cur.y][cur.x] != 1)
	check_way(map, size, (t_point){cur.x - 1, cur.y}, c);
	check_way(map, size, (t_point){cur.x + 1, cur.y}, c);
	check_way(map, size, (t_point){cur.x, cur.y - 1}, c);
	check_way(map, size, (t_point){cur.x, cur.y + 1}, c);
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