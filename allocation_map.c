/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 23:31:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/13 23:31:58 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **allocation_map(int nb_ligne, int nb_colonne) 
{
    int	i;
	int	j;
	
	i = 0;
    char **map = malloc(sizeof(char *) * nb_ligne);
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
		//printf("i:%dlignes:%d\n", i, nb_ligne);
        i++;
    }
	//map[i] = malloc(sizeof(char));
	//map[i] = NULL;
    return (map);
}

