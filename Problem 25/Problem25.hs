module Problem25 where

fib = 0 : 1 : (zipWith (+) fib (tail fib))

main :: IO()
main = do
  putStrLn (show (length $ takeWhile (< 10^999) fib))