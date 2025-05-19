; mycode.asm
.code
public AddNumbers

AddNumbers proc
    mov eax, ecx    ; pierwszy argument (w Visual Studio: ECX)
    add eax, edx    ; drugi argument (EDX)
    ret
AddNumbers endp
end
