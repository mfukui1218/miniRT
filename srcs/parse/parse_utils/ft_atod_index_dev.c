/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_index_dev.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:28:20 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/22 17:13:14 by tookuyam         ###   ########.fr       */
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

static double	parse_integer_part(char *str, size_t *j)
{
	int		sign;
	double	result;

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

static double	parse_fractional_part(char *str, size_t *j)
{
	double	fraction;
	int		divisor;

	fraction = 0.0f;
	divisor = 10;
	if (str[*j] == '.')
	{
		(*j)++;
		while (str[*j] >= '0' && str[*j] <= '9')
		{
			fraction += (double)(str[*j] - '0') / divisor;
			divisor *= 10;
			(*j)++;
		}
	}
	return (fraction);
}

double	ft_atod_index_dev(char *str, size_t *j, bool dev)
{
	double	result;
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
