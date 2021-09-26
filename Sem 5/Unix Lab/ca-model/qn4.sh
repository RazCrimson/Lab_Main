
files=()

for file in ${@}
do
    if ! [ -f "$file" ]; then continue; fi
    files+=( $file )
done

for file_index in ${!files[*]}
do
    for file1 in ${files[*]:$file_index}
    do
        if [[ ${files[$file_index]} = $file1 ]]; then continue; fi
        
        cmp "${files[$file_index]}" "$file1" 1> /dev/null 2> /dev/null
        if [[ $? -eq 0 ]]; 
        then
            rm $file1
            ln ${files[$file_indesx]} $file1
            echo ${files[$file_index]} is linked ot by $file1

        fi
    done
done