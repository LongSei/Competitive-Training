isok x = if (x `mod` 2 == 0 && x > 2) then "YES" else "NO"
main = do
    entry <- getLine
    let input = (read entry :: Integer)
    putStr(isok input)
