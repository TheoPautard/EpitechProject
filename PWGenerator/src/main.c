#include "../include/PWGenerator.h"

int main(int ac, char **av)
{
    if (is_error(ac, av) == true)
        return (84);
    pwgenerator(av);
    return (0);
}