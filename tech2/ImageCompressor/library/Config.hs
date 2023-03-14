module Config
    ( getOpts
    , checkArgs
    ) where

import Utils
import CustomTypes

getOpts :: Conf -> [String] -> Maybe Conf
getOpts z [] = Just z
getOpts (Conf n l f) (x : xs)
    | x == "-n" = case xs of
        [] -> Nothing
        (y : ys) -> if isNumber y
            then getOpts (Conf (read y) l f) ys else Nothing
    | x == "-l" = case xs of
        [] -> Nothing
        (y : ys) -> if isFloat y
            then getOpts (Conf n (read y :: Float) f) ys else Nothing
    | x == "-f" = case xs of
        [] -> Nothing
        (y : ys) -> getOpts (Conf n l y) ys
    | otherwise = Nothing

checkArgs :: Conf -> IO ()
checkArgs (Conf n l f)
    | n <= 0   = throwError "Number of colors must be positive"
    | l <= 0.0 = throwError "Convergence limit must be positive"
    | f == ""  = throwError "File path is missing"
    | otherwise = return ()
