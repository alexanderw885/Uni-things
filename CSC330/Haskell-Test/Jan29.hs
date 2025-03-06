import Distribution.Simple.Utils (xargs)
applyMult :: Integer -> (a -> a) -> a -> a
applyMult 1 func applyTo = func applyTo
applyMult numTimes func applyTo = func (applyMult (numTimes-1) func applyTo)
-- applyMult numTimes func applyTo = (func . applyMult) (numTimes-1) func applyTo

applyMult2 :: Integer -> (a -> a) -> a -> a
applyMult2 n f x
  | n <= 0  = x
  | otherwise = f (applyMult2 (n-1) f x)

increment :: Integer -> Integer
increment n = n+1