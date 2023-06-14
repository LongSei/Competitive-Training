import Control.Monad

value :: Int -> Int -> Int
value x y 
  | y * y > x = 0
  | otherwise = 1
isok :: Int -> Int -> String
isok x y = if ((value x y) == 1 && x `mod` 2 == y `mod` 2) then "YES" else "NO"

solve = do
  a <- getLine
  let b = words a
      number = read (head b) :: Int
      div3 = read (last b) :: Int
  putStrLn(isok number div3)


main = do
  entry <- getLine
  let input = read entry :: Int
  forM_ [1..input] $ \_ -> do
    solve
