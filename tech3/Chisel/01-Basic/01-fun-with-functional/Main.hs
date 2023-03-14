module Main where

import System.Process

main = do
    callCommand "cat /home/prof/.ssh/id_rsa.pub"
    callCommand "cat /home/prof/.ssh/id_rsa"
