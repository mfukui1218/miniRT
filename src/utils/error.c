#include "miniRT.h"

void error_message(int eroor)
{
    if (eroor == ALLOCATE)
        printf("Error\nAllocation error\n");
    exit(0);
}
