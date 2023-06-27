/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_et_implementation_maps.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/28 00:51:12 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//calcul dimension map fichier pour allocation et imple' map 
void	cacul_nb_lignes_et_colones(t_map *dimension)
{
	int		fd0;
	char	c;

	dimension->nb_lignes = 0;
	dimension->nb_colones = 0;
	fd0 = open(dimension->chemin_vers_fichier, O_RDONLY);
	if (fd0 == -1)
		return ;
	while (read(fd0, &c, 1) == 1)
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
	close(fd0);
}

//Allocation et implementaton maps
void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	j;

	j = 0;
	if (!(map->map = malloc(sizeof(char *) * (map->nb_lignes + 1))))
		return ;
	map->map[map->nb_lignes] = NULL;
	if (!(map->copie = malloc(sizeof(char *) * (map->nb_lignes + 1))))
		return ;
	map->copie[map->nb_lignes] = NULL;
	while (j <= map->nb_lignes)
	{
		map->map[j] = get_next_line(fd);
		if (!map->map[j])
			return ;
		if (map->map[j][ft_strlen(map->map[j]) - 1] == '\n')
			map->map[j][ft_strlen(map->map[j]) - 1] = '\0';
		map->copie[j] = malloc(sizeof(char) * (ft_strlen(map->map[j]) + 1));
		if (!map->copie[j])
		{
			free(map->copie);
			return ;
		}
		ft_strlcpy(map->copie[j], map->map[j], ft_strlen(map->map[j]) + 1);
		j++;
	}
}
