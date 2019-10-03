lw $t3, note_array_length # sets the length to register $t3
la $t1, note_array # get array address
li $t2, 0 # set loop counter
loop:
	beq $t2, $t3, loop_end # check for array end
	lw $a0, ($t1) # print value at the array pointer
	
	li $a3, 100 # set the volume to constant
	li $a1, 2000 # 2 seconds (constant)
	li $a2, 56 # instrument trumpet
	
	li $v0, 31
		
	syscall
	
	
	addi $t2, $t2, 1 # advance loop counter by 1 
	addi $t1, $t1, 4 # advance array pointer by 4 "bits"
	j loop
loop_end:

li $v0,10 # load service number in $v0
syscall # end the program

	


.data

note_array: .word 43,50,50,53,52,48,50,50,50,50,50,50  # array 
note_array_length: .word 12 # note array length is 12

