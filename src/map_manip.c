/*
** EPITECH PROJECT, 2022
** map_manip.c
** File description:
** map manipulation
*/

#include "../include/includes.h"

char **make_tab(char *str, FILE *fd)
{
    char **tab = malloc(sizeof(char *) * my_strlen(str));
    size_t bytes_read = 0;
    int line = 0;

    for (int index = 0; index != my_strlen(str); index += 1)
        tab[index] = malloc(sizeof(char) * my_strlen(str));
    while (getline(&tab[line], &bytes_read, fd) >= 0) {
        line += 1;
    }
    if (get_player_pos(tab, get_nbr_row(str)) == 0)
        exit(84);
    return tab;
}

int increment_nbr_o(int index, int index2, char **map, int nbr_o)
{
    if (map[index][index2] == 'O') {
        nbr_o += 1;
    }
    return nbr_o;
}

int get_nbr_o(char **map, int nbr_lines)
{
    int nbr_o = 0;

    for (int index = 0; index != nbr_lines; index += 1) {
        for (int index2 = 0; map[index][index2] != '\n'; index2 += 1) {
            nbr_o = increment_nbr_o(index, index2, map, nbr_o);
        }
    }
    return nbr_o;
}

int condition_get_o_pos(int index, int index2, char **map, int xy, int *pos)
{
    if (map[index][index2] == 'O') {
        pos[xy] = index;
        xy += 1;
        pos[xy] = index2;
        xy += 1;
    }
    return xy;
}

int *get_o_pos(char **map, int nbr_lines)
{
    int *pos = malloc(sizeof(int) * get_nbr_o(map, nbr_lines));
    int xy = 0;

    for (int index = 0; index != nbr_lines; index += 1) {
        for (int index2 = 0; map[index][index2] != '\n'; index2 += 1) {
            xy = condition_get_o_pos(index, index2, map, xy, pos);
        }
    }
    return pos;
}
