module Maths
    ( kMeans
    ) where

import CustomTypes
import Utils

-- Defaulting the following constraints to type ‘Integer’
euclidianDistance :: Color -> Color -> Int
euclidianDistance (Color x1 y1 z1) (Color x2 y2 z2) =
    let x = x1 - x2
        y = y1 - y2
        z = z1 - z2
        res = fromIntegral (x * x + y * y + z * z) :: Float
    in round $ sqrt $ res

-- ------------------------------- kMeans Begin ----------------------------- --

iterateCentroid :: Color -> [OutputData] -> Int -> Int -> Int -> Int
iterateCentroid _ [] tmpIndex _ _ = tmpIndex
iterateCentroid color [(OutputData c _)] tmpIndex tmpDistance iterator =
    if euclidianDistance color c < tmpDistance then iterator else tmpIndex
iterateCentroid color ((OutputData c _) : cs) tmpIndex 90000 iterator =
    iterateCentroid color cs tmpIndex (euclidianDistance color c) (iterator + 1)
iterateCentroid color ((OutputData c _) : cs) tmpIndex tmpDistance iterator = do
    let distance = euclidianDistance color c
    if distance < tmpDistance
        then iterateCentroid color cs iterator distance (iterator + 1)
        else iterateCentroid color cs tmpIndex tmpDistance (iterator + 1)

assignToCentroids :: InputData -> [OutputData] -> Int -> [OutputData]
assignToCentroids inputData centroids n =
    case centroids !! n of
        (OutputData c p) ->
            replaceInList n centroids (OutputData c (inputData : p))

kMeansBegin :: [InputData] -> [OutputData] -> [OutputData]
kMeansBegin [] cl = cl
kMeansBegin ((InputData p c) : ds) cl =
    kMeansBegin ds $ assignToCentroids (InputData p c) cl (iterateCentroid c cl 0 90000 0)

-- ----------------------------- KMeans Iterate ----------------------------- --

assignToNwCluster :: [OutputData] -> [OutputData] -> [OutputData]
assignToNwCluster [] nwClusters = nwClusters
assignToNwCluster [(OutputData _ p)] nwClusters =
    assignToNwCluster [] $ kMeansBegin p nwClusters
assignToNwCluster ((OutputData _ p) : cs) nwClusters =
    assignToNwCluster cs $ kMeansBegin p nwClusters

calcClusterCenter :: OutputData -> Int -> Color -> Color
calcClusterCenter (OutputData oldColor list) len (Color r g b)
    | length list == 0 = if r /= 0
        then Color (r `div` len) (g `div` len) (b `div` len)
        else oldColor
calcClusterCenter (OutputData color list) len (Color r g b)
    | otherwise = case list of
        ((InputData _ (Color r' g' b')):xs) -> do
            let newColor = Color (r + r') (g + g') (b + b')
            calcClusterCenter (OutputData color xs) (len + 1) newColor
        _ -> error "calcClusterCenter: list is empty"


chooseNwClusterCenter :: [OutputData] -> [OutputData] -> [OutputData]
chooseNwClusterCenter [] nwClusters = nwClusters
chooseNwClusterCenter ((OutputData c list) : cs) nwClusters = do
    let newColor = calcClusterCenter (OutputData c list) 0 (Color 0 0 0)
    chooseNwClusterCenter cs ([(OutputData newColor [])] ++ nwClusters)

-- calcConvergence :: [OutputData] -> [OutputData] -> Float -> Float -> Float
-- calcConvergence [] _ converge len = converge / len
-- calcConvergence _ [] converge len = converge / len
-- calcConvergence ((OutputData c _) : cs) ((OutputData c' _) : cs') con l = do
--     let distance = fromIntegral (euclidianDistance c c') :: Float
--     calcConvergence cs cs' (con + distance) (l + 1.0)

kMeansIterate :: [OutputData] -> Float -> [OutputData]
kMeansIterate clusters convergence
    | convergence < 1.0 = clusters
    | otherwise = do
        let nwClusterCenter = chooseNwClusterCenter clusters []
        -- let nwConvergence = calcConvergence clusters nwClusterCenter 0.0 0.0
        let nwCluster = assignToNwCluster clusters nwClusterCenter
        -- if nwConvergence < convergence then nwCluster
        -- else kMeansIterate nwCluster (convergence - 1)
        kMeansIterate nwCluster (convergence - 1.0)

-- ------------------------------- KMeans ----------------------------------- --

kMeans :: [InputData] -> Float -> [OutputData] -> [OutputData]
kMeans inputData convergence out =
    kMeansIterate (kMeansBegin inputData out) convergence
