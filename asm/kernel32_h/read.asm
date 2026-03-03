
extern __imp_GetStdHandle
extern __imp_ReadFile
extern __imp_WriteFile
extern ExitProcess

section .bss
    buffer       resb 256
    bytesRead    resd 1
    bytesWritten resd 1

section .text
global main

main:
    sub rsp, 48
    push rbx
    mov ecx, -10    ; STD_INPUT_HANDLE = -10
    call qword [rel __imp_GetStdHandle]
    mov rbx, rax
    
    mov rcx, rbx
    lea rdx, [rel buffer]
    mov r8d, 256
    lea r9, [rel bytesRead]
    mov qword [rsp+20h], 0
    call qword [rel __imp_ReadFile]

    mov ecx, -11
    call qword [rel __imp_GetStdHandle]
    mov rbx, rax

    mov rcx, rbx
    lea rdx, [rel buffer]
    mov eax, [bytesRead]
    mov r8d, eax
    lea r9, [rel bytesWritten]
    mov qword [rsp+20h], 0
    call qword [rel __imp_WriteFile]
    
    xor ecx, ecx
    call ExitProcess
