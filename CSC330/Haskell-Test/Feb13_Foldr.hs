sumOfSquares :: Integer -> Integer
-- sumOfSquares n = foldr (+) 0 (map (^2) [1..n])
-- We can use function composition to merge the map function into foldr
sumOfSquares n 
   | n < 1  = 0
   | otherwise = foldr((+) . (^2)) 0 [1..n]


sumOfPositiveSquares :: [Integer] -> Integer
sumOfPositiveSquares list = foldr((+) . (^2)) 0 [n | n <- list, n >= 0]

myUnzip :: [(a,b)] -> ([a],[b])
myUnzip [] = ([],[])
myUnzip (x:xl) = (fst x:left, snd x : right)
    where
        (left, right) = myUnzip xl

foldrUnzip :: [(a,b)] -> ([a],[b])
foldrUnzip = foldr (\(l,r) (as, bs) -> (l:as, r:bs)) ([],[])
    where 
        separate (a,b) (as, bs) = (a:as, b:bs) -- not needed because lambda functions exist
