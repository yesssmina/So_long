/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 16:54:29 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/06 19:22:45 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "mlx.h"

typedef struct	s_vars 
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct	s_data 
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int	deal_key(int key, void *param)
{
	(void)param;
	(void)key;
	ft_putchar('X');
	return (0);
}

void	ft_mlx_pixel_put(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_close(int keycode, t_vars *vars)
{
	(void)keycode;
	
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int main()
{
	void	*mlx;
	void	*win;
	char	*path;
	int		img_width;
	int		img_height;
	t_data	img;
	t_vars	vars;
	
	path = "./images/imagepink.xpm";
	img_width = 500;
	img_height = 400;
	mlx = mlx_init();
	
	win = mlx_new_window(mlx, 500, 400, "mlx_42");
	
	img.img = mlx_xpm_file_to_image(mlx, path, &img_width, &img_height);
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	
	mlx_key_hook(win, deal_key, (void *)0);
	
	mlx_hook(vars.win, 2, 1L<<0, ft_close, &vars);
	mlx_loop(mlx);
}

