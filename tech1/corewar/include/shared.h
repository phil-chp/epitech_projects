/*
** EPITECH PROJECT, 2021
** corewar (Workspace)
** File description:
** shared
*/

#ifndef SHARED_H_
#define SHARED_H_

#define HEX(n)  (n < 10 ? (48 + n) : (87 + n))

typedef union hex {
    struct {
        unsigned char x1 :4;
        unsigned char x2 :4;
    };
    unsigned char n;
} hex_u;

typedef union number {
    unsigned char c[4];
    int nb;
} number_u;

typedef union bin {
    struct {
        unsigned char d1 :2;
        unsigned char d2 :2;
        unsigned char d3 :2;
        unsigned char d4 :2;
    };
    struct {
        unsigned char b1 :1;
        unsigned char b2 :1;
        unsigned char b3 :1;
        unsigned char b4 :1;
        unsigned char b5 :1;
        unsigned char b6 :1;
        unsigned char b7 :1;
        unsigned char b8 :1;
    };
    unsigned char c;
} bin_u;

typedef struct bitchar_s {
    unsigned char c :2;
} bitchar_t;

char *my_str_to_hex(char *str, int size);

#endif /* SHARED_H_ */
