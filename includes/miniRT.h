/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:06:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 14:58:45 by mfukui           ###   ########.fr       */
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
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

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
	float		fov;
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

typedef struct s_object
{
	int			type;
	t_vector	position;
	t_vector	orientation;
	t_color		color;
	float		radius;
	float		height;
}	t_object;

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
bool	parse_camera(t_rt *rt);
bool	parse_ambient(t_rt *rt);
bool	parse_light(t_rt *rt);
bool	parse_object(t_rt *rt);
bool	parse_and_add_object(t_rt *rt, char *line, bool (*parse_func)(t_object *, char *));
bool	parse_sphere(t_object *obj, char *line);
bool	parse_plane(t_object *obj, char *line);
bool	parse_cylinder(t_object *obj, char *line);


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
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *new);
t_list	*ft_lstlast(t_list *lst);

//condition
bool	is_valid_condition(char **rt);
bool	parse_and_check(char *str, size_t *j, bool (*check)(char *, size_t *));

bool	check_three_range(char *str, int min, int max);
bool	check_number_with_comma(char *str, size_t *j);
bool	check_last_number(char *str, size_t *j);

//parse

bool	set_coordinate(void *vec, char *str, size_t *j);
bool	set_vector(void *vec, char *str, size_t *j);
bool	set_fov(void *fov, char *str, size_t *j);
bool	skip_and_set(char *line, size_t *j, void *dst, bool (*func)(void *, char *, size_t *));
bool	set_brightness(void *brightness, char *str, size_t *j);
bool	set_color(void *color, char *str, size_t *j);
bool	set_diameter(void *object, char *str, size_t *j);
bool	set_radius(void *radius, char *str, size_t *j);
bool	set_height(void *height, char *str, size_t *j);
int 	ft_atoi_index(char *str, size_t *j);
float 	ft_atof_index(char *str, size_t *j);
bool	check_range_int(int value, int min, int max);
bool	check_range_float(float value, float min, float max);

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