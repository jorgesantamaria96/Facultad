.data
	mensaje: .asciiz "Ingrese la cantidad: "
	mensaje2: .asciiz "Ingrese un numero ["
	ms2: .asciiz "]: "
	mensaje3: .asciiz "Los numeros pares son: "
	msjfin: .asciiz "\nFin de ejecucion.\n"
	salto: .asciiz "\n"
	cont: .word 1
.text
	main:
		jal ingresoCant
		
		move $t0, $v0
		move $t1, $t0
		beqz $t0, FIN
		addi $t2, $zero, 2
		lw $t4, cont
		li $s1, 0 #variable bandera
		li $s2, 0
		
	L1:
		beqz $t0, IMPRIMIR
		jal ingresoNum
		
		div $v0, $t2
		mfhi $t3
		beqz $t3, PAR
		addi $t0, $t0, -1
		j L1
		
	PAR:
		addi $sp, $sp, -4
		addi $t0, $t0, -1
		bne $s1, $zero, PAS 
		jal DIR
		addi $s1, $zero, 1
	PAS:
		sw $v0, ($sp)
		addi $s2, $s2, 1
		j L1
	DIR:
		la $s0, ($sp)
		jr $ra
	
	IMPRIMIR:
		li $v0, 4
		la $a0, mensaje3
		syscall
		move $t0, $s2
	L2:	
		beqz $s2, CONTINUE
		li $v0, 1
		lw $a0, ($s0)
		syscall
		
		addi $s2, $s2, -1
		addi $s0, $s0, -4
		
		j L2
		
	CONTINUE: 	
		jal RestaurarPila
		
		li $v0, 4
		la $a0, salto
		syscall
		
		j main
	FIN:
		
		li $v0, 4
		la $a0, msjfin
		syscall
		
		li $v0, 10
		syscall
	
	ingresoCant:
		li $v0, 4
		la $a0, mensaje
		syscall
		
		li $v0, 5
		syscall
		
		jr $ra
		
	ingresoNum:
		li $v0, 4
		la $a0, mensaje2
		syscall
		
		li $v0, 1
		move $a0, $t4
		syscall
		
		li $v0, 4
		la $a0, ms2
		syscall
		
		li $v0, 5
		syscall
		
		addi $t4, $t4, 1
		jr $ra
	
	RestaurarPila:
		beqz $t0, FRest
		
		addi $sp, $sp, 4
		addi $t0, $t0, -1
		
		j RestaurarPila
	FRest:
		jr $ra
