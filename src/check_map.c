/*
** EPITECH PROJECT, 2022
** check_map.c
** File description:
** checking the map
*/

#include "../include/includes.h"
#include "../include/my.h"

int check_border(char **map, char*str)
{
    for (int index = 0; index != my_strlen(map[0]) - 1; index += 1) {
        if (map[0][index] != '#')
            exit(84);
    }
    for (int index = 0; index != my_strlen(map[get_nbr_row(str)]) - 1;
    index += 1) {
        if (map[get_nbr_row(str) - 1][index] != '#')
            exit(84);
    }
    check_last(map, str);
    return 0;
}

int check_last(char **map, char *str)
{
    for (int index = 0; index != get_nbr_row(str) - 1; index += 1) {
        if (map[index][my_strlen(map[index]) - 2] != '#')
            exit(84);
    }
    return 0;
}

int check_map(char *str)
{
    for (int index = 0; index != my_strlen(str); index += 1) {
        if (str[index] != '#' && str[index] != ' ' && str[index] != 'P' &&
        str[index] != 'X' && str[index] != 'O' && str[index] != '\n')
            exit(84);
    }
    return 0;
}

int check_term(char *str)
{
    int row;
    int col;

    getmaxyx(stdscr, row, col);
    if (row < get_nbr_row(str)|| col < get_nbr_col(str) / 2)
        center_display("Window too small", 17, 1);
    return 0;
}