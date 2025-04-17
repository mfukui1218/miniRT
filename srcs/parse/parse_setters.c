#include "miniRT.h"

bool	set_coordinate(t_vector *vec, char *str, size_t *i)
{
	size_t	j;

	j = *i;
	if (!check_number_with_comma(str, &j))
		return (error_message(COORDINATE_RT), false);
	vec->x = ft_atoi_index(str, i);
	if (!check_number_with_comma(str, &j))
		return (error_message(COORDINATE_RT), false);
	vec->y = ft_atoi_index(str, i);
	if (!check_last_number(str, &j))
		return (error_message(COORDINATE_RT), false);
	vec->z = ft_atoi_index(str, i);
	if (str[j] && str[j] != ' ' && str[j] != '\t')
		return (error_message(COORDINATE_RT), false);
	if (!check_range_int(vec->x, -1000, 1000)
		|| !check_range_int(vec->y, -1000, 1000)
		|| !check_range_int(vec->z, -1000, 1000))
		return (error_message(COORDINATE_RANGE), false);
	*i = j;
	return (true);
}

bool	set_vector(t_vector *vec, char *str, size_t *i)
{
	size_t	j;

	j = *i;
	if (!check_number_with_comma(str, &j))
		return (error_message(VECTOR_RT), false);
	vec->x = ft_atof_index(str, i);
	if (!check_number_with_comma(str, &j))
		return (error_message(VECTOR_RT), false);
	vec->y = ft_atof_index(str, i);
	if (!check_last_number(str, &j))
		return (error_message(VECTOR_RT), false);
	vec->z = ft_atof_index(str, i);
	if (str[j] && str[j] != ' ' && str[j] != '\t')
		return (error_message(VECTOR_RT), false);
	if (!check_range_float(vec->x, -1.0f, 1.0f)
		|| !check_range_float(vec->y, -1.0f, 1.0f)
		|| !check_range_float(vec->z, -1.0f, 1.0f))
		return (error_message(VECTOR_RANGE), false);
	*i = j;
	return (true);
}

bool	set_fov(int *fov, char *str, size_t *i)
{
	size_t	j;

	j = *i;
	while (str[j] && str[j] != ' ' && str[j] != '\t')
	{
		if (!('0' <= str[j] && str[j] <= '9'))
			return (error_message(FOV_RT), false);
		j++;
	}
	*fov = ft_atoi_index(str, i);
	if (*fov < 0 || *fov > 180)
		return (error_message(FOV_RANGE), false);
	*i = j;
	return (true);
}


bool	set_color(t_color *color, char *str, size_t *i)
{
	size_t	j;

	j = *i;
	if (!check_number_with_comma(str, &j))
		return (error_message(COLOR_RT), false);
	color->r = ft_atoi_index(str, i);
	if (!check_number_with_comma(str, &j))
		return (error_message(COLOR_RT), false);
	color->g = ft_atoi_index(str, i);
	if (!check_last_number(str, &j))
		return (error_message(COLOR_RT), false);
	color->b = ft_atoi_index(str, i);
	if (str[j] && str[j] != ' ' && str[j] != '\t')
		return (error_message(COLOR_RT), false);
	if (!check_range_int(color->r, 0, 255)
		|| !check_range_int(color->g, 0, 255)
		|| !check_range_int(color->b, 0, 255))
		return (error_message(COLOR_RANGE), false);
	*i = j;
	return (true);
}

bool	set_brightness(float *brightness, char *str, size_t *i)
{
    size_t	j;

    j = *i;
    while (str[j] && str[j] != ' ' && str[j] != '\t')
    {
        if (!('0' <= str[j] && str[j] <= '9'))
            return (error_message(BRIGHTNESS_RT), false);
        j++;
    }
    *brightness = ft_atof_index(str, i);
    if (*brightness < 0.0f || *brightness > 1.0f)
        return (error_message(BRIGHTNESS_RANGE), false);
    *i = j;
    return (true);
}

bool	set_radius(float *radius, char *str, size_t *i)
{
    size_t	j;

    j = *i;
    while (str[j] && str[j] != ' ' && str[j] != '\t')
    {
        if (!('0' <= str[j] && str[j] <= '9'))
            return (error_message(RADIUS_RT), false);
        j++;
    }
    *radius = ft_atof_index(str, i);
    if (*radius < 0.0f)
        return (error_message(RADIUS_RANGE), false);
    *i = j;
    return (true);
}

bool	set_height(float *height, char *str, size_t *i)
{
    size_t	j;

    j = *i;
    while (str[j] && str[j] != ' ' && str[j] != '\t')
    {
        if (!('0' <= str[j] && str[j] <= '9'))
            return (error_message(CYLINDER_RT), false);
        j++;
    }
    *height = ft_atof_index(str, i);
    if (*height < 0.0f)
        return (error_message(CYLINDER_RANGE), false);
    *i = j;
    return (true);
}

bool	set_diameter(t_object *object, char *str, size_t *i)
{
    size_t	j;

    j = *i;
    if (!check_number_with_comma(str, &j))
        return (error_message(RADIUS_RT), false);
    object->radius = ft_atof_index(str, i);
    if (object->radius < 0)
        return (error_message(RADIUS_RANGE), false);
    if (str[j] && str[j] != ' ' && str[j] != '\t')
        return (error_message(RADIUS_RT), false);
    *i = j;
    return (true);
}

