/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_destroy_evenet_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 05:40:35 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 05:40:35 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

int	rt_destroy_event_handler(t_rt *rt)
{
	free_rt(rt);
	exit(EXIT_SUCCESS);
	return (0);
}
