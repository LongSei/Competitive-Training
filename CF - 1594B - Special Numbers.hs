import Control.Monad
import Data.List
import Data.Bits

modulo = 10 ^ 9 + 7

bpow :: Int -> Int -> Int -> Int -> Int
bpow a b modu acc
  | b == 0 = acc
  | otherwise = bpow na nb modu nacc 
  where na = a * a `mod` modu
        nb = b `div` 2
        nacc = if even b then acc else (acc * a) `mod` modu

fastPow :: Int -> Int -> Int -> Int 
fastPow a b c = bpow a b c 1

process :: Int -> Int -> Int -> Int -> Int 
process n k timer acc | k == 0 = acc | otherwise = process n nk (timer + 1) nacc
                      where nk = div k 2
                            nacc = if even k then acc else mod (acc + fastPow n timer modulo) modulo 

solve = do
  a <- getLine
  let arr = words a
      n = read (head arr) :: Int 
      k = read (last arr) :: Int
  print(process n k 0 0 )

main = do
  entry <- getLine 
  let timer = read entry :: Int
  forM_ [1..timer] $ \_ -> do
    solve
