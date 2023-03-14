--
-- EPITECH PROJECT, 2022
-- PDG-D3
-- File description:
-- Tree
--

-- -- Step 02 -- --

-- Task 11

data Tree a = Empty | Node (Tree a) a (Tree a) deriving (Show)

-- Task 12

addInTree :: Ord a => a -> Tree a -> Tree a
addInTree a Empty = Node Empty a Empty
addInTree a (Node left b right) =
    if a < b
    then Node (addInTree a left) b right
    else Node left b (addInTree a right)

-- Task 13

instance Functor Tree where
    fmap _ Empty = Empty
    fmap f (Node left a right) = Node (fmap f left) (f a) (fmap f right)

-- Task 14

listToTree :: Ord a => [a] -> Tree a
listToTree [] = Empty
listToTree (a : as) = addInTree a (listToTree as)

-- Task 15

treeToList :: Tree a -> [a]
treeToList Empty = []
treeToList (Node left val right) = treeToList left ++ [val] ++ treeToList right

-- Task 16

treeSort :: Ord a => [a] -> [a]
treeSort [] = []
treeSort a = treeToList (listToTree a)

-- Task 17

instance Foldable Tree where
    foldMap _ Empty = mempty
    foldMap f (Node left a right) =
        foldMap f left `mappend` f a `mappend` foldMap f right
