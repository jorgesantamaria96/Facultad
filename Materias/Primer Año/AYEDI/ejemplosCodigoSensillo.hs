fact::(Integral a)=>a -> a
fact 0 = 1
fact n = n * fact (n-1)

cuenta::(Num t)=> [a] -> t 
cuenta []  = 0
cuenta (x:t) = 1 + cuenta t

suma::(Num t)=> [t] -> t
suma [] = 0
suma (x:t) = x + suma t


concatx::[a]->[a]->[a]
concatx [] l2 = l2
concatx (x:t) l = x: concatx t l 


mireverse::[a] -> [a]
mireverse [] =  []
mireverse (x:t) = mireverse t ++ [x]

minimo::(Ord a) => [a]-> a
minimo [] = error "No tiene minimo"
minimo [x]= x
minimo (x:y:t) = if x<=y then minimo(x:t) else minimo(y:t)

mtake :: Int -> [a] -> [a]
mtake _ [] = []
mtake 0 _  = []
mtake n (x:t) = x: take (n-1) t


mdrop :: Int -> [a] -> [a]
mdrop _ [] = []
mdrop 0 l  = l
mdrop n (x:t) = drop (n-1) t 

mzip::[a]->[b]-> [(a,b)]

mzip l1 [] = []
mzip [] l2 =[]
mzip (x:xs) (y:ys) = (x,y): (mzip xs ys)             
         

primos n = [x | x<-[1..n],(divisores x)==[1,x]]
           where divisores z = [ y | y<-[1..z], (z `mod`y)==0]
