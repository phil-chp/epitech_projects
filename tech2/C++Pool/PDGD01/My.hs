--
-- EPITECH PROJECT, 2022
-- PDG-D1
-- File description:
-- My
--

-- -- Step 01 -- --

-- Task 01 - Increments by one

mySucc :: Int -> Int
mySucc x = x + 1

-- Task 02 - Is neg

myIsNeg :: Int -> Bool
myIsNeg x
    | x < 0 = True
    | otherwise = False

-- Task 03 - abs

myAbs :: Int -> Int
myAbs x
    | x < 0 = x * (-1)
    | otherwise = x

-- Task 04 - min of two

myMin :: Int -> Int -> Int
myMin x y
    | x < y = x
    | otherwise = y

-- Task 05 - max of two

myMax :: Int -> Int -> Int
myMax x y
    | x < y = y
    | otherwise = x

-- -- Step 02 -- --

-- Task 06 - two elements to tuple

myTuple :: a -> b -> (a, b)
myTuple a b = (a, b)

-- Task 07 - three elements to truple

myTruple :: a -> b -> c -> (a, b, c)
myTruple a b c = (a, b, c)

-- Task 08 - first element of tuple

myFst :: (a, b) -> a
myFst (a, b) = a

-- Task 09 - second element of tuple

mySnd :: (a, b) -> b
mySnd (a, b) = b

-- Task 10 - swaps tuple

mySwap :: (a, b) -> (b, a)
mySwap (a, b) = (b, a)

-- -- Step 03 -- --

-- Task 11 - first element - head

myHead :: [a] -> a
myHead [] = error "Error: Empty list"
myHead (a : _) = a

-- Task 12 - all elements but first - tail

myTail :: [a] -> [a]
myTail [] = error "Error: Empty list"
myTail [a] = [a]
myTail (_ : as) = as

-- Task 13 - length of list

myLength :: [a] -> Int
myLength [] = 0
myLength (_ : as) = myLength as + 1

-- Task 14 - get nth element of list

myNth :: [a] -> Int -> a
myNth [] _ = error "Error: Empty list"
myNth (a : _) 0 = a
myNth [a] n
    | n > myLength [a] - 1 = error "Error: Index out of range"
    | n < 0 = error "Error: Index out of range"
myNth (_ : as) n = myNth as (n - 1)

-- Task 15 - returns nth first elements

myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake n (a : as) = a : myTake (n - 1) as

-- Task 16 - returns list but nth first elements

myDrop :: Int -> [a] -> [a]
myDrop _ [] = []
myDrop 1 (_ : as) = as
myDrop n (_ : as) = myDrop (n - 1) as

-- Task 17 - appends list to list

myAppend :: [a] -> [a] -> [a]
myAppend [] b = b
myAppend (a : as) b = a : myAppend as b

-- Task 18 - reverse list

myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a : as) = myAppend (myReverse as) [a]

-- Task 19 - gets all elements but last

myInit :: [a] -> [a]
myInit [] = error "Error: Empty list"
myInit a = myTake (myLength a - 1) a

-- Task 20 - gets last element

myLast :: [a] -> a
myLast [] = error "Error: Empty list"
myLast [a] = a
myLast (_ : as) = myLast as

-- Task 21 - zips lists into list of tuples

myZip :: [a] -> [b] -> [(a, b)]
myZip (a : as) (b : bs) = (a, b) : myZip as bs
myZip _ _ = []

-- Task 22 - gets all elements but last

myUnzip :: [(a, b)] -> ([a], [b])
myUnzip [] = ([], [])
myUnzip ((a, b) : ts) = (a : myFst (myUnzip ts), b : mySnd (myUnzip ts))

-- -- Step 04 -- --

-- Task 23 - takes func and list and applies func to all els of list

myMap :: (a -> b) -> [a] -> [b]
myMap _ [] = []
myMap f (a : as) = f a : myMap f as

-- Task 24 - takes predicate and list and returns all True elements of list
-- Predicate - function that returns Bool value

myFilter :: (a -> Bool) -> [a] -> [a]
myFilter _ [] = []
myFilter f (a : as)
    | f a = a : myFilter f as
    | otherwise = myFilter f as

-- Task 25 - applies f on b and a and applies result to next step in list a

myFoldl :: (b -> a -> b) -> b -> [a] -> b
myFoldl _ b [] = b
myFoldl f n (a : as) = myFoldl f (f n a) as


-- Task 26 - same as myFoldl but with right to left

myFoldr :: (a -> b -> b) -> b -> [a] -> b
myFoldr _ b [] = b
myFoldr f b (a : as) = f a (myFoldr f b as)

-- Task 27 - partitions values of list into two lists depending on predicate val

myPartition :: (a -> Bool) -> [a] -> ([a], [a])
myPartition _ [] = ([], [])
myPartition f (a : as)
    | f a = (a : listOfTrue, listOfFalse)
    | otherwise = (listOfTrue, a : listOfFalse)
    where (listOfTrue, listOfFalse) = myPartition f as

-- Task 28 - sorts list depending on predicate value (grt than, sml than, etc)

myQuickSort :: (a -> a -> Bool) -> [a] -> [a]
myQuickSort _ [] = []
myQuickSort f (a : as) =
    let (l, g) = myPartition (f a) as
    in myAppend (myQuickSort f l) (a : myQuickSort f g)
