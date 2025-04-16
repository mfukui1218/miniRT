/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:06:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 13:51:45 by mfukui           ###   ########.fr       */
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
}	t_error;

#define MAX_TXT_HEIGHT 200

void	init_rt(t_rt *rt);
void	init_camera(t_camera *camera);
void	init_light(t_light *light);
void	init_object(t_object *object);
void	init_vector(t_vector *vector);
void	init_color(t_color *color);

//set
bool	set_rt(t_rt *rt, char *file_name);
bool	set_txt(t_rt *rt, char *file_name);
bool	set_camera(t_rt *rt, char *line);

//error
void	error_message(int error);

//utils
size_t	skip_space(char *str);

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