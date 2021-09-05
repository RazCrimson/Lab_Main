#! /bin/bash

numbers=(1 2 3 4 5 6 7 8 9 10)
squares=()

for num in ${numbers[@]}
do
  square=$((num * num))
  squares+=( $square )
done

echo Squares: ${squares[@]}

for i in ${!numbers[@]};
do
    echo ${numbers[$i]} - ${squares[$i]}
done
