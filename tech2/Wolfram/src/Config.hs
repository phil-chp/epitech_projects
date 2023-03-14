module Config
    ( Conf(..)
    , defaultConf
    ) where

import Prelude hiding (lines)

data Conf = Conf {
    ruleset :: [Int],     -- from rule      -- Wolfram ruleset
    rule    :: Int,       --                -- Rule
    start   :: Maybe Int, -- 0              -- Gen to start on
    lines   :: Maybe Int, -- Infinity or -1 -- Height
    window  :: Maybe Int, -- 80             -- Widt
    move    :: Maybe Int  -- 0              -- Offset (- right + left)
}

defaultConf :: Conf
defaultConf = Conf {
    ruleset = [],
    rule    = -1,     -- bad argument
    start   = Just 0,
    lines   = Just (-1),
    window  = Just 80,
    move    = Just 0
}
