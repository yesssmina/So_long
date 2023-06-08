/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/08 19:32:53 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./GNL/get_next_line.h"

int	main()
{
	char	**map;
	//char	*line;
	int		fd;
	int		i;
	
	i = 0;
	fd = open("./maps/small_map.ber", O_RDONLY);
	map = malloc(sizeof(char *) * 10);
	if (!map)
		return (0);
	map[i] = get_next_line(fd);
	i++;
	while (map[i])
	{
		map[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	
	if (check_size(map) == 1)
		return (1);
	return (0);
}