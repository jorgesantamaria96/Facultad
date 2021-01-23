.data
msg1: .asciiz "Comienza\n"
msg2: .asciiz "termina\n"
msg3: .asciiz "subrutina1\n"
msg4: .asciiz "subrutina2\n"

.text
main: la $a0, msg1
      li $v0, 4
      syscall
      jal sub1
      la $a0, msg2
      li $v0, 4
      syscall
      li $v0, 10
      syscall

sub1: la $a0, msg3
      li $v0, 4
      syscall    
      addi $sp, $sp, -4
      sw $ra, ($sp)
      jal sub2
      lw $ra, ($sp)
      addi $sp, $sp, 4
      jr $ra

sub2: la $a0, msg3
      li $v0, 4
      syscall
      jr $ra