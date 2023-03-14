#!/bin/sh
##
## EPITECH PROJECT, 2022
## BDSH
## File description:
## create
##

DATA=""
ARGS=""

write_data() {

    ARGS=$(echo "$BDSH_ARGUMENTS" | tr "," " ")
    N=0

    MULTIPLES=$(echo "$ARGS" | tr ' ' '\n' | sed -e "s/=.*$//g"      \
        | sort  -d                                                   \
        | uniq -cd                                                   \
        | sed -e "s/  //g"                                           \
        | sed -e "s/ / times the key: /g")
    if [ -n "$MULTIPLES" ]; then
        ERROR_MESSAGE="$(\
            echo "You called multiple times the key(s):\n$MULTIPLES")"
        my_error "$ERROR_MESSAGE"
        export BDSH_ERRNO=1
        return 1
    fi


    if grep -q "\"data_$BDSH_OBJECT\"" "$BDSH_FILE"; then
        write_data_object ""
        REGEXP="\"data_$BDSH_OBJECT\"\:\s\[\n/&$DATA,\n"
    else
        DATA="  ],\n  \"data_$BDSH_OBJECT\": [\n"
        write_data_object ""
        DATA="\n$DATA\n  ]\n}"
        REGEXP="\n\s*\]\n}/$DATA"
    fi

    sed -i -z "s/$REGEXP/" "$BDSH_FILE"
}

write_data_object() {
    DATA="$1$DATA    {\n"
    N=0
    for ARG in $ARGS; do
        my_regexp="\"desc_$BDSH_OBJECT\":*[^\}\}]*?\"${ARG%=*}\""

        if ! grep -Pzoq "$my_regexp" "$BDSH_FILE" ; then
            my_error "Key \"${ARG%=*}\" doesn't exist in table \"$BDSH_OBJECT\""
            export BDSH_ERRNO=1
            continue
        fi

        if [ $N -gt 0 ]; then
            DATA="$DATA,\n"
        fi

        DATA="$DATA      \"$(echo "$ARG" | sed 's/=/": "/g')\""
        N=$((N+1))
    done

    DATA="$DATA\n    }"
}

my_insert() {
    if ! grep -q "\"desc_$BDSH_OBJECT\"" "$BDSH_FILE"; then
        my_error "Table \"$BDSH_OBJECT\" doesn't exist."
        export BDSH_ERRNO=1
        return 1
    fi

    write_data
}

get_insert() {
    if [ -z "$2" ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
        export BDSH_SHIFT=1
    fi

    if [ "$#" -lt 3 ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
        export BDSH_SHIFT=1
    else
        export BDSH_COMMAND=my_insert
        export BDSH_OBJECT="$2"
        export BDSH_ARGUMENTS="$3"
        export BDSH_SHIFT=3
    fi
}
