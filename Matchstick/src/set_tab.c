/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** set_tab
*/

#include "matchstick.h"

char **malloc_tab(int nb_lines)
{
    char **tab = malloc(sizeof(char *) * (nb_lines + 3));
    if (tab == NULL) {
        return (NULL);
    }
    int size = 0;
    int end = nb_lines + 2;

    while (size < end) {
        tab[size] = malloc(sizeof(char) * (nb_lines * 2) + 3);
        size++;
    }
    tab[size] = NULL;
    return (tab);
}

char **set_tab(int nb_lines)
{
    char **tab = malloc_tab(nb_lines);
    int i = 0;

    tab[i] = star_line(tab[i], (nb_lines * 2) - 1);
    i++;
    while (i < (nb_lines + 1)) {
        tab[i] = space_line(tab[i], (nb_lines * 2) - 1);
        i++;
    }
    tab[i] = star_line(tab[i], (nb_lines * 2) - 1);
    return (tab);
}

char **file_tab(int nb_lines)
{
    char **tab = set_tab(nb_lines);
    int raw = nb_lines;
    int begin = 1;
    int end = my_strlen(tab[raw]) - 2;

    while (raw > 0) {
        file_line(tab[raw], begin, end);
        begin++;
        end--;
        raw--;
    }
    return (tab);
}

char **rm_matches(info_t *info)
{
    int col = my_strlen(info->tab[info->line]) - 1;
    int matches = info->matches;

    while (col != 0) {
        if (matches != 0) {
            if (info->tab[info->line][col] == '|') {
                info->tab[info->line][col] = ' ';
                matches--;
            }
        }
        col--;
    }
    return (info->tab);
}