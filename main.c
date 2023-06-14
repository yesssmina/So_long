/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/15 01:36:44 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

int	main(int argc, char	**argv)
{
	t_map	map;
	t_point size;
	t_point	cur;
	int		fd;
	t_data	data;
	
	if (argc != 2)
		error_mess("Erreur: Mets la map voulue en 2e argument!\n");
	map.chemin_vers_fichier = argv[1];
	ft_init(&data);

	cacul_nb_lignes_et_colones(&map);
	fd = open(map.chemin_vers_fichier, O_RDONLY);
	if (fd == -1)
		error_mess("Erreur lors de l'ouverture du fichier");
	ft_map_et_map_copie(&map, fd);
	ft_init1(&map, &data, &cur, &size);
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
// gerer ft_error