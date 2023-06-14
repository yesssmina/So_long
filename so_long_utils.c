/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 19:03:06 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/14 22:05:38 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//check if check_way est ok
int	check_check_way(char **map, t_point	size, t_point cur, t_data *data)
{
	//data->nb_collectible = 0;
	data->check_nb_collectible = 0;
	data->nb_player = 0;
	//data->nb_exit = 0;
	
	check_way(map, size, cur, data);
	printf("**col*%d\n", data->nb_collectible);
	printf("**play**%d\n", data->nb_player);
	printf("**ex**%d\n", data->nb_exit);
	printf("**checkcol*%d\n", data->check_nb_collectible);
	if (data->nb_collectible != data->check_nb_collectible || data->nb_exit < 1 || data->nb_player < 1)
	{	
		//puts("non");
		return (0);
	}
	//puts("ccwayoui");
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
	if (res == 0 || data->nb_collectible == 0 || data->nb_exit != 1 || data->nb_player != 1)
	{	
		puts("cccheck map non");
		return (0);
	}
	printf("collectible%d\nplayer%d\nexit%d\n", data->nb_collectible, data->nb_player, data->nb_exit);
	puts("ccheck map oui");
	return (1);
}

//check les fonctions de mon parsing
int	check_parsing(t_map map, t_data *data, t_point size, t_point cur)
{
	t_point	point;
	t_point	pos;
	int	i;
	
	if (!check_size(&map, map.map, &point))
	{	
		puts("non_size");
		return (0);
	}
	if (!check_wall(map.map, &pos))
	{	
		puts("non_wall");
		return (0);
	}

	i = 0;
	if (!check_check_map(map.copie, data, &point))
	{	
		puts("non_map");
		return (0);
	}
	cur.y = data->coor_player_y;
	cur.x = data->coor_player_x;
	if (!check_check_way(map.map, size, cur, data))
	{	
		puts("non_way");
		return (0);
	}
	printf("******collectible%d\nplayer%d\nexit%d*****\n", data->nb_collectible, data->nb_player, data->nb_exit);
	data->nb_collectible = 0;
	return (1);
}
