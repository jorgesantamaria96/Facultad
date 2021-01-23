.data
size: .word 6
vector: .word 11, 5, 2, 23, 1, 7
msg1: .asciiz "La lista a ordenar es:"
spac: .asciiz " "
msg2: .asciiz "\nLa lista ordenada es:"

.text
main:   li $v0, 4             # imprimir msg1
        la $a0, msg1
        syscall
        lw $s1, size($0)      # s1 <- (size)
        la $s2, vector        # s2 <- &vector
L1:     la $a0, spac          # imprimir spac
        li $v0, 4
        syscall               # imprimir *vector
        lw $a0, ($s2)
        li $v0, 1
        syscall
        addi $s2, $s2, 4      # s2=+4
        addi $s1, $s1, -1     # s1--
        beqz $s1, E1          # if s1==0 exit L1
        j L1

        # begin bubblesort code
E1:     lw $s1, size($0)      # s1 <- (size)-1
        addi $s1, $s1, -1
        move $s3, $s1         # s3 <- s1
        la $s2, vector        # s2 <- &vector
L3:     lw $t0, ($s2)
        lw $t1, 4($s2)
        bge $t1, $t0, NOSWAP  # if *(s2+4) > *(s2) noswap
        sw $t1, ($s2)
        sw $t0, 4($s2)
NOSWAP: add $s2, $s2, 4       # s2=+4
        addi $s1, $s1, -1     # s1--
        beqz $s1, E3          # if s1==0 exit L3
        j L3
E3:     addi $s3, $s3, -1     # s3--
        move $s1, $s3         # s1 <- s3
        beqz $s3, E2          # if s3==0 exit sort
        la $s2, vector        # s2 <- &vector
        j L3

        # list ordered list
E2:     li $v0, 4
        la $a0, msg2
        syscall
        la $s2, vector
        lw $s1, size($0)
L4:     la $a0, spac
        li $v0, 4
        syscall
        lw $a0, ($s2)
        li $v0, 1
        syscall
        addi $s2, $s2, 4
        addi $s1, $s1, -1
        beqz $s1, E4
        j L4
E4:     li $v0,10             # exit
        syscall