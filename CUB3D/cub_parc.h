/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_parc.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadlane <afadlane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 08:48:36 by mmajdoub          #+#    #+#             */
/*   Updated: 2023/08/10 17:36:19 by afadlane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_PARC_H
# define CUB_PARC_H

# define SIZE 80
# define LENGH_WALL 50000
# define ROTATION 3
# define WALL_DISTANCE 30
# define SPEED 5
# define WINDOW 800

# include "getnextline/get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tex
{
	void			*img_ptr;
	char			*imge_data;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				width;
	int				height;
}					t_tex;

typedef struct s_parc
{
	int				f;
	int				c;
	char			**map;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			player;
	int				x;
	int				y;

}					t_parc;

typedef struct s_img
{
	char			dir;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				heigth;
	char			*addr;
	void			*ptr;
	struct s_img	*next;
}					t_img;

typedef struct test
{
	int				xi;
	double			v_ray;
	double			h_ray;
	double			k;
	float			x;
	float			y;
	float			teta;
	int				m_r;
	int				m_l;
	int				m_u;
	int				m_d;
	int				rot_rhit;
	int				rot_left;
	void			*mlx;
	void			*win;
	t_img			*img;
	char			**map;
	int				win_w;
	int				win_h;
	double			angle;
	double			dx;
	double			dy;
	double			inter_y;
	double			inter_x;
	double			inter_v_y;
	double			inter_v_x;
	double			ray;
	int				floor;
	int				sky;
	t_parc			*prc;
	t_tex			ptr[4];
}					t_test;

typedef struct ray
{
	double			x;
	double			y;
	double			dir;
	double			length_ray;
	double			dx;
	double			dy;
}					t_ray;

//raycasting
void				texture(t_test *test, t_ray ray, double wall, double floor);
void				render_map(t_test *test);
void				move_up(t_test *test);
void				move_left(t_test *test);
void				move_right(t_test *test);
void				move_down(t_test *test);
int					my_strlen(char *s);
int					ft_exit(void);
int					bosol(int c);
void				get_position(t_test *t);
void				player_direction(t_parc *m, t_test *test);
void				init_var(t_test *test, t_parc *m);
void				player_direction(t_parc *m, t_test *object);
void				__main__(t_test *test);
int					get_lenght(char **map);
t_ray				intresection_vertical(t_test *t, double angle);
t_ray				intresection_horizontal(t_test *t, double angle);
int					check_wall(int x, int y, t_test *t);
void				my_mlx_put(t_img *img, int x, int y, int color);
void				rotation(t_test *test);
int					motion(t_test *test);
int					presse_key(int key, t_test *test);
int					relesse_key(int key, t_test *test);
/// //////parcing
int					ft_get_color_from_img(t_test *t, int x, int y, int i);
void				ft_put_image_to_window_e(double wall, t_test *test,
						double floor, t_ray ray);
void				ft_put_image_to_window_n(double wall, t_test *test,
						double floor, t_ray ray);
void				ft_put_image_to_window_w(double wall, t_test *test,
						double floor, t_ray ray);
void				ft_put_image_to_window_s(double wall, t_test *test,
						double floor, t_ray ray);
void				img_init(t_test *ptr_win);
void				ft_check_inp(char *s);
void				ft_open_fd(char *s, int *fd);
char				*ft_read_fd(int fd);
void				ft_check_map_infd(int fd, t_parc *m);
void				ft_check_direction(char **spltmap, t_parc *m);
int					ft_check_direction_helper(char *ptr, t_parc *m);
void				ft_check_path_direction(char *ptr, int i);
void				ft_check_main_map(char **ptr, t_parc *m);
void				ft_check_main_map_helper(char **ptr, int i, t_parc *m);
void				check_first_line(char **ptr, int i);
int					check_med_map(char **ptr, int i, t_parc *m);
void				check_med_lines(char **ptr, int i);
void				check_med_wall(char **ptr, int i);
int					check_med_wall_helper(char *ptr);
int					ft_check_space_tab(char *ptr);
int					find_first_line(char *ptr);
void				check_last_line(char **ptr, int i);
void				check_isolated_zero(char **ptr, int i);
void				ft_check_newline(char *map_read);
int					find_one(char *ptr, int i);
char				**ft_check_f_c(char *ptr, int i);
int					ft_len_double_pointer(char **ptr);
void				ft_check_f_c_helper(char **str);
void				ft_str_is_digit(char *ptr);
void				ft_check_comma(char *ptr, int i);
void				ft_stock_texture_d_in_struct(char *ptr, int i, t_parc *m);
void				ft_stock_f_c_in_struct(char c, char **str, t_parc *m);
char				**get_texture_path(char *ptr);
int					find_map(char *ptr);
int					check_and_count_player(char **ptr, int i);
void				stock_player_in_struct(char **ptr, int i, t_parc *m);
int					skep_space(char *str);
int					skep_space2(char *str, int i);
void				ft_check_number_in_f_c(char *str);

#endif