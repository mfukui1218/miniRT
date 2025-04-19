/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_number_with_comma.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 20:37:11 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_number_with_comma(char *str, size_t *j)
{
	if (str[*j] == '-')
		(*j)++;
	if (!('0' <= str[*j] && str[*j] <= '9'))
		return (false);
	while ('0' <= str[*j] && str[*j] <= '9')
		(*j)++;
	if (str[*j] == '.')
	{
		(*j)++;
		if (!('0' <= str[*j] && str[*j] <= '9'))
			return (false);
		while ('0' <= str[*j] && str[*j] <= '9')
			(*j)++;
	}
	if (str[*j] != ',')
		return (false);
	(*j)++;
	return (true);
}
