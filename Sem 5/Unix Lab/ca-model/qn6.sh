MAX_NUM=0
MAX_DIFF=0

if [[ ${#*} -eq 1 ]]; then echo "No args" && exit; fi

for entry in ${@}
do 
    if [[ $entry -ne $entry ]]; then echo "Not Number" && exit; fi
    if [[ $(wc -m <<< $entry) -ne 3 ]]; then echo "Not 2 digits" && exit; fi
    DIFF=$((a=$entry/10, b=$entry%10, a-b))
    if [[ $DIFF -lt 0 ]]; then DIFF=$((-$DIFF)); fi

    if [[ $DIFF -gt $MAX_DIFF ]];
    then    
        MAX_DIFF=$DIFF
        MAX_NUM=$entry
    fi

done

echo $MAX_NUM