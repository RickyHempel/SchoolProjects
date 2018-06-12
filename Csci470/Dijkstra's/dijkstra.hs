--Ricky Hempel
--Updated 6/12/2018
--Dijkstra's shortest path in Haskell

testGraph = [('a','b',4),('a','h',10),('b','c',8),('b','h',11),('c','d',7),('c','i',2),('c','f',4),('d','e',9),('d','f',14),('e','f',10),('f','g',2),('g','h',1),('g','i',6),('h','i',7)]

import Data.List
import Data.Ord

dijkstra g s t = (distance t q, reverse $ path s t $ q)
  where q = dijkstra' g t [(0, s, s)]

path :: Char -> Char -> [(Integer, Char, Char)] -> [Char]
path start current q =
  if current == start then current:[]
  else current:(path start (predecessor current q) q)

predecessor v ((d,x,y):qs)
  | v == x = y
  | otherwise = predecessor v qs

dijkstra' g t [] = []
dijkstra' g t ((d,v,p):qs)
  | v == t = (d,v,p):[]
  | otherwise = (d,v,p):dijkstra' g t relaxed_q
  where relaxed_q = relax v d g qs

--relax :: Char -> Integer -> [(Char, Char, Integer)] -> [(Integer, Char, Char)] -> [(Integer, Char, Char)]
relax vert dist g q = relax' vert dist ns q
  where ns = neighbors vert g

--relax' :: Char -> Integer -> [(Char, Char, Integer)] -> [(Integer, Char, Char)] -> [(Char, Char, Integer)]
relax' vert dist [] q = q
relax' vert dist ((_, v, d):ns) q = relax' vert dist ns new_q
  where new_q = update v vert (dist + d) q

distance :: Char -> [(Integer, Char, Char)] -> Integer
distance vert ((d,v,p):qs) =
  if vert == v then d else distance vert qs

neighbors :: Char -> [(Char, Char, Integer)] -> [(Char, Char, Integer)]
neighbors vert [] = []
neighbors vert ((v,w,d):gs)
  | vert == v = (v,w,d):(neighbors vert gs)
  | vert == w = (w,v,d):(neighbors vert gs)
  | otherwise = neighbors vert gs

update :: Char -> Char -> Integer -> [(Integer, Char, Char)] -> [(Integer, Char, Char)]
update vert pred dist [] = [(dist, vert, pred)]
update vert pred dist ((d,v,p):qs)
  | d <= dist && vert == v = (d,v,p):qs
  | dist < d && vert == v = (dist, v, pred):qs
  | dist < d = (dist , vert, pred):(d,v,p):(remove vert qs)
  | otherwise = (d,v,p):(update vert pred dist qs)

remove :: Char -> [(Integer, Char, Char)] -> [(Integer, Char, Char)]
remove vert [] = []
remove vert ((d,v,p):qs) =
  if vert == v then remove vert qs else (d,v,p):(remove vert qs)
