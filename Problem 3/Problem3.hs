module Problem3 where

primeFactor :: Int -> [Int]
primeFactor 1 = []
primeFactor n 
  | even n    = 2 : primeFactor (n `div` 2)
  | otherwise = if factor > 0
                then factor: primeFactor (n `div` factor)
                else [n]
                  where 
                    r = floor $ sqrt (fromIntegral n)
                    factor = let d = [n `mod` k | k<-[3..r]] in if elem 0 d then (length $ takeWhile (/=0) d) + 3 else 0

--primeFactor 600851475143
--[71,839,1471,6857] 
