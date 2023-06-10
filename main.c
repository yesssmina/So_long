/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/10 23:30:55 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

int	main()
{
	char	**map;
	int		fd;
	int		i;
	int		max_ligne = 10;
	t_data	data;
	t_point size;
	t_point	cur;
	
	i = 0;
	fd = open("./maps/small_map.ber", O_RDONLY);
	map = malloc(sizeof(char *) * (max_ligne + 1));
	if (!map)
		return (0);
	while (i < max_ligne)
	{
		map[i] = get_next_line(fd);
		if (!map[i])
			break;
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		printf("%s", map[i]);
		i++;
	}
	size.x = ft_strlen(map[0]);
	size.y = max_ligne;
	cur.x = 2;
    cur.y = 1;
	puts("\n");
	data.nb_collectible = 0;
	data.nb_player = 0;
	data.nb_exit = 0;
	
	check_way(map, size, cur, &data);
	printf("**collectible%d**\n", data.nb_collectible);
	printf("**%dplayer**\n", data.nb_player);
	printf("**%dexit**\n", data.nb_exit);

	if (data.nb_collectible < 1 || data.nb_exit < 1 || data.nb_player < 1)
	{	
		puts("non");
		return (0);
	}
	else
	{	
		puts("oui");
		return (1);
	}
	close(fd);
	
	return (0);
}