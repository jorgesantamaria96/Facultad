#3-Solicite que se ingresen n números que deberá almacenar en la memoria. Para ello solicite primero la cantidad que no deberá ser mayor que 40 y luego cada número hasta completar la cantidad solicita.
#A continuación eleborará una pirámide, de la siguiente forma. Si asumimos que entramos 5 números entonces primero imprimirá los mismos, y luego la suma entre ellos hasta que solo quede un número, como se muestra a continuación:
#5 2 3 1 4
#7 5 4 5
#12 9 9
#21 18
#39
#Se sugiere reutilizar el espacio en memoria donde originalmente está la lista ya que no se pide volver a reutilizar los mismos, de esa manera no es necesario reservar espacio para los filas posteriores.
.data
    msg1:   .asciiz "Ingrese la cantidad: "
    msg2: .asciiz "Ingrese un numero: "
    salto: .asciiz "\n"
.text
main:

    li $s0, 0       # bandera
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    
    move $t0, $v0   # tamaño
    li $t1, 0   #cont
    
L1:
    beq $t1, $t0, continue
    
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 5
    syscall
    
    addi $sp, $sp, -4
    sw $v0, ($sp)
    beqz $s0, dir 
    j sigue
dir:
    la $s1, ($sp) 
    addi $s0, $s0, 1
    
sigue:    
    addi $t1, $t1, 1
    j L1   
continue:    
    la $s2, ($sp)
    la $s3, ($sp)
    la $s4, ($sp)
    li $t1, 0
L2:
    beq $s1, $s4, FIN
    
    lw $t2, 0($s2)
    li $v0, 1
    move $a0, $t2
    syscall
    lw $t3, 4($s2)
    li $v0, 1
    move $a0, $t3
    syscall
    
    #jal Imprime
    
    addi $t0, $t0, -1   
    add $t4, $t2, $t3
    sw $t4, ($s3)
    li $v0, 1
    move $a0, $t4
    syscall
    
    addi $s2, $s2, 4
    addi $s3, $s3, 4 
    addi $s1, $s1, -4
    
    li $v0, 4
    la $a0, salto
    syscall
    
    j L2    
    

FIN:
    #fin de ejecucion
    li $v0, 10
    syscall

    
Imprime:
     beq $t1, $t0, sigue1
     li $v0, 1
     lw $a0, ($s2)
     syscall
            
     addi $s2, $s2, 4
     addi $t1, $t1, 1
     
     j Imprime    

sigue1: 
     li $t1, 0
     jr $ra
