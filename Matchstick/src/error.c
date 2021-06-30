/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** error
*/

#include "matchstick.h"

int check_args(int argc, char **argv)
{
    if (argc != 3) {
        return (1);
    }
    if (is_num(argv[1]) == 1) {
        return (1);
    }
    if (is_num(argv[2]) == 1) {
        return (1);
    }
    return (0);
}

info_t *check_error(char **argv)
{
    info_t *info = NULL;
    int lines = my_getnbr(argv[1]);
    int max_matches = my_getnbr(argv[2]);

    if (lines < 2 || lines > 99)
        return (NULL);
    if (max_matches < 1)
        return (NULL);

    info = file_struct(lines, max_matches);
    if (info == NULL)
        return (NULL);
    return (info);
}

int game_state(int game)
{
    if (game == LOSE) {
        my_putstr("You lost, too bad...\n");
        return (LOSE);
    }
    if (game == WIN) {
        my_putstr("I lost... snif... but I'll get you next time!!\n");
        return (WIN);
    }
    return (0);
}