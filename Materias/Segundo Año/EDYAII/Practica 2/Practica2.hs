-- Ejercicio 1 --

data Color = A String Float Float Float

rojo = A "Rojo" 100 0 0
verde = A "Verde" 0 100 0
azul = A "Azul" 0 0 100

mezclar :: Color -> Color -> (Float, Float, Float)
mezclar (A _ n1 n2 n3) (A _ m1 m2 m3) = ((n1+m1)/2, (n2+m2)/2, (n3+m3)/2) 


-- Ejercicio 2 --

data Linea = B [Char] Int

linea2 = B "Quedate en casa" 5

vacia :: Linea
vacia = (B [] 0)

printLinea :: Linea -> [Char]
printLinea (B xs n) = ((++) ((++) (take n xs) "|") (drop n xs))

moverIzq :: Linea -> Linea
moverIzq (B xs 0) = (B xs 0)
moverIzq (B xs n) = (B xs (n-1))

moverDer :: Linea -> Linea
moverDer (B xs n) | n == (length xs) = (B xs n)
                  | otherwise = (B xs (n+1))
moverIni :: Linea -> Linea
moverIni (B xs n) = (B xs 0)

moverFin :: Linea -> Linea
moverFin (B xs n) = (B xs (length xs))

insertar :: Char -> Linea -> Linea
insertar c (B xs n) = (B ((++) ((++) (take n xs) [c]) (drop n xs)) (n+1))

borrar :: Linea -> Linea
borrar (B xs n) = (B ((++) (take (n-1) xs) (drop n xs)) (n-1))

-- Ejercicio 3 --

data CList a = EmptyCL | CUnit a | Consnoc a (CList a) a
                deriving(Show)
list0 = CUnit 2
list1 = Consnoc 1 list0 3
list2 = Consnoc 0 list1 4

tolist :: CList a -> [a]
tolist EmptyCL = []
tolist (CUnit x) = [x]
tolist (Consnoc x xs y) = (++) (x:(tolist xs)) [y]

headCL :: CList a -> a
headCL (CUnit x) = x
headCL (Consnoc x xs y) = x

tailCL :: CList a -> CList a
tailCL (CUnit x) = EmptyCL
tailCL (Consnoc x EmptyCL y) = CUnit y
tailCL (Consnoc x xs y) = (Consnoc (headCL xs) (tailCL xs) y)

isEmpty :: CList a -> Bool
isEmpty EmptyCL = True
isEmpty (CUnit x) = False
isEmpty (Consnoc x xs y) = False
           
isCUnit :: CList a -> Bool
isCunit EmptyCL = False
isCUnit (CUnit x) = True
isCUnit (Consnoc x xs y) = False

reverseCL :: CList a -> CList a
reverseCL EmptyCL = EmptyCL
reverseCL (CUnit x) = CUnit x
reverseCL (Consnoc x xs y) = Consnoc y (reverseCL xs) x

snocCL :: CList a -> a -> CList a
snocCL EmptyCL x = CUnit x
snocCL (CUnit x) y = (Consnoc x EmptyCL y)
snocCL (Consnoc x xs y) z = (Consnoc x (snocCL xs y) z)

consCL :: a -> CList a -> CList a
consCL x EmptyCL = CUnit x
consCL y (CUnit x) = (Consnoc y EmptyCL x)
consCL z (Consnoc x xs y) = (Consnoc z (consCL x xs) y)

inits :: CList a -> CList(CList a)
inits EmptyCL = EmptyCL
inits (CUnit x) = CUnit (CUnit x) 
inits l@(Consnoc x xs y) = snocCL (inits (consCL x xs)) l

lasts :: CList a -> CList(CList a)
lasts EmptyCL = EmptyCL
lasts (CUnit x) = (CUnit (CUnit x))
lasts l@(Consnoc x xs y) = consCL l (lasts (snocCL xs y))

cl :: CList a -> CList a -> CList a
(cl) EmptyCL x = x
(cl) x EmptyCL = x
(cl) (CUnit x) y = consCL x y
(cl) y (CUnit x) = snocCL y x
(cl) xs ys = (cl) (snocCL xs (headCL ys)) (tailCL ys)   

concatCL :: CList (CList a) -> CList a
concatCL EmptyCL = EmptyCL
concatCL (CUnit x) = x
concatCL (Consnoc x xs y) = (cl) ((cl) x (concatCL xs)) y

-- EJercicio 4 --

data Aexp = Num Int | Prod Aexp Aexp | Div Aexp Aexp

eval :: Aexp -> Int
eval (Num x) = x
eval (Prod x y) = (eval x) * (eval y)
eval (Div x y)= (div) (eval x) (eval y)

{- Para el caso de eval, la división por cero resulta

*Main> let x = Div (Num 1) (Num 0)
*Main> eval x
*** Exception: divide by zero

Devuelve una excepción donde no puede resolver la evaluación de la expresión.

-}

seval :: Aexp -> Maybe Int
seval (Num x) = (Just x) 
seval (Prod x y) = case (seval x) of 
                    Nothing -> Nothing
                    (Just x) -> case (seval y) of
                            Nothing -> Nothing
                            (Just y) -> (Just (x*y))
seval (Div x y) = case (seval y) of 
                    Nothing -> Nothing
                    (Just 0) -> Nothing
                    (Just y) -> case (seval x) of
                            Nothing -> Nothing
                            (Just x) -> (Just ((div) x y))

{- Para el caso de seval, la división por cero resulta

*Main> let x = Div (Num 1) (Num 0)
*Main> seval x
Nothing

Pudiendo completar la función sin terminar de forma inesperada.

-}

-- Ejercicio 5 y 7 --

data Bin a = Hoja | Node (Bin a) a (Bin a)

--calcula el máximo valor de un BST
maximun :: Ord a => BST a -> a 
maximun (Node Hoja a Hoja) = a
maximun (Node tree a Hoja) = max a (maximun tree)
maximun (Node Hoja a tree) = max a (maximun tree)
maximun (Node tree1 a tree2) = max (max a (maximun tree1)) (maximun tree2)

--calcula el minimo valor de un BST
minimun :: Ord a => BST a -> a 
minimun (Node Hoja a Hoja) = a
minimun (Node tree a Hoja) = min a (minimun tree)
minimun (Node Hoja a tree) = min a (minimun tree)
minimun (Node tree1 a tree2) = min (min a (minimun tree1)) (minimun tree2)

--chequea si un árbol binario es un BST
checkBST :: Ord a => BST a → Bool
checkBST Hoja = True
checkBST (Node Hoja a Hoja) = True
checkBST (Node tree a Hoja) = (maximun tree <= a) && (checkBST tree)
checkBST (Node Hoja a tree) = (minimun tree > a) && (checkBST tree)
checkBST (Node tree1 a tree2) = (minimun tree2 > a) && (checkBST tree2) && (checkBST tree1) && (maximun tree1 <= a)


-- Ejercicio 6 --

data Tree a = Leaf a | Nodo (Tree a) a (Tree a)
                deriving(Show) 

completo :: a -> Int -> Tree a
completo a 1 = Leaf a
completo a h = let hijo = (completo a (h-1)) in (Nodo hijo a hijo)

balanceado :: a -> Int -> Tree a
balanceado a 1 = Leaf a
balanceado a n | (mod) n 2 == 0 = let hijo = (balanceado a ((div) n 2)) in (Nodo hijo a hijo)
               | otherwise = (Nodo (balanceado a (n - ((div) n 2))) a (balanceado a ((div) n 2)))


-- Ejercicio 8 --

member :: Ord a => Bin a -> a -> Bool
member Hoja x = False
member (Node t1 a t2) x | x <= a = (member t1 x) || x == a
                        | True   = member t2 x


{-
data GenTree a = EmptyG | NodeG a [GenTree a]
data BinTree a = EmptyB | NodeB (BinTree a) a (BinTree a)

g2bt :: Gentree a -> Bintree a
g2bt t = g2bt' t []

g2bt' :: Gentree a -> [Gentree a] -> Bintree a
g2bt' EmptyG [] = EmptyB

--sin hermanos ni hijos
g2bt' (NodeG x []) [] = NodeB EmptyB x EmptyB

--sin hermanos, con hijos
g2bt' (NodeG x (t:ts)) [] = NodeB (g2bt' t ts) x EmptyB

--con hermanos, sin hijos
g2bt' (Node x []) (t:ts) = NodeB Empty x (g2bt' t ts)

--con hermanos, e hijos
g2bt' (Node x (y:ys)) (t:ts) = NodeB (g2bt' y ys) x (g2bt' t ts)


-- Ejercicio 9 --

 -}