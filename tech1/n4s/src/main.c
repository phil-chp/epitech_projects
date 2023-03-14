/*
** EPITECH PROJECT, 2021
** n4s (Workspace)
** File description:
** main
*/

#include <stdlib.h>
#include <stdio.h>
#include "ai.h"
#include "my.h"

bool handle_input(info_t *info)
{
    char *output = NULL;
    size_t size = 0;

    if (getline(&output, &size, stdin) == -1)
        return (1);
    output[size - 2] = '\0';
    if (main_parser(info, &output, ":"))
        return (1);
    free(output);
    return (0);
}

void check_values(info_t *lidar)
{
    if (lidar->id_status) {
        fprintf(stderr, "id: %d\n", lidar->id);
        fprintf(stderr, "status: %d\n", lidar->status);
    }
    if (lidar->type_cp) {
        for (size_t i = 0; i < lidar->type; i++)
            fprintf(stderr, "[%ld:%d] ", i, lidar->values[i]);
        if (lidar->type > 0) fprintf(stderr, "\n");
        fprintf(stderr, "cp_status: %d\n", lidar->cp.info);
    }
}


bool handle_speed(int speed)
{
    float value = 1.0f;

    switch(speed) {
        case 915 ... 1031:
            value -= 0.1f;
        case 1032 ... 1148:
            value -= 0.2f;
        case 1149 ... 1265:
            value -= 0.2f;
        case 1266 ... 1382:
            value -= 0.2f;
        case 1383 ... 1499:
            value -= 0.2f;
        default:
            break;
    }
    format_movement_string("CAR_FORWARD:", value);
    return (0);
}

void handle_angle(int f_value, int l_value)
{
    float value = 0.0f;
    int delta = f_value - l_value;

    if (delta > 50)
        value = delta % 200;
    // if (lidar->values[0] <= lidar->values[31] && lidar->values[18] <= 1266)
    //     my_putstr(WHEELS("-0.15"));                  // left : positive ; right : negative
    // // else if (lidar->values[0] > lidar->values[31])
    // //     my_putstr(WHEELS("0.1"));
    // else if (lidar->values[0] > lidar->values[31])
    // value = (side ? -value);
}

void handle_values(info_t *lidar)
{
    handle_speed(lidar->values[18]);
    handle_angle(lidar->values[0], lidar->values[31]);
}

int main(int ac, char **av)
{
    bool return_code = 0;
    info_t lidar;

    if (ac != 1 && av)
        return (84);
    my_putstr(START);
    my_putstr(FORWARD("1.0"));
    dump_terminal();
    lidar.stopped = false;
    lidar.values = NULL;
    while (return_code == 0) {
        my_putstr(LIDAR);
        lidar.type = THIRTY_TWO_FLOATS;
        if (lidar.stopped) {
            my_putstr(CYCLE_WAIT("5"));
            dump_terminal();
            break;
        }
        handle_input(&lidar);
        if (lidar.type > 0) check_values(&lidar);
        if (lidar.type_cp) handle_values(&lidar);
    }
    my_putstr(STOP);
    dump_terminal();
    free_lidar_values(&lidar.values);
    return (return_code ? 84 : 0);
}
