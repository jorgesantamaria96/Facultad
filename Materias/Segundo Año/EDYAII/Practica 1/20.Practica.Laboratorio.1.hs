module Practica0 where

import Data.List
import Data.Char

{-
1) Los siguientes códigos tienen errores, cargar el archivo 20.Practica.0.hs en el interprete de Haskell
GHCi, leer los mensajes de error y corregirlos hasta que el archivo se cargue correctamente.
-}

-- a)
{- regla b = case b of
    True -> "Quedate en Casa"
    False -> "Qudate en Casa" -}

regla :: Bool -> String
regla b = case b of True -> "Quedate en casa"
                    False -> "Qudate en casa"

regla' :: Bool -> String
regla' b | b         = "Quedate en Casa"
        | otherwise = "Qudate en Casa"

-- b)
{- case [x]         =  []
case (x:y:xs)      =  y : case (x:xs)
case []          =  [] -}

cAse :: [a] -> [a]
cAse []       = []
cAse [x]      = []
cAse (x:y:xs) = y : cAse (x:xs) 

-- c)
mapFunc :: (a -> a) -> [a] -> [a]
mapFunc f []         =  []
mapFunc f (x:xs)     =  f x : mapFunc f xs

-- d)
{- listNumeros = (1 : 2) : 'a' : [] 
    ERROR, las elementos de las listas tienen todos el mismo tipo.
    Elementos agrupados de forma incorrecta
-}

listNumeros :: (Num a) => [a] 
listNumeros = 1 : (2 : (3 : []))

-- e)
(++!) :: [a] -> [a] -> [a]
[]     ++! ys = ys
(x:xs) ++! ys = x : xs ++! ys

-- f)
-- Esta funcion agrega un elemento a la cola (al final)
addToTail :: a -> [a] -> [a]
addToTail x [] = [x]
addToTail x xs = head xs : addToTail x (tail xs)

-- Esta funcion devuelve la cola de xs y suma x a cada elemento
addToTail' :: Num a => a -> [a] -> [a]
addToTail' x xs = map (+x) (tail xs)

-- g)
listMin' xs = (head . sort) xs

listMin :: (Ord a) => [a] -> a
listMin [x] = x
listmin xs = head (sort xs)


-- h) (*)
smap :: (a -> a) -> [a] -> [a]
smap f [] = []
smap f [x] = [f x]
smap f (x:xs) = f x : smap f xs

{-
2. Definir las siguientes funciones y determinar su tipo:

a) five, que dado cualquier valor, devuelve 5

b) apply, que toma una función y un valor, y devuelve el resultado de
aplicar la función al valor dado

c) identidad, la función identidad

d) first, que toma un par ordenado, y devuelve su primera componente

e) derive, que aproxima la derivada de una función dada en un punto dado

f) sign, la función signo

g) vabs, la función valor absoluto (usando sign y sin usarla)

h) pot, que toma un entero y un número, y devuelve el resultado de
elevar el segundo a la potencia dada por el primero

i) xor, el operador de disyunción exclusiva

j) max3, que toma tres números enteros y devuelve el máximo entre llos

k) swap, que toma un par y devuelve el par con sus componentes invertidas
-}

-- a)

five :: a -> Int
five x = 5

-- b)

apply :: (a -> a) -> a -> a
apply f x = f x

-- c)

identidad :: a -> a
identidad x = x

-- d)

first :: (a,b) -> a
first (x,y) = x

-- e)

derive :: Double -> (Double -> Double) -> Double -> Double
derive a f x = (f(x+a) - f(x))/a

-- f)

sign :: (Ord a, Num a) => a -> Int
sign x | x > 0     = 1
       | x < 0     = -1
       | otherwise = 0

-- g)

vabs1 :: (Ord a, Num a) => a -> a
vabs1 x | (sign x) == 1    = x
        | (sign x) == (-1) = (-x)
        | otherwise        = 0

vabs2 :: (Ord a, Num a) => a -> a
vabs2 x | x >= 0    = x
        | otherwise = -x

-- h)

pot :: (Num a, Eq a) => a -> a -> a
pot 0 b = 1
pot a b = b * (pot (a-1) b)

-- i)

xor' :: Bool -> Bool -> Bool
xor' True False = True
xor' False True = True
xor' _ _        = False

-- j)

max3 :: (Ord a, Num a) => a -> a -> a -> a
max3 x y z = max' x (max' y z)

max' :: (Ord a, Num a) => a -> a -> a
max' x y = if x >= y then x else y

-- k)

swap' :: (a,b) -> (b,a)
swap' (x,y) = (y,x)

{-
3) Definir una función que determine si un año es bisiesto o no, de
acuerdo a la siguiente definición:

año bisiesto 1. m. El que tiene un día más que el año común, añadido al mes de febrero. Se repite
cada cuatro años, a excepción del último de cada siglo cuyo número de centenas no sea múltiplo
de cuatro. (Diccionario de la Real Academia Espaola, 22ª ed.)

¿Cuál es el tipo de la función definida?
-}

bisiesto :: Int -> Bool
bisiesto x | (mod x 4) == 0 && (mod x 100) /= 0 = True
           | (mod x 100) == 0 && (mod x 400) == 0 = True
           | otherwise = False

{-
4) Dar al menos dos ejemplos de funciones que tengan cada uno de los siguientes tipos:
a) (Int -> Int) -> Int
b) Int -> (Int -> Int)
c) (Int -> Int) -> (Int -> Int)
d) Int -> Bool
e) Bool -> (Bool -> Bool)
f) (Int,Char) -> Bool
g) (Int,Int) -> Int
h) Int -> (Int,Int)
i) a -> Bool
j) a -> a
-}

-- a)

fa1 :: Int -> Int
fa1 x = x + x

ej4a1 :: (Int -> Int) -> Int
ej4a1 fa1 = (fa1 3)

ej4a2 :: (Int -> Int) -> Int
ej4a2 fa1 = (fa1 2) + (fa1 3)

-- b)

fb1 :: Int -> Int
fb1 x = x + 3

ej4b1 :: Int -> (Int -> Int)
ej4b1 x = fb1

fb2 :: Int -> Int
fb2 x = x * x

ej4b2 :: Int -> (Int -> Int)
ej4b2 x = fb2

-- c)

fc :: Int -> Int
fc x = x * x * x

gc :: Int -> Int
gc x = x + 5

ej4c1 :: (Int -> Int) -> (Int -> Int)
ej4c1 fc = gc

ej4c2 :: (Int -> Int) -> (Int -> Int)
ej4c2 gc = fc

-- d)

ej4d1 :: Int -> Bool
ej4d1 x = x >= 2

ej4d2 :: Int -> Bool
ej4d2 x = if x == 7 then True else False

-- e)

fe1 :: Bool -> Bool
fe1 x = not x

ej4e1 :: Bool -> (Bool -> Bool)
ej4e1 x = fe1

fe2 :: Bool -> Bool
fe2 x = x || False

ej4e2 :: Bool -> (Bool -> Bool)
ej4e2 x = fe2

-- f)

ej4f1 :: (Int, Char) -> Bool
ej4f1 (x,y) = show x /= [y]

ej4f2 :: (Int, Char) -> Bool
ej4f2 (x,y) = (x == 7) && (y /= 'c')

-- g)

ej4g1 :: (Int, Int) -> Bool
ej4g1 (x,y) = (x > y)

ej4g2 :: (Int, Int) -> Bool
ej4g2 (x, y) = (x == y)

-- h)

ej4h1 :: Int -> (Int, Int)
ej4h1 x = (x, x+7)

ej4h2 :: Int -> (Int, Int)
ej4h2 x = (x + x, x - x)

-- i)

ej4i1 :: a -> Bool
ej4i1 x = True

ej4i2 :: a -> Bool
ej4i2 y = False

-- j)

ej4j1 :: a -> a
ej4j1 x = x

ej4j2 :: a -> a
ej4j2 x = let (y, z) = (x, x) in z

{-
5) Definir las siguientes funciones usando listas por comprensión:

a) 'divisors', que dado un entero positivo 'x' devuelve la
lista de los divisores de 'x' (o la lista vacía si el entero no es positivo)

b) 'matches', que dados un entero 'x' y una lista de enteros descarta
de la lista los elementos distintos a 'x'

c) 'cuadrupla', que dado un entero 'n', devuelve todas las cuadruplas
'(a,b,c,d)' que satisfacen a^2 + b^2 = c^2 + d^2,
donde 0 <= a, b, c, d <= 'n'

d) 'unique', que dada una lista 'xs' de enteros, devuelve la lista
'xs' sin elementos repetidos
unique :: [Int] -> [Int]
-}

-- a)

divisors x = [n | n <- [1..x], mod x n == 0]

-- b)

matches :: (Eq a ,Num a) => a -> [a] -> [a]
matches x ns = [n | n <- ns, n == x]

-- c)

cuadrupla :: (Eq a, Enum a, Num a) => a -> [(a,a,a,a)]
cuadrupla n = [(a,b,c,d) | a <- [0..n], b <- [0..n], c <- [0..n], d <- [0..n], a^2 + b^2 == c^2 + d^2 ]

-- d)

elem' :: (Num a, Eq a) => a -> [a] -> Bool
elem' n [] = False
elem' n (x:xs) = if x == n then True else elem n xs

unique :: (Num a, Ord a, Eq a) => [a] -> [a]
unique xs = [x | (x,i) <- zip xs [0..], not (elem' x (take i xs))]

{-
6) El producto escalar de dos listas de enteros de igual longitud
es la suma de los productos de los elementos sucesivos (misma
posición) de ambas listas.  Definir una función 'scalarProduct' que
devuelva el producto escalar de dos listas.

Sugerencia: Usar las funciones 'zip' y 'sum'. -}

prodTup :: (Eq a, Num a) => (a,a) -> a
prodTup (x,0) = 0
prodTup (0,y) = 0
prodTup (x,y) = x*y

sumList :: (Num a) => [a] -> a
sumList [] = 0
sumList (x:xs) = x + sumList xs

scalarProduct :: (Eq a, Num a) => [a] -> [a] -> a
scalarProduct xs [] = sumList xs
scalarProduct [] ys = sumList ys
scalarProduct xs ys = sumList (map prodTup (zip xs ys))

{-
7) Sin usar funciones definidas en el
preludio, defina recursivamente las siguientes funciones y
determine su tipo más general:

a) 'suma', que suma todos los elementos de una lista de números
-}

suma :: Num a => [a] -> a
suma [] = 0
suma (x:xs) = x + suma xs

{-
b) 'alguno', que devuelve True si algún elemento de una
lista de valores booleanos es True, y False en caso
contrario
-}

alguno :: [Bool] -> Bool
alguno [] = False
alguno (x:xs) = if x == False then alguno xs else True

{-
c) 'todos', que devuelve True si todos los elementos de
una lista de valores booleanos son True, y False en caso
contrario
-}

todos :: [Bool] -> Bool
todos [] = True
todos (x:xs) = if x == True then todos xs else False

{-
d) 'codes', que dada una lista de caracteres, devuelve la
lista de sus ordinales
-}

-- Puse como rango las letras del abecedario, mayúsculas y minúsculas

posicion :: (Eq a) => a -> [a] -> Int
posicion x ys = if elem x ys then aux x ys else 0
                        where aux x [] = 0
                              aux x (y:ys) | x == y = 1
                                           | otherwise = 1 + aux x ys

codes :: [Char] -> [Int]
codes [] = []
codes (x:xs) = 
        if estaEn x mayusculas
        then ((posicion x mayusculas) + 64) : codes xs
        else if estaEn x minusculas
        then ((posicion x minusculas) + 96) : codes xs
        else 0 : codes xs

codes_aux :: [Char] -> [Int]
codes_aux [] = []
codes_aux (x:xs) = (ord x) : codes_aux xs  

{-
e) 'restos', que calcula la lista de los restos de la
división de los elementos de una lista de números dada por otro
número dado
-}

modulo :: (Fractional a) => a -> a -> a
modulo x y = x - (y * (x/y))

restos :: (Fractional a) => [a] -> a -> [a]
restos [] n = []
restos (x:xs) n = modulo x n : restos xs n

{-
f) 'cuadrados', que dada una lista de números, devuelva la
lista de sus cuadrados
-}

cuadrados :: (Num a) => [a] -> [a]
cuadrados [] = []
cuadrados (x:xs) = (x ^ 2) : cuadrados xs

{-
g) 'longitudes', que dada una lista de listas, devuelve la
lista de sus longitudes
-}

longitud :: [a] -> Int
longitud [] = 0
longitud (x:xs) = 1 + longitud xs


longitudes :: [[a]] -> [Int]
longitudes [] = []
longitudes (xs:xss) = (longitud xs) : longitudes xss

{-
h) 'orden', que dada una lista de pares de números, devuelve
la lista de aquellos pares en los que la primera componente es
menor que el triple de la segunda
-}

orden :: (Num a, Ord a) => [(a,a)] -> [(a,a)]
orden [] = []
orden ((a,b):xs) 
        | a < 3 * b = (a,b) : orden xs
        | otherwise = orden xs

{-
i) 'pares', que dada una lista de enteros, devuelve la lista
de los elementos pares
-}

pares :: (Integral a, Eq a) => [a] -> [a]
pares [] = []
pares (x:xs) = if (mod x 2 == 0) then x : pares xs else pares xs

{-
j) 'letras', que dada una lista de caracteres, devuelve la
lista de aquellos que son letras (minúsculas o mayúsculas)
-}

mayusculas = [x | x <- ['A'..'Z']]
minusculas = [x | x <- ['a'..'z']]

estaEn :: (Eq a) => a -> [a] -> Bool
estaEn n [] = False
estaEn n (x:xs) = if n == x then True else estaEn n xs

letras :: [Char] -> [Char]
letras [] = []
letras (x:xs) = if (estaEn x mayusculas) || (estaEn x minusculas) then x : letras xs else letras xs

{-
k) 'masDe', que dada una lista de listas 'xss' y un
número 'n', devuelve la lista de aquellas listas de 'xss'
con longitud mayor que 'n' 
-}

masDe :: [[a]] -> Int -> [[a]]
masDe [] n = []
masDe (xs:xss) n = if (longitud xs) > n then xs : (masDe xss n) else masDe xss n 

{-
8) Redefinir las funciones del ejercicio anterior usando foldr, map y filter.
ver su definición en https://hoogle.haskell.org/
-}

{-
a) 'suma', que suma todos los elementos de una lista de números
-}

suma' :: (Num a) => [a] -> a
suma' xs = foldr (+) 0 xs

{-
b) 'alguno', que devuelve True si algún elemento de una
lista de valores booleanos es True, y False en caso
contrario
-}

alguno' :: [Bool] -> Bool
alguno' xs = foldr (||) False xs

{-
c) 'todos', que devuelve True si todos los elementos de
una lista de valores booleanos son True, y False en caso
contrario
-}

todos' :: [Bool] -> Bool
todos' xs = foldr (&&) True xs

{-
d) 'codes', que dada una lista de caracteres, devuelve la
lista de sus ordinales
-}

codes' :: [Char] -> [Int]
codes' xs = map (\x -> ord x) xs

{-
e) 'restos', que calcula la lista de los restos de la
división de los elementos de una lista de números dada por otro
número dado
-}

restos' :: (Integral a) => [a] -> a -> [a]
restos' [] n = []
restos' xs n = map (\x -> mod x n) xs
 
{-
f) 'cuadrados', que dada una lista de números, devuelva la
lista de sus cuadrados
-}

cuadrados' :: (Num a) => [a] -> [a]
cuadrados' [] = []
cuadrados' (x:xs) = map (\x -> x * x) xs 

{-
g) 'longitudes', que dada una lista de listas, devuelve la
lista de sus longitudes
-}

longitud' :: [a] -> Int
longitud' xs = foldr (\x y -> 1 + y) 0 xs

longitudes' :: [[a]] -> [Int]
longitudes' xss = map longitud' xss

{-
h) 'orden', que dada una lista de pares de números, devuelve
la lista de aquellos pares en los que la primera componente es
menor que el triple de la segunda
-}

orden' :: (Num a, Ord a) => [(a,a)] -> [(a,a)]
orden' [] = []
orden' xs = filter (\ (x,y) -> x < 3 * y) xs

{-
i) 'pares', que dada una lista de enteros, devuelve la lista
de los elementos pares
-}

pares' :: (Integral a) => [a] -> [a]
pares' xs = filter (\ x -> mod x 2 == 0) xs  

{-
j) 'letras', que dada una lista de caracteres, devuelve la
lista de aquellos que son letras (minúsculas o mayúsculas)
-}

letras' :: [Char] -> [Char]
letras' xs = filter (\ x -> (estaEn x mayusculas) || (estaEn x minusculas)) xs

{-
k) 'masDe', que dada una lista de listas 'xss' y un
número 'n', devuelve la lista de aquellas listas de 'xss'
con longitud mayor que 'n' 
-}

masDe' :: [[a]] -> Int -> [[a]]
masDe' xss n = filter (\ xs -> longitud' xs > n) xss