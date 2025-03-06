-- load this file into the interpreter with ;l First.hs

-- square :: Integer -> Integer
square n = n * n

exOr :: Bool -> Bool -> Bool
exOr True x = not x
exOr False x = x

-- Running at around 30 will crash my laptop
fib :: Integer -> Integer
fib 0 = 0
fib 1 = 1
fib n = fib (n-2) + fib (n-1)




fibStep :: (Integer, Integer) -> (Integer, Integer)
fibStep (u, v) = (v, u+v)

fibPair :: Integer -> (Integer, Integer)
fibPair n
    | n==0 = (0, 1)
    | otherwise = fibStep (fibPair (n-1))

fastFib :: Integer -> Integer
fastFib = fst . fibPair  -- period means “function composition”

summation :: Integer -> Integer
summation 0 = 0
summation n = n + summation (n-1)

sumEach :: [Integer] -> [Integer]
sumEach list = [summation n | n <- list]

sumList :: [Integer] -> Integer
sumList [] = 0
sumList (x:xs)
    | null xs   = x
    | otherwise = x + sumList xs


-- used as addNum 5 9
-- would return 14
addNum :: Integer -> (Integer ->Integer)
addNum n = addN
   where
   addN m = n + m
-- to write this out step by step:
-- addNum 3 5
-- -> addN 5 ,where addN = 3 + n