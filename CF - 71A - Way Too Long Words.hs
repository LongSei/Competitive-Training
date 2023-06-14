import Control.Monad
main = do
	t <- getLine
	let timer = read t :: Int
	let solve _ = do
	    entry <- getLine
	    let len = (length entry)
	    let first =(head entry)
	    	second = show (len - 2) 
	    	third =  (last entry)
	    	ans = first : second ++ [third]
	    if len <= 10 then putStrLn entry else putStrLn ans
	forM_ [1..timer] solve
