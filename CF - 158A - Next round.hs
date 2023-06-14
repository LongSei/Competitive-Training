import Control.Monad

main = do
  entry <- getContents
  let input = lines $ entry
  let ex = last input
      arr = words ex 
      arr' = map read arr :: [Int]
  let ex' = head input
      pos = words ex'
      pos' = read (last pos) :: Int
  let mid = arr' !! (pos' - 1)
      mid' = read (show mid) :: Int
  let ans' = filter (> 0) arr'
  let ans = filter (>= mid') ans'
  print(length ans)

