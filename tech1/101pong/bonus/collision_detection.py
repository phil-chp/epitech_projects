#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## collision detection
## File description:
## collisions detection
##

from random import randint

def proj_player_col(proj, player, proj_s):
    if proj[1] >= player[1] and proj[1] <= player[1] + 16:
        if proj[0] >= player[0] and proj[0] <= player[0] + 64:
            proj_s[1] = -proj_s[1]
            proj_s[0] = -proj_s[0] + randint(-5, 5)

    if proj_s[0] == 0 and proj_s[1] == 0:
        proj[0] = player[0] + 24
        proj[1] = player[1] - 16
    return proj_s, proj

def proj_brick_col(Tx, Ty, proj, proj_s):
    (Tx[i][j], Ty[i][j], 64, 24)
    (proj[0] - 32, proj[1] - 32, 80, 80)

def player_bondaries(player, player_s, pos):
    if (player[0] + player_s >= pos[0] - 64):
        player[0] = pos[0] - 64
    elif (player[0] + player_s <= 0):
        player[0] = 0
    player[0] += player_s
    return player

def proj_boundaries(proj, proj_s, pos, player):
    h = 0

    if (proj[0] + proj_s[0] >= pos[0] - 16):
        proj_s[0] = -proj_s[0]
    elif (proj[0] + proj_s[0] <= 0):
        proj_s[0] = -proj_s[0]
    elif (proj[1] + proj_s[1] >= pos[1] - 16):
        proj[0] = player[0] + 24
        proj[1] = player[1] - 16
        proj_s[0] = 0
        proj_s[1] = 0
        h -= 1;
    elif (proj[1] + proj_s[1] <= 0):
        proj_s[1] = -proj_s[1]
    return proj_s, proj, h