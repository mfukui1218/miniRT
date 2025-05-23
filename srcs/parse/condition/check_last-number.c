/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_last-number.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 15:00:26 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_last_number(char *str, size_t *j)
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
	if (str[*j] != '\0' && str[*j] != '\n' && str[*j] != ' ' && str[*j] != '\t')
		return (false);
	return (true);
}
