la $a0, prompt # load address of string to be printed into $a0
li $v0,4 #load service number for string print in $v0
syscall

li $v0,8 #take in input
la $a0, buffer #load byte space into address
li $a1, 50 # allocate 50 bits for address 1
move $s0,$a0 #save string to t0
syscall
# opens prompt for user input

la $s1, V
la $s2, V
la $s3, V
la $s4, VPrime
la $s5, VPrime
la $s6, VCheck
la $s7, VCheck
loop:
    # $s0 = String 
    # $s1 = V Array
    # $t0 = Current character of string
    # $s2 = V array head pointer
    # $s3 = V array head pointer
    # $s4 = VPrime head pointer
    # sw  $s0, 4($sp)                 	# Store $s0 as it will be used for argument
    lb  $t0, 0($s0)                 	# Get current character
    beq $t0, $zero, loop_end        	# Done when reaching NULL character
    beq $t0, ' ', increment             # Check if there is a extra space
    
    addi $t0, $t0, -48   #converts t1's ascii value to dec value
    
    sb $t0 , 0($s1)
    
	
    addi $s1, $s1, 4
    j   increment
loop_end:



la $t1, ($s2)
li $t2, 0
loop_2:
        lw $t0, ($t1)
	beq $t2, 8, loop_end_2
	
	la $a0, ($t0)
	li $v0, 1       
        syscall 
	
	la $a0, newline # load address of string to be printed into $a0
        li $v0,4 #load service number for string print in $v0
        syscall

        sb $t0, 0($s3) 	
        addi $s3, $s3, 4
        
	addi $t1, $t1, 4 # advance array pointer by 4 "bits"
	addi $t2, $t2, 1
	j loop_2
loop_end_2:


li $t7, 0 # sum_counter
li $t6, 0 # loop counter
loop_3:
        beq $t6, 8, loop_end_3
	lw $t0, ($s4)
	lw $t1, ($s5)
	
	sub $t7, $t0, $t1
	sb $t7, 0($s6)
	
	addi $s6, $s6, 4
        addi $s4, $s4, 4
	addi $s5, $s5, 4 
	addi $t6, $t6, 1
	j loop_3
loop_end_3:


li $t7, 0 # sum_counter
li $t6, 0 # loop counter
loop_4:
        beq $t6, 8, loop_end_4
	lw $t0, ($s7)
	add $t7, $t7, $t0
	addi $s7, $s7, 4 
	addi $t6, $t6, 1
	j loop_4
loop_end_4:


la $a0, check_sum_string 
li $v0,4
syscall


li $v0, 1
la $a0, ($t7)
syscall



li $v0, 10   # terminate program run
syscall   


increment:
addi $s0, $s0, 1
j loop

.data

prompt: .asciiz "Input 8 numbers with spaces in between:  "
check_sum_string: .asciiz "Check Result: "
newline: .asciiz "\n"
buffer: .space 16
V: .align 2 
   .word

VPrime: .align 2
        .word
        
VCheck: .align 2
        .word 
