/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** ai
*/

#include "matchstick.h"

int computer(info_t *info)
{
    my_putstr("\nAI's turn...\n");
    srandom(time(NULL));
    do {
        info->line = random() % info->max_lines + 1;
    } while (is_empty_line(info->tab[info->line]) == 1);
    do {
        info->matches = random() % nb_sticks(info->tab[info->line]) + 1;
    } while (check_ai(info) == 1);
    info->tab = rm_matches(info);
    ai_print(info->matches, info->line);
    print_tab(info->tab);
    return  (0);
}

int check_ai(info_t *info)
{
    if (info->matches > info->max_matches) {
        return (1);
    }
    if (info->matches > nb_sticks(info->tab[info->line])) {
        return (1);
    }
    return (0);
}