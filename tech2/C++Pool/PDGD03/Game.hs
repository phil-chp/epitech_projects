--
-- EPITECH PROJECT, 2022
-- PDG-D3
-- File description:
-- Game
--

-- -- Step 00 -- --

-- Task 01, 02, 03

data Item = Sword | Bow | MagicWand deriving (Eq)

instance Show Item where
    show Sword = "sword"
    show Bow = "bow"
    show MagicWand = "magic wand"

-- -- Step 01 -- --

-- Task 04

data Mob = Mummy
    | Skeleton Item
    | Witch (Maybe Item)
    deriving (Eq)

-- Task 05

createMummy :: Mob -- a Mummy
createMummy = Mummy

createArcher :: Mob -- a Skeleton holding a Bow
createArcher = Skeleton Bow

createKnight :: Mob -- a Skeleton holding a Sword
createKnight = Skeleton Sword

createWitch :: Mob -- a Which holding Nothing
createWitch = Witch Nothing

createSorceress :: Mob -- a Which holding a MagicWand
createSorceress = Witch (Just MagicWand)

-- Task 06

create :: String -> Maybe Mob
create str =
    case str of
        "mummy" -> Just Mummy
        "doomed archer" -> Just (Skeleton Bow)
        "dead knight" -> Just (Skeleton Sword)
        "witch" -> Just (Witch Nothing)
        "sorceress" -> Just (Witch (Just MagicWand))
        _ -> Nothing

-- Task 07

equip :: Item -> Mob -> Maybe Mob
equip _ Mummy = Nothing
equip item (Skeleton _) = Just (Skeleton item)
equip item (Witch _) = Just (Witch (Just item))

-- Task 08

instance Show Mob where
    show Mummy = "mummy"
    show (Skeleton Bow) = "doomed archer"
    show (Skeleton Sword) = "dead knight"
    show (Skeleton item) = "skeleton holding a " ++ show item
    show (Witch Nothing) = "witch"
    show (Witch (Just MagicWand)) = "sorceress"
    show (Witch (Just item)) = "witch holding a " ++ show item

-- Task 09

class HasItem mob where
    getItem :: mob -> Maybe Item
    hasItem :: mob -> Bool
    hasItem mob = case getItem mob of
        Nothing -> False
        Just _ -> True

-- Task 10

instance HasItem Mob where
    getItem Mummy = Nothing
    getItem (Skeleton item) = Just item
    getItem (Witch item) = item

    -- hasItem Mummy = False
    -- hasItem (Skeleton item) = True
    -- hasItem (Witch Nothing) = False
    -- hasItem (Witch (Just item)) = True
