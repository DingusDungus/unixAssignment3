.global gcd_func
   .text

gcd_func: # function enter
   pushq %rbp # save current base pointer on to stack
   movq %rsp, %rbp # set value of base pointer to adress of current stack pointer
   movq %rdi, -8(%rbp) # move value x at %rdi into adress -8(%rbp)
   movq %rsi, -16(%rbp) # move value y at %rsi into adress -16(%rbp)
   jmp .loopStart
.loop:
   movq -8(%rbp), %rax
   cmpq %rax, -16(%rbp)
   jnb .elseCase # jump if %rax is not greater than -16(%rbp), CF flag not below 0
   # x is bigger
   movq -16(%rbp), %rax
   subq %rax, -8(%rbp) # subtract %rax from -8(%rbp) and store result %rax
   jmp .loopStart
.elseCase:
   # y is bigger
   movq -8(%rbp), %rax
   subq %rax, -16(%rbp) # subtract %rax from -16(%rbp) and store result %rax
.loopStart:
   movq -8(%rbp), %rax
   cmpq -16(%rbp), %rax # loop condition
   jne .loop # jump/continue loop if -16(%rbp) and %rax is not equal,
   # otherwise end and return
   movq -8(%rbp), %rax # move -8(%rbp) to return register %rax
   popq %rbp
   ret
