import qualified Data.List
import qualified Data.Map
import qualified Data.Set
import Control.Monad

calc :: String -> String
calc [] = []
calc ('R':'?':xs) = 'R':(calc ('B':xs))
calc ('B':'?':xs) = 'B':(calc ('R':xs))
calc ('?':'R':xs) = 'B':(calc ('R':xs))
calc ('?':'B':xs) = 'R':(calc ('B':xs))
calc ('?':'?':xs) = calc ('?':(calc ('?':xs)))
calc ['?'] = ['B']
calc (x:xs) = x:(calc xs)

main = do
  entry <- getLine
  let timer = read entry :: Int
  forM_ [1..timer] $ \_ -> do
    n <- getLine
    array <- getLine
    putStrLn $ calc array
