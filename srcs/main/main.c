/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/20 07:01:56 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <X11/X.h>

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		return (printf("Error\nInvalid number of arguments\n"), EXIT_FAILURE);
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

void	line(void)
{
	printf("--------------------------------------------------\n");
}
