module InputData
    ( createColor
    , createPoint
    , convertStrToInputData
    , getInputData
    ) where

import Utils
import CustomTypes

createPoint :: String -> Point
createPoint s =
    let
        str = init (tail s)
        str2 = wordSplit (==',') str
        x = read (str2 !! 0) :: Int
        y = read (str2 !! 1) :: Int
    in
        Point x y

createColor :: String -> Color
createColor s =
    let
        str = init (tail s)
        str2 = wordSplit (==',') str
        x = read (str2 !! 0) :: Int
        y = read (str2 !! 1) :: Int
        z = read (str2 !! 2) :: Int
    in
        Color x y z

convertStrToInputData :: String -> InputData
convertStrToInputData str =
    InputData (createPoint $ head $ words str) (createColor $ (words str) !! 1)

getInputData :: [String] -> [InputData]
getInputData [] = []
getInputData (x:xs) = convertStrToInputData x : getInputData xs
