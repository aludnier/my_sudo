/*
** EPITECH PROJECT, 2025
** B-CPE-110-PAR-1-1-bssecured-jean-francois2.villacorta-barbat (Workspace)
** File description:
** my_strlen
*/

int my_strlen(char const *str)
{
    int x = 0;

    while (str[x] != '\0')
        x++;
    return x;
}
