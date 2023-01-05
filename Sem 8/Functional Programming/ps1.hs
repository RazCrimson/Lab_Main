-- Qn 1
-- Give another possible calculation for the result of double (double 2).
-- double (double 2)
-- = double 2 + double 2
-- = 4 + 4
-- = 8

-- Qn 2
-- Show that sum[x] = x for any number x.
-- sum [x] 
-- = sum (x:[]) 
-- = x + sum [] 
-- = x + 0 
-- = x

-- Qn 3
-- Define a function product that produces the product of a list of numbers, and show
-- using your definition that product [2, 3, 4] = 24.

multiplyList :: Num a => [a] -> a
multiplyList [] = 0
multiplyList (x:xs) = x * multiplyList xs


-- Qn 4
-- How should the definition of the function qsort be modified so that it produces a reverse
-- sorted version of a list?

-- Original Definition
qsort :: Ord a => [a] -> [a]
qsort [] = []
qsort (x : xs) = qsort lesser ++ [x] ++ qsort greater
  where
    lesser = filter (< x) xs
    greater = filter (>= x) xs

-- Modified definition
qsortR :: Ord a => [a] -> [a]
qsortR [] = []
qsortR (x : xs) =  qsortR greater ++ [x] ++ qsortR lesser
  where
    lesser = filter (< x) xs
    greater = filter (>= x) xs

-- Qn 5
-- What would be the effect of replacing ≤ by &lt; in the definition of qsort? Hint: consider
-- the example qsort [2, 2, 3, 1, 1].
-- Duplicate elements will end up getting missed

-- Qn 6
-- Parenthesise the following arithmetic expressions:
-- 2 ↑ 3 x 4 = (2 ^ 3) * 4
-- 2 x 3 + 4 x 5 = (2 * 3) + (4 * 5)
-- 2 + 3 x 4 ↑ 5 = 2 + (3 * (4 ^ 5))

-- Qn 8
-- The script below contains three syntactic errors. Correct these errors and then check
-- that your script works properly using Hugs.
-- Issues:
-- 1. Using Capital letter for function name
-- 2. Wrong Indentation
-- 3. Wrong Quotes were using for the div operator

-- Correct Solution:
n = a `div` length xs
  where
    a = 10
    xs = [1, 2, 3, 4, 5]


-- Qn 9
-- Show how the library function last that selects the last element of a nonempty list could
-- be defined in terms of the library functions introduced in this chapter. Can you think of
-- another possible definition?
last1 :: [a] -> a
last1 l = head (drop (length l - 1) l) 

last2 :: [a] -> a
last2 l = l !! (length l - 1)

-- Qn 10
-- Show how the library function init that removes the last element from a non-empty list
-- could similarly be defined in two different ways.
init1 :: [a] -> [a]
init1 l = reverse (tail (reverse l))

init2 :: [a] -> [a]
init2 l = reverse (drop 1 (reverse l))


main :: IO()
main = do
  putStrLn "Enter the input list below (min 3 elements) :"
  input <- getLine
  let inputList = read input :: [Int]
  putStr "Product of all elements of the list: "
  print (multiplyList inputList)
  
  putStr "Selecting the last element (builtin) : "
  print (last inputList)
  putStr "Selecting the last element (method1) : "
  print (last1 inputList)
  putStr "Selecting the last element (method2) : "
  print (last2 inputList)

  putStr "Dropping the last element (builtin) : "
  print (init inputList)
  putStr "Dropping the last element (method1) : "
  print (init1 inputList)
  putStr "Dropping the last element (method2) : "
  print (init2 inputList)