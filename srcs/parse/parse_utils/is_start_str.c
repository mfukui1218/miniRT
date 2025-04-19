/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_start_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:03:27 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 20:35:02 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
