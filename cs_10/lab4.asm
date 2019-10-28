.text
main:
    li $a1, 1 # martix 1
    jal matrix_input   # call procedure       
              
    li $a1, 2 # martix 2
    jal matrix_input   # call procedure                          
                                             
                                                                                                                                        
    li $v0, 10   # terminate program run
    syscall  
    
matrix_input:
    addi $sp,$sp,-4     # Moving Stack pointer
    sw $ra, 0($sp)      # Store previous value
    
            
    li $a0, 1 
    jal matrix_input_row    # call procedure

    li $a0, 2
    jal matrix_input_row    # call procedure    
    
    li $a0, 3
    jal matrix_input_row    # call procedure   

    li $a0, 4
    jal matrix_input_row    # call procedure


       
    lw $ra, 0($sp)      # Load previous value
    addi $sp,$sp,4      # Moving Stack pointer 
    jr $ra              # return (Copy $ra to PC)   
    
        	                 	             
matrix_input_row:
      addi $sp,$sp,-4     # Moving Stack pointer
      sw $t0, 0($sp)      # Store previous value
      # a0 = index
     
     move $t6,$a0 # save index argument to t6 register
     move $t7, $a1 # save matrix argument to t7 register
     
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
          
          beq $t7, 1, matrix_1_intialize
          beq $t7, 2, matrix_2_intialize
          matrix_1_intialize:
                la $s1, M_1 # get array address
                j skip_intialize
                
          matrix_2_intialize:
                la $s1, M_2 # get array address
                j skip_intialize          
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


matrix_multiply:
    addi $sp,$sp,-4     # Moving Stack pointer
    sw $s7, 0($sp)      # Store previous value    
    
    la $s1, M_1 # get array address
    la $s2, M_2 # get array address
    la $s3, M_3 # get array address
    
    
    li $t0, 0 # first index counter
    li $t1, 0 # second index counter
    li $t2, 0 # third index counter
    matrix_loop_1:
    	   beq $t0, 4, matrix_end_1
    	   
           matrix_loop_2:
           	beq $t1, 4, matrix_end_1
                
                lw $t3, 0($s3) # t3 = M_3[i][j]
                
                matrix_loop_3:
                	beq $t2, 4, matrix_end_1
                	
                	
                	addi $t2, $t2, 1	
                	j matrix_loop_3	
                matrix_end_3:
                
                sb $t3, 0($s3)
                
                addi $t1, $t1, 1
                addi $s3, $s3, 4
                j matrix_loop_2
                
           matrix_end_2:
           
           addi $t0, $t0, 1
           addi $s3, $s3, 4
           j matrix_loop_1    
    matrix_end_1:
	
    
    lw $t0, 0($sp)      # Load previous value
    addi $sp,$sp,4      # Moving Stack pointer 
    jr $ra              # return (Copy $ra to PC)	

.data 
sum_prompt: .asciiz "Matrix sum: "
prompt: .asciiz "Row "
buffer: .space 16
M_1: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
M_2: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
M_3: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
