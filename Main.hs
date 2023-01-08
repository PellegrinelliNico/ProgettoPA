--MERGE SORT
--Preso una lista ne restituisce l'indice centrale (approssimato per eccesso)
half :: [a] -> Int
half l = length l `div` 2

--Fa il merge di due liste ordinate
merge :: Ord a => [a] -> [a] -> [a]
merge [] l = l
merge l [] = l 
merge (x:xs) (y:ys) = if x <= y 
                      then x : merge xs (y:ys)
                      else y : merge (x:xs) ys                   
--Merge sort
msort :: Ord a => [a] -> [a]
msort [] = []
msort [x] = [x]
msort l = let h = half l 
          in merge (msort (take h l)) (msort (drop h l))

--OPERAZIONI TRA STRINGHE E INTERI
--Trasforma ogni stringa in un intero pari al umero di volte in cui compare il carattere
countLett :: Char -> [String] -> [Int]
countLett _ [] = []
countLett c (s1:s) = [n1] ++ countLett c s 
                     where n1 = sum[1 | x <- s1, x == c]
--Trasforma un intero in una stringa composta dal carattere ripetuto n volte con tail recurtion
printLett :: Char -> Int -> String
printLett c n = printTail "" c n
                where printTail acc c n | n >= 1 = printTail (c:acc) c (n-1) 
                                        | otherwise = acc

--MAP SU INTERI
--Versione alternativa di map su liste di interi
eseguiOp :: (Int -> Int) -> [Int] -> [Int]
eseguiOp _ [] = []
eseguiOp op (i:is) = [op i] ++ eseguiOp op is

--MAIN
main = do
  putStrLn "Inesrisci la lettera da cercare: "
  input1 <- getLine
  putStrLn "Inesrisci la lista di stringhe in cui cercarla: "
  input2 <- getLine
  putStrLn "Inesrisci la lettera da stampare: "
  input3 <- getLine
  let letteraI = (read input1 :: Char)
  let lista = (read input2 :: [String])
  let letteraO = (read input3 :: Char)
  putStrLn "Risultato: "
  print(map (printLett letteraO) (msort (eseguiOp (\x -> x*2 + 2) (countLett letteraI lista))))

--Esempio di esecuzione
-- input1:    's'
-- input2:    ["sassari", "si", "sesto"]
-- input3:    'z'
-- countLett: [3,1,2]
-- eseguiOp:  [8,4,6]
-- msort:     [4,6,8]
-- printLett: ["zzzz","zzzzzz","zzzzzzzz"]