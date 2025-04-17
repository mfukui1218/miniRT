#include "miniRT.h"

int ft_atoi_index(char *str, size_t *i)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	while (str[*i] && str[*i] != ' ' && str[*i] != '\t')
	{
		if (!('0' <= str[*i] && str[*i] <= '9'))
			return (false);
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result * sign);
}

bool	skip_and_set(char *line, size_t *i, void *dst, bool (*func)(void *, char *, size_t *))
{
	*i += skip_space(line + *i);
	return (func(dst, line, i));
}

float   ft_atof_index(char *str, size_t *i)
{
	float	result;
	float	fraction;
	int		sign;
	int		divisor;

	result = 0.0f;
	sign = 1;
	divisor = 10;
	fraction = 0.0f;
	*i += skip_space(str);
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign = -1;
		(*i)++;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			fraction += (float)(str[*i] - '0') / divisor;
			divisor *= 10;
			(*i)++;
		}
	}
	result += fraction;
	return (result * sign);
}

bool	check_range_int(int value, int min, int max)
{
	return (value >= min && value <= max);
}

bool	check_range_float(float value, float min, float max)
{
	return (value >= min && value <= max);
}
