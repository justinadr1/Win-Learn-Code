
bits 64
default rel

extern ExitProcess
extern printf

section .data
    fmt_count db "Total args: %d", 10, 0
    fmt_arg db "Arg [%d]: %s", 10, 0

section .text
global main

main:
    push rbp
    mov rbp, rsp
    sub rsp, 32
    
    mov r12, rcx
    mov r13, rdx

    mov rdx, r12
    mov rcx, fmt_count  
    call printf

.loop:
    ; if (index == argc) exit
    cmp r14, r12
    je .done

    ; printf(fmt_arg, index, argv[index])
    mov rcx, fmt_arg
    mov rdx, r14

    ; argv[index]
    ; [r13 + r14 * 8] means start at argv, skip (index * 8) bytes
    mov r8, [r13 + r14 * 8]
    call printf

    inc r14
    jmp .loop

.done:
    xor rcx, rcx
    call ExitProcess