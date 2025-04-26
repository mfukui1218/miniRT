/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:00:24 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 17:17:47 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_txt(t_rt *rt, char *file_name)
{
	int		fd;
	size_t	i;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (error_message(OPEN), false);
	rt->rt = malloc(sizeof(char *) * MAX_TXT_HEIGHT + 1);
	if (!rt->rt)
		return (error_message(ALLOCATE), false);
	i = 0;
	while (1)
	{
		rt->rt[i] = get_next_line(fd);
		if (!rt->rt[i])
			break ;
		if (i >= MAX_TXT_HEIGHT)
		{
			free_split(rt->rt);
			return (error_message(MAX_TXT), false);
		}
		i++;
	}
	close(fd);
	return (true);
}
