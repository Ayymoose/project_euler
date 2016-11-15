module PE485
where

f :: Integer -> Integer -> Integer
f k n = sum [n'^k | n' <- [1..n]]

s :: Integer -> Integer -> Integer
s k n = sum (take n (iterate (f k n) 1))