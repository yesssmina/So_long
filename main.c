/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:01:40 by sanaggar          #+#    #+#             */
/*   Updated: 2023/07/01 00:16:13 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_data_mlx	img;
	t_vars_mlx	vars;
	t_map		map;
	t_all		all;

	if (argc != 2)
		error_mess("Error\nMets la map choisie en 2e argument! (./map/...)\n");
	check_parsing_final(argv[1], &map);
	vars.mlx = mlx_init();
	ft_init_img(&img, &map, vars.mlx);
	vars.win = mlx_new_window(vars.mlx, img.img_width, img.img_height, 
			"It's me");
	all.v_mlx = &vars;
	all.map = &map;
	all.d_mlx = &img;
	do_mlx(&all);
	return (0);
}

//norminette ko
//check if .ber est bien un fichier