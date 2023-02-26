.code
ALIGN 16

EXTERN Setup_HitDetection_Attack : PROC
EXTERN HitDetection_Attack_SubRetAddr : PROC

HitDetection_Attack_Sub PROC
  mov rax,[r14+00000190h]
  mov r15,[rax+00000098h]

  push rax
  push rcx
  push rdx
  sub rsp,08h

  mov rcx,r14
  mov rdx,rsi
  call Setup_HitDetection_Attack

  call HitDetection_Attack_SubRetAddr
  mov r10,rax

  add rsp,08h
  pop rdx
  pop rcx
  pop rax

  jmp r10
  
HitDetection_Attack_Sub ENDP

END