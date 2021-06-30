/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** lib
*/

#include "matchstick.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

int my_getnbr(char const *str)
{
    int x = 1;
    int p = 0;
    int i = 0;

    while (str[p] == '-' || str[p] == '+') {
        if (str[p] == '-')
            x = x * (-1);
        p++;
    }
    while (str[p] >= '0' && str[p] <= '9') {
        i = i * 10;
        i = i + (str[p] - 48);
        p++;
    }
    return (x * i);
}

void free_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        free(tab[i]);
        i++;
    }
    free(tab);
}