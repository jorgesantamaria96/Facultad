------------------------------------------------
------------------------------------------------
------------------ CLASE -----------------------
------------------------------------------------
------------------------------------------------


-----------------------
--- Insertion sort ----
-----------------------

insert :: (Num a, Ord a) => a -> [a] -> [a]
insert x [] = []
insert x (y:t) = if x < y then (x:y:t)
                 else (y:insert y t)

isort :: (Num a, Ord a) => [a] -> [a]
isort [] = []
isort [x] = [x]
isort (x:t) = insert x (isort t)




------------------------------------------------
------------------------------------------------
----------------- PRACTICA ---------------------
------------------------------------------------
------------------------------------------------

-- EJERCICIO 1 --

five :: a -> Int
five _ = 5

apply :: (a -> a) -> a -> a
apply f x = f x

id :: a -> a
id x = x

first :: (a,b) -> a
first (x,_) = x

-- derive 

sign :: (Num a, Ord a) => a -> Int
sign x | x < 0 = -1
       | x == 0 = 0
       | otherwise = 1
       
absSign :: (Num a, Ord a) => a -> a
absSign x = if (sign x) == -1 then -x else x

abs :: (Num a, Ord a) => a -> a
abs x | x < 0 = -x
      | otherwise = x

pot :: (Num a, Ord a) => a -> a -> a
pot num 0 = 1
pot num exp = num * pot num (exp-1)

xor :: (Num a, Eq a) => a -> a -> a
xor x y = if x == y then 0 else 1

max1 :: (Num a, Ord a) => a -> a -> a
max1 a b = if a >= b then a else b

max3 :: (Num a, Ord a) => a -> a -> a -> a
max3 a b c = max1 (max1 a b) c

swap1 :: (a,b) -> (b,a)
swap1 (a,b) = (b,a)

-- EJERCICIO 2 --

-- a) --

f11 :: (Int -> Int) -> Int
f11 f = 0

f12 :: (Int -> Int) -> Int
f12 g = 5

-- b) --

f21 :: Int -> (Int -> Int)
f21 x = five

f22 :: Int -> (Int -> Int)
f22 y = sign

-- c) --

f31 :: (Int -> Int) -> (Int -> Int)
f31 absSign = five

f32 :: (Int -> Int) -> (Int -> Int)
f32 id = id

-- d) --

f41 :: Int -> Bool
f41 1 = False
f41 0 = True

f42 :: Int -> Bool
f42 0 = False
f42 _ = True

-- e) --

andBool :: Bool -> Bool -> Bool
andBool True True = True
andBool _ _       = False

notBool :: Bool -> Bool
notBool True = False
notBool False = True

idBool :: Bool -> Bool
idBool True = True
idBool False = False

f51 :: Bool -> (Bool -> Bool)
f51 True = notBool

f52 :: Bool -> (Bool -> Bool)
f52 _ = idBool

-- f) --

f61 :: (Int,Char) -> Bool
f61 (0, c) = True
f61 (_, c) = False

f62 :: (Int,Char) -> Bool
f62 (x, 'a') = True
f62 (x, _) = False

-- g) --

sumaInt :: Int -> Int -> Int
sumaInt x y = x+y

f71 :: (Int,Int) -> Int
f71 (x,y) = x

f72 :: (Int,Int) -> Int
f72 (x,y) = sumaInt x y

-- h) --

f81 :: Int -> (Int,Int)
f81 x = (x,x)

f82 :: Int -> (Int,Int)
f82 x = (pot x x, x*x)

-- i) --

f91 :: a -> Bool
f91 _ = True

f92 :: a -> Bool
f92 _ = False

-- j) --

f101 :: a -> a
f101 x = x

f102 :: a -> a
f102 x = x


-- EJERCICIO 3 --

-- a) --

--f x = let (y,z) = (x,x) 
--      in y

eje3a :: a -> a
eje3a x = x


-- b) --

-- greater (x,y) = if x > y then True else False

greater :: (Num a, Ord a) => a -> a -> Bool
greater x y | x > y = True
            | otherwise = False
            
-- c) --

-- f (x,y) = let z = x + y
--           in g (z,y)
--               where g (a,b) = a - b

eje3c :: Num a => (a,a) -> a
eje3c (x,y) = x

-- EJERCICIO 4 --

-- f :: c -> d
-- g :: a -> b -> c

-- h x y = f (g x y)

-- EJERCICIO 6 --

-- a) --

suma :: [Int] -> Int
suma [] = 0
suma (x:xs) = x + suma xs

-- b) --

alguno :: [Bool] -> Bool
alguno [] = False
alguno (x:xs) = if x == True then True else alguno xs

-- c) --

todos :: [Bool] -> Bool
todos [] = True
todos (x:xs) = if x == False then False else todos xs

-- d) --

oridinales = [('a',1),('b',2),('c',3),('d',4),('e',5),('f',6),('g',7),('h',8),('i',9),('j',10),('k',11),('l',12),('m',13),('n',14),('ñ',15),('o',16),('p',17),('q',18),('r',19),('s',20),('t',21),('u',22),('v',23),('w',24),('x',25),('y',26),('z',27)]

-- e) --

restos :: Integral a => a -> [a] -> [a]
restos 0 (x:xs) = []
restos n (x:xs) = ((mod x n) : restos n xs)

-- f) --

cuadrados :: (Num a, Ord a) => [a] -> [a]
cuadrados [] = []
cuadrados (x:xs) = (pot x 2) : cuadrados xs

-- g) --

cantidad :: (Num a) => [a] -> a
cantidad [] = 0
cantidad (x:xs) = 1 + cantidad xs

longitudes :: (Num a) => [[a]] -> [a]
longitudes [] = [0]
longitudes (xs:xss) = cantidad xs : longitudes xss

-- h) --

orden :: (Num a, Ord a) => [(a,a)] -> [(a,a)]
orden [] = []
orden ((x,y):xs) = if x < 3*y then ((x,y) : (orden xs)) else orden xs

-- i) --

pares :: (Num a, Integral a, Eq a) => [a] -> [a]
pares [] = []
pares (x:xs) = if mod x 2 == 0 then (x : pares xs) else pares xs

-- j) --

mayusculas = [x | x <- ['A'..'Z']]
minusculas = [x | x <- ['a'..'z']]

estaEn :: (Eq a) => a -> [a] -> Bool
estaEn y []     = False
estaEn y (x:xs) = if y == x then True else (estaEn y xs)

letras :: [Char] -> [Char]
letras []     = []
letras (x:xs) = if (estaEn x mayusculas) || (estaEn x minusculas) 
                then (x: letras xs)
                else letras xs

-- k) --

masDe :: (Num a, Ord a) => a -> [[a]] -> [[a]]
masDe n []       = []
masDe n (xs:xss) = if (cantidad xs) > n then (xs : (masDe n xss)) else masDe n xss

-- EJERCICIO 7 --

sum_escalar :: (Num a) => [(a,a)] -> a
sum_escalar ((x,y):xs) = (x*y) + sum_escalar xs

scalarProduct :: (Num a) => [a] -> [a] -> a
scalarProduct (x:xs) (y:ys) = sum_escalar zs
                            where zs = [ls | ls <- (zip xs ys)]
