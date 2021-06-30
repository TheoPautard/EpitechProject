/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** main
*/

#include "matchstick.h"

int main(int argc, char **argv)
{
    int game = matchstick(argc, argv);

    if (game == -1)
        return (0);
    return (game);
}