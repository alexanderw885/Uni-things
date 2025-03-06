f (x, y) = (x, ['a' .. y]) -- We don't know what x could be, but since we can make a list ['a' .. y], y must be a char
 -- This could be declared as f :: (a, Char) -> (a, String)
g (m, zs) = m + length zs -- we know length zs is an int, and to put it into length, zs must be numeric
-- we can add m and a numeric, so m must be numeric, let's say Integer
-- g :: (Integer, [a]) -> Integer
h = g . f --whatever f returns is the input to g. in order for f to be passed into g, f must output (Integer, [a])
-- for f to output those types, x must be an integer. 
-- due to the definition of f, y must be a char.
-- Since we're passing a (Integer, String) into g, it will output an Integer
-- meaning that h :: (Integer, Char) -> Integer