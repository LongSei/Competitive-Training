main = do
  entry <- getContents
  let ans = sum . map (\x -> if x!!1 == '+' then 1 else -1) . tail . lines $ entry
  print(ans)
