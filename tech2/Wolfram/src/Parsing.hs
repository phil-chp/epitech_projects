module Parsing
    (getOpts
    , getRuleset
    , checkArgs
    , decToBinArray
    , binArrayToDec
    , getRulesetIndex
    , fillArray
    , getFirstGen
    , printUsage
    ) where

import Prelude hiding (lines)
import System.Exit (ExitCode(ExitFailure), exitWith)

import Config ( Conf(..) )
import Utils ( isInt, myFromMaybe, myReverse )

-- Parameter parsing
getOpts :: Conf -> [String] -> Maybe Conf
getOpts conf [] = Just conf
getOpts conf (x : xs)
    | not $ isInt $ head xs = Nothing
    | x == "--rule"   = getOpts (conf {rule   =       read $ head xs :: Int }) (drop 1 xs)
    | x == "--start"  = getOpts (conf {start  = Just (read $ head xs :: Int)}) (drop 1 xs)
    | x == "--lines"  = getOpts (conf {lines  = Just (read $ head xs :: Int)}) (drop 1 xs)
    | x == "--window" = getOpts (conf {window = Just (read $ head xs :: Int)}) (drop 1 xs)
    | x == "--move"   = getOpts (conf {move   = Just (read $ head xs :: Int)}) (drop 1 xs)
    | otherwise = Nothing

-- Given conf takes rule and decomposes it into 8bit binary to get ruleset
getRuleset :: Maybe Conf -> Maybe Conf
getRuleset Nothing = Nothing
getRuleset (Just conf) = Just $ conf
    {ruleset = myReverse $ fillArray $ decToBinArray (rule conf)}

-- Checks if the arguments are valid TODO: Remove for bonus of 256 rules
checkArgs :: Conf -> IO()
checkArgs (Conf rs r s l w m)
    | r < 0 || r > 255 = callUsage "Rule must be between 0 and 255"
    | s < Just 0 = callUsage "Start must be greater than or equal to 0"
    | l < Just (-1) = callUsage "Lines must be greater than 0 or -1 (infinity)"
    | w < Just 0 = callUsage "Window must be greater than or equal to 0"
    | otherwise = return ()

-- Given an error message prints it then prints usage and exits
callUsage :: String -> IO ()
callUsage str = do
    putStrLn str
    putStrLn ""
    printUsage
    exitWith $ ExitFailure 84

printUsage :: IO ()
printUsage = do
    putStrLn "USAGE\n\t./wolfram --rule <rule> [OPTIONS]"
    putStrLn "\nRULE\t--rule\t\t<rule>\t\t(0-255)"
    putStrLn "\nOPTIONS"
    putStrLn "\t--start\t\t<generation>\t(by default 0)"
    putStrLn "\t--lines\t\t<height>\t(by default -1 (infinity))"
    putStrLn "\t--window\t<width>\t\t(by default 80)"
    putStrLn "\t--move\t\t<offset>\t(by default 0)"

-- given a decimal value, return the binary array
decToBinArray :: Int -> [Int]
decToBinArray 0 = []
decToBinArray n = decToBinArray (n `div` 2) ++ [n `mod` 2]

-- given a binary array, return the decimal value
binArrayToDec :: [Int] -> Int
binArrayToDec [] = 0
binArrayToDec (x:xs) = x + 2 * binArrayToDec xs

-- Given three numbers returns the binary value of the concat of these numbers
getRulesetIndex :: Maybe Int -> Maybe Int -> Maybe Int -> Int
getRulesetIndex x y z = binArrayToDec $ [myFromMaybe 0 z, myFromMaybe 0 y, myFromMaybe 0 x]

-- Fills an array by adding 0's at the front to fill in 8bits
fillArray :: [Int] -> [Int]
fillArray xs = replicate (8 - length xs) 0 ++ xs

-- Generates a list of zeros with an initial one at the closest non float center
getFirstGen :: Maybe Int -> Maybe Int -> [Int]
getFirstGen (Just 0) _ = []
getFirstGen n center
    | n == center = 1 : getFirstGen ((-) <$> n <*> Just 1) center
    | otherwise = 0 : getFirstGen ((-) <$> n <*> Just 1) center
