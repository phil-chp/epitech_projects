module Utils
    ( isInt
    , myFromMaybe
    , myReverse
    , myNth
    , myWhen
    , myStrip
    ) where

import Data.Char (isDigit)

-- Checks for an Int
isInt :: String -> Bool
isInt [] = True
isInt (x:xs)
    | x == '-' = isInt xs
    | otherwise = isDigit x && isInt xs

-- Litteraly just fromMaybe from Data.Maybe
-- but I don't know if the lib is allowed
myFromMaybe :: a -> Maybe a -> a
myFromMaybe v a = case a of {Nothing -> v;Just a'  -> a'}

-- Reverses [a]
myReverse :: [a] -> [a]
myReverse [] = []
myReverse (a : as) = myReverse as ++ [a]

-- gets nth element of a list
myNth :: [a] -> Int -> a
myNth [] _ = error "Error: Empty list"
myNth (a : _) 0 = a
myNth [a] n
    | n > length [a] - 1 = error "Error: Index out of range"
    | n < 0 = error "Error: Index out of range"
myNth (_ : as) n = myNth as (n - 1)

-- Taken from the Monad lib : when function
myWhen :: (Monad m) => Bool -> m () -> m ()
myWhen p s =  if p then s else return ()

-- returns nth first elements
myTake :: Int -> [a] -> [a]
myTake _ [] = []
myTake 0 _ = []
myTake n (a : as) = a : myTake (n - 1) as

-- all elements but first - tail
myTail :: [a] -> [a]
myTail [] = error "Error: Empty list"
myTail [a] = [a]
myTail (_ : as) = as

-- strips list of first and last element
myStrip :: [a] -> [a]
myStrip [] = []
myStrip a = myTake ((length a) - 2) (myTail a)
