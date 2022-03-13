/*
** EPITECH PROJECT, 2022
** includes.h
** File description:
** include
*/

#ifndef includes
#define includes

    #include "../lib/my/my.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <ncurses.h>

int center_display(char *str, int nbr_col, int nbr_row);
int get_nbr_row(char *string);
int get_nbr_col(char *string);
char *get_str_from_file(char *filename);
char **make_tab(char *str, FILE *fd);
int *get_player_pos(char **map, int nbr_lines);
int get_nbr_o(char **map, int nbr_lines);
int *get_o_pos(char **map, int nbr_lines);
char **game_loop(char **map, WINDOW *window, char *str_map);
int make_loop(char *str_map, FILE *fd);
int *get_player_pos(char **map, int nbr_lines);
int *get_x_pos(char **map, int nbr_lines);
int check_border(char **map, char *str);
int check_map(char *str);
int check_last(char **map, char *str);
int check_term(char *str);

#endif /* !includes */
