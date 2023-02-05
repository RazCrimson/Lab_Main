-- Cleave1
evens (x : _ : xs) = x : evens xs
evens [] = []
evens [x] = [x]

odds [] = []
odds [x] = []
odds (_ : x : xs) = x : odds xs

cleave1 :: [a] -> ([a], [a])
cleave1 xs = (evens xs, odds xs)

-- Cleave2
cleave2' (eacc, oacc) [] = (eacc, oacc)
cleave2' (eacc, oacc) [x] = (x : eacc, oacc)
cleave2' (eacc, oacc) (x : x' : xs) = cleave2' (x : eacc, x' : oacc) xs

cleave2 :: [a] -> ([a], [a])
cleave2 xs = cleave2' ([], []) xs

-- Cleave3
evens' lst = [lst !! x | x <- [0, 2 .. 2 * ((1 + length lst) `div` 2) - 1]]

odds' lst = [lst !! x | x <- [1, 3 .. 2 * ((length lst) `div` 2) - 1]]

cleave3 lst = (evens' lst, odds' lst)

-- Cleave4
firstHalf lst count subSize
  | count == subSize = []
  | otherwise = (head lst) : firstHalf (tail lst) (count + 1) subSize

secondHalf lst count subSize
  | count == subSize = lst
  | otherwise = secondHalf (tail lst) (count + 1) subSize

cleave4 lst = (firstHalf lst 0 subSize, secondHalf lst 0 subSize)
  where
    subSize = ((1 + length lst) `div` 2)

-- Time Complexity of Cleave definitions
-- Worst case time complexity of cleave1 and cleave2 will be of the order of O(n)
-- But the worst case complexity of cleave3 would be of the order of O(n^2).
-- This is due ot the cleave3 using the `!!` operator to retreive each element.
-- The `!!` operator iterates the list from the start for each retreival leading to O(n^2).
-- The Worst case complexity of cleave4 will also be of order O(n) as it iterates the list
-- from both sides and meets at the middle

-- Merge1
merge1 :: (Ord a) => [a] -> [a] -> [a]
merge1 xs [] = xs
merge1 [] ys = ys
merge1 xs@(x : t) ys@(y : u)
  | x <= y = x : merge1 t ys
  | otherwise = y : merge1 xs u

-- Merge2
merge2 :: (Ord a) => [a] -> [a] -> [a]
merge2 xs [] = xs
merge2 [] ys = ys
merge2 xs@(x : t) ys@(y : u)
  | x <= y = x : merge2 t ys
  | x == y = x : y : merge2 t u
  | otherwise = y : merge2 xs u

-- Time Complexity of the merge definitions
-- Both the definition try to iterate through each element of the list once, the movement
-- happens to one list at a time, based on whichever list has the smallest element. Something
-- to be mentioned is that, this expects the lists to be already sorted to produce a sorted
-- final result list.

-- Efficieny
-- The second variation would have a slightly faster (due to less recursion) execution when
-- there are a considereable number of duplicated between the two lists.
