.global fact_func
   .text

fact_func:
   pushq %rbp # function enter, push base pointer on to stack
   movq %rsp, %rbp # set value of base pointer to adress of stack pointer
   subq $16, %rsp # decrease stack pointer
   # to make room for local variables
   movq %rdi, -8(%rbp) # move param value into %rdi
   cmpq $0, -8(%rbp)
   jne .factRecurse # recurse unless param is 0, and we return 1.
   movl $1, %eax # move 1 into %eax and then end function.
   jmp .factEnd
.factRecurse:
   movq -8(%rbp), %rax # save %rax before we deacrease it by 1
   subq $1, %rax # decrement %rax by 1
   movq %rax, %rdi # move value into return register %rax
   call fact_func # recurse
   imulq -8(%rbp), %rax # when we as caller get back control
   # multiply and move on to .factEnd to return result
.factEnd:
   movq %rbp, %rsp # function leave release stack space
   popq %rbp # continue from above
   ret # return control to calling program
