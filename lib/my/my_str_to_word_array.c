/*
** EPITECH PROJECT, 2022
** bootstrap
** File description:
** my_str_to_world_array
*/

#include <stdlib.h>
#include "my.h"

static int count_words(const char *phrase)
{
    int result = 0;

    if (phrase == NULL || phrase[0] == '\0')
        return result;
    result = (my_isnum(phrase[0]) == 0) ? 0 : 1;
    for (int i = 1; phrase[i]; i++) {
        if (my_isnum(phrase[i]) == 1 && my_isnum(phrase[i - 1]) == 0)
            result++;
    }
    return result;
}

static int count_char(const char *src, int *index)
{
    int result = 0;

    for (; my_isnum(src[*index]) == 1 && src[*index] != '\0'; (*index)++) {
        result++;
    }
    (*index)++;
    return result;
}

static char *fill_word(const char *src, int nbr_char, int index)
{
    char *result = NULL;

    result = malloc(sizeof(char) * (nbr_char + 1));
    if (result == NULL)
        return NULL;
    for (int i = 0; i < nbr_char; i++)
        result[i] = src[(index - nbr_char - 1) + i];
    result[nbr_char] = '\0';
    return result;
}

char **my_str_to_word_array(const char *src)
{
    char **result = NULL;
    int nbr_words = count_words(src);
    int index = 0;
    int nbr_char = 0;

    if (!nbr_words)
        return NULL;
    result = malloc(sizeof(char *) * (nbr_words + 1));
    result[nbr_words] = NULL;
    for (int i = 0; i < nbr_words; i++) {
        nbr_char = count_char(src, &index);
        if (nbr_char == 0)
            i--;
        else
            result[i] = fill_word(src, nbr_char, index);
    }
    return result;
}
