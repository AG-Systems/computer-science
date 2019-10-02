la $a0, prompt_name_string # load address of string to be printed into $a0
li $v0,4 #load service number for string print in $v0
syscall
# prints What is your name fam?


li $v0,8 #take in input
la $a0, buffer #load byte space into address
li $a1, 50 # allot the byte space for string
move $t0,$a0 #save string to t0
syscall
# opens prompt for user input




######## Age set up and prompt ############

la $a0, prompt_age_string # load address of string to be printed into $a0
li $v0,4 #load service number for string print in $v0
syscall
# prints What is your age fam?

li $v0,5 
syscall 
move $t1,$v0 

##### PRINTING SECTION ##########

la $a0, result_name_string
li $v0, 4
syscall


li $v0, 4       # you can call it your way as well with addi 
la $a0, newline       # load address of the string
syscall


addi $t3,$t1,4 
li $v0,4 
la $a0, result_age_string_1 
syscall

li $v0,1 # print an integer
move $a0,$t3 # integer to print goes in a0
syscall

li $v0,4 #load service number for string print in $v0
la $a0, result_age_string_2 # load address of string to be printed into $a0
syscall

li $v0,10 #load service number in $v0
syscall 
# the null-terminated string must be defined in data segment

.data

newline: .asciiz "\n"


buffer: .space 20

prompt_name_string: .asciiz "What is your name fam?: "

prompt_age_string: .asciiz "What is your age young one?: "

result_name_string: .asciiz "Hello, "

result_age_string_1: .asciiz "You will be "

result_age_string_2: .asciiz " years old in four years."

