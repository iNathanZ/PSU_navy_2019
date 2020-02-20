/*
** EPITECH PROJECT, 2019
** navy
** File description:
** my_getnbr.c
*/

int my_getnbr(char *str)
{
    int ret = 0;

    for (int count = 0; str[count] != '\0'; count++)
        ret = (ret * 10) + (str[count] - 48);
    return (ret);
}