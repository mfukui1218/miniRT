/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:06:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/20 01:38:19 by tookuyam         ###   ########.fr       */
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

typedef void 				(*t_print_func)(const void *);

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct rt
{
	void		*mlx;
	void		*win;
	char		**rt;
	t_camera	*camera;
	t_ambient	*ambient;
	t_light		*light;
	t_list		*object;
}	t_rt;

typedef struct s_camera
{
	t_vector	position;
	t_vector	orientation;
	int			fov;
}	t_camera;

typedef struct s_ambient
{
	float		brightness;
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	t_vector	position;
	float		brightness;
	t_color		color;
}	t_light;

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
}	t_object_type;

typedef struct s_object
{
	t_object_type	type;
	void			*object;
	t_color			color;
}	t_object;

typedef struct s_sphere
{
	t_vector	position;
	float		radius;
}	t_sphere;

typedef struct s_plane
{
	t_vector	position;
	t_vector	orientation;
}	t_plane;

typedef struct s_cylinder
{
	t_vector	position;
	t_vector	orientation;
	float		radius;
	float		height;
}	t_cylinder;

typedef enum error
{
	MLX = 1,
	WIN,
	ALLOCATE,
	OPEN,
	CAMERA,
	AMBIENT,
	LIGHT,
	OBJECT,
	COORD_RT,
	COORD_RANGE,
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

# define MAX_TXT_HEIGHT	200
# define SCREEN_HEIGHT	800
# define SCREEN_WIDTH	1000
# define RED			"\e[31m"
# define GREEN			"\e[32m"
# define YELLOW			"\e[33m"
# define BLUE			"\e[34m"
# define CLC			"\e[0m"
# define FMT_24COLOR	"\e[38;2;%d;%d;%dm"
# define INDENT_SIZE	4
# define ADD_INDENT		1
# define SUB_INDENT		-1
# define PRINT_INDENT	0

void	init_rt(t_rt *rt);
void	init_camera(t_camera *camera);
void	init_ambient(t_ambient *ambient);
void	init_light(t_light *light);
void	init_object(t_object *object);
void	init_vector(t_vector *vector);
void	init_color(t_color *color);
void	init_sphere(t_sphere *sphere);
void	init_plane(t_plane *plane);
void	init_cylinder(t_cylinder *cylinder);

//set
bool	parse_rt(t_rt *rt, char *file_name);
bool	parse_txt(t_rt *rt, char *file_name);
bool	parse_camera(t_rt *rt);
bool	parse_ambient(t_rt *rt);
bool	parse_light(t_rt *rt);
bool	parse_object(t_rt *rt);
bool	parse_sphere(t_object *obj, char *line);
bool	parse_plane(t_object *obj, char *line);
bool	parse_cylinder(t_object *obj, char *line);

//error
void	error_message(int error);
bool	error_ambient(int error);
bool	error_brightness(int error);
bool	error_color(int error);
bool	error_coordinate(int error);
bool	error_cylinder(int error);
bool	error_radius(int error);
bool	error_vector(int error);
bool	error_fov(int error);
bool	error_message_common(int error);
bool	error_message_parse(int error);
bool	error_message_value(int error);

//utils
size_t	skip_space(char *str);
void	inclement_ij(size_t *i, size_t *j);
bool	is_start_str(char *str, char *start);
float	ft_atof_index_dev(char *str, size_t *j, bool dev);
size_t	find_line_str(char **rt, char *start);

//condition
bool	is_valid_condition(char **rt);
bool	check_number_with_comma(char *str, size_t *j);
bool	check_last_number(char *str, size_t *j);

//parse

bool	set_coordinate(void *vec, char *str, size_t *j);
bool	set_vector(void *vec, char *str, size_t *j);
bool	set_fov(void *fov, char *str, size_t *j);
bool	skip_and_set(char *line, size_t *j, void *dst,
			bool (*func)(void *, char *, size_t *));
bool	set_brightness(void *brightness, char *str, size_t *j);
bool	set_color(void *color, char *str, size_t *j);
bool	set_diameter(void *object, char *str, size_t *j);
bool	set_radius(void *radius, char *str, size_t *j);
bool	set_height(void *height, char *str, size_t *j);
int		ft_atoi_index(char *str, size_t *j);
bool	check_range_int(int value, int min, int max);
bool	check_range_float(float value, float min, float max);

//free
void	free_rt(t_rt *rt);
void	free_txt(char **rt);
void	free_camera(t_camera *camera);
void	free_ambient(t_ambient *ambient);
void	free_light(t_light *light);
void	free_object(void *object);
void	free_object_list(t_list **obj);
void	free_vector(t_vector *vector);
void	free_color(t_color *color);
void	free_split(char **split);

void line(void);

//printer
void	rt_print_ambient(const t_ambient *ambient);
void	rt_print_camera(const t_camera *camera);
void	rt_print_color(const t_color *color);
void	rt_print_cylinder(const t_cylinder *cylinder);
void	rt_print_light(const t_light *light);
void	rt_print_list(const t_list *lst, void (*f)(const void *));
void	rt_print_ntp(const void **ntp, void (*f)(const void *));
void	rt_print_object_type(const t_object_type *type);
void	rt_print_object(const t_object *obj);
void	rt_print_plane(const t_plane *plane);
void	rt_print_rt(const t_rt *rt);
void	rt_print_sphere(const t_sphere *sphere);
void	rt_print_str(const char *str);
void	rt_print_vector(const t_vector *vector);
void	rt_print_indent(int indent);
void	rt_print_with_indent(t_print_func f, const void *arg);

#endif
