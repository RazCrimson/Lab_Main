sumSquare :: Int -> Int
sumSquare x = sum [1 .. x] ^ 2

squareSum :: Int -> Int
squareSum x = sum [n ^ 2 | n <- [1 .. x]]

calcDiff :: Int -> Int
calcDiff x = sumSquare x - squareSum x

main =
  do
    putStr "The diff of sum of the squares of the first 100 natural numbers and the square of the sum: "
    print (calcDiff 100)
