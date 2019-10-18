.text
main:    #assume value a is already in $t0, b in $t1
    li $a0, 1
    jal matrix_input_row    # call procedure

    li $a0, 2
    jal matrix_input_row    # call procedure    
    
    li $a0, 3
    jal matrix_input_row    # call procedure   

    li $a0, 4
    jal matrix_input_row    # call procedure   
    

    jal matrix_sum_print   # call procedure       
              
                          
                                                
    li $v0, 10   # terminate program run
    syscall  
    
              
matrix_input_row:
      addi $sp,$sp,-4     # Moving Stack pointer
      sw $t0, 0($sp)      # Store previous value
      # a0 = index
     
     move $t6,$a0 # save index argument to t6 register
     
     
     la $a0, prompt # print the prompt
     li $v0,4 # "Row: "
     syscall
     
     la $a0, ($t6)
     li $v0,1    # print the integer
     syscall # the ( $a0) integer index parameter is stored in $a0
     
  
     
     li $v0,8 # take in input
     la $a0, buffer # load byte space into address
     li $a1, 50 # allocate 50 bits for address 1
     move $s0,$a0 # save string to s0
     syscall # opens prompt for user input   
	
     li $t5, 0 # loop counter
     
     intialize:
          bne  $t6, 1, skip_intialize
          la $s1, M # get array address
     skip_intialize:
     
     
    loop:
    	 beq $t5, 4, end
    	 
    	 lb  $t0, 0($s0) 
    	 addi $t0, $t0, -48 
    	 sb $t0 , 0($s1)
    	 
    	 addi $s0, $s0, 2
    	 addi $t5, $t5, 1
    	 addi $s1, $s1, 4
         j loop
    end:
    

    lw $t0, 0($sp)      # Load previous value
    addi $sp,$sp,4      # Moving Stack pointer 
    jr $ra              # return (Copy $ra to PC)



matrix_sum_print:
      addi $sp,$sp,-4     # Moving Stack pointer
      sw $t0, 0($sp)      # Store previous value
      
      la $s1, M # get array address
      li $t0, 0 # index
      li $t1, 0 # sum counter
      sum_loop:
      	 beq $t0, 16, sum_exit
      	  
	 lw $t2, ($s1)
      	 add $t1, $t1, $t2
      	 
    	 addi $t0, $t0, 1
    	 addi $s1, $s1, 4      	  
      	 j sum_loop
      sum_exit:

      la $a0, sum_prompt # print the prompt
      li $v0,4 # "Sum: "
      syscall

     la $a0, ($t1)
     li $v0, 1    # print the integer
     syscall # the ( $a0) integer index parameter is stored in $a0    	
      

      lw $t0, 0($sp)      # Load previous value
      addi $sp,$sp,4      # Moving Stack pointer 
      jr $ra              # return (Copy $ra to PC)
	

.data 
sum_prompt: .asciiz "Matrix sum: "
prompt: .asciiz "Row "
buffer: .space 16
M: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
