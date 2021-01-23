.data
pedidocant:  .asciiz "interoduzca una cantidad:"
pedidonros:  .asciiz "\nintroduzca el elemento["
cierre:  .asciiz "]:"
resumen: .asciiz "\nLos elementos pares son:"
fin:     .asciiz "\nFin de Programa\n"
espaci: .asciiz " "

.text
main:
li $s4,2
# mensage de pedido de una cantidad
li $v0,4
la $a0,pedidocant
syscall

# pedido de ingreso cantidad
li $v0,5
syscall
beqz  $v0,finalizar

#guardo la cantidad en $t0
move $s0,$v0

#llamado a funcion para ingersar nros
jal funcnro

#llamado a funcion imprmir elementos pares
jal pares

# mensaje finalizacion
finalizar:
li $v0,4
la $a0,fin
syscall

# Free ver como es ????

# syscall para finalizar
li $v0,10
syscall

# funcion ingreso nros
funcnro:
move $t0,$s0             # $t0 guarda la cantidad de nros a cargar
li $t1,0
mul $t3,$t0,-4
add $sp,$sp,$t3        # guardo memoria

inicio:
addi $t1,$t1,1       #$t1 es el contador

li $v0,4
la $a0,pedidonros
syscall

li $v0,1
move $a0,$t1
syscall

li $v0,4
la $a0,cierre
syscall

li $v0,5
syscall

sw $v0,0($sp)         # guardo el nro ingresado en memoria
add $sp,$sp,4

blt $t1,$t0,inicio    # si la cantidad de nros ingresados es menor al contador, vuelve a inicio

jr $ra


# impresion nros pares
pares:
move $t0,$s0             # $t0 guarda la cantidad de nros a cargar
li $t1,0
mul $t3,$t0,-4
add $sp,$sp,$t3        # muevo puntero 

inicio2:
addi $t1,$t1,1       #$t1 es el contador

lw $s1,0($sp)         # saco el nro ingresado de memoria a registro
add $sp,$sp,4
div $s1,$s4
mfhi $t4

bnez $t4,salto

li $v0,1
move $a0,$s1
syscall

li $v0,4
la $a0,espaci
syscall
