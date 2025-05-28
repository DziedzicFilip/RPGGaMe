; PrintText.asm
.code
extern printf : proc     ; zadeklaruj printf z libc
public PrintText

PrintText proc
    ; RCX ? wska?nik do napisu (to argument funkcji w x64)
    ; Musimy przekaza? RCX do printf jako 1. argument

    sub rsp, 40          ; zachowaj 16-bajtowe wyr?wnanie stosu
    mov rdx, rcx         ; przenosimy wska?nik do napisu do RDX
    lea rcx, formatStr   ; RCX = format string "%s\n"
    call printf
    add rsp, 40
    ret

formatStr db "%s", 10, 0 ; napis formatuj?cy "%s\n"

PrintText endp
end