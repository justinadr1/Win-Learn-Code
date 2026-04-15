default rel

extern ExitProcess
extern WriteFile
extern GetStdHandle

section .data
    msg db "HELLO WORLD", 0
    len equ $ - msg


section .text
global main

main:
    sub rsp, 40
    mov ecx, 0xFFFFFFF5     ; -11
    call GetStdHandle
    mov rbx, rax
    
    mov rcx, rbx
    lea rdx, [msg]
    mov r8d, len
    lea r9, [rsp+32]
    mov qword [rsp+32], 0
    
    mov qword [rsp+40], 0
    call WriteFile
    
    xor ecx, ecx
    call ExitProcess