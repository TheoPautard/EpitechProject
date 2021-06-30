/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** set_lines
*/

#include "matchstick.h"

char *star_line(char *str, int len)
{
    char star = '*';
    int i = 0;

    while (i < (len + 2)) {
        str[i] = star;
        i++;
    }
    str[i] = '\0';
    return (str);
}

char *space_line(char *str, int len)
{
    char space = ' ';
    int i = 0;

    str[i] = '*';
    i++;
    while (i < (len + 1)) {
        str[i] = space;
        i++;
    }
    str[i] = '*';
    i++;
    str[i] = '\0';
    return (str);
}

void file_line(char *str, int begin, int end)
{
    int mid = my_strlen(str) / 2;

    while ((begin != mid) && (end != mid)) {
        str[begin] = '|';
        str[end] = '|';
        begin++;
        end--;
    }
    str[mid] = '|';
}

int is_empty_line(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            return (0);
        i++;
    }
    return (1);
}

int nb_sticks(char *str)
{
    int i = 0;
    int sticks = 0;

    while (str[i] != '\0') {
        if (str[i] == '|')
            sticks++;
        i++;
    }
    return (sticks);
}