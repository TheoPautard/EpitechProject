/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** input_handling
*/

#include "matchstick.h"

char *check_input(void)
{
    size_t size = 4;
    char *input = NULL;
    char *str = NULL;

    if (getline(&input, &size, stdin) <= 0) {
        free(input);
        return (NULL);
    }
    str = adapt_input(input, size);
    return (str);
}

int check_line(info_t *info)
{
    my_putstr("Line: ");
    char *input = check_input();

    if (input == NULL)
        return (-1);
    else {
        if (is_num(input) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(input);
            return (ERR);
        }
        info->line = my_getnbr(input);
        if (info->line < 1 || info->line > info->max_lines) {
            my_putstr("Error: this line is out of range\n");
            free(input);
            return (ERR);
        }
    }
    free(input);
    return (0);
}

int check_int_matches(info_t *info)
{
    if (info->matches > info->max_matches) {
        error_print(info->max_matches);
        return (ERR);
    }
    if (info->matches < 1) {
        my_putstr("Error: you have to remove at least one match\n");
        return (ERR);
    }
    if (is_empty_line(info->tab[info->line]) == 1 || info->matches >\
    nb_sticks(info->tab[info->line])) {
        my_putstr("Error: not enough matches on this line\n");
        return (ERR);
    } return (0);
}

int check_matches(info_t *info)
{
    my_putstr("Matches: ");
    char *input = check_input();

    if (input == NULL)
        return (-1);
    else {
        if (is_num(input) == 1) {
            my_putstr("Error: invalid input (positive number expected)\n");
            free(input);
            return (ERR);
        }
        info->matches = my_getnbr(input);
        if (check_int_matches(info) == ERR) {
            free(input);
            return (ERR);
        }
    }
    free(input);
    return (0);
}

int check_game(info_t *info)
{
    int game = check_line(info);

    if (game == -1)
        return (-1);
    else {
        if (game == ERR)
            return (ERR);
        game = check_matches(info);
    }
    if (game == -1)
        return (-1);
    if (game == ERR)
        return (ERR);
    return (0);
}