/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/18 22:29:47 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	if (key == 53)
        ft_close(key, param);
	ft_putchar('X');
    return (0);
}

void	ft_mlx_pixel_put(t_data_mlx *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(int keycode, t_vars_mlx *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

void	do_mlx(t_data_mlx *img, t_vars_mlx *vars, t_map *map)
{
	void	*mlx;

	//ft_init_img(&img);
	img->path = "./images/imagepink.xpm";
	img->path_wall = "./images/mur.xpm";
	img->img_width = map->nb_colones * 20;
	img->img_height = map->nb_lignes * 20;
	img->wall_width = 1;
	img->wall_height = 1;
	
	//printf("widh%d\nheight%d\n", map->nb_colones, map->nb_lignes);
	mlx = mlx_init();

	vars->win = mlx_new_window(mlx, img->img_width, img->img_height, "mlx_42");
	
	img->img = mlx_xpm_file_to_image(mlx, img->path, &(img->wall_width), &(img->wall_height));
	img->wall = mlx_xpm_file_to_image(mlx, img->path_wall, &(img->wall_width), &(img->wall_height));
	
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	//printf("img%p", img->img);
	
	mlx_put_image_to_window(mlx, vars->win, img->img, 0 * 20, 0 * 20);
	
	mlx_put_image_to_window(mlx, vars->win, img->wall, 1 * 20, 1 * 20);
	mlx_key_hook(vars->win, deal_key, (void *)0);
	
	mlx_hook(vars->win, 17, 1L<<0, ft_close, &vars);
	mlx_loop(mlx);
}

//verifier pourquoi les image se superpose 