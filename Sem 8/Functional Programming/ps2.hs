-- l = [1, 2, 3]

-- -- Qn 1
-- -- Find the last element of a list.
-- last l

-- -- Qn 2
-- -- Find the last but one element of a list.
-- l !! (length l - 2)


-- -- Qn 3
-- -- Find the Kth element of a list. The first element in the list is number 1.
-- nth k list = list !! (k - 1)
-- nth 2 l

-- -- Qn 4
-- -- Find the number of elements of a listBut.
-- length l


-- -- Qn 5
-- -- Reverse a list.
-- reverse l

-- Qn 6
-- Palindrome
isPalindrome:: String -> Bool
isPalindrome str = str == reverse str 

-- Qn 7
-- Flatten a list


-- Qn 8
-- Compress a list
compress :: Eq a => [a] -> [a]
compress (x : xs : xss)
    | x == xs   = compress (xs : xss)
    | otherwise = x : compress (xs : xss)
compress s = s

-- Qn 9
-- Compress a list into sublists of duplicate elements
pack :: Eq a => [a] -> [[a]]
pack (x:xs) = let (first, rest) = span (==x) xs in (x:first) : pack rest
pack [] = []

-- Qn 10
-- Encode lists resulting from prev qn with a length
encode :: Eq a => [a] -> [(a, Int)]
encode xs = map (\l -> (head l, length l)) (pack xs)

main :: IO()
main = do
  putStrLn "Enter the string for palindrome check :"
  input <- getLine
  putStr "Palindrome status: "
  print (isPalindrome input)

  putStrLn "Enter the input list (integers) below :"
  input <- getLine
  let inputList = read input :: [Int]

  putStr "Compressed List : "
  print (compress inputList)
  putStr "Packed List : "
  print (pack inputList)
  putStr "Encoded List : "
  print (encode inputList)
