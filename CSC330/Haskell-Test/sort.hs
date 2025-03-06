qsort :: [Integer] -> [Integer]
qsort [] = []
qsort (x:xs) -- x is the head value, xs is everything after the head
    = qsort [y | y <- xs, y <=x] 
    ++ [x] 
    ++ [y | y <- xs, y>x]
