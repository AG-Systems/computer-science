.text
main:
    li $a1, 1 # martix 1
    jal matrix_input   # call procedure       
              
    li $a1, 2 # martix 2
    jal matrix_input   # call procedure                          
                                             
    jal matrix_multiply
                                                                                                                                                                                                                                                                    
    jal matrix_print
    
    
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
    
         li $t1, 0 # I index counter
         li $t3, 0 # cij 
    	m_col_row_1:
    		beq $t1, 4, m_col_row_1
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_1_end
    	m_col_row_1_end:
    	sb $t3, 0($s3)
    	li $t3, 0
    	li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 4
    	m_col_row_2:
    		beq $t1, 4, m_col_row_2
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_2_end
    	m_col_row_2_end:
    	sb $t3, 0($s3)
    	li $t3, 0 
    	li $t1, 0   	
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 8    
     	m_col_row_3:
    		beq $t1, 4, m_col_row_3
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_3_end
    	m_col_row_3_end: 
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 12    
     	m_col_row_4:
    		beq $t1, 4, m_col_row_4
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_4_end
    	m_col_row_4_end:    
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s3, $s3, 4	



	

	
	m_col_row_5:
    		beq $t1, 4, m_col_row_5
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_5_end
    	m_col_row_5_end:
    	sb $t3, 0($s3)
    	li $t3, 0
    	li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s1, $s1, 12
        addi $s3, $s3, 4 
        addi $s2, $s2, 4
    	m_col_row_6:
    		beq $t1, 4, m_col_row_6
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_6_end
    	m_col_row_6_end:
    	sb $t3, 0($s3)
    	li $t3, 0 
    	li $t1, 0   	
        la $s1, M_1 # get array address
        addi $s1, $s1, 12
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 8    
     	m_col_row_7:
    		beq $t1, 4, m_col_row_7
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_7_end
    	m_col_row_7_end: 
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 12
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 12    
     	m_col_row_8:
    		beq $t1, 4, m_col_row_8
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_8_end
    	m_col_row_8_end:    
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 12
        la $s2, M_2 # get array address
        addi $s3, $s3, 4	
	










	m_col_row_9:
    		beq $t1, 4, m_col_row_9
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_9_end
    	m_col_row_9_end:
    	sb $t3, 0($s3)
    	li $t3, 0
    	li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s1, $s1, 24
        addi $s3, $s3, 4 
        addi $s2, $s2, 4
    	m_col_row_10:
    		beq $t1, 4, m_col_row_10
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_10_end
    	m_col_row_10_end:
    	sb $t3, 0($s3)
    	li $t3, 0 
    	li $t1, 0   	
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 8    
     	m_col_row_11:
    		beq $t1, 4, m_col_row_11
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_11_end
    	m_col_row_11_end: 
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 12    
     	m_col_row_12:
    		beq $t1, 4, m_col_row_12
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_12_end
    	m_col_row_12_end:    
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4

	
		
			

	m_col_row_13:
    		beq $t1, 4, m_col_row_13
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_13_end
    	m_col_row_13_end:
    	sb $t3, 0($s3)
    	li $t3, 0
    	li $t1, 0
        la $s1, M_1 # get array address
        la $s2, M_2 # get array address
        addi $s1, $s1, 24
        addi $s3, $s3, 4 
        addi $s2, $s2, 4
    	m_col_row_14:
    		beq $t1, 4, m_col_row_14
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_14_end
    	m_col_row_14_end:
    	sb $t3, 0($s3)
    	li $t3, 0 
    	li $t1, 0   	
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 8    
     	m_col_row_15:
    		beq $t1, 4, m_col_row_15
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_15_end
    	m_col_row_15_end: 
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4 
        addi $s2, $s2, 12    
     	m_col_row_16:
    		beq $t1, 4, m_col_row_16
    		
    		lb $t4, 0($s1)
    		lb $t5, 0($s2)
    		
    		mul $t6, $t4, $t5
    		add $t3, $t3, $t6
    		
    		addi $s2, $s2, 16
    		addi $s1, $s1, 4
    		addi $t1, $t1, 1
    		j m_col_row_16_end
    	m_col_row_16_end:    
    	sb $t3, 0($s3)
    	li $t3, 0    
        li $t1, 0
        la $s1, M_1 # get array address
        addi $s1, $s1, 24
        la $s2, M_2 # get array address
        addi $s3, $s3, 4	
			
	
    
    lw $t0, 0($sp)      # Load previous value
    addi $sp,$sp,4      # Moving Stack pointer 
    jr $ra              # return (Copy $ra to PC)	


matrix_print:
    addi $sp,$sp,-4     # Moving Stack pointer
    sw $s7, 0($sp)      # Store previous value   
    
    la $s3, M_3 # get array address
    li $t0, 0 # counter
    li $t1, 0 # inner counter
    
    matrix_print_loop:
    	 beq $t0, 4, matrix_print_end

         la $a0, prompt # print the prompt
         li $v0,4 # "Row: "
         syscall  
          
          
         row_loop:
             beq $t1, 4, row_end
             
             lw $a0, ($s3)
             li $v0,1    # print the integer
             syscall # the ( $a0) integer index parameter is stored in $a0   
                       
             addi $t1, $t1, 4
             addi $s3, $s3, 4
             j row_loop
         row_end:
                      
         addi $t0, $t0, 1
        j matrix_print_loop
    matrix_print_end:
    
    
    
    lw $t0, 0($sp)      # Load previous value
    addi $sp,$sp,4      # Moving Stack pointer 
    jr $ra              # return (Copy $ra to PC)

.data 
prompt: .asciiz "Row "
buffer: .space 16
M_1: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
M_2: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
M_3: .word 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
