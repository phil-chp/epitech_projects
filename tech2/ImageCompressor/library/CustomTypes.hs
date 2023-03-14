module CustomTypes
    ( Conf(..)
    , Point(..)
    , Color(..)
    , InputData(..)
    , OutputData(..)
    , defaultConf
    , showInputData
    , showOutputData
    , initOutputDataList
    ) where

-- _______________________________ Data types _______________________________ --

data Conf = Conf {
    nb_color  :: Int,   -- number of colors
    limit     :: Float, -- limit of convergence
    file      :: String -- file path
}

data Point = Point Int Int

data Color = Color Int Int Int

data InputData = InputData Point Color

data OutputData = OutputData Color [InputData]

-- _____________________________ Show instances _____________________________ --

instance Show Point where
    show (Point x y) = "(" ++ show x ++ "," ++ show y ++ ")"

instance Show Color where
    show (Color r g b) = "(" ++ show r ++ "," ++ show g ++ "," ++ show b ++ ")"

instance Show InputData where
    show (InputData point color) = show point ++ " " ++ show color

instance Show OutputData where
    show (OutputData cluster points) =
        "--\n" ++ show cluster ++ "\n-" ++
        concatMap (\input -> "\n" ++ show input) points

-- __________________________________________________________________________ --

defaultConf :: Conf
defaultConf = Conf {
    nb_color = 0,
    limit = 0.0,
    file = ""
}

showInputData :: [InputData] -> IO ()
showInputData [] = return ()
showInputData (x:xs) = do
    putStrLn $ show x
    showInputData xs

showOutputData :: [OutputData] -> IO ()
showOutputData [] = return ()
showOutputData (x:xs) = do
    putStrLn $ show x
    showOutputData xs

initOutputData :: Color -> OutputData
initOutputData color = OutputData color []

initOutputDataList :: [InputData] -> [OutputData]
initOutputDataList [] = []
initOutputDataList ((InputData _ c) : xs) =
    (initOutputData c) : initOutputDataList xs
