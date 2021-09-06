#! /bin/bash

while true; do
    printf "\n**** MENU ****\nEnter 1 for contents of /etc/passwd\nEnter 2 for list of logged in users\nEnter 3 for sum, product and factorial of the given number\nEnter 4 to find power of two cli arguments\nEnter anything else to exit\n"
    read -p "Enter your choice:" CHOICE

    case $CHOICE in
    1) cat /etc/passwd ;;

    2) echo "Logged-in Users: " $(users) ;;

    3)
        read -p "Enter the number: " NUMBER
        if ! [ "$NUMBER" ] || [ $NUMBER -ne $NUMBER ] 2>/dev/null; then echo "Invalid Number" && exit 0; fi

        declare -i SUM=0
        declare -i PRODUCT=1
        declare -i FACTORIAL=1

        NUM=$NUMBER
        while [ $NUM -gt 0 ]; do
            DIGIT=$(expr $NUM % 10)
            SUM=$(expr $SUM + $DIGIT)
            PRODUCT=$(expr $PRODUCT \* $DIGIT)
            NUM=$(expr $NUM / 10)
        done
        echo "Sum of digits: $SUM"
        echo "Product of digits: $PRODUCT"

        NUM=$NUMBER
        while [ $NUM -gt 0 ]; do
            FACTORIAL=$(expr $FACTORIAL \* $NUM)
            NUM=$(expr $NUM - 1)
        done
        echo "Factorial: $FACTORIAL"
        ;;
    4)
        read -p "Enter the number: " NUMBER
        if ! [ "$NUMBER" ] || [ $NUMBER -ne $NUMBER ] 2>/dev/null; then echo "Invalid Number" && exit 0; fi

        read -p "Enter the exponent: " EXP
        if ! [ "$EXP" ] || [ $EXP -ne $EXP ] 2>/dev/null; then echo "Invalid Number" && exit 0; fi
        
        declare -i RESULT=1
        while [ $EXP -gt 0 ]; do
            RESULT=$(expr $RESULT \* $NUMBER)
            EXP=$(expr $EXP - 1)
        done
        echo "$RESULT"
        ;;
    *) exit ;;
    esac

done
