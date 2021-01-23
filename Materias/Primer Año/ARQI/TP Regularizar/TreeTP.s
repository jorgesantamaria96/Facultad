.data 
msg: .asciiz "Ingrese el dato (0 para terminar): "
ln: .asciiz "\n"
espacio: .asciiz " "
msgInorder: .asciiz "\nRecorrido inorder: \n"
msgPreorder: .asciiz "\nRecorrido preorder: \n"
msgPostorder: .asciiz "\nRecorrido postorder: \n"
msgFin: .asciiz "\nFin del programa.\n"

.text

main:
	li $s2, 0 		# $s2                 = valor inicial 
     move $a0, $s2 		# dato argumento      = $s2 
     li $a1, 0 	     # izquierda argumento = NULL 
     li $a2, 0 		# derecha argumento   = NULL 
     jal crearNodo	 	# crearNodo 
	
	move $s0, $v0       # pongo el valor retornado en $s0 

ingresoLoop:

     li $v0, 4
     la $a0, msg
     syscall
	
     # ingreso el dato #
	li $v0, 5
     syscall
	
	beqz $v0, finIngreso     # si ingreso 0 termina la secuencia de ingresar
	
     move $t2, $v0		     # $t2      = dato
	
	move $s1, $t2		     # $s1      = dato
	
	move $a0, $s1 		     # dato argumento = $s1 
     move $a1, $s0 		     # raiz argumento = $s0 
     jal insertar 		     # insertar
	
	j ingresoLoop
	
finIngreso:
     ## imprimir INORDER
	 
	la $a0, msgInorder
	li $v0, 4
	syscall
	 
     lw $a0, 4($s0) # imprime los subarboles izquierdos
     jal imprimirInorder
     
     lw $a0, 8($s0) # imprime los subarboles derechos 
     jal imprimirInorder
    
	## imprimir PREORDER
	 
	la $a0, msgPreorder
	li $v0, 4
	syscall
	 
	lw $a0, 4($s0)
	jal imprimirPreorder
	 
	lw $a0, 8($s0)
	jal imprimirPreorder
	
	## imprimir POSTORDER
	
	la $a0, msgPostorder
	li $v0, 4
	syscall
	
	lw $a0, 4($s0)
	jal imprimirPostorder
	 
	lw $a0, 8($s0)
	jal imprimirPostorder
	
	## Fin del programa ##
	
	la $a0, msgFin
	li $v0, 4
	syscall
	
     li $v0, 10
	syscall
	
	
crearNodo:
     # inicializo la pila #
	 
     addi $sp, $sp, -24 
     sw $ra, 20($sp)  
     sw $s0, 16($sp) 
     sw $s1, 12($sp) 
     sw $s2, 8($sp) 
     sw $s3, 4($sp) 
     
     move $s0, $a0 		# $s0 = dato
     move $s1, $a1 		# $s1 = izquierda
     move $s2, $a2 		# $s2 = derecha
     
     li $a0, 12 		# 12 bytes para crear un nuevo nodo
     li $v0, 9 			# llamada a sbrk 
     syscall 
	 
     move $s3, $v0 		# $s3 = direccion del nuevo nodo
     
     sw $s0, 0($s3) 	# nodo->dato  = dato
     sw $s1, 4($s3) 	# nodo->izq   = izquierda  
     sw $s2, 8($s3) 	# nodo->der   = derecha 
     
     move $v0, $s3 		# pongo el valor de retorno (direccion del nodo recien creado) en $v0 
						
	# restauro la pila #
     
	lw $ra, 20($sp) 	# restauro la direccion de retorno 
     lw $s0, 16($sp) 	# restauro $s0
     lw $s1, 12($sp) 	# restauro $s1 
     lw $s2, 8($sp) 	# restauro $s2 
     lw $s3, 4($sp) 	# restauro $s3 
     addi $sp, $sp, 24  # restauro $sp 
     jr $ra 			# retorno $v0
	 
     ## fin crearNodo
	 
## INSERTAR 
     ## Uso de los registros: 
     ## $s0 - dato 
     ## $s1 - nodo raiz
     ## $s2 - nuevo nodo 
     ## $s3 - puntero a la raiz
     ## $s4 - puntero temporal
     insertar:  
	# inicializar la pila # 
     addi $sp, $sp, -24 
     sw $ra, 24($sp)
     sw $s0, 20($sp) 
     sw $s1, 16($sp) 
     sw $s2, 12($sp) 
     sw $s3, 8($sp) 
     sw $s4, 4($sp) 
     
     # cargo los parametros: 
     move $s0, $a0 		# $s0 = dato 
     move $s1, $a1 		# $s1 = raiz 
     # creo el nuevo nodo 
     # nuevoNodo = crearNodo(valor, izq, der); 
     move $a0, $s0 		# dato argumento      = $s0 
     li $a1, 0 			# izquierda argumento = 0 
     li $a2, 0 			# derecha argumento   = 0 
	# para crear un nuevo nodo el hijo izquierdo y el derecho deben estar en NULL
     jal crearNodo 		# llama a crearNodo 
	move $s2, $v0 		# guarda en $s2 el retorno
L1:
     lw $s3, 0($s1) 		# valor de la raiz = raiz->dato; 
     ble $s0, $s3, LEFT 	# si (value <= s3 (puntero a la raiz)) saltar a LEFT; 
     j RIGHT 			# saltar a RIGHT; 
     
LEFT: 
     lw $s4, 4($s1) 		    # $s4 = raiz->izq; 
     beqz $s4, insertar_left 	# if(raiz->izq == NULL) goto insertar_left; 
     move $s1, $s4 			    # raiz = $s4; 
     j L1 				        # goto L;
     
insertar_left: 
     sw $s2, 4($s1)             # raiz->izq = nuevo nodo; guardo en el hijo izquierdo el nuevo nodo
     j Fin    				# goto FinLeft; 
     
RIGHT: 
     lw $s4, 8($s1)        		# $s4 = raiz->der; 
     beqz $s4, insertar_right   # if(raiz->der == NULL) goto insertar_right; 
     move $s1, $s4              # raiz = $s4; 
     j L1 					    # goto L1; 
     
insertar_right: 
     sw $s2, 8($s1) 			# raiz->der = nuevo nodo; 
     j Fin 				        # goto Fin; 
     
Fin:  
     
     # restauramos la pila #
     lw $ra, 24($sp) 			# restaurar $ra
     lw $s0, 20($sp) 			# restaurar $s0
     lw $s1, 16($sp) 			# restaurar $s1
     lw $s2, 12($sp) 			# restaurar $s2
     lw $s3, 8($sp) 			# restaurar $s3 
     lw $s4, 4($sp) 			# restaurar $s4
     addi $sp, $sp, 28 			# restaurar $sp 
     jr $ra 					# return
     ## fin insertar nodo. 
	 
	## Recorrido inorder
     ## Uso de los registros: 
     ## s0 - arbol a imprimir 
     imprimirInorder: 
     # Iniciar la pila # 
     addi $sp, $sp, -28 
     sw $ra, 24($sp)  
     sw $s0, 20($sp) 
	 
     # tomamos los parametros: 
     move $s0, $a0 # $s0 = arbol
     
     beqz $s0, finInorder # if (raiz == NULL) return; 
     
     lw $a0, 4($s0) # llamada recursiva a la izquierda 
     jal imprimirInorder 
     
	# imprimo el valor de la raiz     
	lw $a0, 0($s0)  
     li $v0, 1 
     syscall 
     la $a0, espacio # imprimo un espacio
     li $v0, 4 
     syscall 
     
     lw $a0, 8($s0) # llamada recursiva a la derecha. 
     jal imprimirInorder 
     
     finInorder: 
	# limpio la pila y retorno #
     lw $ra, 24($sp) # restauro $ra 
     lw $s0, 20($sp) # restauro $s0
     addi $sp, $sp, 28 # restauro $sp
     jr $ra # return
     ## fin imprimirInorder
	 
	## Recorrido Preorder
     ## Uso de los registros: 
     ## s0 - arbol a imprimir 
     imprimirPreorder: 
     # Iniciar la pila # 
     addi $sp, $sp, -28 
     sw $ra, 24($sp)  
     sw $s0, 20($sp) 
	 
     # tomamos los parametros: 
     move $s0, $a0 # $s0 = arbol
     
     beqz $s0, finPreorder # if (raiz == NULL) return; 
     
	# imprimo el valor de la raiz   
	
	lw $a0, 0($s0)  
     li $v0, 1 
     syscall 
     la $a0, espacio # imprimo un espacio 
     li $v0, 4 
     syscall 
	 
     lw $a0, 4($s0) # llamada recursiva a la izquierda 
     jal imprimirPreorder
     
     lw $a0, 8($s0) # llamada recursiva a la derecha. 
     jal imprimirPreorder 
     
finPreorder: 
	# limpio la pila y retorno #
     lw $ra, 24($sp) # restauro $ra 
     lw $s0, 20($sp) # restauro $s0
     addi $sp, $sp, 28 # restauro $sp
     jr $ra # return
     ## fin imprimirPreorder
	 
imprimirPostorder:
     addi $sp, $sp, -28
     sw $ra, 24($sp)	 
	sw $s0, 20($sp)
	
	move $s0, $a0
	 
	beqz $s0, finPostorder
	 
	lw $a0, 4($s0)
	jal imprimirPostorder
	 
	lw $a0, 8($s0)
	jal imprimirPostorder
	 
	lw $a0, 0($s0)
	li $v0, 1
	syscall
	 
	la $a0, espacio
	li $v0, 4
	syscall
	 
	 
finPostorder:
	lw $ra, 24($sp)
	lw $s0, 20($sp)
	addi $sp, $sp, 28
	jr $ra
	## fin imprimirPostorder