module Practice where

maxNumOfList :: Int
maxNumOfList = 64

deadEnd :: Integer -> Int
deadEnd 169 = 3
deadEnd 363601 = 3
deadEnd 1454 = 3
deadEnd 871 = 3
deadEnd 45361 = 3
deadEnd 872 = 2
deadEnd 45362 = 2
deadEnd 2 = 1
deadEnd 40585 = 1
deadEnd n = error ("What the fuck? --> " ++ show n)

deadEnds :: [Integer]
deadEnds = [169, 363601, 1454, 871, 45361, 872, 45362, 2, 40585]

findNextNumber :: Integer -> Integer
findNextNumber
  = sum . map factorial . tearApart

factorial :: Integer -> Integer
factorial n = foldl (*) 1 [1..n]

tearApart :: Integer -> [Integer]
tearApart
  = reverse . map (flip mod 10) . takeWhile (>0) . iterate (flip div 10)

chains :: Integer -> [Integer]
chains = take maxNumOfList . iterate findNextNumber

numOfTerms :: Integer -> (Int, Integer)
numOfTerms n
  = (terms, n)
  where
    terms = termNum (chains n) 0

    termNum :: [Integer] -> Int -> Int
    termNum (x : xs) count
      | x `elem` deadEnds = count + deadEnd x
      | otherwise
        = termNum xs (succ count)
    termNum _ count = count

main :: IO()
main = do
  putStrLn (show $ length $ filter ((==60) . fst) $ map numOfTerms [1..1000000])
