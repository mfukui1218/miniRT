/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_rt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:10:43 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 01:08:12 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "miniRT.h"

void	rt_print_rt(const t_rt *rt)
{
	if (rt == NULL)
		return ;
	rt_print_indent(0);
	printf("mlx: %p\n", rt->mlx);
	rt_print_indent(0);
	printf("win: %p\n", rt->win);
	rt_print_str("rt:\n");
	rt_print_indent(1);
	rt_print_ntp((const void **)rt->rt, (void (*)(const void *))rt_print_str);
	rt_print_indent(-1);
	printf("\n");
	rt_print_str("camera:\n");
	rt_print_with_indent((t_print_func)rt_print_camera, rt->camera);
	rt_print_str("ambient:\n");
	rt_print_with_indent((t_print_func)rt_print_ambient, rt->ambient);
	rt_print_str("light:\n");
	rt_print_with_indent((t_print_func)rt_print_light, rt->light);
	rt_print_str("object(rt):\n");
	rt_print_indent(1);
	rt_print_list(rt->object, (void (*)(const void *))rt_print_object);
	rt_print_indent(-1);
}
