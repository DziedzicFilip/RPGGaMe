; PrintText.asm
.code
extern printf : proc     ; zadeklaruj printf z libc
public PrintText

PrintText proc
    ; RCX ? wska?nik do napisu (to argument funkcji w x64)
    ; 

    sub rsp, 40          ; zachowuje 16-bajtowe wyrownanie stosu
    mov rdx, rcx         ; przenosi wskaznik do napisu do RDX
    lea rcx, formatStr   ; RCX = format string "%s\n"
    call printf
    add rsp, 40
    ret

formatStr db "%s", 10, 0 ; napis formatujacy "%s\n"

PrintText endp
end