/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_line_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 21:08:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 21:08:12 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
