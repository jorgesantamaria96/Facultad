.data 
    size: .word 6
    vect: .word 11, 5, 2, 23, 1, 7
    msj: .asciiz "Array: "
    msj2: .asciiz "\nOrdenado: "
    espacio: .asciiz " "

.text
main:
	la $a0, msj		#muestro "Array: "
	li $v0, 4
	syscall
	lw $s1, size	#cargo size (6) en $s1, "declaro" el contador
	la $s2, vect	#carga la direccion del vector en $s2
L1: 
	la $a0, espacio		#muestra un espacio " "
	li $v0, 4
	syscall
	lw $a0, ($s2)	#muestra la posicion del arreglo
	li $v0, 1
	syscall
	addi $s2, $s2, 4	#suma 4 a $s2, incremento el "contador" 
	addi $s1, $s1, -1	#decrementa el "contador"
	beqz $s1, E1	#si $s1 es igual a 0, salta a E1
	j L1	#salta al comienzo del bucle
	
E1:
	lw $s1, size	#carga nuevamente size en $s1, "declara" el primer contador
	addi $s1, $s1, -1	#le resta 1 a size, 6 - 1
	move $s3, $s1	#copia el valor de $s1 en $s3, "declara" el segundo contador
	la $s2, vect
L2:
	lw $t0, ($s2)	#carga en $t0 el contenido de $s2, la primer posicion del arreglo
	lw $t1, 4($s2)	#carga en $t1 el contenido de $s2 + 4, la segunda posicion del arreglo
	bge $t1, $t0, NOSWAP #si $t1 (la segunda posicion) es mayor que $t0 (la primer posicion) o igual, entonces no hay que cambiar nada y salta a NOSWAP 
	#realiza el SWAP
	sw $t1, ($s2)	#guarda el la primer posicion en $t1
	sw $t0, 4($s2)	#guarda la segunda posicion en $t0
NOSWAP:
	addi $s2, $s2, 4	#pasa a la siguiente posicion 
	addi $s1, $s1, -1	#decrementa size
	beqz $s1, E2	#si $s1 (el primer contador) es igual a 0, salta a E2
	j L2	#salta a L2
E2: 
	addi $s3, $s3, -1	#decrementa el segundo contador
	move $s1, $s3	#copia el valor de $s3 a $s1
	la $s2, vect	#guarda en $s2 la direccion de vect (la primer posicion)
	beqz $s3, E3	#si $s3 (el segundo contador) es igual a cero, salta a E3
	j L2	#salta a L2
E3:
	la $a0, msj2	#muestra "\nOrdenado"
	li $v0, 4
	syscall
	lw $s1, size	#cargo en size (6) en $s1, "declaro" el contador
	la $s2, vect	#guarda en $s2 la direccion del arreglo (primer posicion)
L3:
	la $a0, espacio		#muestra un espacio " "
	li $v0, 4
	syscall
	lw $a0, ($s2)	#muestra la posicion del arreglo
	li $v0, 1
	syscall
	addi $s2, $s2, 4	#suma 4 a $s2, incremento el "contador"
	addi $s1, $s1, -1	#decrementa el "contador" 
	beqz $s1, E4	#si $s1 es igual a 0, salta a E1
	j L3	#salta al comienzo del bucle L3
E4:	
	li $v0, 10
	syscall #exit
