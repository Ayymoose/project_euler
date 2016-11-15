module Practice where
import Data.List

--Very slow
zList = replicate 20 0
result = [n | n <- [1..] , (map (n `mod`) [1..20]) == zList] 

--This doesn't require any programming at all
--Can be done mathematically , if you know how
--Can you do any better?
