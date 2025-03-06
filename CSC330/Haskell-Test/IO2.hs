main = interact (show . calculateDays . readInput)

readInput :: String -> Double
readInput x = read x :: Double

calculateDays :: Double -> Integer
calculateDays n = ceiling (logBase 2 n) + 1

solve :: Double -> Integer
solve _ = 5
