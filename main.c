/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/12 20:44:09 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

//check if check_way est ok
int	check_check_way(char **map, t_point	size, t_point cur, t_data *data)
{
	data->nb_collectible = 0;
	data->nb_player = 0;
	data->nb_exit = 0;
	
	check_way(map, size, cur, data);
	printf("**col*%d\n", data->nb_collectible);
	printf("**play**%d\n", data->nb_player);
	printf("**ex**%d\n", data->nb_exit);
	if (data->nb_collectible < 1 || data->nb_exit < 1 || data->nb_player < 1)
	{	
		puts("non");
		return (0);
	}
	puts("oui");
	return (1);
}

// check si check_map est ok
int	check_check_map(char **map, t_data *dat, int nb_collectible_needed)
{
	int	res;
	
	res = check_map(map, nb_collectible_needed, dat);
	printf("collectible%d\nplayer%d\nexit%d\n", dat->nb_collectible, dat->nb_player, dat->nb_exit);
	if (res == 0 || dat->nb_collectible == 0 || dat->nb_exit != 1 || dat->nb_player != 1)
	{	
		puts("non");
		return (0);
	}
	puts("oui");
	return (1);
}

//check les fonctions de mon parsing
int	check_parsing(char **map, t_data *data, t_point size, t_point cur)
{
	int	wall;
	int csize;
	int	way;
	int	maap;

	csize = check_size(map);
	wall = check_wall(map);
	way = check_check_way(map, size, cur, data);
	maap = check_check_map(map, data, data->nb_collectible_needed);
	data->nb_collectible = 0;
	if (!csize)
	{	
		puts("la");
		return (0);
	}
	if (!wall)
	{	
		puts("la");
		return (0);
	}
	if (!way)
	{	
		puts("la");
		return (0);
	}
	if (!maap)
	{	
		puts("la");
		return (0);
	}
	return (1);
}


int	main()
{
	char	**map;
	int		fd;
	int		i;
	int		max_ligne = 11;
	t_point size;
	t_point	cur;
	t_data	data;
	
	
	i = 0;
	fd = open("./maps/small_map.ber", O_RDONLY);
	map = allocation_map(9, 16);
	if (!map)
		return (0);
	while (i < max_ligne)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break;
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		printf("%s\n", map[i]);
		i++;
	}
	map[i] = NULL;
	puts("\n");
	data.nb_player = 0;
	data.nb_exit = 0;
	data.nb_collectible_needed = 5;
	size.x = ft_strlen(map[0]);
	size.y = max_ligne;
	cur.x = 2;
    cur.y = 1;
	if (check_parsing(map, &data, size, cur) == 1)
	{
		puts("oui");
		return (1);
	}
	close(fd);
	return (0);
}

//char	error_mess(char	*message)
//{
//	perror(message);
//	exit(EXIT_FAILURE);
//}