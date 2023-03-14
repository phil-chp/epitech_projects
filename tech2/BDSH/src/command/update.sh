#!/bin/sh
##
## EPITECH PROJECT, 2022
## BDSH
## File description:
## create
##

my_update() {
    echo "update"
    # KEYS=$(echo "$BDSH_ARGUMENTS"                                   \
    #     | tr ',' '\n'                                               \
    #     | sed -e "s/=.*$//g"                                        \
    #     | tr '\n' ' ')
    # VALUES=$(echo "$BDSH_ARGUMENTS"                                 \
    #     | tr ',' '\n'                                               \
    #     | sed -e "s/^.*=//g"                                        \
    #     | tr '\n' ' ')
    # echo "$VALUES"
    # I=1
    # for K in $KEYS; do
    #     REGEXP="desc_$BDSH_OBJECT:.*[^\] \"$K:*,"
    #     sed -i -z -e "s/$REGEXP/${REGEXP%:*,}$(echo "$VALUES"          \
    #         | cut -d ' ' -f "$I")," "$BDSH_FILE"
    #     I=$((I + 1))
    # done
}

get_update() {
    if [ $# -lt 3 ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
    elif [ $# = 3 ]; then
        export BDSH_COMMAND=my_update
        export BDSH_OBJECT="$2"
        export BDSH_ARGUMENTS="$3"
    fi
}
