/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_print_ntp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tookuyam <tookuyam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 17:53:17 by tookuyam          #+#    #+#             */
/*   Updated: 2025/04/19 18:36:53 by tookuyam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

void	rt_print_ntp(const void **ntp, void (*f)(const void *))
{
	bool	is_print;

	if (ntp == NULL)
		return ;
	is_print = false;
	while (*ntp != NULL)
	{
		if (is_print == true)
			printf(" -> ");
		f(*ntp);
		is_print = true;
		ntp++;
	}
	return ;
}
