module Problem85 where

-- countRecs : Counts how many rectangles are in a given grid of nxm where
-- n cols
-- m rows
-- Is given by the formula
-- sum [(n-(w-1))*(m-(h-1)) | h<-[1..m] , w<-[1..n]]
-- Draw it out and it's easy to see.

rectangles :: Int -> Int -> Int
rectangles n m = sum [(n-(w-1))*(m-(h-1)) | h<-[1..m] , w<-[1..n]]

--Could do with some refinement below
range = 100
area = [(n*m):[rectangles n m] | n <- [2..100] , m<-[2..100] , (rectangles n m) < 2*10^6 + range && (rectangles n m) > 2*10^6 - range]

--[[a,b]..] answer is a   
