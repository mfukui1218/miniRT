#include "miniRT.h"

bool	set_coordinate(void *vec, char *str, size_t *j)
{
	t_vector	*vec_f;

	vec_f = (t_vector *)vec;
	vec_f->x = ft_atof(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->y = ft_atof(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COORD_RT), false);
	vec_f->z = ft_atof(&str[*j]);
	if (!check_last_number(str, j))
		return (error_message(COORD_RT), false);
	if (!check_range_float(vec_f->x, -1000.0f, 1000.0f)
		|| !check_range_float(vec_f->y, -1000.0f, 1000.0f)
		|| !check_range_float(vec_f->z, -1000.0f, 1000.0f))
		return (error_message(COORD_RANGE), false);
	return (true);
}

bool	set_vector(void *vec, char *str, size_t *j)
{
	t_vector	*vec_f;

	vec_f = (t_vector *)vec;
	vec_f->x = ft_atof(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	vec_f->y = ft_atof(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	vec_f->z = ft_atof(&str[*j]);
	if (!check_last_number(str, j))
		return (error_message(VECTOR_RT), false);
	if (!check_range_float(vec_f->x, -1.0f, 1.0f)
		|| !check_range_float(vec_f->y, -1.0f, 1.0f)
		|| !check_range_float(vec_f->z, -1.0f, 1.0f))
		return (error_message(VECTOR_RANGE), false);
	return (true);
}

bool	set_fov(void *fov, char *str, size_t *j)
{
	int		*fov_f;

	fov_f = (int *)fov;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
		(*j)++;
	*fov_f = ft_atoi(&str[*j]);
	if (*fov_f < 0 || *fov_f > 180)
		return (error_message(FOV_RANGE), false);
	return (true);
}

bool	set_color(void *color, char *str, size_t *j)
{
	t_color	*color_f;

	color_f = (t_color *)color;
	color_f->r = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->g = ft_atoi(&str[*j]);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	color_f->b = ft_atoi(&str[*j]);
	if (!check_last_number(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_range_int(color_f->r, 0, 255)
		|| !check_range_int(color_f->g, 0, 255)
		|| !check_range_int(color_f->b, 0, 255))
			return (error_message(COLOR_RANGE), false);
	return (true);
}

bool	set_brightness(void *brightness, char *str, size_t *j)
{
    float	*brightness_f;

    brightness_f = (float *)brightness;
    *brightness_f = ft_atof_index(str, j);
    if (*brightness_f < 0.0f || *brightness_f > 1.0f)
        return (error_message(BRIGHTNESS_RANGE), false);
    return (true);
}

bool	set_radius(void *radius, char *str, size_t *j)
{
    float	*radius_f;

    radius_f = (float *)radius;
    *radius_f = ft_atof_index(str, j);
    if (*radius_f < 0.0f)
        return (error_message(RADIUS_RANGE), false);
    return (true);
}

bool	set_height(void *height, char *str, size_t *j)
{
	float	*height_f;

	height_f = (float *)height;
	*height_f = ft_atof_index(str, j);
	if (*height_f < 0.0f)
		return (error_message(CYLINDER_RANGE), false);
	return (true);
}

bool	set_diameter(void *diameter, char *str, size_t *j)
{
	float	*diameter_f;

	diameter_f = (float *)diameter;
	*diameter_f = ft_atof(&str[*j]);
	if (*diameter_f < 0.0f)
		return (error_message(RADIUS_RANGE), false);
	return (true);
}

