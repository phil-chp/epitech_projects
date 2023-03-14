{-# OPTIONS_GHC -Wno-incomplete-patterns #-}
--
-- EPITECH PROJECT, 2022
-- PGE-Rush1
-- File description:
-- PushswapChecker
--

import System.Exit
import System.Environment
import Data.Char
import Control.Monad


-- -- -- Tests -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

class Apply com where
    apply :: com -> ([Int], [Int]) -> ([Int], [Int])

data Command = Sa | Sb | Sc | Pa | Pb | Ra | Rb | Rr | Rra | Rrb | Rrr | Err
    deriving (Eq) 

instance Show Command where 
    show Sa = "sa"
    show Sb = "sb"
    show Sc = "sc"
    show Pa = "pa"
    show Pb = "pb"
    show Ra = "ra"
    show Rb = "rb"
    show Rr = "rr"
    show Rra = "rra"
    show Rrb = "rrb"
    show Rrr = "rrr"

instance Apply Command where
    apply Sa (la, lb) = (mySwap la, lb)
    apply Sb (la, lb) = (la, mySwap lb)
    apply Sc (la, lb) = (mySwap la, mySwap lb)
    apply Pa (la, lb) = myPush la lb False
    apply Pb (la, lb) = myPush la lb True
    apply Ra (la, lb) = (myRotate la, lb)
    apply Rb (la, lb) = (la, myRotate lb)
    apply Rr (la, lb) = (myRotate la, myRotate lb)
    apply Rra (la, lb) = (myRevRotate la, lb)
    apply Rrb (la, lb) = (la, myRevRotate lb)
    apply Rrr (la, lb) = (myRevRotate la, myRevRotate lb) 

-- -- -- Commands -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

confirmedCommands :: [Command]
confirmedCommands =
    [Sa, Sb, Sc, Pa, Pb, Ra, Rb, Rr, Rra, Rrb, Rrr]


myRotate :: [Int] -> [Int]
myRotate as = zipWith const (drop 1 (cycle as)) as

myRevRotate :: [Int] -> [Int]
myRevRotate as = zipWith const (drop (length as - 1) (cycle as)) as

mySwap :: [Int] -> [Int]
mySwap [] = []
mySwap [a] = [a]
mySwap (x:y:xs) = y:x:xs

-- True = pb
myPush :: [Int] -> [Int] -> Bool -> ([Int], [Int])
myPush [] bs True = ([], bs)
myPush as [] False = (as, [])
myPush (a:as) [] True = (as, [a])
myPush [] (b:bs) False = ([b], bs)
myPush (a : as) bs True = (as, a : bs)
myPush as (b:bs) False = (b:as, bs)

-- -- -- Operations -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

myDoOpClean :: [Command] -> ([Int], [Int]) -> ([Int], [Int])
myDoOpClean [] t = t
myDoOpClean (com:coms) (la, lb) = myDoOpClean coms (apply com (la, lb))

-- -- Checks -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

readInt :: String -> Int 
readInt [] = 0
readInt ('-':xs) = if myIsNum xs 
    then (read xs :: Int) * (-1)
    else 0
readInt xs = read xs :: Int

myIsNum :: [Char] -> Bool
myIsNum [] = False
myIsNum [x] = isDigit x
myIsNum (x:xs) = isDigit x && myIsNum xs

isSortedTup :: (Ord a) => ([a], [a]) -> Bool
isSortedTup ([], []) = True
isSortedTup (la, []) = isSorted la
isSortedTup ([], lb) = isSorted lb
isSortedTup (la, lb) = False

isSortedUp :: Ord a => [a] -> Bool
isSortedUp [] = True
isSortedUp [x] = True
isSortedUp (x:y:xs) = x <= y && isSortedUp (y:xs)

isSortedDown :: Ord a => [a] -> Bool
isSortedDown [] = True
isSortedDown [x] = True
isSortedDown (x:y:xs) = x >= y && isSortedDown (y:xs)

isSorted :: Ord a => [a] -> Bool
isSorted xs = isSortedUp xs || isSortedDown xs

checkArgs :: [String] -> IO ()
checkArgs [] = return ()
checkArgs (x:xs) =
    if myIsNum x || (head x == '-' && myIsNum (drop 1 x))
    then checkArgs xs
    else exitWith (ExitFailure 84)

getCommand :: String -> [Command] -> Command
getCommand [] _ = Err
getCommand str (com:coms) = if str == show com
    then com
    else getCommand str coms


buildCommand :: [String] -> [Command]
buildCommand [] = []
buildCommand (x:xs) = do
    let com = getCommand x confirmedCommands
    if com == Err 
        then [Err]
        else com : buildCommand xs

-- -- Algo -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --

main :: IO ()
main = do
    arg <- getArgs
    comandString <- getLine
    if not (null arg) then checkArgs arg else exitWith (ExitFailure 84)
    let commands = buildCommand (words comandString)
    when (commands == [Err]) (exitWith (ExitFailure 84))
    let result = myDoOpClean commands (fmap readInt arg, [])
    if isSorted (fst result) && null (snd result)
    then putStrLn "OK" >> exitWith ExitSuccess
    else putStr "KO : " >> print result >> exitWith ExitSuccess