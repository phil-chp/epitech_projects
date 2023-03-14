#!/bin/sh
##
## EPITECH PROJECT, 2022
## BDSH
## File description:
## create
##

DESC=""
DATA=""
ALL_LENGTHS=""

print_head() {
    for KEY in $KEYS; do
        if [ "$I" -gt 0 ]; then
            printf "| "
        fi

        printf "%s" "$KEY"

        if [ "$I" -lt $((DESC_LEN - 1)) ]; then
            LOOP_LENGTH=$(echo -n "$ALL_LENGTHS" | cut -d ' ' -f $((I + 1)))
        else
            LOOP_LENGTH=-3
        fi

        TMP_LENGTH="$(echo "$KEY" | wc -m)"

        while [ $((TMP_LENGTH)) -lt $((LOOP_LENGTH + 3)) ]; do
            printf " "
            TMP_LENGTH=$((TMP_LENGTH + 1))
        done

        I=$((I + 1))
    done
}

print_line() {
    LINE_LENGTH=0

    for len in $ALL_LENGTHS; do
        LINE_LENGTH=$((LINE_LENGTH + len + 4))
    done

    Z=2

    while [ $Z -lt "$LINE_LENGTH" ]; do
        printf "-"
        Z=$((Z + 1))
    done
}

print_data() {
    for Data in $NEW_DATA; do
        Y=0

        for KEY in $KEYS; do
            SINGLE_DATA=$(echo -n "$Data"   \
                | tr ',' '\n'               \
                | grep -s "$KEY:*"          \
                | sed -e "s/$KEY://g")
            if [ $Y -gt 0 ]; then
                printf "|"
                if [ -n "$SINGLE_DATA" ] || [ "$Y" -lt $((DESC_LEN - 1)) ]; then
                    printf " "
                fi
            fi
            printf "%s" "$SINGLE_DATA"

            if [ "$Y" -lt $((DESC_LEN - 1)) ]; then
                LOOP_LENGTH=$(echo -n "$ALL_LENGTHS" | cut -d ' ' -f $((Y + 1)))
                else
                LOOP_LENGTH=-3
            fi

            TMP_LENGTH=$( (echo -n "$SINGLE_DATA" | wc -m) )

            while [ $((TMP_LENGTH)) -lt $((LOOP_LENGTH + 2)) ] ; do
                printf " "
                TMP_LENGTH=$((TMP_LENGTH + 1))
            done

            Y=$((Y + 1))
        done

        printf "\n"
    done
}

print_simple_select() {
    I=0
    DESC_LEN="$(echo "$KEYS" | wc -w)"

    print_head
    printf "\n"
    print_line
    printf "\n"
    print_data
}

get_lengths() {
    for KEY in $KEYS; do
        MAX_LENGTH=$(echo -n "$KEY" | wc -m)

        for D in $NEW_DATA; do
            SINGLE_DATA=$(echo -n "$D" \
                | tr ',' '\n'          \
                | grep -s "$KEY:*"     \
                | sed -e "s/$KEY://g")

            TMP_LENGTH=$(echo -n "$SINGLE_DATA" | wc -m)

            if [ "$TMP_LENGTH" -gt "$MAX_LENGTH" ]; then
                MAX_LENGTH="$TMP_LENGTH"
            fi
        done

        export ALL_LENGTHS="$ALL_LENGTHS$MAX_LENGTH "
    done
}

my_select_json() {
    J_DESC="$(grep -Pzo "\"desc_$BDSH_OBJECT\":*[^\]-\]]*\]" "$BDSH_FILE" | tr -d '\0')"
    J_DATA="$(grep -Pzo "\"data_$BDSH_OBJECT\":*[^\]-\]]*\]" "$BDSH_FILE" | tr -d '\0')"
    ARGS_TO_REMOVE="$DESC"
    ARGS=$(echo $BDSH_ARGUMENTS | tr ',' ' ')

    for ARG in $ARGS; do
        ARGS_TO_REMOVE=$(echo "$ARGS_TO_REMOVE" | sed "s/$ARG//gm" | tr '' ' ')
    done

    for ARG in $ARGS_TO_REMOVE; do
        J_DESC="$(echo "$J_DESC" | grep -vw "$ARG")"
        J_DATA="$(echo "$J_DATA" | grep -vw "$ARG")"
    done

    JSON_RESULT="$(echo "{\n  $J_DESC,\n  $J_DATA\n}\n" \
        | sed -z "s/,\n[[:blank:]]*\}/\n    \}/gm"      \
        | sed -z "s/,\n[[:blank:]]*\]/\n  \]/gm")"

    printf "$JSON_RESULT"
}

my_select() {
    if ! grep -q "\"desc_$BDSH_OBJECT\"" "$BDSH_FILE"; then
        my_error "Table \"$BDSH_OBJECT\" doesn't exist."
        export BDSH_ERRNO=1
        return 1
    fi

    KEYS=$(echo "$BDSH_ARGUMENTS" | tr ',' ' ')
    MULTIPLES=$(echo "$KEYS"                            \
        | tr ' ' '\n'                                   \
        | sort -d                                       \
        | uniq -cd                                      \
        | sed -e "s/  //g"                              \
        | sed -e "s/ / times the key: /g")
    if [ -n "$MULTIPLES" ]; then
        ERROR_MESSAGE="$(\
            echo -e "You called multiple times the key(s):\n$MULTIPLES")"
        my_error "$ERROR_MESSAGE"
        export BDSH_ERRNO=1
        return 1
    fi
    get_desc

    if [ $BDSH_ERRNO -gt 0 ]; then
        return 1
    fi

    if [ "$BDSH_DISPLAY" = "table" ]; then
        get_data
        get_lengths
        print_simple_select
    else
        my_select_json
    fi
}
# echo "Desc: [$KEYS] of length: ($KEYS_LEN)"
# echo "NEW_Data: [\n$NEW_DATA\n]"

get_desc() {
    DESC=$(grep -Pzo "\"desc_$BDSH_OBJECT\":*[^\]-\]]*" "$BDSH_FILE"  \
        | tr -d '\0[:blank:]'                                         \
        | cut -d '"' -f 2                                             \
        | sed -e "1d"                                                 \
        | tr '\n' ' ')

    for KEY in $KEYS; do
        if ! echo "$DESC" | grep -qw "$KEY"; then
            my_error "Key \"$KEY\" is not present in table \"$BDSH_OBJECT\"."
            export BDSH_ERRNO=1
            break
        fi
    done
}

get_data() {
    DATA=$(grep -Pzo "\"data_$BDSH_OBJECT\":*[^\]-\]]*" "$BDSH_FILE"  \
        | tr -d '\0[:blank:]'                                         \
        | tr -d '\{\},'                                               \
        | sed -e "1d"                                                 \
        | sed -e "1d"                                                 \
        | tr '\n' ','\
        | sed -e "s/,,,/ /g"\
        | sed -e "s/,,//g")

    for DA in $DATA; do
        I=1

        for K in $KEYS; do
            for D in $(echo "$DA" | tr ',' ' '); do
                KEY=$(echo "$D" | cut -d ':' -f 1 | cut -d '"' -f 2)
                VALUE=$(echo "$D" | cut -d ':' -f 2 | cut -d '"' -f 2)

                if [ "$K" = "$KEY" ]; then
                    if [ "$I" -lt $(echo "$KEYS" | wc -w) ]; then
                        C=","
                    else
                        C=" "
                    fi
                    NEW_DATA="$NEW_DATA$KEY:$VALUE$C"
                fi
            done

            I=$((I + 1))
        done
    done
}

get_options() {
    case $1 in
        where)
            if [ -z "$WHERE" ]; then
                export BDSH_WHERE="$2"
            else
                export BDSH_ERRNO=1
            fi
            ;;

        join)
            if [ -z "$JOIN" ]; then
                export BDSH_JOIN="$2"
            else
                export BDSH_ERRNO=1
            fi
            ;;

        orderby)
            if [ -z "$ORDER" ]; then
                export BDSH_ORDER="$2"
            else
                export BDSH_ERRNO=1
            fi
            ;;

        -j)
            export BDSH_SHIFT=3
            ;;

        -f)
            export BDSH_SHIFT=3
            ;;

        --file=*)
            export BDSH_SHIFT=3
            ;;

        *)
            export BDSH_ERRNO=1
    esac
}

get_select() {
    if [ $# -lt 3 ]; then
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
    elif [ $# -gt 6 ]; then
        export BDSH_COMMAND=my_select
        export BDSH_OBJECT="$2"
        export BDSH_ARGUMENTS="$3"
        get_options "$4" "$5"
        if [ "$BDSH_SHIFT" -eq 0 ]; then
            get_options "$6" "$7"
            if [ "$BDSH_SHIFT" -eq 0 ]; then
                export BDSH_SHIFT=7
            else
                export BDSH_SHIFT=5
            fi
        fi
        return 7
    elif [ $# -gt 4 ]; then
        export BDSH_COMMAND=my_select
        export BDSH_OBJECT="$2"
        export BDSH_ARGUMENTS="$3"
        get_options "$4" "$5"
        if [ "$BDSH_SHIFT" -eq 0 ]; then
            export BDSH_SHIFT=5
        fi
        return 5
    elif [ $# -gt 2 ]; then
        export BDSH_COMMAND=my_select
        export BDSH_OBJECT="$2"
        export BDSH_ARGUMENTS="$3"
        export BDSH_SHIFT=3
        return 3
    else
        my_error "Missing argument after \"$1\"."
        export BDSH_ERRNO=1
    fi
}
