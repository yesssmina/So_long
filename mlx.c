/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/19 22:23:45 by sanaggar         ###   ########.fr       */
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

void	put_texture(void *mlx, t_map *map, t_data_mlx *img, t_vars_mlx *vars)
{	
	t_point	point;
	
	point.y = 0;
	point.x = 0;
	while (map->copie[point.y])
	{
		//printf("%s\n", map->copie[point.y]);
		while (map->copie[point.y][point.x])
		{
			mlx_put_image_to_window(mlx, vars->win, img->img, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == '1')
				mlx_put_image_to_window(mlx, vars->win, img->wall, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == 'C')
				mlx_put_image_to_window(mlx, vars->win, img->collectible, point.x * 50, point.y * 50);
			if (map->copie[point.y][point.x] == 'P')
				mlx_put_image_to_window(mlx, vars->win, img->player, point.x * 50, point.y * 50);
			//}//faire pitch et sortie xpm
			//if (map->copie[point.y][point.x] == 'E')
			//{
			//	mlx_put_image_to_window(mlx, vars->win, img->img, point.x * 50, point.y * 50);
			//	mlx_put_image_to_window(mlx, vars->win, img->collectible, point.x * 50, point.y * 50);
			//}
			point.x++;
		}
		point.x = 0;
		point.y++;
	}
}

void	do_mlx(t_data_mlx *img, t_vars_mlx *vars, t_map *map)
{
	void	*mlx;
	
	//ft_init_img(&img);
	img->path = "./images/texture.xpm";
	img->path_wall = "./images/wall.xpm";
	img->path_collectible = "./images/diams.xpm";
	img->path_player = "./images/pitch_right.xpm";
	img->img_width = (map->nb_colones - 1) * 50;
	img->img_height = map->nb_lignes * 50;
	img->wall_width = 0;
	img->wall_height = 0;
	
	//printf("widh%d\nheight%d\n", map->nb_colones, map->nb_lignes);
	mlx = mlx_init();

	vars->win = mlx_new_window(mlx, img->img_width, img->img_height, "mlx_42");
	
	img->img = mlx_xpm_file_to_image(mlx, img->path, &(img->wall_width), &(img->wall_height));
	img->wall = mlx_xpm_file_to_image(mlx, img->path_wall, &(img->wall_width), &(img->wall_height));
	img->collectible = mlx_xpm_file_to_image(mlx, img->path_collectible, &(img->wall_width), &(img->wall_height));
	img->player = mlx_xpm_file_to_image(mlx, img->path_player, &(img->wall_width), &(img->wall_height));
	//printf("widh%d\nheight%d\n", img->wall_width, img->wall_height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	printf("img%p", img->img);
	printf("player%p", img->player);
	
	//mlx_put_image_to_window(mlx, vars->win, img->img, 0 * 50, 0 * 50);
	//mlx_put_image_to_window(mlx, vars->win, img->wall, 1 * 50, 1 * 50);
	put_texture(mlx, map, img, vars);
	mlx_key_hook(vars->win, deal_key, (void *)0);
	
	mlx_hook(vars->win, 17, 1L<<0, ft_close, &vars);
	mlx_loop(mlx);
}
