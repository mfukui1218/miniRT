/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_expose_evenet_hander.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42tokyo.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 04:30:08 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/20 04:30:08 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
#include <stdio.h>

int	rt_expose_event_handler(t_rt *rt)
{
	render(rt);
	printf("Expose event triggered\n");
	return (0);
}
