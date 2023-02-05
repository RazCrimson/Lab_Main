-- Using List Comprehension
deleteAll1 :: (Eq a) => a -> [a] -> [a]
deleteAll1 x y = [a | a <- y, a /= x]

-- Using functions in Haskell Prelude
deleteAll2 :: (Eq a) => a -> [a] -> [a]
deleteAll2 x y = filter (\a -> a /= x) y

-- Using Recursion
deleteAll3 :: (Eq a) => a -> [a] -> [a]
deleteAll3 _ [] = []
deleteAll3 x (y : ys) = if y == x then deleteAll3 x ys else y : deleteAll3 x ys

main =
  do
    let x = [1, 3, 3, 3, 3, 4, 4, 5, 3]
    putStr "Original List:"
    print x
    putStr "deleteAll by List Comprehension: "
    print (deleteAll1 3 x)
    putStr "deleteAll by functions in Haskell Prelude: "
    print (deleteAll2 3 x)
    putStr "deleteAll by Recursion: "
    print (deleteAll3 3 x)
