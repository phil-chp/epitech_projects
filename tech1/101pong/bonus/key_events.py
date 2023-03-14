#!/usr/bin/env python
##
## EPITECH PROJECT, 2020
## key events
## File description:
## keypress events
##

import pygame
from random import randint

def key_events(event, player_s, proj_s, fps):
    if event.type == pygame.KEYDOWN:
        if event.key == pygame.K_LEFT:
            player_s = -0.35 * fps
        if event.key == pygame.K_RIGHT:
         player_s = 0.35 * fps

    if event.type == pygame.KEYUP:
        if event.key == pygame.K_LEFT and player_s < 0:
            player_s = 0
        if event.key == pygame.K_RIGHT and player_s > 0:
            player_s = 0
        if event.key == pygame.K_UP:
            if proj_s[0] == 0 and proj_s[1] == 0:
                proj_s[0] = randint(-5, 5)
                proj_s[1] = -0.4 * fps
    return player_s, proj_s

def exit_game(event, status, h):
    if event.type == pygame.QUIT:
        status = False
    return status