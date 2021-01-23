.data
msg1: .asciiz "Comienza\n"
msg2: .asciiz "termina\n"
msg3: .asciiz "subrutina\n"

.text
main: la $a0, msg1 # imp msg1
      li $v0, 4
      syscall
      jal sub1     # llamar a sub1
      la $a0, msg2 # imp msg2
      li $v0, 4
      syscall
      li $v0, 10
      syscall

sub1: la $a0, msg3 # imp msg3
      li $v0, 4
      syscall
      jr $ra       # retornar
