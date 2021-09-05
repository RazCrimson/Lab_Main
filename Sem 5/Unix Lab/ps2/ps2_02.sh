#! /bin/bash
printf "BOOK MANAGEMENT SYSTEM\n\n"

DATA_FILE="books.dat"
CHOICE=$1

READ_BOOK_NAME() {
    read -p "Enter the Book name: " BOOK_NAME
    if [ -z "$BOOK_NAME" ]; then echo "Invalid Book name!" && exit 1; fi
}

READ_AUTHOR_NAME() {
    read -p "Enter the Author name: " AUTHOR_NAME
    if [ -z "$AUTHOR_NAME" ]; then echo "Invalid Author name!" && exit 1; fi
}

if [ -z $CHOICE ]; then
    printf "Enter 1 to enter a record\nEnter 2 to remove a record\nEnter 3 to list all books\nEnter 4 to list all books of an author\nEnter your choice: "
    read CHOICE
fi

case $CHOICE in
1)
    READ_BOOK_NAME
    READ_AUTHOR_NAME

    if ! [ -s "$DATA_FILE" ]; then
        touch "$DATA_FILE"
        INDEX_NUMBER=0
    fi

    if [ -z "$INDEX_NUMBER" ]; then INDEX_NUMBER=$(tail -n 1 "$DATA_FILE" | grep -o "^[0-9]\+"); fi

    if [ -z "$INDEX_NUMBER" ]; then echo "$DATA_FILE is corrupt" && exit 1; fi

    INDEX_NUMBER=$((INDEX_NUMBER + 1))
    printf "$INDEX_NUMBER\\t$BOOK_NAME\\t$AUTHOR_NAME\n" >>"$DATA_FILE"
    ;;

2)
    printf "Deleting by Book name\n"
    READ_BOOK_NAME

    if ! [ -f "$DATA_FILE" ]; then touch "$DATA_FILE"; fi

    grep -v "^[0-9]\+	$BOOK_NAME" "$DATA_FILE" >"$DATA_FILE.tmp"
    mv "$DATA_FILE.tmp" "$DATA_FILE"
    ;;

3)
    if ! [ -f "$DATA_FILE" ]; then touch "$DATA_FILE"; fi
    printf "ALL BOOKS\n"
    cut -f 2 "$DATA_FILE"
    ;;

4)
    if ! [ -f "$DATA_FILE" ]; then touch "$DATA_FILE"; fi

    printf "Listing books by Author\n"
    READ_AUTHOR_NAME

    printf "BOOKS BY $AUTHOR_NAME\n"
    grep "$AUTHOR_NAME$" "$DATA_FILE" | cut -f 2
    ;;

*)
    echo "Invalid Choice!"
    ;;
esac
