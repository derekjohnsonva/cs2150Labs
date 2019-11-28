; mathlib.s
; Derek Johnson
; 11/4/19
; Purpose : this file contains the implementation of the function
;           product and power
;           rdi stores the first number
;           rsi stores the second number
  global product

  section .text

product:

  xor rax, rax ; will be used for return
  xor r10, r10 ; will be used as counter i
start:
  cmp r10, rsi  ; does i == y
  je done       ; if yes finish the routine
  add rax, rdi  ; add x to the return
  inc r10       ; inc the counter i
  jmp start     ; start the loop again
done: 
  ret


  global power

  section .text

power:
  
start2:
  cmp rsi, 1   ; if y = 1, return 1
  jne loop    
  mov rax, rdi   
  ret  
loop:
  dec rsi
  call power
  push rsi
  push rdi
  mov rsi, rax  ; rsi = return value
  call product  ; rax = product
  pop rdi
  pop rsi
  ret  




