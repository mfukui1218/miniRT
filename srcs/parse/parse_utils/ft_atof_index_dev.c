/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof_index_dev.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:28:20 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 17:40:54 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	skip_parse_sign(char *str, size_t *j)
{
	int	sign;

	sign = 1;
	if (str[*j] == '-')
	{
		sign = -1;
		(*j)++;
	}
	else if (str[*j] == '+')
		(*j)++;
	return (sign);
}

static float	parse_integer_part(char *str, size_t *j)
{
	int		sign;
	float	result;

	sign = 1;
	if (str[*j] == '-')
	{
		sign = -1;
		(*j)++;
	}
	else if (str[*j] == '+')
		(*j)++;
	result = 0.0f;
	while (str[*j] >= '0' && str[*j] <= '9')
	{
		result = result * 10 + (str[*j] - '0');
		(*j)++;
	}
	return (result * sign);
}

static float	parse_fractional_part(char *str, size_t *j)
{
	float	fraction;
	int		divisor;

	fraction = 0.0f;
	divisor = 10;
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
	return (fraction);
}

float	ft_atof_index_dev(char *str, size_t *j, bool dev)
{
	float	result;
	int		sign;
	size_t	tmp;

	tmp = *j;
	result = 0.0f;
	sign = skip_parse_sign(str, &tmp);
	result = parse_integer_part(str, &tmp);
	result += parse_fractional_part(str, &tmp);
	if (dev)
		*j = tmp;
	return (result * sign);
}
