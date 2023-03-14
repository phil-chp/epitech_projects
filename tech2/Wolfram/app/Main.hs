--
-- EPITECH PROJECT, 2022
-- BSWolfram (Workspace)
-- File description:
-- Wolfram
--

module Main where
import System.Environment (getArgs)
import Prelude hiding (lines)
import System.Exit

import Config
import Parsing
import Utils

printGen :: [Int] -> IO ()
printGen [] = putStr "\n" >> return ()
printGen (x:xs)
    | x == 0 = putStr " " >> printGen xs
    | x == 1 = putStr "*" >> printGen xs

-- Given a generation, a cell and a maximum cell, returs a
-- tuple with the (left, center, right) cells.
getCells :: [Int] -> Int -> Maybe Int -> (Int, Int, Int)
getCells [] _ _ = (0, 0, 0)
getCells _ _ Nothing = (0, 0, 0)
getCells gen 0 _ = (0, head gen, gen !! 1)
getCells gen cell (Just maxCell)
    | cell + 1 == maxCell = (gen !! (cell - 1), gen !! cell, 0)
    | otherwise           = (gen !! (cell - 1), gen !! cell, gen !! (cell + 1))

loopCells :: Int -> [Int] -> Conf -> Int -> IO [Int]
loopCells nGen gen (Conf rs r s l w m) cell
    | ((-) <$> Just cell <*> w) == Just 0 = return []
    | otherwise = do
        let index = getRulesetIndex (Just left) (Just center) (Just right)
        let cellValue = rs !! index

        res <- loopCells nGen gen (Conf rs r s l w m) (cell + 1)
        return (cellValue : res)
        where (left, center, right) = getCells gen cell w

loopGens :: Int -> [Int] -> Conf -> IO ()
loopGens _ _ (Conf rs r s (Just 1) w m) = return ()
loopGens nGen gen (Conf rs r s l w m) = do
    newGen <- loopCells nGen gen (Conf rs r s l w m) 0
    myWhen (Just nGen >= s) (printGen (myStrip newGen))
    loopGens (nGen + 1) newGen (Conf rs r s ((-) <$> l <*> Just 1) w m)

main :: IO ()
main = do
    args <- getArgs
    let opts = getRuleset $ getOpts defaultConf args
    case opts of
        Nothing -> printUsage >> exitFailure
        Just (Conf rs r s l w m) -> do
            checkArgs (Conf rs r s l w m)
            let gen = getFirstGen w (div <$> w <*> Just 2)
            myWhen (s <= Just 0) (printGen (myStrip gen))
            loopGens 0 gen (Conf rs r s ((+) <$> l <*> s) w m)
