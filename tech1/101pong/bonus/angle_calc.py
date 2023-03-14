#!/usr/bin/env python3
##
## EPITECH PROJECT, 2020
## bricks
## File description:
## the brick breaker game
##

from math import acos, sqrt, pi
from bricks_functions import security, define_points, vect, define_inter, define_time


def print_vel(vect_ab):
    print("The velocity vector of the ball is:")
    print("(%.2f, %.2f, %.2f)" % (vect_ab[0], vect_ab[1], vect_ab[2]))
    return


def print_time(n, a, vect_ab, n_time_vect):
    print("At time t + %d, ball coordinates will be:" % (n))
    if (n < 0):
        print("(%.2f, %.2f, %.2f)" % (a[0], a[1], a[2]))
    elif (n == 0):
        print("(%.2f, %.2f, %.2f)" % (vect_ab[0], vect_ab[1], vect_ab[2]))
    else:
        print("(%.2f, %.2f, %.2f)" % (n_time_vect[0], n_time_vect[1], n_time_vect[2]))
    return


def print_angle(a, b, vect_ab, alpha):
    if (abs(a[2]) >= 0) and (abs(b[2]) >= 0) and (abs(a[2]) > abs(b[2])) and (alpha != pi):
        print("The incidence angle is:")
        print("%.2f degrees" % (alpha))
    else:
        print("The ball won't reach the paddle.")
    return


def main():
    a, b, n = define_points()
    security(n)

    vect_ab = vect(a, b)

    n_time_vect = define_time(a, vect_ab, n)
    inter = define_inter(a, b, vect_ab)
    if inter == pi:
        norm_ia, norm_pi = pi, pi
    else:
        vect_ia = vect(a, inter)
        norm_ia = sqrt(vect_ia[0] ** 2 + vect_ia[1] ** 2 + vect_ia[2] ** 2)

        proj_a = (a[0], a[1], 0)
        vect_pi = vect(inter, proj_a)
        norm_pi = sqrt(vect_pi[0] ** 2 + vect_pi[1] ** 2 + vect_pi[2] ** 2)

    if (norm_ia == 0) or (norm_pi > norm_ia) or (norm_ia == pi):
        alpha = pi;
    else:
        alpha = (acos(norm_pi / norm_ia) * 180 / pi)

    print_vel(vect_ab)
    print_time(n, a, vect_ab, n_time_vect)
    print_angle(a, b, vect_ab, alpha)
    return 0


if __name__ == "__main__":
    main()