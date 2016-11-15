module Problem6
where

sumSquares :: Int -> Int 
sumSquares n = sum [x^2 | x <- [1..n]]

squareSum :: Int -> Int
squareSum n = let s = (n `div` 2) * (n+1) in s*s

-- Beat that @ AM 10:35 18/11/14
