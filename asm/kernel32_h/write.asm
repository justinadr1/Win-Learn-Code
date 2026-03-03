
extern __imp_GetStdHandle
extern __imp_WriteFile
extern ExitProcess

section .data
    msg db "Epic message", 13, 10
    msg_len equ $ - msg - 1

section .bss
    bytesWritten resd 1

section .text
global main

main:
    sub rsp, 48
    push rbx
    mov ecx, -11    ; STD_OUTPUT_HANDLE = -11
    call qword [rel __imp_GetStdHandle]
    mov rbx, rax

    mov rcx, rbx
    lea rdx, [rel msg]
    mov r8d, msg_len
    lea r9, [rel bytesWritten]
    mov qword [rsp+20h], 0
    call qword [rel __imp_WriteFile]
    
    xor ecx, ecx
    call ExitProcess
