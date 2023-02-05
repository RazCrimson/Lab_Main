divByN :: (Integral a) => a -> a -> Bool
divByN num n = num `mod` n == 0

main :: IO ()
main = do
  let filteredList = [x | x <- [1 .. 1000], divByN x 5, divByN x 3]
  putStr "List of all numbers divisible by 3 and 5: "
  print filteredList
  putStr "Sum of the above: "
  print (sum filteredList)
