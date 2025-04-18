/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfukui <mfukui@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:32:22 by mfukui            #+#    #+#             */
/*   Updated: 2025/04/18 14:15:43 by mfukui           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	check_number_with_comma(char *str, size_t *j)
{
	if (str[*j] == '-')
		(*j)++;
	if (!('0' <= str[*j] && str[*j] <= '9'))
		return (false);
	while ('0' <= str[*j] && str[*j] <= '9')
		(*j)++;
	if (str[*j] == '.')
	{
		(*j)++;
		if (!('0' <= str[*j] && str[*j] <= '9'))
			return (false);
		while ('0' <= str[*j] && str[*j] <= '9')
			(*j)++;
	}
	if (str[*j] != ',')
		return (false);
	(*j)++;
	return (true);
}

bool	check_last_number(char *str, size_t *j)
{
	if (str[*j] == '-')
		(*j)++;
	if (!('0' <= str[*j] && str[*j] <= '9'))
		return (false);
	while ('0' <= str[*j] && str[*j] <= '9')
		(*j)++;
	if (str[*j] == '.')
	{
		(*j)++;
		if (!('0' <= str[*j] && str[*j] <= '9'))
			return (false);
		while ('0' <= str[*j] && str[*j] <= '9')
			(*j)++;
	}
	if (str[*j] != '\n' && str[*j] != ' ' && str[*j] != '\t' && str[*j] != '\0')
		return (false);
	return (true);
}

bool	parse_and_check(char *str, size_t *j, bool (*check)(char *, size_t *))
{
	*j += skip_space(str + *j);
	if (!check(str, j))
		return (false);
	return (true);
}

bool	check_three_range(char *str, int min, int max)
{
	char	**vec;
	int		n;
	int		i;

	vec = ft_split(str, ',');
	if (!vec)
		return (error_message(ALLOCATE), false);
	i = 0;
	while (i < 3)
	{
		n = ft_atoi(vec[i]);
		if (n < min || n > max)
			return (free_split(vec), false);
		i++;
	}
	free_split(vec);
	return (true);
}