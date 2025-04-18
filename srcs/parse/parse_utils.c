/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 15:05:42 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int ft_atoi_index(char *str, size_t *i)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
	{
		if (!('0' <= str[*i] && str[*i] <= '9'))
			return (false);
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result * sign);
}

bool	skip_and_set(char *line, size_t *j, void *dst, bool (*func)(void *, char *, size_t *))
{
	*j += skip_space(line + *j);
	if (!func(dst, line, j))
		return (false);
	return (true);
}

float   ft_atof_index(char *str, size_t *j)
{
	float	result;
	float	fraction;
	int		sign;
	int		divisor;

	result = 0.0f;
	sign = 1;
	divisor = 10;
	fraction = 0.0f;
	*j += skip_space(str + *j);
	if (str[*j] == '+' || str[*j] == '-')
	{
		if (str[*j] == '-')
			sign = -1;
		(*j)++;
	}
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		result = result * 10 + (str[*j] - '0');
		(*j)++;
	}
	if (str[*j] == '.')
	{
		(*j)++;
		while (str[*j] >= '0' && str[*j] <= '9')
		{
			fraction += (float)(str[*j] - '0') / divisor;
			divisor *= 10;
			(*j)++;
		}
	}
	result += fraction;
	return (result * sign);
}

bool	check_range_int(int value, int min, int max)
{
	return (value >= min && value <= max);
}

bool	check_range_float(float value, float min, float max)
{
	return (value >= min && value <= max);
}
