module Problem20
where

factorialSum :: Integer -> Integer
factorialSum f = sum $ tearApart f
	where
	  tearApart :: Integer -> [Integer]
	  tearApart n 
	    | n /= 0    = tearApart (n `div` 10) ++ [n `mod` 10] 
	    | otherwise = []

factorial :: Integer -> Integer
factorial n = foldl1 (*) [1..n]
