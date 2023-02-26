.code
ALIGN 16

EXTERN GetPlayer_DeathEventRetAddr : PROC
EXTERN Setup_PlayerDeathEvent : PROC

Player_DeathEventSub PROC
  push rbx
  sub rsp,40h
  mov DWORD PTR [rsp+50h],0

  push rdx
  push r8
  push r9

  push rcx
  call Setup_PlayerDeathEvent
  pop rcx

  push rcx
  call GetPlayer_DeathEventRetAddr
  pop rcx

  pop r9
  pop r8
  pop rdx

  jmp rax
Player_DeathEventSub ENDP

END