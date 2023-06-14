fastpow :: Integer -> Integer
fastpow 0 = 1
fastpow timer = (((fastpow (timer - 1) * 4) `mod` 1000000007) ^ 2) `mod` 1000000007

main = do
  entry <- getContents
  let n = read (head . lines $ entry) :: Integer
  let ans = (fastpow (n - 1) * 6) `mod` 1000000007
  print(ans)
