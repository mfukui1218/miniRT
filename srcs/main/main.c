/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 22:19:11 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/16 18:47:55 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

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
	return (0);
}

void line(void)
{
	printf("--------------------------------------------------\n");
}