.section .data
data_items:
    .long 3, 67, 34, 222, 45, 75, 54, 34, 44, 33, 22, 11, 246, 0
    # 0 < Number < 256
data_print:
    .ascii "resu:xxxx\n"
.section .text
.global _start
_start:
    movl $0, %edi
    movl data_items(, %edi, 4), %eax
    movl %eax, %ebx

start_loop:
    incl %edi
    movl data_items(, %edi, 4), %eax
    cmpl $0, %eax
    je loop_exit
    cmpl %ebx, %eax
    jle start_loop
    movl %eax, %ebx
    #pushl %ebx
    #call print
    #popl %ebx
    jmp start_loop

loop_exit:
    movl $1, %eax
    #movl $4, %ebx
    int $0x80


.type print, @function
print:
    pushl %ebp
    movl %esp, %ebp
    movl $4, %eax
    movl $1, %ebx
    
    movl $data_print, %edi
    movl 8(%ebp), %ecx
    movl %ecx, 5(%edi)
    #movl $data_print, %ecx
    movl %edi, %ecx
    movl $10, %edx
    int $0x80
    movl %ebp, %esp
    popl %ebp
    ret


