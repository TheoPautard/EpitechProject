/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** utils
*/

#include "matchstick.h"

int my_putnbr(int nb)
{
    int x = 1;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    while (nb / x >= 10) {
        x = x * 10;
    }
    while (x > 0) {
        my_putchar(((nb / x) % 10) + 48);
        x = x / 10;
    }
    return (0);
}

int is_num(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {
            return (1);
        }
        i++;
    }
    return (0);
}

int is_empty(info_t *info)
{
    int i = 1;
    int j = 0;

    while (info->tab[i] != NULL) {
        while (info->tab[i][j] != '\0') {
            if (info->tab[i][j] == '|') {
                return (1);
            }
            j++;
        }
        j = 0;
        i++;
    }
    return (0);
}

char *adapt_input(char *input, size_t size)
{
    size_t nb_char = 0;
    int i = 0;

    while (input[i] != '\0') {
        if (input[i] > 31 && input[i] < 127)
            nb_char++;
        i++;
    }
    input[size - (size - nb_char)] = '\0';
    return (input);
}

void free_struct(info_t *info)
{
    free_tab(info->tab);
    free(info);
}