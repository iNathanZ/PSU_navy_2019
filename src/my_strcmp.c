/*
** EPITECH PROJECT, 2019
** libmy
** File description:
** my_strcmp.c
*/

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (1) {
        if (s1[i] == '\0' && s2[i] == '\0') {
            return (0);
        }
        if (s1[i] == s2[i]) {
            i++;
            continue;
        }
        return (s1[i] - s2[i]);
    }
}
