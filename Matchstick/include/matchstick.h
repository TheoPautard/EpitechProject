/*
** EPITECH PROJECT, 2021
** B-CPE-200-BDX-2-1-matchstick-theo.pautard
** File description:
** matchstick
*/

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_
#define GETLINE_ERR -1
#define ERR 1
#define WIN 1
#define LOSE 2
#define OUT_OF_RANGE my_putstr("Error: this line is out of range\n");

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <criterion/criterion.h>

typedef struct info_game
{
    int line;
    int matches;
    int max_lines;
    int max_matches;
    char **tab;
    int set_game;
    int set;
}info_t;

info_t *file_struct(int max_line, int max_matches);
void free_struct(info_t *info);

/*-----------------------LIB/LIB_TWO-------------------------*/

void my_putchar(char c);
void my_putstr(char *str);
int my_putnbr(int nb);
int my_strlen(char *str);
int my_getnbr(char const *str);
int is_empty_line(char *str);
int nb_sticks(char *str);
char *adapt_input(char *input, size_t size);
void free_tab(char **tab);

/*--------------------------PRINT---------------------------*/

void error_print(int matches);
void player_print(int matches, int line);
void ai_print(int matches, int line);
void print_game(info_t *info);

/*---------------------------TAB----------------------------*/

char **malloc_tab(int nb_lines);
char **set_tab(int nb_lines);
char **file_tab(int nb_lines);
char **rm_matches(info_t *info);
void print_tab(char **tab);

/*---------------------------ROW----------------------------*/

char *star_line(char *str, int len);
char *space_line(char *str, int len);
void file_line(char *str, int begin, int end);

/*---------------------------GAME---------------------------*/

int player(info_t *info, char *input, size_t size);
int computer(info_t *info);
int loop(info_t *info);

/*-----------------------CHECK_INPUTS-----------------------*/

int check_int_matches(info_t *info);
int check_matches(info_t *info);
int check_line(info_t *info);
char *check_input(void);
int check_game(info_t *info);
int check_ai(info_t *info);

/*---------------------------ERR----------------------------*/

int check_args(int argc, char **argv);
info_t *check_error(char **argv);
int matchstick(int argc, char **argv);
int is_empty(info_t *info);
int is_num(char *str);
int game_state(int game);

#endif /* !MATCHSTICK_H_ */
