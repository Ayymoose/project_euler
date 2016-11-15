module Problem16
where

digitSum :: Integer -> Integer
digitSum f = sum $ tearApart f
	where
	  tearApart :: Integer -> [Integer]
	  tearApart n 
	    | n /= 0    = tearApart (n `div` 10) ++ [n `mod` 10] 
	    | otherwise = []

