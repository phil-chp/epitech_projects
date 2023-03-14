/*
** EPITECH PROJECT, 2021
** n4s (Workspace)
** File description:
** ai
*/

#ifndef AI_H_
#define AI_H_

#define START           "START_SIMULATION\n"
#define STOP            "STOP_SIMULATION\n"

#define FORWARD(fl)     "CAR_FORWARD:"fl"\n"         // 0:1
#define BACKWARDS(fl)   "CAR_BACKWARDS:"fl"\n"       // 0:1
#define CYCLE_WAIT(i)   "CYCLE_WAIT:"i"\n"           // 0:INT_MAX
#define WHEELS(fl)      "WHEELS_DIR:"fl"\n"          // -1:1

#define WHEEL           "GET_CURRENT_WHEELS\n"
#define SPEED           "GET_CURRENT_SPEED\n"
#define SPEED_MAX       "GET_CAR_SPEED_MAX\n"
#define SPEED_MIN       "GET_CAR_SPEED_MIN\n"
#define LIDAR           "GET_INFO_LIDAR\n"
#define SIMTIME         "GET_INFO_SIMTIME\n"

#include <stdbool.h>

typedef enum type_id_e {
    NOT_LAUNCHED = 0,
    NO_ERROR,
    RUNNING,
    ERROR_NO_DETAILS,
    ERROR_CHECKPOINT = 5,
    FAILURE_NETWORK,
    ERROR_SERVER,
    ERROR_CLIENT,
    _EOF,
    END,
    EMPTY_COMMAND,
    UNKNOWN_COMMAND,
    WRONG_ARGUMENT,
    TOO_MANY_ARGS,
    PIPE_FAIL,
    UNEXPECTED_ARG_VALUE,
    FAILURE_CAMERA,
    COMMAND_NOT_FOUND,
    ALREADY_UP,
    CYCLE_DONE,
    FAILURE_SENSOR,
    NOT_ENOUGH_CP,
    FAILURE_TIMER_INIT,
    FAILURE_TIMER_GET,
    FAILURE_MAP_LOAD
} type_id_t;

typedef enum cp_info_e {
    NOTHING,
    FIRST_CP_CLEARED,
    CP_CLEARED,
    LAP_CLEARED,
    TRACK_CLEARED
} cp_info_t;

typedef enum values_e {
    EMPTY = 0,
    ONE_FLOAT = 1,
    TWO_LONG = 2,
    THIRTY_TWO_FLOATS = 32
} values_t;

typedef struct cp_s {
    cp_info_t info;           // checkpoint lap and track status
    short cp_num;               // -1 for last checkpoint
    unsigned long microseconds; // to transform from nano to micro
} cp_t;

typedef struct info_s {
    bool stopped;
    bool id_status;
    bool type_cp;
    type_id_t id;       // the return codes of the program
    bool status;        // OK or KO, let's check O or K, O == 0, K == 1
    values_t type;      // determines the type of the int * above mentioned
    int *values;        // either nothing or 32 floats or 1 float or two longs
    cp_t cp;       // checkpoint information
} info_t;

bool cp_parser(info_t *info, char ***tab, size_t pos);
bool values_parser(info_t *info, char ***tab, size_t pos);
bool main_parser(info_t *info, char **output, char *delim);

bool dump_terminal(void);
void free_tab(char ***tab);
void free_lidar_values(int **values);
bool format_movement_string(char *parameter, float value);

#endif /* AI_H_ */
