module Problem48
where

powerSum :: Integer -> Integer
powerSum n = sum [x^x | x <- [1..n]]

--reverse $ take 10 (reverse (show (powerSum 1000)))
