.code
ALIGN 16

EXTERN GetKillDetection_EstusSubRetAddr : PROC
EXTERN Setup_KillDetection_Estus : PROC

KillDetection_EstusSub PROC
  push rax
  sub rsp,08

  mov edx,[rax+00000124h]

  test edx,edx
  js testlabel

  mov ecx,[rax+00000124h]

  push rdx
  push r9
  push r11
  sub rsp,08h
  call Setup_KillDetection_Estus
  add rsp,08h
  pop r11
  pop r9
  pop rdx

  xor ecx,ecx
  jmp skipLabel
testlabel:
  mov ecx,01
skipLabel:
  call GetKillDetection_EstusSubRetAddr
  mov r10,rax

  mov rcx,[rdi+10h]

  add rsp,08
  pop rax

  jmp r10

  
KillDetection_EstusSub ENDP

END