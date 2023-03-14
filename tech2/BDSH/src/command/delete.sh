#!/bin/sh
##
## EPITECH PROJECT, 2022
## BDSH
## File description:
## create
##

my_delete() {
    echo "delete"
}

get_delete() {
    if [ $# -lt 4 ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
    elif [ $# = 4 ]; then
        export BDSH_COMMAND=my_delete
        export BDSH_OBJECT="$2"
        export BDSH_WHERE="$4"
    fi
}
