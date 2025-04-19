/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 20:34:22 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_atoi_index(char *str, size_t *i)
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

bool	skip_and_set(char *line, size_t *j,
		void *dst, bool (*func)(void *, char *, size_t *))
{
	*j += skip_space(line + *j);
	if (!func(dst, line, j))
		return (false);
	return (true);
}

bool	check_range_int(int value, int min, int max)
{
	return (value >= min && value <= max);
}

bool	check_range_float(float value, float min, float max)
{
	return (value >= min && value <= max);
}


size_t	find_line_str(char **rt, char *start)
{
	size_t	i;

	i = 0;
	while (rt[i])
	{
		if (is_start_str(rt[i], start))
			return (i);
		i++;
	}
	return (0);
}
