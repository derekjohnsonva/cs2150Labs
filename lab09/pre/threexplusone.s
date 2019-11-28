; threexplusone.s
; Derek Johnson
; 11/15/19
; Purpose : This file will return the number of steps required to
;           reach 1 using the collatz conjecture. The conjecture is 
;           that any number will reach 1 when performing the following 
;           functions recursively. If even, x/2.  If odd, 3x+1.
;           

  global threexplusone

  section .text

threexplusone:

start:
; compare the first perameter to 1 to see if it is the base case
  cmp rdi, 1
  jle done
; Determine the sign of rdx, mov rdx into rax and divide by 2
; If remainder(stored in rdx) = 1 jump to odd, else to even 
  mov rax, rdi
  xor rdx, rdx
  mov r10, 2
  idiv r10

  cmp rdx, 1
  je odd

even:
  ; from the operation above, x/2 is in the rax register
  mov rdi, rax
  xor rax, rax
  inc rax
  jmp rec
odd:
  lea rdi, [rdi+rdi*2+1]
  xor rax, rax
  inc rax
rec:
  push rax
  xor rax, rax
  call threexplusone
  mov r10, rax
  pop rax
  add rax, r10 
done:
  ret

; I had originally been using seperate registers for each variable
; that the program needed to store. To optimize I made it so that all of my
; temporary variables are stored in r10 and simply overwritten as the program
; runs
;I started to use the xor command instead of (mov reg, 0) 
;Additionally, I used the lea command for the (mult by 3 +1) in the odd
; section 
