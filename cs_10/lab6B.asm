.text
main:
	la $a0, matrix_message_A			
	li $v0, 4					# Prints message
	syscall
	la $a3, matrixA
	jal read_matrix
	la $a0, matrix_message_B			
	li $v0, 4					# Prints message
	syscall
	la $a3, matrixB
	jal read_matrix
	la $a1, temp_matrix_1a
	la $a2, matrixA
	jal matrix_multiply				# Matrix A x Matrix B
	move $a3, $a1					# Going to print the product
	la $a0, matrix_message_C			# Loads message to print
	li $v0, 4					# Prints message		
	syscall
	jal read_matrix4x4				# Prints product
        li $v0, 10                                      # terminate program run
        syscall 
	
matrix_multiply:
	li $t1, 4					# Row size = 4
	li $s0, 0					# Initialize 1st for loop (i = 0)
	i_loop:	
		li $s1, 0				# Restart 2nd for loop (j= 0)
		j_loop:
			li $s2, 0			# Restart 3rd for loop (k = 0)
			sll $t2, $s0, 2			# t2 = i * 2 ^ 2
			addu $t2, $t2, $s1		# ++t2
			sll $t2, $t2, 2			# t2 = byte offset of [i][j]
			addu $t2, $a1, $t2		# t2 = byte address of c[i][j]
			lw $t4, 0($t2)			# t4 = 4 bytes of c[i][j]
			k_loop:
				sll $t0, $s2, 2		# t0 = k * 2 ^ 2
				addu $t0, $t0, $s1	# t0 = t0 + j
				sll $t0, $t0, 2		# t0 = byte offset of [k]}j]
				addu $t0, $a3, $t0 	# t0 = byte address of b[k][j]
				lw $t5, 0($t0)		# t5 = 4 bytes of b[k][j]
				sll $t0, $s0, 2		# t0 = i * 2 ^ 2
				addu $t0, $t0, $s2	# t0 = t0 + k
				sll $t0, $t0, 2		# t0 = byte offset of [i][k]
				addu $t0, $a2, $t0	# t0 = byge address of a[i][k]
				lw $t6, 0($t0)		# t6 = 4 bytes of a[i][k]	
				mul $t5, $t6, $t5	# t5 = a[i][k] * b[i][k]
				add $t4, $t4, $t5	# t4 = c[i][j] + t5
				addiu $s2, $s2, 1	# ++k
				bne $s2, $t1, k_loop	# if (k != 4) go to L3
			sw $t4, 0($t2)			# c[i][j] = t4
			addiu $s1, $s1, 1		# ++j
			bne $s1, $t1, j_loop		# if (j != 4) go to L2
		addiu $s0, $s0, 1			# ++i
		bne $s0, $t1, i_loop			# if (i != 4) go to L2
	jr $ra


read_matrix4x4:
	li $t0, 0					
	li $t2, 15					
	li $s1, 4					
	li $s2, 8					
	li $s3, 12					
	la $a0, row1					
	li $v0, 4
	syscall						# Prints message
	begin_loop:
		bgt $t0, $t2, exit_loop		
		sll $t3, $t0, 2				
		addu $t3, $t3, $a3			
		lw $t1, 0($t3)				
		move $a0, $t1				
		li $v0, 1				
		syscall
		la $a0, space				
		li $v0, 4				
		syscall
		addi $t0, $t0, 1			# Print the rows 
		beq $t0, $s1, print_row_2			
		beq $t0, $s2, print_row_3			
		beq $t0, $s3, print_row_4			
		j begin_loop			# Restart loop
	exit_loop:
	jr $ra

read_matrix:
	li $t0, 0					
	li $t2, 63					
	li $s0, 8					
	li $s1, 16					
	li $s2, 24					
	li $s3, 32					
	li $s4, 40					
	li $s5, 48					
	li $s6, 56					
	la $a0, row1					
	li $v0, 4
	syscall						# Prints message
	begin_loop_2:
		bgt $t0, $t2, exit_loop_2		
		sll $t3, $t0, 2				
		addu $t3, $t3, $a3			
		lw $t1, 0($t3)				
		move $a0, $t1				
		li $v0, 1				
		syscall
		la $a0, space				# Loads space to print between integers
		li $v0, 4				# Prints space
		syscall
		addi $t0, $t0, 1			# Print the different rows
		beq $t0, $s0, print_row_2			
		beq $t0, $s1, print_row_3		
		beq $t0, $s2, print_row_4		
		beq $t0, $s3, print_row_5			
		beq $t0, $s4, print_row_6			
		beq $t0, $s5, print_row_7			
		beq $t0, $s6, print_row_8		
		j begin_loop_2				
	exit_loop_2:
	jr $ra
	
print_row_2:
	la $a0, row2					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_3:
	la $a0, row3					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_4:
	la $a0, row4					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_5:
	la $a0, row5					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_6:
	la $a0, row6					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_7:
	la $a0, row7					
	li $v0, 4					
	syscall
	j begin_loop_2					
print_row_8:
	la $a0, row8					
	li $v0, 4					
	syscall
	j begin_loop_2					


.data
matrixA: .word		1,  2,  3,  4,  5,  6,  7,  8,
			9,  10, 11, 12, 13, 14, 15, 16,
			17, 18, 19, 20, 21, 22, 23, 24,
			25, 26, 27, 28, 29, 30, 31, 32,
			33, 34, 35, 36, 37, 38, 39, 40,
			41, 42, 43, 44, 45, 46, 47, 48,
			49, 50, 51, 52, 53, 54, 55, 56,
			57, 58, 59, 60, 61, 62, 63, 64
			
matrixB: .word 		1,  2,  3,  4,  5,  6,  7,  8,
			9,  10, 11, 12, 13, 14, 15, 16,
			17, 18, 19, 20, 21, 22, 23, 24,
			25, 26, 27, 28, 29, 30, 31, 32,
			33, 34, 35, 36, 37, 38, 39, 40,
			41, 42, 43, 44, 45, 46, 47, 48,
			49, 50, 51, 52, 53, 54, 55, 56,
			57, 58, 59, 60, 61, 62, 63, 64
			
matrixC: .space  	256
temp_matrix_1a: .space 64
row1: .asciiz "\n Row 1: "
row2: .asciiz "\n Row 2: "
row3: .asciiz "\n Row 3: "
row4: .asciiz "\n Row 4: "
row5: .asciiz "\n Row 5: "
row6: .asciiz "\n Row 6: "
row7: .asciiz "\n Row 7: "
row8: .asciiz "\n Row 8: "
space: .asciiz " "

matrix_message_A: .asciiz "Matrix A:"
matrix_message_B: .asciiz "\n Matrix B:"
matrix_message_C: .asciiz "\n Matrix A x Matrix B = "
