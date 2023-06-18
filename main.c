/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/19 01:33:19 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_img(t_data_mlx	*img)
{
	img->path = NULL;
	img->path_wall = NULL;
	img->img_width = 0;
	img->img_height = 0;
	img->wall_width = 0;
	img->wall_height = 0;
	img->img = NULL;
	img->wall = NULL;
	img->addr = NULL;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

int	main(int argc, char	**argv)
{
	t_data_mlx	img;
	t_vars_mlx	vars;
	t_map		map;
	
	if (argc != 2)
		error_mess("Error\nMets la map choisie en 2e argument! (./map/...)\n");
	check_parsing_final(argv[1], &map);
	//printf("%s\n", map.copie[3]);
	//printf("**widh%d\nheight%d\n**", map.nb_colones, map.nb_lignes);
	ft_init_img(&img);
	do_mlx(&img, &vars, &map);
	
	return (0);
}


//Reussi a positionner de la textuire et du mur, ;plus qua ajouter collectible,
// Verifier fonction map et map copie
//faire bouger player