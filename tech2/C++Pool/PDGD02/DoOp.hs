--
-- EPITECH PROJECT, 2022
-- PDG-D2
-- File description:
-- DoOp
--

-- -- Step 00 -- --

-- Task 01 - if el is in list returns True

myElem :: Eq a => a -> [a] -> Bool
myElem _ [] = False
myElem el (a : as)
    | el == a = True
    | otherwise = myElem el as

-- -- Step 01 -- --

-- Task 02 - safe division using maybe to check for divider being 0

safeDiv :: Int -> Int -> Maybe Int
safeDiv _ 0 = Nothing
safeDiv n m = Just (n `div` m)

-- Task 03 - gets nth element in list securely

safeNth :: [a] -> Int -> Maybe a
safeNth [] _ = Nothing
safeNth (a : _) 0 = Just a
safeNth [a] n
    | n > length [a] - 1 = Nothing
    | n < 0 = Nothing
safeNth (_ : as) n = safeNth as (n - 1)

-- Task 04 - secure successor

safeSucc :: Maybe Int -> Maybe Int
-- safeSucc (Just n) = Just (n + 1)
safeSucc (Just n) = fmap (+1) (Just n)
-- safeSucc (Just n) = Just n >>= (\_ -> Just (n+1))
safeSucc _ = Nothing

-- Task 05 - lookups in tuple list an el if matches returns just content

myLookup :: Eq a => a -> [(a, b)] -> Maybe b
myLookup _ [] = Nothing
myLookup n (a : as)
    | n == fst a = Just (snd a)
    | otherwise = myLookup n as

-- Task 06 - gets func and two maybe wrapped, returns the op of func on a and b

maybeDo :: ( a -> b -> c ) -> Maybe a -> Maybe b -> Maybe c
maybeDo f (Just a) (Just b) = Just (f a b)
maybeDo _ _ _ = Nothing

-- Task 07 - str to int if parsable else Nothing

checkNbr :: [Char] -> Int -> Bool
checkNbr [] _ = True
checkNbr ('-' : cs) 0 = checkNbr cs 1
checkNbr (c : cs) n
    | c >= '0' && c <= '9' = checkNbr cs (n + 1)
    | otherwise = False

readInt :: [Char] -> Maybe Int
readInt [] = Nothing
readInt str
    | checkNbr str 0 = Just (read str :: Int)
    | otherwise = Nothing

-- -- Step 02 -- --

-- Task 08 - reads stdin and returns input length

getLineLength :: IO Int
getLineLength = do
    str <- getLine
    return (length str)

-- Task 09 - reads stdin and returns stdin and input length

printAndGetLength :: String -> IO Int
printAndGetLength str =
    putStrLn str >>
    return (length str)

-- Task 10 - print a box of height n and length n x 2

myRepeat :: a -> [a]
myRepeat a = as
    where as = a : as

myRotate :: Int -> [a] -> [a]
myRotate n as = zipWith const (drop n (cycle as)) as

myReplBorder :: Int -> a -> a -> [a]
myReplBorder n c c' = myRotate 1 (c' : c' : take (n - 2) (myRepeat c))

printBoxHeight :: Int -> Int -> IO ()
printBoxHeight current n
    | n < 1 = return ()
printBoxHeight current n | n `elem` [1, current] =
    putStrLn (myReplBorder (current * 2) '-' '+') >>
    printBoxHeight current (n - 1)
printBoxHeight current n =
    putStrLn (myReplBorder (current * 2) ' ' '|') >>
    printBoxHeight current (n - 1)

printBox :: Int -> IO ()
printBox 1 = putStrLn "++"
printBox n
    | n > 1 = printBoxHeight n n
    | otherwise = putStr ""

-- Task 11 - given a number of lines (n) concats stdin n times

appendLines :: String -> Int -> IO String
appendLines str 0 = return str
appendLines str n = do
    newStr <- getLine
    appendLines (str ++ newStr) (n - 1)

concatLines :: Int -> IO String
concatLines n
    | n < 1 = return ""
concatLines n = appendLines "" n

-- Task 12 - getLine but in IO form

getInt :: IO (Maybe Int)
getInt = do
    str <- getLine
    return (readInt str)

-- Task 13 - bistro and eval expr

-- doOp :: Int -> Char -> Int -> IO Int
-- doOp a f b = do
--     do
--     let res = case f of
--         '+' -> a + b
--         '-' -> a - b
--         '*' -> a * b
--         '/' -> a `div` b
--         '%' -> a `mod` b
--     return 0
