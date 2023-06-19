/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanaggar <sanaggar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 14:18:43 by sanaggar          #+#    #+#             */
/*   Updated: 2023/06/08 17:17:04 by sanaggar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./GNL/get_next_line.h"
# include "./GNL/get_next_line_bonus.h"
# include "./Libft/libft.h"
# include "./Printf/ft_printf.h"
# include <stdio.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>
#include <unistd.h>
#include <mlx.h>

typedef struct	s_data_mlx
{
	char	*path;
	char	*path_wall;
	char	*path_collectible;
	char	*path_player;
	int		img_width;
	int		img_height;
	int		wall_width;
	int		wall_height;
	void	*img;
	void	*wall;
	void	*collectible;
	void	*player;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data_mlx;

typedef struct	s_vars_mlx 
{
	void	*mlx;
	void	*win;
}				t_vars_mlx;


typedef struct	s_data
{
	int	nb_collectible;
	int	nb_exit;
	int	nb_player;
	int check_nb_collectible;
	int	coor_player_x;
	int	coor_player_y;
}				t_data;

typedef struct 	s_point 
{
    int 		x;
    int 		y;
} 				t_point;

typedef struct 		s_map	
{
	char	**map;
	char	**copie;
	int		nb_colones;
	int		nb_lignes;
	char	*chemin_vers_fichier;
}					t_map;

int		check_size(t_map *data, char **map, t_point *point);
int		check_wall(char **map, t_point	*pos);
void	check_way(char **map, t_point size, t_point cur, t_data *data);
int		check_map(char **map, t_data *data, t_point *point);
int		check_check_way(char **map, t_point	size, t_point cur, t_data *data);
int		check_check_map(char **map, t_data *data, t_point *point);
int		check_parsing(t_map *map, t_data *data, t_point size, t_point cur);
char	 **allocation_map(int nb_ligne, int nb_colonne);
int		egal_ECP1or0(char **map, int y, int x, t_data *data);
void	ft_map_et_map_copie(t_map *map, int fd);
void	cacul_nb_lignes_et_colones(t_map	*dimension);
void 	ft_init(t_data *data);
void	ft_init1(t_map *map, t_data *data, t_point *cur, t_point *size);
char	*error_mess(char	*message);
int		check_ber(char *fichier);
void 	check_parsing_final(char *chemin_fichier, t_map *map);
void	do_mlx(t_data_mlx *img, t_vars_mlx *vars, t_map *map);
void	superpose_image(void *mlx, void *background_img, void *sur_img, int x, int y);
void	ft_init_img(t_data_mlx	*img);
void ft_putchar(char c);
int	deal_key(int key, void *param);
void	ft_mlx_pixel_put(t_data_mlx *img, int x, int y, int color);
int	ft_close(int keycode, t_vars_mlx *vars);
void	put_texture(void *mlx, t_map *map, t_data_mlx *img, t_vars_mlx *vars);