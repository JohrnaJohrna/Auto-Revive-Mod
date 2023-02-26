.code
ALIGN 16

EXTERN Setup_HitDetection_Bullet : PROC
EXTERN HitDetection_Bullet_SubRetAddr : PROC

HitDetection_Bullet_Sub PROC
  mov rax,[r14+00000190h]
  mov edx,[rdi+00000204h]
  mov rcx,[rax+00000098h]

  push rax
  push rcx
  push rdx
  sub rsp,08h

  mov rcx,rsi
  mov rdx,r14
  call Setup_HitDetection_Bullet

  call HitDetection_Bullet_SubRetAddr
  mov r10,rax

  add rsp,08h
  pop rdx
  pop rcx
  pop rax

  jmp r10
  
HitDetection_Bullet_Sub ENDP

END