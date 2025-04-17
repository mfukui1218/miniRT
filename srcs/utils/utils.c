/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:43 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/17 23:21:44 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_valid_condition(char **rt)
{
	if (has_one_info(rt, "C") != 1)
		return (false);
	if (has_one_info(rt, "A") != 1)
		return (false);
	if (has_one_info(rt, "L") != 1)
		return (false);
	if (has_object_info(rt) == 0)
		return (false);
	return (true);
}

size_t	skip_space(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

void	inclement_ij(size_t *i, size_t *j)
{
	(*i)++;
	(*j)++;
}

