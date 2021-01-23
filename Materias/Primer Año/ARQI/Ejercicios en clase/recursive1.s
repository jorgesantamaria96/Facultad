.data

.text
main: li $a0, 6
      jal fib
      move $a0, $v0
      li $v0, 1
      syscall
      li $v0, 10
      syscall

fib:  addi $sp, $sp, -12
      sw $a0, 8($sp)
      sw $ra, 4($sp)

      bge $a0, 2, deep
      li $v0, 1
      j endf
deep: addi $a0, $a0, -1
      jal fib
      sw $v0, 0($sp)
      lw $a0, 8($sp)
      addi $a0, $a0, -2
      jal fib
      lw $t0, 0($sp)
      add $v0, $v0, $t0

endf: lw $a0, 8($sp)
      lw $ra, 4($sp)
      addi $sp, $sp, 12
      jr $ra
