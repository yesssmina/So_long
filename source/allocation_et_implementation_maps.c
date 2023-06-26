/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_et_implementation_maps.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/25 23:29:41 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//calcul dimension map fichier pour allocation et imple' map 
void	cacul_nb_lignes_et_colones(t_map *dimension)
{
	int fd0;
	char c;
	
	dimension->nb_lignes = 0;
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
	//printf("nb_colonnes%d, nb_lignes%d\n", dimension->nb_colones, dimension->nb_lignes);
	close(fd0);
}

// Alloue la map
//char **allocation_map(int nb_ligne, int nb_colonne) 
//{
//    int	i;
//	//int	j;
	
//	i = 0;
//	(void)nb_colonne;
	
//    char **map = malloc(sizeof(char *) * (nb_ligne + 1));
//    if (!map)
//        return (NULL);
//	map[nb_ligne] = NULL;
//    /*while (i < nb_ligne) 
//	{
//        map[i] = malloc(sizeof(char) * (nb_colonne + 1));
//        if (!map[i]) 
//		{
//            j = 0;
//            while (j < i) 
//			{
//                free(map[j]);
//                j++;
//            }
//            free(map);
//            return (NULL);
//        }
//        i++;
//    }*/
//    return (map);
//}


////implementation map et map_copie
//void	ft_map_et_map_copie(t_map *map, int fd)
//{
//	int	i;
//	int j;
//	char *line;

//	i = 0;
//	j = 0;
//	line = NULL;
//	if (!(map->map = allocation_map(map->nb_lignes, map->nb_colones)))
//		return ;
//	if (!(map->copie = allocation_map(map->nb_lignes, map->nb_colones)))
//        return ;
//	while (j <= map->nb_lignes)
//	{
//		map->map[j] = get_next_line(fd);
//		j++;
//	}
//	/*while ((line = get_next_line(fd)) != NULL)
//	{
//		map->map[i] = line;
//		if (!map->map[i])
//			break;
//		if (map->map[i][ft_strlen(map->map[i]) - 1] == '\n')
//			map->map[i][ft_strlen(map->map[i]) - 1] = '\0';
//		ft_strlcpy(map->copie[i], map->map[i], ft_strlen(map->map[i]) + 1);
//		if (!map->copie[i])
//			break;
//		printf("%s\n", map->map[i]);
//		i++;
//	}*/

//	map->map[j] = NULL;
//	map->copie[i] = NULL;
//	i = 0;
//	j = 0;
//	//write(1, "bonjour", 7);
//	//while (1);
//	puts("");
//}

//fusionner allocation et map;
void	ft_map_et_map_copie(t_map *map, int fd)
{
	int j;

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