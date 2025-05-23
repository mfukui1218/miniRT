/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/26 21:59:10 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <X11/X.h>

static bool	path_condition(const char *file_path);

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		return (printf("Error\nInvalid number of arguments\n"), EXIT_FAILURE);
	if (!path_condition(argv[1]))
		return (printf("Error\nInvalid file name\n"), EXIT_FAILURE);
	rt = malloc(sizeof(t_rt));
	if (!rt)
		return (EXIT_FAILURE);
	init_rt(rt);
	if (!parse_rt(rt, argv[1]))
		return (free_rt(rt), EXIT_FAILURE);
	mlx_key_hook(rt->win, rt_key_event_handler, rt);
	mlx_expose_hook(rt->win, rt_expose_event_handler, rt);
	mlx_hook(rt->win, DestroyNotify, NoEventMask, rt_destroy_event_handler, rt);
	draw(rt);
	render(rt);
	mlx_loop(rt->mlx);
	free_rt(rt);
	return (0);
}

static bool	path_condition(const char *file_path)
{
	size_t	i;

	if (ft_strlen(file_path) <= 2)
		return (printf("Error\nInappropriate file name.\n"), 0);
	i = 0;
	while (file_path[i])
		i++;
	i--;
	if (!(file_path[i - 2] == '.' && file_path[i - 1] == 'r'
			&& file_path[i] == 't'))
		return (printf("Error\nInappropriate file name.\n"), 0);
	return (true);
}
