/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:17:05 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_valid_condition(char **rt)
{
	if (!is_valid_camera(rt))
		return (false);
	if (!is_valid_ambient(rt))
		return (false);
	if (!is_valid_light(rt))
		return (false);
	if (!is_valid_object(rt))
		return (false);
	return (true);
}

bool	is_valid_camera(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "C") != 1)
		return (false);
	i = find_line_str(rt, "C");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_vector))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	return (true);
}

bool	is_valid_ambient(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "A") != 1)
		return (false);
	i = find_line_str(rt, "A");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_brightness))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_color))
		return (false);
	return (true);
}

bool	is_valid_light(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "L") != 1)
		return (false);
	i = find_line_str(rt, "L");
	j = skip_space(rt[i]) + 1;
	if (!parse_and_check(rt[i], &j, is_valid_coordinate))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_brightness))
		return (false);
	if (!parse_and_check(rt[i], &j, is_valid_color))
		return (false);
	return (true);
}
typedef struct s_obj_validator {
	char	*prefix;
	bool	(*validate)(char *line);
}	t_obj_validator;

bool	is_valid_object(char **rt)
{
	size_t	i;

	i = 0;
	if (!has_object_info(rt))
		return (false);
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
			return (is_valid_sphere(rt[i]));
		if (is_start_str(rt[i], "pl"))
			return (is_valid_plane(rt[i]));
		if (is_start_str(rt[i], "cy"))
			return (is_valid_cylinder(rt[i]));
		i++;
	}
	return (true);
}

bool	is_valid_coordinate(char *str, size_t *j)
{
	if (!parse_number_with_comma(str, j))
		return (error_message(COORDINATE_RT), false);
	if (!parse_number_with_comma(str, j))
		return (error_message(COORDINATE_RT), false);
	if (!parse_last_number(str, j))
		return (error_message(COORDINATE_RT), false);
	if (str[*j] && str[*j] != ' ' && str[*j] != '\t')
		return (error_message(COORDINATE_RT), false);
	if (!check_three_range(str, -1000, 1000))
		return (error_message(COORDINATE_RANGE), false);
	return (true);
}

bool	is_valid_vector(char *str, size_t *j)
{
	if (!parse_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	if (!parse_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	if (!parse_last_number(str, j))
		return (error_message(VECTOR_RT), false);
	if (!check_three_range(str, -1, 1))
		return (error_message(VECTOR_RANGE), false);
	return (true);
}

bool	is_valid_fov(char *str, size_t *j)
{
	int	start;
	int	fov;

	start = *j;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9'))
			return (error_message(FOV_RT), false);
		(*j)++;
	}
	fov = ft_atoi(&str[start]);
	if (fov < 0 || fov > 180)
		return (error_message(FOV_RANGE), false);
	return (true);
}


bool	is_valid_brightness(char *str, size_t *j)
{
	int		start;
	int		dot_flag;

	dot_flag = 0;
	start = *j;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9'))
		{
			if (str[*j] == '.' && !dot_flag)
				dot_flag = 1;
			else
				return (error_message(BRIGHTNESS_RT), false);
		}
		(*j)++;
	}
	if (*j == (size_t)start)
		return (error_message(BRIGHTNESS_RT), false);
	if (ft_atof(&str[start]) < 0.0 || ft_atof(&str[start]) > 1.0)
		return (error_message(BRIGHTNESS_RANGE), false);

	return (true);
}

bool	is_valid_color(char *str, size_t *j)
{
	if (!parse_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	if (!parse_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	if (!parse_last_number(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_three_range(str, 0, 255))
		return (error_message(COLOR_RANGE), false);
	return (true);
}


bool	is_valid_sphere(char *rt)
{
	
}

bool	is_valid_plane(char *rt)
{
	
}

bool	is_valid_cylinder(char *rt)
{
	size_t	i;

	i = 0;
	i += skip_space(rt) + 1;
	i += skip_space(rt + i);
	if (!is_valid_coordinate(rt, &i))
		return (false);
	i += skip_space(rt + i);
	if (!is_valid_vector(rt, &i))
		return (false);
	i += skip_space(rt + i);
	if (!is_valid_radius(rt, &i))
		return (false);
	i += skip_space(rt + i);
	if (!is_valid_height(rt, &i))
		return (false);
	i += skip_space(rt + i);
	if (!is_valid_color(rt, &i))
		return (false);
	if (i == 0)
		return (false);
	return (true);
}

bool	is_valid_radius(char *str, size_t *j)
{
	if (!is_valid_radius_rt(str, j))
		return (error_message(RADIUS_RT), false);
	if (!is_valid_radius_range(str))
		return (error_message(RADIUS_RANGE), false);
	return (true);
}

bool	is_valid_radius_rt(char *str, size_t *j)
{
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9') && !(str[*j] == '.'))
			return (false);
		if (str[*j] == '0')
			inclement_ij(j, (size_t *)(&order_flag));
		if (str[*j] == '.')
		{
			if (order_flag != 1)
				return (false);
			inclement_ij(j, (size_t *)(&order_flag));
		}
		if ('0' <= str[*j] && str[*j] <= '9')
		{
			if (order_flag != 2)
				return (false);
			inclement_ij(j, (size_t *)(&order_flag));
		}
	}
	if (order_flag != 3)
		return (false);
	return (true);
}

bool	is_valid_radius_range(char *str)
{
	if (0.0 <= ft_atof(str) && ft_atof(str) <= 1000.0)
		return (false);
	return (true);
}

bool	is_valid_height(char *str, size_t *j)
{
	if (!is_valid_height_rt(str, j))
		return (error_message(CYLINDER_RT), false);
	if (!is_valid_height_range(str))
		return (error_message(CYLINDER_RANGE), false);
	return (true);
}

bool	is_valid_height_rt(char *str, size_t *j)
{
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9') && !(str[*j] == '.'))
			return (false);
		if (str[*j] == '0')
			inclement_ij(j, (size_t *)(&order_flag));
		if (str[*j] == '.')
		{
			if (order_flag != 1)
				return (false);
			inclement_ij(j, (size_t *)(&order_flag));
		}
		if ('0' <= str[*j] && str[*j] <= '9')
		{
			if (order_flag != 2)
				return (false);
			inclement_ij(j, (size_t *)(&order_flag));
		}
	}
	if (order_flag != 3)
		return (false);
	return (true);
}

bool	is_valid_height_range(char *str)
{
	if (0.0 <= ft_atof(str) && ft_atof(str) <= 1000.0)
		return (false);
	return (true);
}

