module Problem1
where

sumMultiples :: Int -> Int
sumMultiples n = sum [x | x <- [1..n] , (mod x 5 == 0 || mod x 3 == 0) && x < n]
