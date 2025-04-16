/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 13:49:27 by mfukui           ###   ########.fr       */
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
	i = 0;
	while (rt[i])
	{
		j = 0;
		if (is_start_str(rt[i], "C"))
		{
			j += skip_space(rt[i]) + 1;
			j += skip_space(rt[i] + j);
			if (!is_valid_coordinate(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_vector(rt[i], &j))
				return (printf("Error\nInvalid camera vector\n"), false);
			j += skip_space(rt[i] + j);
			if (!is_valid_fov(rt[i], &j))
				return (printf("Error\nInvalid camera fov\n"), false);
		}
		i++;
	}
	return (true);
}

bool	is_valid_coordinate(char *str, size_t *j)
{
	if (!is_valid_coordinate_rt(str, j))
		return (error_message(COORDINATE_RT), false);
	if (!is_valid_coordinate_range(str))
		return (error_message(COORDINATE_RANGE), false);
	return (true);
}

bool	is_valid_coordinate_rt(char *str, size_t *j)
{
	size_t	i;
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9') && !(str[*j] == ',') && !(str[*j] == '-'))
			return (false);
		if (str[*j] == '-')
		{
			if (!(order_flag == 0 || order_flag == 2))
				return (false);
			(*j)++;
		}
		if ('0' <= str[*j] && str[*j] <= '9')
		{
			while ('0' <= str[*j] && str[*j] <= '9')
			{
				if (!(order_flag == 0 || order_flag == 2 || order_flag == 4))
					return (false);
				(*j)++;
			}
			order_flag++;
		}
		if (str[*j] == ',')
		{
			if (order_flag == 1 || order_flag == 3)
				return (false);
			order_flag++;
			(*j)++;
		}
	}
	if (order_flag != 5)
		return (false);
	return (true);
}

bool	is_valid_coordinate_range(char *str)
{
	char	**coordinate;

	coordinate = ft_split(str, ',');
	if (!coordinate)
		return (error_message(ALLOCATE), false);
	if (-1000 <= ft_atoi(coordinate[0]) && ft_atoi(coordinate[0]) <= 1000)
		return (free_split(coordinate), false);
	if (-1000 <= ft_atoi(coordinate[1]) && ft_atoi(coordinate[1]) <= 1000)
		return (free_split(coordinate), false);
	if (-1000 <= ft_atoi(coordinate[2]) && ft_atoi(coordinate[2]) <= 1000)
		return (free_split(coordinate), false);
	free_split(coordinate);
	return (true);
}

bool	is_valid_vector(char *str, size_t *j)
{
	if (!is_valid_vector_rt(str, j))
		return (error_message(VECTOR_RT), false);
	if (!is_valid_vector_range(str))
		return (error_message(VECTOR_RANGE), false);
	return (true);
}

bool	is_valid_vector_rt(char *str, size_t *j)
{
	size_t	i;
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '1') && !(str[*j] == ',') && !(str[*j] == '-'))
			return (false);
		if (str[*j] == '-')
		{
			if (!(order_flag == 0 || order_flag == 2))
				return (false);
			(*j)++;
		}
		if ('0' <= str[*j] && str[*j] <= '1')
		{
			while ('0' <= str[*j] && str[*j] <= '1')
			{
				if (!(order_flag == 0 || order_flag == 2 || order_flag == 4))
					return (false);
				(*j)++;
			}
			order_flag++;
		}
		if (str[*j] == ',')
		{
			if (order_flag == 1 || order_flag == 3)
				return (false);
			order_flag++;
			(*j)++;
		}
	}
	if (order_flag != 5)
		return (false);
	return (true);
}

bool	is_valid_vector_range(char *str)
{
	char	**vector;

	vector = ft_split(str, ',');
	if (!vector)
		return (error_message(ALLOCATE), false);
	if (-1 <= ft_atoi(vector[0]) && ft_atoi(vector[0]) <= 1)
		return (free_split(vector), false);
	if (-1 <= ft_atoi(vector[1]) && ft_atoi(vector[1]) <= 1)
		return (free_split(vector), false);
	if (-1 <= ft_atoi(vector[2]) && ft_atoi(vector[2]) <= 1)
		return (free_split(vector), false);
	free_split(vector);
	return (true);
}

bool	is_valid_fov(char *str, size_t *j)
{
	if (!is_valid_fov_rt(str, j))
		return (error_message(FOV_RT), false);
	if (!is_valid_fov_range(str))
		return (error_message(FOV_RANGE), false);
	return (true);
}

bool	is_valid_fov_rt(char *str, size_t *j)
{
	size_t	i;

	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9'))
			return (false);
		(*j)++;
	}
	return (true);
}

bool	is_valid_fov_range(char *str)
{
	if (0 <= ft_atoi(str) && ft_atoi(str) <= 180)
		return (false);
	return (true);
}

bool	is_valid_ambient(char **rt)
{
	size_t	i;
	size_t	j;

	if (has_one_info(rt, "A") != 1)
		return (false);
	i = 0;
	while (rt[i])
	{
		j = 0;
		if (is_start_str(rt[i], "A"))
		{
			j += skip_space(rt[i]) + 1;
			j += skip_space(rt[i] + j);
			if (!is_valid_brightness(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_color(rt[i], &j))
				return (printf("Error\nInvalid ambient color\n"), false);
		}
		i++;
	}
	return (true);
}

bool	is_valid_brightness(char *str, size_t *j)
{
	if (!is_valid_brightness_rt(str, j))
		return (error_message(BRIGHTNESS_RT), false);
	if (!is_valid_brightness_range(str))
		return (error_message(BRIGHTNESS_RANGE), false);
	return (true);
}

bool	is_valid_brightness_rt(char *str, size_t *j)
{
	size_t	i;
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9') && !(str[*j] == '.'))
			return (false);
		if (str[*j] == '0')
		{
			order_flag++;
			(*j)++;
		}
		if (str[*j] == '.')
		{
			if (order_flag != 1)
				return (false);
			order_flag++;
			(*j)++;
		}
		if ('0' <= str[*j] && str[*j] <= '9')
		{
			if (order_flag != 2)
				return (false);
			order_flag++;
		}
		(*j)++;
	}
	if (order_flag != 3)
		return (false);
	return (true);
}

bool	is_valid_brightness_range(char *str)
{
	if (0 <= ft_atof(str) && ft_atof(str) <= 1)
		return (false);
	return (true);
}

bool	is_valid_color(char *str, size_t *j)
{
	if (!is_valid_color_rt(str, j))
		return (error_message(COLOR_RT), false);
	if (!is_valid_color_range(str))
		return (error_message(COLOR_RANGE), false);
	return (true);
}

bool	is_valid_color_rt(char *str, size_t *j)
{
	size_t	i;
	int		order_flag;

	order_flag = 0;
	while (str[*j] && str[*j] != ' ' && str[*j] != '\t')
	{
		if (!('0' <= str[*j] && str[*j] <= '9') && !(str[*j] == ','))
			return (false);
		if ('0' <= str[*j] && str[*j] <= '9')
		{
			while ('0' <= str[*j] && str[*j] <= '9')
			{
				if (!(order_flag == 0 || order_flag == 2 || order_flag == 4))
					return (false);
				(*j)++;
			}
			order_flag++;
		}
		if (str[*j] == ',')
		{
			if (order_flag == 1 || order_flag == 3)
				return (false);
			order_flag++;
			(*j)++;
		}
	}
	if (order_flag != 5)
		return (false);
	return (true);
}

bool	is_valid_color_range(char *str)
{
	char	**color;

	color = ft_split(str, ',');
	if (!color)
		return (error_message(ALLOCATE), false);
	if (0 <= ft_atoi(color[0]) && ft_atoi(color[0]) <= 255)
		return (free_split(color), false);
	if (0 <= ft_atoi(color[1]) && ft_atoi(color[1]) <= 255)
		return (free_split(color), false);
	if (0 <= ft_atoi(color[2]) && ft_atoi(color[2]) <= 255)
		return (free_split(color), false);
	free_split(color);
	return (true);
}

bool	is_valid_light(char **rt)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (rt[i])
	{
		j = 0;
		if (is_start_str(rt[i], "L"))
		{
			j += skip_space(rt[i]) + 1;
			j += skip_space(rt[i] + j);
			if (!is_valid_coordinate(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_brightness(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_color(rt[i], &j))
				return (false);
		}
		i++;
	}
	return (true);
}

bool	is_valid_object(char **rt)
{
	size_t	i;
	int		flag;

	i = 0;
	flag = 0;
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
		{
			flag++;
			if (!is_valid_sphere(rt[i]))
				return (false);
		}
		if (is_start_str(rt[i], "pl"))
		{
			flag++;
			if (!is_valid_plane(rt[i]))
				return (false);
		}
		if (is_start_str(rt[i], "cy"))
		{
			flag++;
			if (!is_valid_cylinder(rt[i]))
				return (false);
		}
		i++;
	}
	if (flag == 0)
		return (false);
	return (true);
}

bool	is_valid_sphere(char *rt)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
		{
			j += skip_space(rt[i]) + 1;
			j += skip_space(rt[i] + j);
			if (!is_valid_coordinate(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_radius(rt[i], &j))
				return (false);
			j += skip_space(rt[i] + j);
			if (!is_valid_color(rt[i], &j))
				return (false);
		}
		i++;
	}
	if (j == 0)
		return (false);
	return (true);
}
