.data

result_fmt:
  .string "Test Case %d\nInput: %s\nOutput: %d\n\n"

test_case_1:
  .string "ababa"

test_case_2:
  .string "abb"

test_case_3:
  .string ""

.text
.global _main
.extern _printf

# aligned call because mac requires 16-byte alignment
# for function calls. Assumes stack pointer ends in 0x8.
.macro ACALL func
  subq $0x8, %rsp
  call \func
  addq $0x8, %rsp
.endm

solution:
  # Args:
  #   %rdi: address to string
  #   %esi: length of string
  # Returns:
  #   %eax: answer

  # check if length is 0
  testl %esi, %esi
  jz zero_len

  # %r12 will store address of string
  push %r12
  movq %rdi, %r12

  # %r13 will store length of string
  push %r13
  movl %esi, %r13d

  # %r14 will store floor(length of string) / 2
  push %r14
  movq %r13, %r14
  shr $0x1, %r14

  # %r15 will store index of current char
  push %r15
  movq $0x0, %r15

  # %rax will start as 0
  movq $0x0, %rax

  loop_1:

    # %dil will store char1
    movb (%r12, %r15), %dil

    # %sil will store char2
    movq %r13, %rsi
    subq %r15, %rsi
    subq $0x1, %rsi
    movb (%r12, %rsi), %sil

    # compare chars
    cmp %dil, %sil
    jne chars_ne

    # update loop
    addl $0x1, %r15d
    cmpl %r14d, %r15d
    jl loop_1

  end:
    addq $0x1, %rax
    pop %r15
    pop %r14
    pop %r13
    pop %r12
    ret

  zero_len:
    movq $0x0, %rax
    ret

  chars_ne:
    addq $0x1, %rax
    jmp end

_main:
  leaq test_case_1(%rip), %rdi
  movq $0x5, %rsi
  ACALL solution

  leaq result_fmt(%rip), %rdi
  movq $0x1, %rsi
  leaq test_case_1(%rip), %rdx
  movq %rax, %rcx
  ACALL _printf

  leaq test_case_2(%rip), %rdi
  movq $0x3, %rsi
  ACALL solution

  leaq result_fmt(%rip), %rdi
  movq $0x2, %rsi
  leaq test_case_2(%rip), %rdx
  movq %rax, %rcx
  ACALL _printf

  leaq test_case_3(%rip), %rdi
  movq $0x0, %rsi
  ACALL solution

  leaq result_fmt(%rip), %rdi
  movq $0x3, %rsi
  leaq test_case_3(%rip), %rdx
  movq %rax, %rcx
  ACALL _printf

  movq $0, %rax
  ret
