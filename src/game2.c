/*
** EPITECH PROJECT, 2022
** game2.c
** File description:
** game file suite
*/

#include "../include/includes.h"

int increment_nbr_x(int index, int index2, char **map, int nbr_o)
{
    if (map[index][index2] == 'X') {
        nbr_o += 1;
    }
    return nbr_o;
}

int get_nbr_x(char **map, int nbr_lines)
{
    int nbr_o = 0;

    for (int index = 0; index != nbr_lines; index += 1) {
        for (int index2 = 0; map[index][index2] != '\n'; index2 += 1) {
            nbr_o = increment_nbr_x(index, index2, map, nbr_o);
        }
    }
    return nbr_o;
}

int check_if_dead(char **map, int nbr_lines, int nbr_x)
{
    int *xpos = get_x_pos(map, nbr_lines);
    int nbr_x_fucked = 0;

    for (int index = 0; index != nbr_x; index += 1) {
        if (((map[xpos[index * 2] - 1][xpos[index * 2 + 1]] == '#')
        && (map[xpos[index * 2]][xpos[index * 2 + 1] - 1] == '#')) ||
        ((map[xpos[index * 2]][xpos[index * 2 + 1] - 1] == '#')
        && (map[xpos[index * 2] - 1][xpos[index * 2 + 1]] == '#'))  ||
        ((map[xpos[index * 2] + 1][xpos[index * 2 + 1]] == '#')
        && (map[xpos[index * 2]][xpos[index * 2 + 1] + 1] == '#')) ||
        ((map[xpos[index * 2]][xpos[index * 2 + 1] - 1] == '#')
        && (map[xpos[index * 2] + 1][xpos[index * 2 + 1]] == '#')))
            nbr_x_fucked += 1;
    }
    if (nbr_x_fucked == nbr_x)
        return 84;
    return 0;
}

int make_game_loop(WINDOW *window, int *poso, char **map, char *str_map)
{
    int nbr_o = get_nbr_o(map, get_nbr_row(str_map));
    int nbr_x = get_nbr_x(map, get_nbr_row(str_map));

    window = initscr();
    noecho();
    raw();
    curs_set(0);
    keypad(window, 1);
    while (nbr_o != 0) {
        check_term(str_map);
        if (check_if_dead(map, get_nbr_row(str_map), nbr_x) == 84)
            exit(1);
        for (int index = 0; index != nbr_o; index += 1) {
            if (map[poso[index * 2]][poso[index * 2 + 1]] == ' ') {
                map[poso[index * 2]][poso[index * 2 + 1]] = 'O';
            }
        }
        game_loop(map, window, str_map);
        nbr_o = get_nbr_o(map, get_nbr_row(str_map));

    }
    return 0;
}

int make_loop(char *str_map, FILE *fd)
{
    WINDOW *window = NULL;
    char **map = make_tab(str_map, fd);
    int *poso = get_o_pos(map, get_nbr_row(str_map));

    check_border(map, str_map);
    make_game_loop(window, poso, map, str_map);
    for (int index = 0; str_map[index] != '\0'; index += 1) {
        if (str_map[index] != ' ' && str_map[index] != '\n'
        && str_map[index] != '#' && str_map[index] != 'X'
        && str_map[index] != 'O' && str_map[index] != 'P')
            exit(84);
    }
    noraw();
    echo();
    curs_set(1);
    endwin();
    return 0;
}
