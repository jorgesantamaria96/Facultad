#Consigna:
#Hacer un programa en assembly de MIPS R2000, que solicite una cantidad de números y luego imprima solo los pares en el 
#mismo orden ingresado como se muestra en el ejemplo de ejecución. El programa solo finaliza si introduce 0 como cantidad
#Respete las cadenas de mensajes como se muestra en el ejemplo. Puede tener en cuenta que un operador del programa jamás 
#ingresará una cantidad superior a 32. Documente su programa de la mejor manera posible.
#
#Introduzca una cantidad: 3
#Introduzca el elemento [1]: 4
#Introduzca el elemento [2]: 1
#Introduzca el elemento [3]: 2
#Los elementos pares son: 4, 2,
#Introduzca una cantidad: 0
#Fin del programa

.data
    msg1:   .asciiz "Introduzca una cantidad: "
    msg2:   .asciiz "Introduzca el elemento ["
    msg3:   .asciiz "]: "
    msg4:   .asciiz "Los elementos pares son: "
    msg5:   .asciiz ", "
    msg6:   .asciiz "\n"
    msg7:   .asciiz "\nFin del programa\n"
    contador:   .word   1
    
.text
main:
    jal cantidad
    
    move $t0, $v0               # t0 = cantidad
    move $t1, $v0               # t1 = cantidad    
    li $s0, 0                   # contador para el bucle
    li $s1, 0                   # s1 es mi bandera para guardar la primera direccion de sp
    lw $s2, contador($0)        # contador bucle []
    li $s3, 0                   # contador pares en la pila
    beqz $t0, FIN
    addi $t2, $zero, 2

proceso1:
    beq $s0, $t0, IMPRIMIR
    jal numeros
    
    div $v0, $t2
    mfhi $t3
    beqz $t3, esPAR
    addi $s0, $s0, 1
    j proceso1
    
esPAR:
    addi $sp, $sp, -4
    addi $s0, $s0, 1
    bne $s1, $zero, SIGUE
    jal DIR
    addi $s1, $s1, 1

SIGUE:
    sw $v0, ($sp)
    addi $s3, $s3, 1
    j proceso1
    
DIR:
    la $t8, ($sp)
    jr $ra
    
IMPRIMIR:
    li $v0, 4
    la $a0, msg4
    syscall
    
    move $t0, $s3               # s3 = cantidad pares
    li $t9, 0        
        
proceso2:
    beq $t9, $t0, CONTINUE
    li $v0, 1
    lw $a0, ($t8)
    syscall
    
    li $v0, 4
    la $a0, msg5
    syscall
    
    addi $t8, $t8, -4
    addi $t9, $t9, 1
    
    j proceso2
    
CONTINUE:
    jal RESTAURARPILA
    li $v0, 4
    la $a0, msg6
    syscall
    
    j main    
    
    
RESTAURARPILA:
    beqz $t0, FINREST
    addi $sp, $sp, 4
    addi $t0, $t0, -1
    j RESTAURARPILA
    
FINREST:
    jr $ra    

cantidad:
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    
    jr $ra
    
FIN:
    li $v0, 4
    la $a0, msg7
    syscall
    
    li $v0, 10
    syscall
    
numeros:
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 1
    move $a0, $s2
    syscall
    
    li $v0, 4
    la $a0, msg3
    syscall
    
    li $v0, 5
    syscall
    
    addi $s2, $s2, 1
    jr $ra
