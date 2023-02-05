-- Using Prelude
import Data.List

deleteSecond1 :: (Eq a) => a -> [a] -> [a]
deleteSecond1 x [] = []
deleteSecond1 x [a] = [a]
deleteSecond1 x y = if length (elemIndices x y) >= 2 then take ((elemIndices x y) !! 1) y ++ drop (1 + ((elemIndices x y) !! 1)) y else y

-- Using Recursion
deleteFirst :: (Eq a) => a -> [a] -> [a]
deleteFirst _ [] = []
deleteFirst a (x : xs)
  | a == x = xs
  | otherwise = x : deleteFirst a xs

deleteSecond2 :: (Eq a) => a -> [a] -> [a]
deleteSecond2 _ [] = []
deleteSecond2 a (x : xs)
  | x == a = x : deleteFirst a xs
  | otherwise = x : deleteSecond2 a xs

main =
  do
    let x = [1, 2, 3, 3, 3, 4, 5]
    putStr "Original List:"
    print x
    putStr "deleteSecond by Prelude functions: "
    print (deleteSecond1 3 x)
    putStr "deleteSecond by Recursion: "
    print (deleteSecond2 3 x)
