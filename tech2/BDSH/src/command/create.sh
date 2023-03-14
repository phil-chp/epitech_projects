#!/bin/sh
##
## EPITECH PROJECT, 2022
## BDSH
## File description:
## create
##

create_database() {
    if [ -z "$BDSH_FILE" ]; then
        my_error "You forgot to mention a filename"
        export BDSH_ERRNO=1
    elif [ -f "$BDSH_FILE" ]; then
        my_error "already exists \"$BDSH_FILE\"."
        export BDSH_ERRNO=1
    else
        touch "$BDSH_FILE"
        printf "{\n\n}" > "$BDSH_FILE"
    fi
}

write_desc() {
    if grep -q "\"desc_$BDSH_WHERE\"" "$BDSH_FILE"; then
        my_error "Table name \"$BDSH_WHERE\" is already used."
        export BDSH_ERRNO=1
        return 1
    fi

    DESC="{\n  \"desc_$BDSH_WHERE\": [\n"
    ARGS=$(echo "$BDSH_ARGUMENTS" | tr "," " ")
    N=0

    for ARG in $ARGS; do
        if [ $N -gt 0 ]; then
            DESC="$DESC,\n"
        fi
        DESC="$DESC    \"$ARG\""
        N=$((N+1))
    done

    DESC="$DESC\n  ]"

    if grep -q "\"" "$BDSH_FILE"; then
        REGEXP="{\n/$DESC,\n"
    else
        REGEXP="{\n/$DESC"
    fi
    sed -i -z "s/$REGEXP/" "$BDSH_FILE"
}

create_table() {
    if [ -z "$BDSH_FILE" ]; then
        my_error "File \"$BDSH_FILE\" doesn't exist."
        export BDSH_ERRNO=1
    else
        write_desc
    fi
}

my_create() {
    if [ "$BDSH_OBJECT" = "database" ]; then
        create_database
    elif [ "$BDSH_OBJECT" = "table" ]; then
        create_table
    else
        my_error "Wrong argument after \"create\"."
    fi
}

get_create() {
    if [ -z "$2" ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
    else

        if [ "$2" = "database" ]; then
            export BDSH_COMMAND=my_create
            export BDSH_OBJECT="$2"
            export BDSH_SHIFT=2
        elif [ "$2" = "table" ]; then

            if [ "$#" -lt 4 ]; then
                my_error "Wrong number of arguments after \"$1\"."
                export BDSH_ERRNO=1
            else
                export BDSH_COMMAND=my_create
                export BDSH_OBJECT="$2"
                export BDSH_WHERE="$3"
                export BDSH_ARGUMENTS="$4"
                export BDSH_SHIFT=4
            fi

        fi

    fi
}
