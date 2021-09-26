 
for entry in ${*}
do
    if [[ -d $entry ]]; then echo $entry is a Directory.; fi
    if [[ -f $entry ]]; then echo $entry is a file. Line Count: $(wc -l "$entry") ; fi
done

    