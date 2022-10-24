.global inc_func
   .text

inc_func:
   push %rbp                 # function prelog
   movq %rsp, %rbp           #
   adcq $0x1, %rdi           # add 1 to uint64_t
   movq %rdi, %rax           # move result to rax
   pop %rbp                  # function epilog
   ret                       # return
