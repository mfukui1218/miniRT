/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_ambiendouble.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:05:00 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/25 02:37:29 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	calc_ambient_radiance(t_rt *rt)
{
	double	result;

	result = rt->ambient->brightness;
	return (result);
}
