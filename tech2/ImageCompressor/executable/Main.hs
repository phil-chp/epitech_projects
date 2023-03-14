import System.Environment
import System.Exit()

import CustomTypes
import Config
import Utils
import InputData
import Maths

imageCompressor :: Conf -> String -> IO ()
imageCompressor (Conf n l _) str = do
    let myData = getInputData (lines str)
    let randomNumber = getCenterClusters n myData (length myData)
    m <- mapM (\x -> x) randomNumber
    let clusters = getRandomClusters m myData -- n
    let outputData = kMeans myData (l * 15.0) (initOutputDataList (clusters))
    showOutputData outputData

-- TODO: Test pour n=1 n=2 n=8 n=4 n=16
main :: IO ()
main = do
    args <- getArgs
    let opts = getOpts defaultConf args
    case opts of
        Nothing -> throwError "Invalid arguments"
        Just conf -> do
            checkArgs conf
            s <- readFile (file conf)
            imageCompressor conf s
