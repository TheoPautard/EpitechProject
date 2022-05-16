#include "../include/PWGenerator.h"

bool is_num(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return (false);
    } return (true);
}

bool is_error(int ac, char **av)
{
    if (ac != 2)
        return (true);
    if (is_num(av[1]) == false)
        return (true);
    if (atoi(av[1]) < 8 || atoi(av[1]) > 16)
        return (true);
    return (false);
}