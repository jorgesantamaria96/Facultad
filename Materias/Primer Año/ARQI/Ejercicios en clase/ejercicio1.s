#1-Elabore un menu con tres opciones y luego solicite que ingrese una opción mediante un número entre 0 y 3.
#Si el número es 0 deberá finalizar, colocando el mensaje "Terminado", si está entre la opción 1 a la 3 imprima un mensaje "Ingreso a la opción x\n", donde x debería ser 1, 2 o 3 y luego repita todo nuevamente. Cualquier otro número informará que eligió la opción incorrecta y volverá a solicitar que ingrese una opción.
.data
    msg1:   .asciiz "Ingrese un numero entre 0 y 3: "
    msg2:   .asciiz "Ingreso la opcion "
    msg3:   .asciiz "Ingreso una opcion incorrecta."
    msg4:   .asciiz "Terminado."
    msg5:   .asciiz "\n"
    
.text
main:
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    
    move $t0, $v0
    
    beq $v0, 0, FIN
    beq $v0, 1, IMPRIMIR
    beq $v0, 2, IMPRIMIR
    beq $v0, 3, IMPRIMIR
    bgt $v0, 3, INCORRECTO
    blt $v0, 0, INCORRECTO

FIN:
    li $v0, 4
    la $a0, msg4
    syscall
    
    li $v0, 10
    syscall
    
IMPRIMIR:
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 1
    move $a0, $t0
    syscall
    
    li $v0, 4
    la $a0, msg5
    syscall
    
    j main
    
INCORRECTO:
    li $v0, 4
    la $a0, msg3
    syscall
    
    li $v0, 4
    la $a0, msg5
    syscall
    
    j main
