main = do
  input <- getContents
  print
    . sum
    . map ((\x -> if x>1 then 1 else 0) . sum . map read . words)
    . tail
    . lines
    $ input
