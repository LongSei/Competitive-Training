import Data.List
import Control.Monad

readInts = fmap (map read.words) getLine :: IO [Integer]

print1 [] [] = ""
print1 (x:xs) (y:ys) = (show x)++" "++(show y)++" " ++ print1 xs ys

main = do
  entry <- getLine
  let timer = read entry :: Int
  forM_ [1..timer] $ \_ -> do
    n <- readLn :: IO Int
    array <- readInts
    let sorted = sort array
        b = take n sorted
        c = take n $ reverse sorted
    let ans = print1 b c
    putStrLn(ans)
