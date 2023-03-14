module Utils
    ( isNumber
    , isFloat
    , throwError
    , wordSplit
    , printUsage
    , replaceInList
    , getCenterClusters
    , getRandomClusters
    ) where

import System.Exit (exitWith, ExitCode(ExitFailure))
import System.IO (hPutStrLn, stderr)
import Data.Char (isDigit)
import System.Random (getStdRandom, randomR)

import CustomTypes

isNumber :: String -> Bool
isNumber [] = True
isNumber (x:xs) = (isDigit x || x == '-') && isNumber xs

isFloat :: String -> Bool
isFloat [] = True
isFloat (x:xs) = (isDigit x || x == '-' || x == '.') && isFloat xs

throwError :: String -> IO ()
throwError str =
    hPutStrLn stderr (str ++ "\n") >> printUsage >> exitWith (ExitFailure 84)

printUsage :: IO ()
printUsage =
    putStrLn "USAGE:\n\t./imageCompressor -n N -l L -f F\n\
    \\nOPTIONS:\n\tN\tnumber of colors in the final image\n\
    \\tL\tconvergence limit\n\
    \\tF\tpath to the file containing the colors of the pixels"

wordSplit :: (Char -> Bool) -> String -> [String]
wordSplit p s = case dropWhile p s of
    "" -> []
    s' -> w : wordSplit p s''
        where (w, s'') = break p s'

replaceInList :: Int -> [OutputData] -> OutputData -> [OutputData]
replaceInList index list element =
    take index list ++ [element] ++ drop (index + 1) list

chooseRandomPoint :: Int -> IO Int
chooseRandomPoint len = getStdRandom (randomR (0, (len) - 1))

getCenterClusters :: Int -> [InputData] -> Int -> [IO Int]
getCenterClusters 0 _ _ = []
getCenterClusters nb input len =
    chooseRandomPoint len : getCenterClusters (nb - 1) input len

getRandomClusters :: [Int] -> [InputData] -> [InputData]
getRandomClusters [] _ = []
getRandomClusters (p:ps) inputData =
    (inputData !! p) : getRandomClusters ps inputData

-- splitCluster :: Int -> [InputData] -> [[InputData]]
-- splitCluster 0 _ = []
-- splitCluster nb inputData = (take nb inputData)
-- : splitCluster (nb - 1) (drop nb inputData)

-- getRandomClusters :: [Int] -> Int -> [InputData] -> [InputData]
-- getRandomClusters randomNb list len = do
--     let listCluster = splitCluster len (sortClusters list)

-- getDistance :: InputData -> Float
-- getDistance (InputData _ (Color a b c)) = sqrt $ fromIntegral
-- (a * a + b * b + c * c) :: Float

-- sortClusters :: [InputData] -> [InputData]
-- sortClusters [] = []
-- sortClusters (x:xs) = sortClusters smaller ++ [x] ++ sortClusters larger
--     where
--         smaller = [y | y <- xs, getDistance y <= getDistance x]
--         larger = [y | y <- xs, getDistance y > getDistance x]
