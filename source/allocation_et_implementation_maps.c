/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_et_implementation_maps.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/04 22:34:49 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_map(t_map *map)
{
	map->nb_lignes = 0;
	map->nb_colones = 0;
	map->nb_colonnes_temp = 0;
	map->nouvelle_ligne = 1;
	map->fd0 = open(map->chemin_vers_fichier, O_RDONLY);
	if (map->fd0 == -1)
		return ;
}

//calcul map map fichier pour allocation et imple' map
void	cacul_nb_lignes_et_colones(t_map *map)
{
	ft_init_map(map);
	while (read(map->fd0, &map->c, 1) == 1)
	{
		if (map->c == '\n')
		{
			if (map->nouvelle_ligne)
			{
				map->nb_lignes++;
				map->nouvelle_ligne = 0;
			}
			if (map->nb_colonnes_temp > 0)
				map->nb_colones = map->nb_colonnes_temp;
			map->nb_colonnes_temp = 0;
		}
		else
		{
			map->nb_colonnes_temp++;
			map->nouvelle_ligne = 1;
		}
	}
	if (map->nouvelle_ligne)
		map->nb_lignes++;
	if (map->nb_colonnes_temp > 0)
		map->nb_colones = map->nb_colonnes_temp;
	close(map->fd0);
}

void	protection(char **map)
{
	if (!map)
	{
		free(map);
		error_mess("Error\nErreur d'allocation\n");
	}
}

void	protection_line(char *line, t_map *map)
{
	if (!line)
	{
		free(map->copie);
		error_mess("Error\nErreur d'allocation\n");
	}
}

//Allocation and implementation maps
void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	j;

	j = -1;
	map->map = malloc(sizeof(char *) * (map->nb_lignes + 1));
	protection(map->map);
	map->copie = malloc(sizeof(char *) * (map->nb_lignes + 1));
	protection(map->copie);
	map->map[map->nb_lignes] = NULL;
	map->copie[map->nb_lignes] = NULL;
	while (j++ <= map->nb_lignes)
	{
		map->map[j] = get_next_line(fd);
		if (!map->map[j])
			return ;
		if (map->map[j][ft_strlen(map->map[j]) - 1] == '\n')
			map->map[j][ft_strlen(map->map[j]) - 1] = '\0';
		map->copie[j] = malloc(sizeof(char) * (ft_strlen(map->map[j]) + 1));
		protection_line(map->copie[j], map);
		ft_strlcpy(map->copie[j], map->map[j], ft_strlen(map->map[j]) + 1);
	}
}
