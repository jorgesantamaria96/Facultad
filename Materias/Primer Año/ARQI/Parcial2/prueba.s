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
    msg2:   .asciiz "La cantidad ingresada supera el limite (40).\n"
    msg3:   .asciiz "Ingrese los numeros\n"
    msg4:   .asciiz "Ingrese un numero: "
    salto:  .asciiz "\n"
    vector: .space  160
    
.text
main:
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    
    bgt $v0, 40, ERROR
    li $t0, 0               # t0 = 0
    
    move $s0, $v0           # s0 = cantidad
    la $t8, vector($0)
    
    # comienzo a guardar los numeros
    li $v0, 4
    la $a0, msg3
    syscall
    
    li $t1, 0               # t1 = 0
    move $t2, $s0           # t2 = cantidad
    
    jal ingresarNum
    
    # una vez guardados los datos, vamos a realizar el calculo
    # t0 tiene la posicion del ultimo elemento
    # como voy a tomar de a dos, resto uno a t0
    
    li $t1, 0               # t1 = 0    
    li $s4, 0               # s4 = 0
    move $s5, $t0           # s5 = cantidad    

mostrarPIRAM:
    beq $s4, $s5, FIN
    addi $t0, $t0, -1
    jal piramide
    
    li $t1, 0
    li $v0, 4
    la $a0, salto
    syscall
    
    j mostrarPIRAM
    
FIN:
    li $v0, 10
    syscall
    
    
    
ingresarNum:
    beq $t1, $t2, FINNUM
    li $v0, 4
    la $a0, msg4
    syscall
    
    li $v0, 5
    syscall
    
    sw $v0, vector($t0)
    
    addi $t0, $t0, 4
    addi $t1, $t1, 1
    
    j ingresarNum
    
FINNUM:    
    jr $ra
    
ERROR:
    li $v0, 4
    la $a0, msg2
    syscall
    j main         

piramide:
    beq $t1, $t0, FINFILA
    lw $s1, 0($t8)
    lw $s2, 4($t8)
    add $s3, $s1, $s2
    sw $s3, 0($t8)
    
    li $v0, 1
    move $a0, $s3
    syscall
    
    addi $t1, $t1, 1
    addi $t8, $t8, 4
    j piramide
    
FINFILA:
    jr $ra
