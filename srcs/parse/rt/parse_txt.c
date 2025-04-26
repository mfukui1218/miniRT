/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 18:00:24 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 21:41:10 by tookuyam         ###   ########.fr       */
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
	rt->rt = malloc(sizeof(char *) * (MAX_TXT_HEIGHT + 1));
	if (!rt->rt)
		return (error_message(ALLOCATE), false);
	ft_memset(rt->rt, 0, sizeof(char *) * (MAX_TXT_HEIGHT + 1));
	i = 0;
	while (1)
	{
		if (i >= MAX_TXT_HEIGHT)
			return (close(fd), get_next_line(-1),
				error_message(MAX_TXT), false);
		rt->rt[i] = get_next_line(fd);
		if (!rt->rt[i])
			break ;
		i++;
	}
	close(fd);
	return (true);
}
