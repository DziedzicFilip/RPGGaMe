; PrintText.asm
.code
extern printf : proc     ; zadeklaruj printf z libc
public PrintText

PrintText proc
    ; RCX – wskaŸnik do napisu (to argument funkcji w x64)
    ; Musimy przekazaæ RCX do printf jako 1. argument

    sub rsp, 40          ; zachowaj 16-bajtowe wyrównanie stosu
    mov rdx, rcx         ; przenosimy wskaŸnik do napisu do RDX
    lea rcx, formatStr   ; RCX = format string "%s\n"
    call printf
    add rsp, 40
    ret

formatStr db "%s", 10, 0 ; napis formatuj¹cy "%s\n"

PrintText endp
end
