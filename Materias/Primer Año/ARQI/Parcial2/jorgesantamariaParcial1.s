.data
    msg1:   .asciiz "Introduzca un numero: "
    msg2:   .asciiz "Introduzca otro numero: "
    msg3:   .asciiz "El LCM es: "
    msg4:   .asciiz "Fin del Programa\n"
    msg5:   .asciiz "\n"

.text
main:
    li $v0, 4
    la $a0, msg1
    syscall
    
    li $v0, 5
    syscall
    
    beq $v0, 0, FIN
    
    move $s0, $v0           # s0 = N°1
    move $s8, $v0           # s8 = N°1
    
    li $v0, 4
    la $a0, msg2
    syscall
    
    li $v0, 5
    syscall
    
    move $s1, $v0           # s1 = N°2
    move $s3, $s1           # s3 = N°2
    
    beq $s1, 0, FIN1
    
    move $a0, $s0
    move $a1, $s1
    
    jal LCM
    
    # v1 = lcm(a,b)

    li $v0, 4
    la $a0, msg3
    syscall
    
    li $v0, 1
    move $a0, $v1
    syscall
    
    li $v0, 4
    la $a0, msg5
    syscall
    
    j main
    
LCM:
    add $sp, $sp, -4
    sw $ra, 0($sp)
    
    jal GCD
    
    lw $ra, 0($sp)
    add $sp, $sp, 4
    
    # v1 = gcd(a,b)
    
    add $sp, $sp, -4
    sw $ra, 0($sp)
    
    move $a0, $s0
    move $a1, $s1
    
    jal MOD
    
    lw $ra, 0($sp)
    add $sp, $sp, 4
    
    # v0 = a*b
    
    div $v1, $v0, $v1
    
    jr $ra
    
FIN1:
    move $t8, $s1
    
GCD:
    div $a0, $a1
    mfhi $t2
    move $a0, $a1
    move $a1, $t2
    
    beqz $a1, FINGCD
    j GCD
    
FINGCD:
    move $v1, $a0
    jr $ra
    
FIN:
    li $v0, 4
    la $a0, msg4
    syscall
    
    li $v0, 10
    syscall
    
MOD:
    mul $v0, $a0, $a1
    jr $ra
