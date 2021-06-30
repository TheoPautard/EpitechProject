/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** game_loop
*/

#include "matchstick.h"

int matchstick(int argc, char **argv)
{
    int game = 0;
    info_t *info = NULL;

    if (check_args(argc, argv) == 1)
        return (84);
    else if (check_error(argv) == NULL)
        return (84);
    info = check_error(argv);
    if (info == NULL)
        return (0);
    print_tab(info->tab);
    my_putstr("\nYour turn:\n");
    game = loop(info);
    if (game == -1) {
        free_struct(info);
        return (-1);
    } else if (game == 1 || game == 2) {
        return (game_state(game));
        free_struct(info);
    }
    return (game);
}

int loop(info_t *info)
{
    while (1) {
        info->set = check_game(info);
        if (info->set == -1)
            return (-1);
        else {
            while (info->set == ERR)
                info->set = check_game(info);
            if (info->set == 0)
                print_game(info);
            if (is_empty(info) == 0)
                return (LOSE);
            info->set = computer(info);
            if (is_empty(info) == 0)
                return (WIN);
        }
        my_putstr("\nYour turn:\n");
    }
    return (0);
}