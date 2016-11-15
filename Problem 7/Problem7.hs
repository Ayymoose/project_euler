module Problem7
where

import Data.List

-- Prime list of all primes under n
oList :: Integer -> [Integer]
oList n = (2 : filter odd [2..n])

mList :: Integer -> Integer -> [Integer]
mList l n = [x*n | x <- [3,5..(l `div` 3)] , x*n < l]

--Slow but works
--Inefficient
-- primeList :: Integer -> [Integer]
-- primeList n = let o = oList n in foldl (\\) o (map (mList n) $ drop 1 $ takeWhile (/= div n 3) o)

-- try this
primeList n = take n (nubBy (fmap (fmap (==0)) mod) [2..])