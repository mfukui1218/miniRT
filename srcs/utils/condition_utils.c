/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:27 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 02:00:36 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	has_one_info(char **txt, char *str)
{
	size_t	i;
	int		signal;

	signal = 0;
	i = 0;
	while (txt[i])
	{
		if (is_start_str(txt[i], str))
			signal++;
		i++;
	}
	if (signal == 1)
		return (1);
	else if (signal > 1)
		return (printf("Error\nThere are more than one %s\n", str), 2);
	else
		return (printf("Error\nThere is no %s\n", str), 0);
}

bool	is_start_str(char *str, char *start)
{
	size_t	i;
	size_t	j;

	i = skip_space(str);
	while (str[i])
	{
		j = 0;
		while (start[j] && str[i + j] == start[j])
			j++;
		if (start[j] == '\0' && (str[i + j] == ' ' || str[i + j] == '\t'))
			return (true);
		i++;
	}
	return (false);
}

float	ft_atof(char *str)
{
	float	result;
	float	fraction;
	int		sign;
	int		i;
	int		divisor;

	result = 0.0f;
	sign = 1;
	divisor = 10;
	fraction = 0.0f;
	i = 0;
	i += skip_space(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			fraction += (float)(str[i] - '0') / divisor;
			divisor *= 10;
			i++;
		}
	}
	result += fraction;
	return (result * sign);
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

int	has_object_info(char **rt)
{
	size_t	i;
	int		signal;

	signal = 0;
	i = 0;
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
			signal++;
		else if (is_start_str(rt[i], "pl"))
			signal++;
		else if (is_start_str(rt[i], "cy"))
			signal++;
		i++;
	}
	if (signal == 0)
		return (printf("Error\nThere is no object\n"), 0);
	return (signal);
}
