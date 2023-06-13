/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/14 01:34:36 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	i;
	char *line;

	i = 0;
	line = NULL;
	map->map = allocation_map(28, 62);
	if (!map->map)
		return ;
	map->copie = allocation_map(28, 62);
	if (!map->copie)
		return ;
	while ((line = get_next_line(fd)) > 0)
	{
		map->map[i] = line;
		if (!map->map[i])
			break;
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
			map->map[i][ft_strlen(map->map[i]) - 1] = '\0';
		map->copie[i] = ft_strdup(map->map[i]);
		if (!map->copie[i])
			break;
		printf("%s\n", map->map[i]);
		//printf("%s\n\n", map->copie[i]);
		i++;
	}
	map->map[i] = NULL;
	map->copie[i] = NULL;
}

int	main()
{
	t_map	map;
	//char	**map;
	int		fd;
	int		i;
	int		max_ligne = 29;
	t_point size;
	t_point	cur;
	t_data	data;
	
	i = 0;
	fd = open("./maps/big_map28_62.ber", O_RDONLY);
	if (fd == -1)
		return (0);
	ft_map_et_map_copie(&map, fd);
	puts("\n");
	data.nb_player = 0;
	data.nb_exit = 0;
	size.x = ft_strlen(map.map[0]);
	size.y = max_ligne;
	cur.x = data.coor_player_x;
    cur.y = data.coor_player_y;
	if (check_parsing(map, &data, size, cur) == 1)
	{
		printf("x%dy%d", data.coor_player_x, data.coor_player_y);
		puts("oui");
		return (1);
	}
	close(fd);
	
	puts("non final");
	return (0);
}

//char	error_mess(char	*message)
//{
//	perror(message);
//	exit(EXIT_FAILURE);
//}