/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/14 20:33:30 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

void	cacul_nb_lignes_et_colones(t_map *dimension)
{
	int fd0;
	int c;
	
	fd0 = open(dimension->chemin_vers_fichier, O_RDONLY);
	if (fd0 == -1)
		return ;
	
	while(read(fd0, &c, 1) == 1)
	{
		if (c == '\n')
		{
			dimension->nb_lignes++;
			dimension->nb_colones = 0;
		}
		else
			dimension->nb_colones++;
	}
	dimension->nb_lignes++;
	printf("lignes::%d\n", dimension->nb_lignes);
	printf("colones::%d\n", dimension->nb_colones);
	close(fd0);
}

void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	i;
	char *line;

	i = 0;
	line = NULL;
	if (!(map->map = map->copie = allocation_map(map->nb_lignes, map->nb_colones)))
		return ;
	while ((line = get_next_line(fd)) != NULL)
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
	int		fd;
	int		i;
	t_point size;
	t_point	cur;
	t_data	data;
	
	i = 0;

	map.chemin_vers_fichier = "./maps/big_map28_62.ber";
	ft_init(&data);

	cacul_nb_lignes_et_colones(&map);
	printf("lignes::%d\n", map.nb_lignes);
	printf("colones::%d\n", map.nb_colones);
	fd = open(map.chemin_vers_fichier, O_RDONLY);
	if (fd == -1)
		return (0);
	ft_map_et_map_copie(&map, fd);
	puts("\n");
	data.nb_player = 0;
	data.nb_exit = 0;
	size.x = ft_strlen(map.map[0]);
	size.y = map.nb_lignes + 1;
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

//  A faire
// optimisation main ++
// gerer ft_error



//char	error_mess(char	*message)
//{
//	perror(message);
//	exit(EXIT_FAILURE);
//}