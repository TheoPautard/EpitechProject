/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** print
*/

#include "matchstick.h"

void ai_print(int matches, int line)
{
    my_putstr("AI removed ");
    my_putnbr(matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putchar('\n');
}

void player_print(int matches, int line)
{
    my_putstr("Player removed ");
    my_putnbr(matches);
    my_putstr(" match(es) from line ");
    my_putnbr(line);
    my_putchar('\n');
}

void error_print(int matches)
{
    my_putstr("Error: you cannot remove more than ");
    my_putnbr(matches);
    my_putstr(" match(es) per line\n");
}

void print_tab(char **tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
}

void print_game(info_t *info)
{
    info->tab = rm_matches(info);
    player_print(info->matches, info->line);
    print_tab(info->tab);
}