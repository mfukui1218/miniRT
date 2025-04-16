/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:06:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:51:28 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx-linux/mlx.h"
# include "vector.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct s_camera		t_camera;
typedef struct s_light		t_light;
typedef struct s_object		t_object;
typedef struct s_scene		t_scene;
typedef struct s_ambient	t_ambient;

typedef struct s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_color;

typedef struct rt
{
	void		*mlx;
	void		*win;
	char		**rt;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_object	*object;
}	t_rt;

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	double		fov;
}	t_camera;

typedef struct s_ambient
{
	double		brightness;
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	t_vector	position;
	double		brightness;
	t_color		color;
}	t_light;

typedef struct s_object
{
	int			type;
	t_vector	position;
	t_vector	orientation;
	t_color		color;
	double		radius;
	double		height;
}	t_object;

typedef enum error
{
	ALLOCATE = 1,
	OPEN,
	COORDINATE_RT,
	COORDINATE_RANGE,
	BRIGHTNESS_RT,
	BRIGHTNESS_RANGE,
	COLOR_RT,
	COLOR_RANGE,
	FOV_RT,
	FOV_RANGE,
	VECTOR_RT,
	VECTOR_RANGE,
	RADIUS_RT,
	RADIUS_RANGE,
	CYLINDER_RT,
	CYLINDER_RANGE,
	AMBIENT_RT,
	AMBIENT_RANGE,
}	t_error;

#define MAX_TXT_HEIGHT 200

void	init_rt(t_rt *rt);
void	init_camera(t_camera *camera);
void	init_ambient(t_ambient *ambient);
void	init_light(t_light *light);
void	init_object(t_object *object);
void	init_vector(t_vector *vector);
void	init_color(t_color *color);

//set
bool	parse_rt(t_rt *rt, char *file_name);
bool	parse_txt(t_rt *rt, char *file_name);
bool	parse_camera(t_rt *rt, char *line);
bool	parse_ambient(t_rt *rt, char *line);
bool	parse_light(t_rt *rt, char *line);
bool	parse_object(t_rt *rt, char *line);
bool	parse_color(t_rt *rt, char *line, size_t *j);


//error
void	error_message(int error);

//utils
size_t	skip_space(char *str);
void	inclement_ij(size_t *i, size_t *j);
bool	is_start_str(char *str, char *start);
float	ft_atof(char *str);
int		has_one_info(char **rt, char *str);
int		has_object_info(char **rt);
size_t	find_line_str(char **rt, char *start);

//condition
bool	is_valid_condition(char **rt);
bool	parse_and_check(char *str, size_t *j, bool (*check)(char *, size_t *));
bool	is_valid_camera(char **rt);
bool	is_valid_ambient(char **rt);
bool	is_valid_light(char **rt);
bool	is_valid_object(char **rt);
bool	is_valid_coordinate(char *str, size_t *j);
bool	is_valid_brightness(char *str, size_t *j);
bool	is_valid_color(char *str, size_t *j);
bool	is_valid_fov(char *str, size_t *j);
bool	is_valid_vector(char *str, size_t *j);
bool	is_valid_sphere(char *str);
bool	is_valid_plane(char *str);
bool	is_valid_cylinder(char *str);

bool	check_three_range(char *str, int min, int max);
bool	check_number_with_comma(char *str, size_t *j);
bool	check_last_number(char *str, size_t *j);



//free
void	free_rt(t_rt *rt);
void	free_camera(t_camera *camera);
void	free_ambient(t_ambient *ambient);
void	free_light(t_light *light);
void	free_object(t_object *object);
void	free_vector(t_vector *vector);
void	free_color(t_color *color);
void	free_split(char **split);

void line(void);

#endif