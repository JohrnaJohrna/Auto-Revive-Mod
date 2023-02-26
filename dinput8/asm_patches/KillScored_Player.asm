.code
ALIGN 16

EXTERN GetPlayer_KillScoredRetAddr : PROC
EXTERN Setup_KillScoredPc : PROC

Player_KillScoredSub PROC
  mov [rsp+08h],rbx
  push rdi
  sub rsp,30h
  mov eax,3F800000h
  movd xmm0,eax

  push rdx
  push r8
  push r9

  push rcx
  call Setup_KillScoredPc
  pop rcx

  push rcx
  call GetPlayer_KillScoredRetAddr
  pop rcx

  pop r9
  pop r8
  pop rdx

  jmp rax
Player_KillScoredSub ENDP

END