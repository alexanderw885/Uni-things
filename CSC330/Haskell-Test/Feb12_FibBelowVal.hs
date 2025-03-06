fibIndexBelowVal :: Integer -> Integer
fibIndexBelowVal n = fromIntegral (length result - 1)
   where
    result = takeWhile (<n) $
     0:1:[result!!(y-1) + result!!(y-2) | y <- [2..]]

-- 0 1 2 3 4 5 6  7  8
-- 0 1 1 2 3 5 8 13 21 

