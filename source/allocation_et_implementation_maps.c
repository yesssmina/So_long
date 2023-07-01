/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_et_implementation_maps.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/01 02:45:47 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//calcul dimension map fichier pour allocation et imple' map
void	cacul_nb_lignes_et_colones(t_map *dimension)
{
	int fd0;
    char c;
    int nb_colonnes_temp;
    int nouvelle_ligne;

    dimension->nb_lignes = 0;
    dimension->nb_colones = 0;
    nb_colonnes_temp = 0;
    nouvelle_ligne = 1;

    fd0 = open(dimension->chemin_vers_fichier, O_RDONLY);
    if (fd0 == -1)
        return;

    while (read(fd0, &c, 1) == 1)
    {
        if (c == '\n')
        {
            if (nouvelle_ligne)
            {
                dimension->nb_lignes++;
                nouvelle_ligne = 0;
            }
            if (nb_colonnes_temp > 0)
                dimension->nb_colones = nb_colonnes_temp;
            nb_colonnes_temp = 0;
        }
        else
        {
            nb_colonnes_temp++;
            nouvelle_ligne = 1;
        }
        printf("c%c\nnb_colonnes_temp%d\n", c, nb_colonnes_temp);
    }

    if (nouvelle_ligne)
        dimension->nb_lignes++;

    if (nb_colonnes_temp > 0)
        dimension->nb_colones = nb_colonnes_temp;

    close(fd0);
}

//Allocation and implementation maps
void	ft_map_et_map_copie(t_map *map, int fd)
{
	int	j;

	j = -1;
	map->map = malloc(sizeof(char *) * (map->nb_lignes + 1));
	map->copie = malloc(sizeof(char *) * (map->nb_lignes + 1));
	if (!(map->map || !(map->copie)))
		return ;
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
		if (!map->copie[j])
		{
			free(map->copie);
			return ;
		}
		ft_strlcpy(map->copie[j], map->map[j], ft_strlen(map->map[j]) + 1);
	}
}
