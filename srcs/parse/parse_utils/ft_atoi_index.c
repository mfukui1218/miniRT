/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 21:06:18 by mfukui           ###   ########.fr       */
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
