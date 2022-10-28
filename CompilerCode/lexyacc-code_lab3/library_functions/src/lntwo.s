.global lntwo_func
   .text

lntwo_func:
# Prologue
   # %rbp is the frame pointer, contains snapshot of base pointer
   pushq %rbp # save current base pointer on to stack
   movq %rsp, %rbp # set value of base pointer to adress of current stack pointer
   subq $16, %rsp # reserve 16 bytes for local variables
# lntwo
   movq %rdi, -8(%rbp) # move value at adress -8(%rbp) into %rdi
   cmpq $1, -8(%rbp) # check if value is 1
   jbe .earlyEnd # jump if value is below or equal to 1
   movq -8(%rbp), %rax # save %rax at adress -8(%rbp) before we shift it
   shrq %rax # shift right for unsigned integers
   movq %rax, %rdi # move value into return register %rax
   call lntwo_func # recursive call
   addq $1, %rax # when call returns, add 1 to %rax before we jump to end
   jmp .lntwoEnd
.earlyEnd:
   movl $0, %eax # move 0 into %eax, then end and return
.lntwoEnd:
# Epilouge
   movq %rbp, %rsp # drop stack pointer, release stack space
   popq %rbp # pop base pointer of stack, so it's restored to before the prolouge
   ret # return control to calling function
