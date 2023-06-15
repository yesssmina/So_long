/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/15 02:49:37 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

int	check_ber(char *fichier)
{
	int i;

	i = ft_strlen(fichier) - 1;
	if (fichier[i] == 'r' && fichier[i - 1] == 'e' && fichier[i - 2] == 'b' && 
		fichier[i - 3] == '.' )
			return (1);
	return (0);	
}

int	main(int argc, char	**argv)
{
	t_map	map;
	t_point size;
	t_point	cur;
	int		fd;
	t_data	data;
	
	if (argc != 2)
		error_mess("Error\nMets la map choisie en 2e argument! (./map/...)\n");
	map.chemin_vers_fichier = argv[1];
	ft_init(&data);
	cacul_nb_lignes_et_colones(&map);
	
	fd = open(map.chemin_vers_fichier, O_RDONLY);
	if (fd == -1)
	{
		if (check_ber(map.chemin_vers_fichier) != 1)
			error_mess("Erreur\nLe fichier doit etre un .ber\n");
		error_mess("Erreur lors de l'ouverture du fichier\n");
	}

	ft_map_et_map_copie(&map, fd);
	ft_init1(&map, &data, &cur, &size);
	
	if (check_parsing(map, &data, size, cur) == 1)
		return (1);
		
	close(fd);
	puts("non final");
	return (0);
}

//  A faire
// gerer ft_error