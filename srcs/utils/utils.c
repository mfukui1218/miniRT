#include "miniRT.h"

size_t skip_space(char *str)
{
    size_t i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    return (i);
}