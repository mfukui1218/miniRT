#include "miniRT.h"

int	has_one_info(char **txt, char *str)
{
	size_t i;
	int signal;

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

bool is_start_str(char *str, char *start)
{
    size_t i;
    size_t j;

    i = skip_space(str);
    j = 0;
    while (str[i] && start[j])
    {
        if (str[i] != start[j])
            return (false);
        j++;
        i++;
    }
    if (start[j] == '\0' && (str[i] == ' ' || str[i] == '\0'))
        return (true);
    return (false);
}

void free_split(char **split)
{
    size_t i;

    i = 0;
    while (split[i])
    {
        free(split[i]);
        i++;
    }
    free(split);
}

float ft_atof(char *str)
{
    float result;
    float fraction;
    int sign;
    int i;
    int divisor;

    result = 0.0f;
    sign = 1;
    divisor = 10;
    fraction = 0.0f;
    i = 0;
    i += skip_space(str);
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    if (str[i] == '.')
    {
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            fraction += (float)(str[i] - '0') / divisor;
            divisor *= 10;
            i++;
        }
    }
}