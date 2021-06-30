/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** file_struct
*/

#include "matchstick.h"

info_t *file_struct(int max_line, int max_matches)
{
    info_t *info = malloc(sizeof(info_t));

    if (info == NULL)
        return (NULL);
    info->max_lines = max_line;
    info->max_matches = max_matches;
    info->line = 0;
    info->matches = 0;
    info->tab = file_tab(info->max_lines);
    info->set_game = 0;
    info->set = 0;

    return (info);
}