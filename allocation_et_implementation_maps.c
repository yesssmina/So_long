/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_et_implementation_maps.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/19 15:39:29 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//calcul dimension map fichier pour allocation et imple' map 
void	cacul_nb_lignes_et_colones(t_map *dimension)
{
	int fd0;
	int c;
	
	dimension->nb_colones = 0;
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
	dimension->nb_colones++;
	close(fd0);
}

// Alloue la map
char **allocation_map(int nb_ligne, int nb_colonne) 
{
    int	i;
	int	j;
	
	i = 0;
    char **map = malloc(sizeof(char *) * (nb_ligne + 1));
    if (!map)
        return (NULL);

    while (i < nb_ligne) 
	{
        map[i] = malloc(sizeof(char) * (nb_colonne + 1));
        if (!map[i]) 
		{
            j = 0;
            while (j < i) 
			{
                free(map[j]);
                j++;
            }
            free(map);
            return (NULL);
        }
        i++;
    }
    return (map);
}


//implementation map et map_copie
void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	i;
	char *line;

	i = 0;
	line = NULL;
	if (!(map->map = allocation_map(map->nb_lignes, map->nb_colones)))
		return ;
	if (!(map->copie = allocation_map(map->nb_lignes, map->nb_colones)))
        return;
	while ((line = get_next_line(fd)) != NULL)
	{
		map->map[i] = line;
		if (!map->map[i])
			break;
		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
			map->map[i][ft_strlen(map->map[i]) - 1] = '\0';
		ft_strlcpy(map->copie[i], map->map[i], ft_strlen(map->map[i]) + 1);
		if (!map->copie[i])
			break;
		printf("%s\n", map->map[i]);
		i++;
	}
	map->map[i] = NULL;
	map->copie[i] = NULL;
	puts("");
}
