/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_condition.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 20:32:02 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/19 20:33:26 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	has_object_info(char **rt)
{
	size_t	i;
	int		signal;

	signal = 0;
	i = 0;
	while (rt[i])
	{
		if (is_start_str(rt[i], "sp"))
			signal++;
		else if (is_start_str(rt[i], "pl"))
			signal++;
		else if (is_start_str(rt[i], "cy"))
			signal++;
		i++;
	}
	if (signal == 0)
		return (printf("Error\nThere is no object\n"), 0);
	return (signal);
}

static int	has_one_info(char **txt, char *str)
{
	size_t	i;
	int		signal;

	signal = 0;
	i = 0;
	while (txt[i])
	{
		if (is_start_str(txt[i], str))
			signal++;
		i++;
	}
	if (signal == 1)
		return (1);
	else if (signal > 1)
		return (printf("Error\nThere are more than one %s\n", str), 2);
	else
		return (printf("Error\nThere is no %s\n", str), 0);
}

bool	is_valid_condition(char **rt)
{
	if (has_one_info(rt, "C") != 1)
		return (false);
	if (has_one_info(rt, "A") != 1)
		return (false);
	if (has_one_info(rt, "L") != 1)
		return (false);
	if (has_object_info(rt) == 0)
		return (false);
	return (true);
}
