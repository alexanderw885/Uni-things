-- Is Integer in the list of Integers?
-- Example: elem 20 [3, 9, 15] == False
myElem :: Integer -> [Integer] -> Bool
myElem _ [] = False
myElem val (v:vs)
   | val == v   = True
   | otherwise  = myElem val vs


-- Elements in result are doubled
-- Example: doubleAll [20, -10, 0, 5] == [40, -20, 0, 10]
doubleAll :: [Integer] -> [Integer]
-- doubleAll list = [2 * n | n <- list]
-- doubleAll list = map (*2) list
doubleAll = map (* 2) -- map applies function to every element in list

-- Elements in result are even
-- Example: selectEven [3, 1, 4, 1, 59, 26, 53, 58] == [4, 26, 58]
selectEven :: [Integer] -> [Integer]
-- selectEven list = [n | n <- list, even n]
selectEven [] = []
selectEven (x:xs)
   | even x    = x:selectEven xs
   | otherwise = selectEven xs

-- Elements in result are those from start of list != Integer
-- Example: allBefore 5 [3, 1, 4, 1, 5, 9, 2, 6, 7] == [3, 1, 4, 1]
allBefore :: Integer -> [Integer] -> [Integer]
allBefore _ [] = []
allBefore n (x:xs)
   | n == x    = []
   | otherwise = x : allBefore n xs

-- Compute the weighted sum of two list of numbers
-- Example: weightedSum [10.0, 20.0, 30.0] [0.1, 0.3, 0.6] == 25.0
multTwoAccum (a, b) c = a * b + c
weightedSum :: [Double] -> [Double] -> Double
weightedSum xs ys = foldr multTwoAccum 0 (zip xs ys)
-- weightedSum [] [] = 0
-- weightedSum (x:xs) (y:ys) = x * y + weightedSum xs ys