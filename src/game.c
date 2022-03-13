/*
** EPITECH PROJECT, 2022
** game.c
** File description:
** game functions
*/

#include "../include/includes.h"

int *go_left(char **map, int *pos, int ch)
{
    if (ch == KEY_LEFT && map[pos[0]][pos[1] - 1] != '#') {
        if (map[pos[0]][pos[1] - 1] == 'X' && map[pos[0]][pos[1] - 2] != '#')
            map[pos[0]][pos[1] - 2] = 'X';
        else if (map[pos[0]][pos[1] - 1] == 'X'
        && map[pos[0]][pos[1] - 2] == '#')
            return 0;
        map[pos[0]][pos[1]] = ' ';
        map[pos[0]][pos[1] - 1] = 'P';
        pos[1] -= 1;
    }
    return pos;
}

int *go_right(char **map, int *pos, int ch)
{
    if (ch == KEY_RIGHT && map[pos[0]][pos[1] + 1] != '#') {
        if (map[pos[0]][pos[1] + 1] == 'X' && map[pos[0]][pos[1] + 2] != '#')
            map[pos[0]][pos[1] + 2] = 'X';
        else if (map[pos[0]][pos[1] + 1] == 'X'
        && map[pos[0]][pos[1] + 2] == '#')
            return 0;
        map[pos[0]][pos[1]] = ' ';
        map[pos[0]][pos[1] + 1] = 'P';
        pos[1] += 1;
    }
    return pos;
}

int *go_up(char **map, int *pos, int ch)
{
    if (ch == KEY_UP && map[pos[0] - 1][pos[1]] != '#') {
        if (map[pos[0] - 1][pos[1]] == 'X' && map[pos[0] - 2][pos[1]] != '#')
            map[pos[0] - 2][pos[1]] = 'X';
        else if (map[pos[0] - 1][pos[1]] == 'X'
        && map[pos[0] - 2][pos[1]] == '#')
            return 0;
        map[pos[0]][pos[1]] = ' ';
        map[pos[0] - 1][pos[1]] = 'P';
        pos[0] -= 1;
    }
    return pos;
}

int *go_down(char **map, int *pos, int ch)
{
    if (ch == KEY_DOWN && map[pos[0] + 1][pos[1]] != '#') {
        if (map[pos[0] + 1][pos[1]] == 'X' && map[pos[0] + 2][pos[1]] != '#')
            map[pos[0] + 2][pos[1]] = 'X';
        else if (map[pos[0] + 1][pos[1]] == 'X'
        && map[pos[0] + 2][pos[1]] == '#')
            return 0;
        map[pos[0]][pos[1]] = ' ';
        map[pos[0] + 1][pos[1]] = 'P';
        pos[0] += 1;
    }
    return pos;
}

char **game_loop(char **map, WINDOW *window, char *str_map)
{
    int *pos = get_player_pos(map, get_nbr_row(str_map));
    int ch;

    wclear(window);
    for (int index = 0; index != get_nbr_row(str_map); index += 1) {
        addstr(map[index]);
    }
    refresh();
    ch = getch();
    if (ch == 27) {
        noraw();
        echo();
        curs_set(1);
        endwin();
        exit(84);
    }
    pos = go_left(map, pos, ch);
    pos = go_right(map, pos, ch);
    pos = go_up(map, pos, ch);
    pos = go_down(map, pos, ch);
    refresh();
    return map;
}
