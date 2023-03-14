/*
** EPITECH PROJECT, 2022
** PDG-D6 (Workspace)
** File description:
** my_cat
*/

#include <iostream>
#include <fstream>

int my_cat(char *file)
{
    std::fstream fs;
    std::string str;
    char c;

    fs.open(file, std::ios::in);
    if (!fs.is_open()) {
        std::cerr
            << "my_cat: "
            << file
            << ": No such file or directory"
            << std::endl;
        return (1);
    }
    while (fs.get(c)) {
        std::cout << c;
    }
    fs.close();
    return (0);
}

int main(int ac, char **av)
{
    if (ac == 1) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (1);
    }
    for (int i = 1; i < ac; i++) {
        my_cat(av[i]);
    }
    return (0);
}
