#2-Ingrese una lista de 10 números e imprímala en sentido inverso
.data
    msg1:   .asciiz "Ingrese una lista de 10 numeros.\n"
    msg2:   .asciiz "Ingrese un numero: "
    msg3:   .asciiz "La lista invertida es: "
    msg5:   .asciiz " "
    vect:   .space   40
    tam:    .word   10
    
.text
main:
    li $v0, 4
    la $a0, msg1
    syscall
    
    addi $t0, $zero, 0
    li $t1, 10
    
proceso1:
    beqz $t1, BREAK
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 5
    syscall
    
    sw $v0, vect($t0)
    
    addi $t1, $t1, -1
    addi $t0, $t0, 4
    
    j proceso1
    
BREAK:
    lw $t1, tam
    addi $t0, $t0, -4
    
proceso2:
    li $v0, 1
    lw $a0, vect($t0)
    syscall
    
    addi $t1, $t1, -1
    addi $t0, $t0, -4
    
    beqz $t1, FIN
    
    j proceso2
    
FIN:
    li $v0, 10
    syscall
    
    j proceso2
