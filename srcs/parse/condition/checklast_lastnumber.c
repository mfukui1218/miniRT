/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklast_lastnumber.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 15:01:10 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	checklast_last_number(char *str, size_t *j)
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
	while (str[*j] == ' ' || str[*j] == '\t')
		(*j)++;
	if (str[*j] != '\0' && str[*j] != '\n')
		return (false);
	return (true);
}
