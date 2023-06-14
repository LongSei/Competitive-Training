main = do 
  entry <- getContents
  let input = words . head . lines $ entry
      a = read (head input) :: Int
      b = read (last input) :: Int
      ans = a * b - (a * b `mod` 2)
  print(ans `div` 2)
