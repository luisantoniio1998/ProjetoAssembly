.MODEL FLAT, C  

.CODE             
add_vtr_asm PROC 
    push ebp 
    mov ebp,esp
    push esi 
    push edi 
    mov esi,[ebp+8] 
    mov ebx, [ebp+12]
    mov edi, [ebp+16]
    mov ecx,[ebp+20]
    shr ecx,2  
    mov eax,0 
    L1:movdqa XMM0,[esi + eax] ; adressamento complexo para um c�digo com menos instru��es 
    paddd xmm0,[ebx + eax] ;adressamento complexo
    movdqa [edi + eax], XMM0
    add eax, 16
    dec ecx
    jnz L1
    pop edi
    pop esi
    pop ebp
    ret
    add_vtr_asm ENDP
    END
