/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-theo.pautard
** File description:
** test_one
*/

#include "matchstick.h"

Test(check_ai, test_random)
{
    info_t *info = file_struct(3, 5);

    info->line = 1;
    info->matches = 6;
    cr_assert(check_ai(info) == 1);
    info->matches = 2;
    cr_assert(check_ai(info) == 1);
    info->matches = 1;
    cr_assert(check_ai(info) == 0);
}

Test(computer, check_ai_effectivness)
{
    info_t *info = file_struct(3, 4);

    computer(info);
    int a = info->line;
    int b = info->matches;

    cr_assert(a <= info->max_lines);
    cr_assert(a >= 1);
    cr_assert(b > 0);
    cr_assert(b <= info->max_matches);
    cr_assert(b <= nb_sticks(info->tab[a]));
    free_struct(info);
}

Test(check_args, test_if_good_args)
{
    int argc = 3;
    char **argv = malloc(sizeof(char *) * argc + 1);
    int i = 0;

    while (i != argc) {
        argv[i] = malloc(sizeof(char) + 1);
        i++;
    }
    argv[1] = "a";
    argv[2] = "b";

    int a = check_args(2, argv);
    int b = check_args(argc, argv);
    int c = 0;
    int d = 0;

    argv[1] = "3";
    c = check_args(argc, argv);
    argv[2] = "4";
    d = check_args(argc, argv);
    cr_assert(a == 1);
    cr_assert(b == 1);
    cr_assert(c == 1);
    cr_assert(d == 0);
}

Test(game_state, check_win_lose)
{
    int a = game_state(LOSE);
    int b = game_state(WIN);
    int c = game_state(0);

    cr_assert(a == LOSE);
    cr_assert(b == WIN);
    cr_assert(c == 0);
}

Test(check_int_matches, test_matches)
{
    info_t *info = file_struct(3, 4);
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    info->line = 2;
    info->matches = 5;
    a = check_int_matches(info);
    info->matches = 0;
    b = check_int_matches(info);
    info->matches = 4;
    c = check_int_matches(info);
    info->matches = 2;
    d = check_int_matches(info);
    cr_assert(a == ERR);
    cr_assert(b == ERR);
    cr_assert(c == ERR);
    cr_assert(d == 0);
}