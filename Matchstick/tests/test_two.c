/*
** EPITECH PROJECT, 2021
** Matchstick
** File description:
** test_two
*/

#include "matchstick.h"

Test(is_num, test_is_num)
{
    int a = is_num("23aa34");
    int b = is_num("1234");

    cr_assert(a == 1);
    cr_assert(b == 0);
}

Test(is_empty, check_if_tab_is_empty)
{
    info_t *info = file_struct(2, 3);

    cr_assert(is_empty(info) == 1);
    info->line = 1;
    info->matches = 1;
    info->tab = rm_matches(info);
    info->line = 2;
    info->matches = 3;
    info->tab = rm_matches(info);
    cr_assert(is_empty(info) == 0);
}