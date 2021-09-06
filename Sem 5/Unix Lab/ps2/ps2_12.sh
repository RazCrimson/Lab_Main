#! /bin/bash

DATA_FILE="contacts"

READ_INPUT() {
    read -p "$1" INPUT
    echo "$INPUT"
    if [[ -z "$INPUT" ]]; then echo "Invalid Input!" && exit 1; fi
}

while [ true ]; do
    printf "\n**** MENU ****\n1. Add a record\n2. List all records\n3. To Delete an entry\nAny other input to exit\n"
    read -p "Enter your choice : " ch

    case $ch in
    1)
        READ_INPUT "Enter the entry number "
        if ! [[ "$INPUT" =~ [0-9]+ ]]; then echo "Invalid Entry Number!" && exit 1; fi
        ENTRY_NUM=$INPUT

        READ_INPUT "Enter the mobile number "
        if ! [[ "$INPUT" =~ [0-9]{10} ]]; then echo "Invalid Mobile Number!" && exit 1; fi
        MOBILE_NUM=$INPUT

        READ_INPUT "Enter the First name : "
        if ! [[ "$INPUT" =~ [a-zA-Z\ ]+ ]]; then echo "Invalid First Name!" && exit 1; fi
        FIRST_NAME=$INPUT

        READ_INPUT "Enter the Last name : "
        if [[ ! "$INPUT" =~ [a-zA-Z\ ]+ ]]; then echo "Invalid Last Name!" && exit 1; fi
        LAST_NAME=$INPUT

        READ_INPUT "Enter the Address : "
        ADDRESS=$INPUT

        READ_INPUT "Enter the id : "
        ID=$INPUT

        printf "$ENTRY_NUM\\t$MOBILE_NUM\\t$FIRST_NAME\\t$LAST_NAME\\t$ADDRESS\\t$ID\n" >>"$DATA_FILE"
        ;;

    2)
        echo "**** DATA ****"
        cat "$DATA_FILE"
        ;;

    3)
        READ_INPUT "Enter the Entry to delete : "
        if ! [[ "$INPUT" =~ [0-9]+ ]]; then echo "Invalid Entry Number!" && exit 1; fi

        grep -v "^$INPUT" "$DATA_FILE" >"$DATA_FILE.tmp"
        mv "$DATA_FILE.tmp" "$DATA_FILE"
        ;;
    *) exit ;;
    esac
done
