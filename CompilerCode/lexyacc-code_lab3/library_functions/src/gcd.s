.global gcd_func
   .text

gcd_func: # function enter
   pushq %rbp # save current base pointer on to stack
   movq %rsp, %rbp # set value of base pointer to adress of current stack pointer
   movq %rdi, -8(%rbp) # move value y at adress -8(%rbp) into %rdi
   movq %rsi, -16(%rbp) # move value x at adress -16(%rbp) into %rsi
   jmp .loopStart
.loop:
   movq -8(%rbp), %rax
   cmpq %rax, -16(%rbp)
   jnb .elseCase # jump if -16(%rbp) is not greater than %rax, CF flag not below 0
   # x is bigger "x = -16(%rbp)"
   movq -16(%rbp), %rax
   subq %rax, -8(%rbp) # subtract -8(%rbp) from %rax and store result %rax
   jmp .loopStart
.elseCase:
   # y is bigger "y = -8(%rbp)"
   movq -8(%rbp), %rax
   subq %rax, -16(%rbp) # subtract -8(%rbp) from %rax and store result %rax
.loopStart:
   movq -8(%rbp), %rax
   cmpq -16(%rbp), %rax # loop condition
   jne .loop # jump/continue loop if -16(%rbp) and %rax is not equal,
   # otherwise end and return
   movq -8(%rbp), %rax
   popq %rbp
   ret
