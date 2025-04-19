/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:29:55 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 22:13:51 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	parse_camera(t_rt *rt)
{
	size_t	i;
	size_t	j;

	rt->camera = malloc(sizeof(t_camera));
	if (!rt->camera)
		return (error_message(ALLOCATE), false);
	init_camera(rt->camera);
	i = find_line_str(rt->rt, "C");
	j = skip_space(rt->rt[i]) + 1;
	if (!skip_and_set(rt->rt[i], &j, &(rt->camera->position),
			(bool (*)(void *, char *, size_t *))set_coordinate))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->camera->orientation),
			(bool (*)(void *, char *, size_t *))set_vector))
		return (false);
	if (!skip_and_set(rt->rt[i], &j, &(rt->camera->fov),
			(bool (*)(void *, char *, size_t *))set_fov))
		return (false);
	return (true);
}
