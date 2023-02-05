data Tree a = EmptyTree | Node a (Tree a) (Tree a) deriving (Show, Read, Eq)

instance Functor Tree where
  fmap f EmptyTree = EmptyTree
  fmap f (Node x leftsub rightsub) = Node (f x) (fmap f leftsub) (fmap f rightsub)

singleton :: a -> Tree a
singleton x = Node x EmptyTree EmptyTree

treeInsert :: (Ord a) => a -> Tree a -> Tree a
treeInsert x EmptyTree = singleton x
treeInsert x (Node a left right)
  | x == a = Node x left right
  | x < a = Node a (treeInsert x left) right
  | x > a = Node a left (treeInsert x right)

preOrder EmptyTree = []
preOrder (Node a left right) = [a] ++ preOrder (left) ++ preOrder (right)

inOrder EmptyTree = []
inOrder (Node a left right) = inOrder (left) ++ [a] ++ inOrder (right)

postOrder EmptyTree = []
postOrder (Node a left right) = postOrder (left) ++ postOrder (right) ++ [a]

main = do
  let x = foldr treeInsert EmptyTree [4, 5, 3, 2, 1, 6]
  putStr "Original List :"
  print x
  putStr "PreOrder: "
  print (preOrder (x))
  putStr "InOrder: "
  print (inOrder (x))
  putStr "PostOrder: "
  print (postOrder (x))
