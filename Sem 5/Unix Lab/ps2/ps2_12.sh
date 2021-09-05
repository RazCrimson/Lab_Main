#! /bin/bash

while [ true ]; do
    echo "1. ENTER NEW RECORD "
    echo "2. REPORT ALL RECORDS "
    echo "3. EXIT"
    read -p "ENTER YOUR CHOICE " ch
    case $ch in
    1)
        sno="."
        mob="."
        fname="."
        sname="."
        addr="."
        ID="."

        read -p "Enter the entry number " index
        sno=$index
        read -p "Enter mobile number " mobno
        pat="[0-9]"
        if [ ${#num} -gt 10 ]; then
            echo "Enter valid phone number "
        else
            if [[ $mobno =~ $pat ]]; then
                mob=$mobno
            else
                echo "Enter valid phone number"
                exit
            fi
        fi
        read -p "Enter first name " firstname
        if [[ "${firstname}" =~ [a-zA-Z] ]]; then
            fname=$firstname
        else
            echo "Enter valid name"
            exit
        fi
        read -p "Enter second name " secondname
        if [[ "{$secondname}" =~ [a-zA-Z] ]]; then
            sname=$secondname
        else
            echo "Enter valid name"
            exit
        fi
        read -p "Enter Address " address
        addr=$address
        read -p "Enter id " id
        if [ ${#id} -gt 12 ]; then
            echo "Enter valid id "
            exit
        else
            if [[ "{$id}" =~ [0-9]{12} ]]; then
                ID=$id
            else
                echo "Enter valid id "
                exit
            fi
        fi
        echo "INDEX $sno " >>contacts.txt
        echo "PHONE NUMBER $mob " >>contacts.txt
        echo "FIRST NAME $fname " >>contacts.txt
        echo "SECOND NAME $sname" >>contacts.txt
        echo "ADDRESS $addr" >>contacts.txt
        echo "ID $id" >>contacts.txt
        ;;

    2)
        cat contacts.txt
        ;;
    3)
        exit
        ;;
    *) echo "Enter valid Choice" ;;
    esac
done
