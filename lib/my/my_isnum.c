/*
** EPITECH PROJECT, 2022
** B-CPE-110-TLS-1-1-antman-julien.vignau-espine
** File description:
** my_isnum
*/

int my_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    return 0;
}
