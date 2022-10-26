.global fact_func
   .text

fact_func: # function enter
# Prologue
   # %rbp is the frame pointer, contains snapshot of base pointer
   pushq %rbp # save current base pointer on to stack
   movq %rsp, %rbp # set value of base pointer to adress of current stack pointer
   subq $16, %rsp # reserve 16 bytes for local variables
# fact
   movq %rdi, -8(%rbp) # move value at adress -8(%rbp) into %rdi
   cmpq $0, -8(%rbp) # check if value is 0
   jne .factCont # jump if value is not 0
   movl $1, %eax # move 1 into %eax and then jump to end and return
   jmp .factEnd
.factCont:
   movq -8(%rbp), %rax # save %rax at adress -8(%rbp) before we deacrease it by 1
   subq $1, %rax # decrement %rax by 1
   movq %rax, %rdi # move value into return register %rax
   call fact_func # recursive call
   # when call returns multiply with result from call and result is stored in %rax
   imulq -8(%rbp), %rax
   # then move on to .factEnd to return to calling function
.factEnd: # function leave
# Epilouge
   movq %rbp, %rsp # drop stack pointer, release stack space
   popq %rbp # pop base pointer of stack, so it's restored to before the prolouge
   ret # return control to calling function
