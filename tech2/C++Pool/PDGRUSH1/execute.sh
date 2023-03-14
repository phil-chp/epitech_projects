#!/bin/bash

NUMS=$(python3 random_num $1)

./push_swap $NUMS | ./pushswap_checker $NUMS