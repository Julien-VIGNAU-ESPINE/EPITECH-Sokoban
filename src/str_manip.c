/*
** EPITECH PROJECT, 2022
** str_manip.c
** File description:
** all manipulations with the str
*/

#include "../include/includes.h"

int get_nbr_row(char *string)
{
    int nbr_row = 1;

    for (int index = 0; index != my_strlen(string); index += 1) {
        if (string[index] == '\n')
            nbr_row += 1;
    }
    return nbr_row;
}

int get_nbr_col(char *string)
{
    int nbr_col = 0;
    int temp = 0;

    for (int index2 = 0; index2 != get_nbr_row(string); index2 += 1) {
        for (int index = 0; string[index] != '\n'; index += 1)
            nbr_col += 1;
        if (nbr_col > temp)
            temp = nbr_col;
    }
    return temp;
}

char *get_str_from_file(char *filename)
{
    FILE *f = fopen(filename, "rb");
    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *string = malloc(fsize + 1);

    fread(string, fsize, 1, f);
    fclose(f);
    string[fsize] = 0;
    return string;
}

int condition_get_x_pos(int index, int index2, char **map, int xy, int *pos)
{
    if (map[index][index2] == 'X') {
        pos[xy] = index;
        xy += 1;
        pos[xy] = index2;
        xy += 1;
    }
    return xy;
}

int *get_x_pos(char **map, int nbr_lines)
{
    int *pos = malloc(sizeof(int) * get_nbr_o(map, nbr_lines));
    int xy = 0;

    for (int index = 0; index != nbr_lines; index += 1) {
        for (int index2 = 0; map[index][index2] != '\n'; index2 += 1) {
            xy = condition_get_x_pos(index, index2, map, xy, pos);
        }
    }
    return pos;
}