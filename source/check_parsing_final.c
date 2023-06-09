/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_parsing_final.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 21:20:34 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/01 01:33:34 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	if_parsing_ok(int fd)
{
	close(fd);
	return ;
}

void	check_parsing_final(char *chemin_fichier, t_map *map)
{
	t_point	size;
	t_point	cur;
	int		fd;
	t_data	data;

	map->chemin_vers_fichier = chemin_fichier;
	ft_init(&data);
	cacul_nb_lignes_et_colones(map);
	fd = open(map->chemin_vers_fichier, O_DIRECTORY);
	if (fd != -1)
		error_mess("Error\nLe fd n'est pas un fichier\n");
	fd = open(map->chemin_vers_fichier, O_RDONLY);
	if (fd == -1)
	{
		if (check_ber(map->chemin_vers_fichier) != 1)
			error_mess("Erreur\nLe fichier doit etre un .ber\n");
		error_mess("Erreur lors de l'ouverture du fichier\n");
	}
	ft_map_et_map_copie(map, fd);
	ft_init1(map, &data, &cur, &size);
	if (check_parsing(map, &data, size, cur) == 1)
		if_parsing_ok(fd);
	close(fd);
}
