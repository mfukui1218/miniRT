/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:22:05 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:31:47 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_valid_coordinate(char *str, size_t *j)
{
	if (!check_number_with_comma(str, j))
		return (error_message(COORDINATE_RT), false);
	if (!check_number_with_comma(str, j))
		return (error_message(COORDINATE_RT), false);
	if (!check_last_number(str, j))
		return (error_message(COORDINATE_RT), false);
	if (str[*j] && str[*j] != ' ' && str[*j] != '\t')
		return (error_message(COORDINATE_RT), false);
	if (!check_three_range(str, -1000, 1000))
		return (error_message(COORDINATE_RANGE), false);
	return (true);
}

bool	is_valid_vector(char *str, size_t *j)
{
	if (!check_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	if (!check_number_with_comma(str, j))
		return (error_message(VECTOR_RT), false);
	if (!check_last_number(str, j))
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
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_number_with_comma(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_last_number(str, j))
		return (error_message(COLOR_RT), false);
	if (!check_three_range(str, 0, 255))
		return (error_message(COLOR_RANGE), false);
	return (true);
}
